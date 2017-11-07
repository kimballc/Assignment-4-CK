#include "stdafx.h"
#include "Student.h"
#include "DataManager.h"
#include <sstream>
#include <iomanip>
using namespace std;

//Default Constructor
Student::Student()
{
	name = "Bob Smith";
	year = 3;
	major = "Computer Science";
	course = "CS245";
}

//Initializer Constructor
Student::Student(int id, const string &name, int year, const string &major, const string &course) :
	id(id), name(name), year(year), major(major), course(course) {}

//set the name of the student 
void Student::setName(const string &name)
{
	this->name = name;
}

//set the year (grade level) of the student
void Student::setYear(int year)
{
	//the year cannot be more than 4 or less than 0
	if (year > 4 || year < 0)
	{
		this->year = 3;
	}
	else
	{
		this->year = year;
	}
}

//set the major of the student
void Student::setMajor(const string &major)
{
	this->major = major;
}

//set the student's course
void Student::setCourse(const string &course)
{
	//number of letters in the string
	int numLetters = 0;
	//number of digits in the string
	int numDigits = 0;
	//does the string have special characters
	bool hasSpecial = true;
	//does the string have any spaces
	bool hasSpace = true;

	//loop through each character of the string
	for (auto c : course)
	{
		//check if the character is a digit
		//if it is increment numDigits
		if (isdigit(c)) { numDigits++; }

		//check if the character is a letter
		if (isalpha(c))
		{
			//if it is check if it is uppercase
			//if it is increment numLetters
			if (isupper(c)) { numLetters++; }
		}

		//check if the character is a special character
		if (!isalnum(c))
		{
			//if it is, set hasSpecial to true
			hasSpecial = true;
		}
		else
		{
			//else make it false
			hasSpecial = false;
		}

		//check if the character is a space
		if (isspace(c))
		{
			//if it is set hasSpace to true
			hasSpace = true;
		}
		else
		{
			//else make it false
			hasSpace = false;
		}
	}

	//check requirments
	if (numLetters == 2 && numDigits == 3 && hasSpecial == false && hasSpace == false)
	{
		//if requirements are met use the initializer input
		this->course = course;
	}
	else
	{
		//else use default value
		this->course = "CS245";
	}
}

void Student::setId(int ID)
{
	id = ID;
}

Student::~Student()
{
}

//Return a formatted string of the Student's information
string Student::display()
{
	//cout << right << setw(70) << "ID: " << getId();
	//cout << left << setw(70) << "Name: " << getName();
	//cout << right << setw(70) << "Year: " << getYear();
	//cout << left << setw(70) << "Course: " << getCourse();


	//constant references to data members
	const int &ID = id;
	const string &NAME = name;
	const int &YEAR = year;
	const string &COURSE = course;

	stringstream ss;

	//insert data members with formating into stringstream
	ss << left << setw(15) <<ID;
	ss << left << setw(25) << NAME;
	ss << right << setw(10) << YEAR;
	ss << right << setw(20) << COURSE << endl;

	//convert stringstream to string
	string output = ss.str();
	
	return output;
}