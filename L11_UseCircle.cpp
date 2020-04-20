/*
     FILE:   L11_UseCircleSoln.cpp
	 AUTHOR: 
	 DATE:   April 22nd. 2020
	 DESCR:
	 This is a client file for testing the
	 student created Circle class.
*/

// using declarations for std namespace
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

// specification file
#include "Circle.h"

// get number of circle objects
int Circle::numCircle = 0;
int Circle::getNumObj() {
	return numCircle;
}
// constructors
// default
Circle::Circle() {
	this->name;
	radius = 0;
	numCircle++;
}
// Parameterized
Circle::Circle(std::string *cName, double cRadius) {
	this->name = cName;
	radius = cRadius;
	numCircle++;
}
// copy constructor
Circle::Circle(const Circle& c) {
	this->name = c.name;
	radius = c.radius;
	numCircle++;
}
// destructor
Circle::~Circle() {
	numCircle--;
}
// mutators
void Circle::setName(std::string* cName) {
	this->name = cName;
}

void Circle::setRadius(double cRadius) {
	radius = cRadius;
}

// calculation methods
double Circle::calcArea() const {
	double area = M_PI * pow(radius, 2);
	return area;
}

double Circle::calcCircumference() const {
	double circumference = 2 * M_PI * radius;
	return circumference;
}

// overloaded insertion operator as friend function
// uses private member names and public calculation 
// methods (NOTE: friend prototype included as
// part of Circle declaration)

std::ostream& operator<< (std::ostream& lhs, const Circle& rhs) {
	lhs << rhs.name << " radius = " << std::fixed << std::setprecision(2) << rhs.radius
		<< " circumference = " << rhs.calcCircumference()
		<< " area = " << rhs.calcArea() << std::endl;
	return lhs;
}

// overload = operator as member function
Circle& Circle::operator = (const Circle& rhs) {
	// check for object equliaty
	if (this != &rhs) {
		this->name = rhs.name;
		this->radius = rhs.radius;
	}
	return *this;
}

int main() {
	
	// output number of circle objects before any are created
	std::cout << "Number of circle objects = " << Circle::getNumObj() << std::endl;
	// create circle objects using constructors (parameter, copy, and default)
	Circle c1("c1", 4.0), c2(c1), c3;
	// reset c2 properties
	c2.setName("c2");
	c2.setRadius(6.0);
	// assign c2 properties to c3 using overloaded assignment operator
	c3 = c2;
	// reset c3 properties
	c3.setName("c3");
	c3.setRadius(8.0);
	// display circles using overloaded insertion operator
	std::cout << "**Circles***" << std::endl;
	std::cout << c1 << c2 << c3;
	// output number of circle objects after objects have been created
	std::cout << "Number of circle objects = " << c3.getNumObj() << std::endl;
	return EXIT_SUCCESS;
}