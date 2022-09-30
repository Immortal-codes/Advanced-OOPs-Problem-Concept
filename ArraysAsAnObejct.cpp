#include <iostream>
using namespace std;

int digitToInt(char c)
{
	return (static_cast<int>(c) - static_cast<int>('0'));
}

class Money
{
public:
	Money();
	Money(double dollars);
	Money(long dollars, int cents);

	friend Money operator +(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount1, const Money& amount2);
	friend bool operator ==(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount);
	friend Money operator ++(Money& amount);
	friend Money operator --(Money& amount);
	friend bool operator <(const Money& amount1, const Money& amount2);
	friend istream& operator >>(istream& ins, Money& amount);
	friend ostream& operator <<(ostream& outs, const Money& amount);

	double getAllCents() const;
	void setAllCents(long x);

private:
	long allCents;
};


// constructors
Money::Money(long dollars, int cents)
{
	if (dollars * cents < 0) //If one is negative and one is positive
	{
		cout << "Illegal values for dollars and cents.\n";
		exit(1);
	}
	allCents = dollars * 100 + cents;
}
Money::Money(double dollars) : allCents(dollars * 100)
{

}
Money::Money() : allCents(0)
{

}


// overloaded operators
Money operator +(const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.allCents = amount1.allCents + amount2.allCents;
	return temp;
}
Money operator -(const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.allCents = amount1.allCents - amount2.allCents;
	return temp;
}
bool operator ==(const Money& amount1, const Money& amount2)
{
	return (amount1.allCents == amount2.allCents);
}
Money operator -(const Money& amount)
{
	Money temp;
	temp.allCents = -amount.allCents;
	return temp;
}
Money operator ++(Money& amount)
{
	amount.allCents = amount.allCents + 100;
	return amount;
}
Money operator --(Money& amount)
{
	amount.allCents = amount.allCents - 100;
	return amount;
}
bool operator <(const Money& amount1, const Money& amount2)
{
	if (amount1.allCents < amount2.allCents)
		return true;
	else
		return false;
}
istream& operator >>(istream& ins, Money& amount)
{
	char oneChar, decimalPoint, digit1, digit2; //digits for the amount of cents
	long dollars;
	int cents;
	bool negative;//set to true if input is negative.
	ins >> oneChar;
	if (oneChar == '-')
	{
		negative = true;
		ins >> oneChar; //read '$'
	}
	else
		negative = false;
	//if input is legal, then oneChar == '$'
	ins >> dollars >> decimalPoint >> digit1 >> digit2;
	if (oneChar != '$' || decimalPoint != '.'
		|| !isdigit(digit1) || !isdigit(digit2))
	{
		cout << "Error illegal form for money input\n";
		exit(1);
	}
	cents = digitToInt(digit1) * 10 + digitToInt(digit2);
	amount.allCents = dollars * 100 + cents;
	if (negative)
		amount.allCents = -amount.allCents;
	return ins;
}
ostream& operator <<(ostream& outs, const Money& amount)
{
	long positiveCents, dollars, cents;
	positiveCents = labs(amount.allCents);
	dollars = positiveCents / 100;
	cents = positiveCents % 100;

	if (amount.allCents < 0)
		outs << "- $" << dollars << '.';
	else
		outs << "$" << dollars << '.';

	if (cents < 10)
		outs << '0';
	outs << cents;

	return outs;
}


// getters and setters
double Money::getAllCents() const
{
	return (allCents * 0.01);
}
void Money::setAllCents(long x)
{
	allCents = x;
}


int main()
{
	Money amount[5], max;   // default constructor

	cout << "Enter 5 amounts of money:" << endl;
	cin >> amount[0];
	max = amount[0];  // shallow copy

	for (int i = 1; i < 5; i++)
	{
		cin >> amount[i];
		if (max < amount[i])
			max = amount[i];
	}

	Money difference[5];
	for (int i = 0; i < 5; i++)
		difference[i] = max - amount[i];

	cout << "The highest amount is " << max << endl;
	cout << "The amounts and their differences from the largest are : " << endl;

	for (int i = 0; i < 5; i++)
		cout << amount[i] << " off by " << difference[i] << endl;

	return 0;
}