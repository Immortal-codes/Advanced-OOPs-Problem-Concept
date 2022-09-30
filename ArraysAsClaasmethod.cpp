#include <iostream>
using namespace std;

const int SUBJECTS = 3;

class Student {

public:
	Student();
	Student(string n, int i);

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
	int id, grades[SUBJECTS];
};


Student::Student()
{
	name = "";
	id = 0000;
	for (int i = 0; i < SUBJECTS; i++)
		grades[i] = 0;
}
Student::Student(string n, int i)
{
	name = n;
	id = i;
}


istream& operator >>(istream& ins, Student& s)
{
	cout << "Enter student name: ";
	ins >> s.name;
	cout << "Enter student id: ";
	ins >> s.id;
	for (int i = 0; i < SUBJECTS; i++)
	{
		cout << "Enter student grade for subject " << i + 1 << ": ";
		ins >> s.grades[i];
	}

	return ins;
}
ostream& operator <<(ostream& outs, const Student& s)
{
	outs << "Student name: " << s.name << endl;
	outs << "Student id: " << s.id << endl;
	outs << "Average Score: ";

	int sum = 0;
	for (int i = 0; i < SUBJECTS; i++)
		sum += s.grades[i];
	outs << static_cast<double>(sum) / SUBJECTS << endl << endl;

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
	Student s1, s2;

	cout << endl << "For Student # 1" << endl;
	cin >> s1;

	cout << endl << "For Student # 2" << endl;
	cin >> s2;

	cout << endl << "---- Student Details ----" << endl;
	cout << endl << "For Student # 1" << endl << s1;
	cout << endl << "For Student # 2" << endl << s2;


	return 0;
}