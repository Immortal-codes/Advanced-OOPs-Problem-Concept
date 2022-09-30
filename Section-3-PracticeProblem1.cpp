#include <iostream>
using namespace std;

class Array { // Class declaration
public:
	Array(); 
	// default constructor
	
	Array(int x); 
	//Initialize the array with 0 values
	
	Array(const Array&); 
	// copy constructor
	
	~Array(); 
	//destructor
	
	bool setValue(int index, int value); 
	// assign a value to an array element
	
	bool getValue(int index, int& value); 
	// get an array element

	int getSize();
	// return the size of the array.
	
	Array& increment(); 
	// cascade function to increment each array element by 1 
	
	void print() const; 
	// print each element of the array
	
	Array& Add(const Array ar);
	//casade function to add all elements of arr to all elements of the 
	// “this” array (element by element) and return a reference to the resulting array 
	
	bool Equal(const Array* ar)const;
	// return true if all elements in both arrays are equal, false otherwise.
		
	Array& removeAt(int index);
	//cascade function to remove element at the index.( if index is within the valide 
	//range, you should allocate new memory with 1 element less, copy all elements but 
	//the element at index to new memory, delete the old one)
		
	Array& insertAt(int index, int value);
	// insert value at index location, if index is greater than the size, then insert 
	// the element at the end of the array, if index is < 0 then insert the element at 
	// the beggining of the array, otherwise, insert in the exact index(you should 
	// allocate new memory, copy element etc…)

private:
	int size; // size of created array
	int* arr;
};

Array::Array() 
{

}

Array::Array(int x) 
{

}

Array::Array(const Array& a) // Copy Constructor
{

}

Array::~Array() //Initialize the array with 0 values
{

}

bool Array::setValue(int index, int value)
{

}

bool Array::getValue(int index, int& value)
{

}

Array& Array::increment()
{

}

int Array::getSize()
{

}

void Array::print() const
{

}

Array& Array::Add(const Array ar)
{

}

bool Array::Equal(const Array* ar)const
{

}

Array& Array::removeAt(int index)
{

}

Array& Array::insertAt(int index, int value)
{

}

int main()
{
	Array A;
	cout << "Please Enter " << A.getSize() << " elements for A1 :";
	int x;
	for (int i = 0; i < A.getSize(); i++)
	{
		cin >> x;
		A.setValue(i, x);
	}
	Array B(5);
	cout << "Please Enter " << B.getSize() << " elements for B : ";
	for (int i = 0; i < B.getSize(); i++)
	{
		cin >> x;
		B.setValue(i, x);
	}
	cout << "Testing copy constrcutor : Array X(A); D = ";
	Array X(A);
	X.print();
	cout << endl;
	cout << "I am printing A using getValue assuming that I don't know the size,\nA = ";
	int i = 0;
	while (A.getValue(i, x))
	{
		cout << x << " ";
		i++;
	}
	cout << "\nArray C = A.increment(), printing (using A.print()) A and C after the" 
		<<"function call\nA = ";
		Array C(A.increment());
	A.print();
	cout << "\nC = ";
	C.print();
	cout << "\nA.Equal(C) = " << A.Equal(&C) << endl;
	cout << "A.Equal(B) = " << A.Equal(&B) << endl;
	cout << "Array D = A.Add(B) = ";
	Array D = A.Add(B);
	D.print();
	cout << "\nA is ";
	A.print();
	cout << "\nB is ";
	B.print();
	cout << endl;
	cout << "Inserting 99 at index 99999 in A, the result is :\n";
	A.insertAt(99999, 99);
	A.print();
	cout << endl;
	cout << "Inserting -99 at index -99999 in A, the result is :\n";
	A.insertAt(-99999, -99);
	A.print();
	cout << endl;
	cout << "Inserting 7 at index 3 in A, the result is :\n";
	A.insertAt(3, 7);
	A.print();
	cout << endl;
	cout << "Deleting the element at index 2 from A, the result is :\n";
	A.removeAt(2);
	A.print();
	cout << endl;
}