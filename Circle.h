/*
Author: 
Date: April 22nd. 2020
Prog: Circle.h
Descr: 
Include guard to help with defining the class
*/
#include <iostream>
#include <string>


#ifndef CIRCLE_H
#define CIRCLE_H



class Circle {
private:
	std::string* name = new std::string;
	double radius = 0;
	static int numCircle;
	
public:
	// constructors
	// default
	Circle();
	// Parameterized
	Circle(std::string*, double);
	// copy constructor
	Circle(const Circle&);
	// destructor
	~Circle();
	// mutators
	void setName(std::string*);
	void setRadius(double);
	// accessors
	std::string *getName() { return name; };
	double getRadius() const { return radius; };
	// calculation methods
	double calcArea() const;
	double calcCircumference() const;
	// static accessor method for static variable
	static int getNumObj();
	// grant friendsip to operator
	friend std::ostream& operator << (std::ostream&, const Circle&);
	// overload = operator as member function
	// lhs is object upon which member function is invoked
	Circle& operator = (const Circle&);
	
};

#endif // !CIRCLE_H


