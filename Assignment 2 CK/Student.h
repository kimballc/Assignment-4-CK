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
	Student(int, const string &, int, const string &, const string &);
	~Student();
	//Getters
	string getName() { return name; }
	int getYear() { return year; }
	string getMajor() { return major; }
	string getCourse() { return course; }
	int getId() { return id; }
	//Setters
	void setName(const string &);
	void setYear(int);
	void setMajor(const string &);
	void setCourse(const string &);
	void setId(int);
	//return formatted string
	string display();
private:
	int id;
	string name;
	int year;
	string major;
	string course;
};

#endif // !STUDENT_H