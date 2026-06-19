#pragma once
#include <cstdio>

#define MAX_DEGREE 80 // Maximum possible degree of the polynomial + 1

class Polynomial {
	int		degree;               // Highest degree of the polynomial
	float	coef[MAX_DEGREE];     // Coefficients for each term

public:
	// Constructor: Initialize the maximum degree to 0
	Polynomial() { degree = 0; }

	// Member function to input polynomial details
	void read() {
		printf("Enter the highest degree of the polynomial: ");
		scanf_s("%d", &degree);

		printf("Enter the coefficients (Total %d): ", degree + 1);
		for (int i = 0; i <= degree; i++) {
			scanf_s("%f", coef + i);
		}
	}

	// Function to display the polynomial on the screen
	void display(const char* str = " Poly = ") {
		printf("\t%s", str);
		for (int i = 0; i < degree; i++) {
			printf("%5.1f x^%d + ", coef[i], degree - i);
		}
		printf("%4.1f\n", coef[degree]);
	}

	// Function to add polynomials a and b and set it to the current object
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {          // degree of a > degree of b
			*this = a;                      // Copy polynomial a to the current object
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {                              // degree of a <= degree of b
			*this = b;                      // Copy polynomial b to the current object
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}

	// Is the highest degree 0?
	bool isZero() { return degree == 0; }

	// Change the sign of all coefficients
	void negate() {
		for (int i = 0; i <= degree; i++) {
			coef[i] = -coef[i];
		}
	}
};