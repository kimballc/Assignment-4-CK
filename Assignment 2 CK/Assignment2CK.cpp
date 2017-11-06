// Assignment2CK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Student.h"
#include <vector>
#include <iostream>

using std::cout; using std::vector; using std::endl;

int main()
{
	//create first Student using default constructor
	Student student1;
	//create next 2 Students using initializer constructor
	Student student2 = Student("Christian Kimball", 3, "Security and Cyber Defense", "CS415");
	Student student3 = Student("Nick Hagan", 4, "Computer Science", "MG444");
	
	//create vector to store each student
	vector<Student> students;
	students.push_back(student1);
	students.push_back(student2);
	students.push_back(student3);

	//loop through vector and print each value for each object
	for(int i = 0; i < students.size(); i++)
	{
		cout << "Name: " << students[i].getName() << endl;
		cout << "Year: " << students[i].getYear() << endl;
		cout << "Major: " << students[i].getMajor() << endl;
		cout << "Course: " << students[i].getCourse() << endl << endl;
	}

	//variable of class’s type, and assign it the 1st item in vector
	Student varStudent = students[0];

	//variable of class’s type, and assign it the address of the 2nd item in vector.
	Student *studentPtr = &students[1];

	//variable of class’s type, and bind it to the 3rd item in vector
	Student& studentRef = students[2];

	//modify a value via the above 3 variables
	varStudent.setCourse("CS346");
	studentPtr->setCourse("CS346");
	studentRef.setCourse("CS346");

	//loop through vector and print each value for each object
	for (int i = 0; i < students.size(); i++)
	{
		cout << "Name: " << students[i].getName() << endl;
		cout << "Year: " << students[i].getYear() << endl;
		cout << "Major: " << students[i].getMajor() << endl;
		cout << "Course: " << students[i].getCourse() << endl << endl;
	}
	/*
	The values changed using the pointer and the reference, but not via the straight variable.
	This is because the variable is just a copy of the original object where the pointer and 
	reference refer to the origin object.
	*/
    return 0;
}

