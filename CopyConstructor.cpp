#include <iostream>
#include<string>
#include <fstream>
using namespace std;


class Student 
{
public:
	Student();
	Student(string n, int i);
	Student(const Student& s);                    // 1. Copy Constructor
	~Student();                                   // 2. Destructor
	void operator =(const Student& rightSide);    // 3. Overloading Assignment Operator


	friend istream& operator >>(istream& ins, Student& s);
	friend ostream& operator <<(ostream& outs, const Student& s);


	string getName();
	int getID();
	int getGrades(int i);
	void setName(string n);
	void setID(int i);
	void setGrades(int index, int value);

private:
	string name;
	int id, *grades, gradesSize;
};


Student::Student()
{
	name = "";
	id = 0000;
	gradesSize = 0;
}
Student::Student(string n, int i)
{
	name = n;
	id = i;
	gradesSize = 0;
}
Student::Student(const Student& s) 
{
	name = s.name;
	id = s.id;

	gradesSize = s.gradesSize;
	grades = new int[gradesSize];
	for (int i = 0; i < gradesSize; i++)
		grades[i] = s.grades[i];
}
Student::~Student()
{
	delete[] grades;
}
void Student::operator =(const Student& rightSide)
{
	name = rightSide.name;
	id = rightSide.id;

	delete[] grades;

	gradesSize = rightSide.gradesSize;
	grades = new int[gradesSize];

	for (int i = 0; i < gradesSize; i++)
		grades[i] = rightSide.grades[i];
}


istream& operator >>(istream& ins, Student& s)
{
	string x;
	
	getline(ins, x);
	s.name = x;

	getline(ins, x);
	s.id = stoi(x);

	getline(ins, x);
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == ' ')  // check if current character is a space
			s.gradesSize++;  // if it is a space, increment grades count
	}

	s.grades = new int[s.gradesSize];
	int index=0;

	string m="";
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] != ' ')  // check if current character is a space
			m += x[i];
		else
		{
			s.grades[index++] = stoi(m);
			m = "";
		}	

		if (x[i] == '\n')
			s.grades[index] = stoi(m);
	}
	
	return ins;
}
ostream& operator <<(ostream& outs, const Student& s)
{
	outs << "Student name: " << s.name << endl;
	outs << "Student id: " << s.id << endl;
	outs << "Average Score: ";

	int sum = 0;
	for (int i = 0; i < s.gradesSize; i++)
		sum += s.grades[i];
		
	outs << static_cast<double>(sum) / s.gradesSize << endl << endl;

	return outs;
}


string Student::getName()
{
	return name;
}
int Student::getID()
{
	return id;
}
int Student::getGrades(int i)
{
	return grades[i];
}
void Student::setName(string n)
{
	name = n;
}
void Student::setID(int i)
{
	id = i;
}
void Student::setGrades(int index, int value)
{
	grades[index] = value;
}


int main()
{
	ifstream inStream("input.txt");

	Student s1;

	inStream >> s1;
	cout << s1;

	cout << "Testing the assignment operator:" << endl;
	Student s2 = s1;
	cout << s2;

	cout << "Testing the copy constructor" << endl;
	Student s3(s1);
	cout << s3;

	return 0;
}