#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using std::string;

class Student
{
public:
	//Default Constructor
	Student();
	//Initializer Constructor
	Student(const string &, int, const string &, const string &);
	~Student();
	//Getters
	string getName() { return name; }
	int getYear() { return year; }
	string getMajor() { return major; }
	string getCourse() { return course; }
	//Setters
	void setName(const string &);
	void setYear(int);
	void setMajor(const string &);
	void setCourse(const string &);
	//return formatted string
	string display();
private:
	string name;
	int year;
	string major;
	string course;
};

#endif // !STUDENT_H