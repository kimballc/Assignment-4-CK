#ifndef DATA_MANGER_H
#define DATA_MANAGER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include "Student.h"

using namespace std;

class DataManager
{
public:
	DataManager(const string &);
	~DataManager();

	//functions
	Student* findStudent(const int &);
	void addStudent(Student);
	void display();
private:
	string filePath;
	vector<Student> students;
	
	//functions
	vector<string> splitString(const string &, char);
	void readDataFile(const string &);
	void writeDataFile(const string &);
};

#endif // !DATA_MANGER_H