#include "stdafx.h"
#include "DataManager.h"

//constructor
DataManager::DataManager(const string & file)
{
	//read the data file
	filePath = file;
	readDataFile(filePath);
}

//destructor
DataManager::~DataManager()
{
	//write to output file on close
	writeDataFile("output.txt");
}

//search the students vector for a unique student
Student* DataManager::findStudent(const int &idNum)
{
		/*auto it = find_if(students.begin(), students.end(), [idNum](Student &s)->bool {return s.getId() == idNum; });
		if (it == students.end()) 
		{
			return nullptr;
		}
		else
		{
			return it;
		}*/

	//loop through the vector
	for (Student s : students) 
	{
		//compare the id passed as parameter to the current student's id
		if (s.getId() == idNum)
		{
			//return a pointer to the found student if it was found
			return &s;
		}
	}

	//no student was found return a null pointer
	return nullptr;
}

//calls the find function to add a unique student
void DataManager::addStudent(Student s)
{
	/*students.push_back(findStudent(s.getId()));
	if (findStudent(s.getId()) == nullptr)
	{
		students.push_back(s);
	}
	else
	{
		cout << "Student already exists" << endl;
	}*/

	//check if the the student to be added already exists
	if (findStudent(s.getId()) == nullptr)
	{
		//if it does not exist add it
		students.push_back(s);
	}
	else
	{
		//already exists
		cout << "Already exists" << endl;
	}
}

//formatted display of all students
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


//splits a string separated by a certain character and stores each field in a vector
vector<string> DataManager::splitString(const string &text, char sep)
{
	string field;
	vector<string> fields;

	//string to split
	istringstream inputStr(text);

	//get the fields from the input string
	while (getline(inputStr, field, sep))
	{
		//add it to the vector
		fields.push_back(field);
	}
	return fields;
}

//read data file and convert data to Student objects
void DataManager::readDataFile(const string &file)
{
	string line;
	//input file
	ifstream input(file);
	vector<string> fields;
	
	//check to see if the file opens
	if (input.fail())
	{
		cout << "File not found. Exiting..." << endl;
		return;
	}

	//loop through the file until its end of file character
	while (!input.eof())
	{
		//get the current line of the file
		getline(input, line);
		//split it by tabs
		fields = splitString(line, '\t');

		if (fields.size() == 5)
		{
			//get the fields for the Student object
			Student s;
			s.setId(stoi(fields[0]));
			s.setName(fields[1]);
			s.setYear(stoi(fields[2]));
			s.setMajor(fields[3]);
			s.setCourse(fields[4]);

			//add the student
			addStudent(s);
		}
	}
	//close the file
	input.close();
}

//write the data included any added students to a new file
void DataManager::writeDataFile(const string &text)
{
	//output file
	ofstream output;
	output.open(text);
	stringstream ss;
	
	for (auto &s : students)
	{
		ss << s.getId() << '\t' << s.getName() << '\t' << s.getYear() << '\t' << s.getCourse() << endl;
	}
	output << ss.str();

	output.close();
	/*output << "HI\n";
	output.close();*/
}