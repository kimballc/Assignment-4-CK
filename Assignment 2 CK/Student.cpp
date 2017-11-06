#include "stdafx.h"
#include "Student.h"

//Default Constructor
Student::Student()
{
	name = "Bob Smith";
	year = 3;
	major = "Computer Science";
	course = "CS245";
}

//Initializer Constructor
Student::Student(const string &name, int year, const string &major, const string &course) :
	name(name), year(year), major(major), course(course) {}

//set the name of the student 
void Student::setName(const string &name)
{
	this->name = name;
}

//set the year (grade level) of the student
void Student::setYear(int year) 
{
	//the year cannot be more than 4 or less than 0
	if(year > 4 || year < 0)
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
		if(!isalnum(c))
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
		if(isspace(c))
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

Student::~Student()
{
}

string Student::display()
{

}