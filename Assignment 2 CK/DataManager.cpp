#include "stdafx.h"
#include "DataManager.h"

DataManager::DataManager(const string & file)
{
	filePath = file;
	readDataFile(filePath);
}


DataManager::~DataManager()
{
	writeDataFile("output.txt");
}

Student* DataManager::findStudent(const int &idNum)
{
		//auto it = find_if(students.begin(), students.end(), [idNum](Student &s)->bool {return s.getId() == idNum; });
		//if (it == students.end()) 
		//{
		//	return nullptr;
		//}
		//else
		//{
		//	return it;
		//}
	for (Student s : students) 
	{
		if (s.getId() == idNum)
		{
			return &s;
		}
	}
	return nullptr;
}

void DataManager::addStudent(Student s)
{
	//students.push_back(findStudent(s.getId()));
	/*if (findStudent(s.getId()) == nullptr)
	{
		students.push_back(s);
	}
	else
	{
		cout << "Student already exists" << endl;
	}*/
	if (findStudent(s.getId()) == nullptr)
	{
		students.push_back(s);
	}
	else
	{
		cout << "Already exists" << endl;
	}
}

void DataManager::display()
{
	cout << left << setw(15) << "Student ID";
	cout << left << setw(25) << "Name";
	cout << right << setw(10) << "Year";
	cout << right << setw(20) << "Coures" << endl;
	string s(70, '-');
	cout << s << endl;

	for (auto &s : students)
	{
		cout << s.display();
	}

}



vector<string> DataManager::splitString(const string &text, char sep)
{
	string field;
	vector<string> fields;

	istringstream inputStr(text);

	while (getline(inputStr, field, sep))
	{
		fields.push_back(field);
	}
	return fields;
}

void DataManager::readDataFile(const string &file)
{
	string line;
	ifstream input(file);
	vector<string> fields;
	
	if (input.fail())
	{
		cout << "File not found. Exiting..." << endl;
		return;
	}

	while (!input.eof())
	{
		getline(input, line);
		fields = splitString(line, '\t');

		if (fields.size() == 5)
		{
			Student s;
			s.setId(stoi(fields[0]));
			s.setName(fields[1]);
			s.setYear(stoi(fields[2]));
			s.setMajor(fields[3]);
			s.setCourse(fields[4]);

			addStudent(s);
		}
	}
	input.close();
}

void DataManager::writeDataFile(const string &text)
{
	ofstream output;
	output.open(text);
	stringstream ss;
	
	for (auto &s : students)
	{
		ss << s.getId() << '\t' << s.getName() << '\t' << s.getYear() << '\t' << s.getCourse() << endl;
	}
	output << ss.str();

	output.close();
	//output << "HI\n";
	//output.close();
}