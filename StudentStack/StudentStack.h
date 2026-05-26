#pragma once
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAX_STRING = 20;
const int MAX_STACK_SIZE = 20;

// Student 클래스 정의
class Student {
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];
public:
    Student(int i = 0, const char* n = "", const char* d = "") { set(i, n, d); }
    void set(int i, const char* n, const char* d) {
        id = i;
        // 안전을 위해 _s 또는strncpy 사용을 권장하지만, 일단 기존 코드 유지
        strcpy_s(name, n);
        strcpy_s(dept, d);
    }
    void display() {
        printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
    }
};

// 클래스 이름을 StudentStack으로 변경하여 구분함
class StudentStack {
    int top;
    Student data[MAX_STACK_SIZE];
public:
    StudentStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1; }

    void push(Student e) {
        if (isFull()) printf("스택 포화 에러\n");
        else data[++top] = e;
    }
    Student pop() {
        if (isEmpty()) exit(1);
        return data[top--];
    }
    void display() {
        printf("[스택 항목의 수 = %2d]\n", top + 1);
        for (int i = 0; i <= top; i++)
            data[i].display(); // Student 객체의 display 호출
    }
};
