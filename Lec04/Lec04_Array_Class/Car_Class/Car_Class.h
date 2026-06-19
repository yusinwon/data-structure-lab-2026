#pragma once
#include <cstdio>
#include <cstring> // For strcpy_s

class Car {
protected:
	int speed;          // Speed
	char name[40];      // Name
public:
	int gear;           // Gear

	Car() {}           // Default constructor
	~Car() {}          // Destructor

	// Constructor with parameters (Added 'const' to prevent C2440 error)
	Car(int s, const char* n, int g)
		: speed(s), gear(g) {
		// Used strcpy_s instead of strcpy for security (Prevents C4996 error)
		strcpy_s(name, sizeof(name), n);
	}

	// Member function to change gear
	void changeGear(int g = 4) {
		gear = g;
	}

	// Member function to increase speed by 5
	void speedUp() {
		speed += 5;
	}

	// Display car information
	void display() {
		printf("[%s] : Gear=%d Speed=%dkmph\n", name, gear, speed);
	}

	// Print object address (Changed %x to %p for pointers)
	void whereAmI() {
		printf("Object address = %p\n", this);
	}
}; 
