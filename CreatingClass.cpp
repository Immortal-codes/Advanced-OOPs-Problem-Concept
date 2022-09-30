#include <iostream>
#include <fstream>
using namespace std;

class Car
{
public:
    void move();
    void stop();

    double getMileage();
    int getWeight();

    void setMileage(double x);
    void setWeigth(int x);

    void outputDetails(ostream &out);

private:
    double mileage;
    int weight;
};

void Car::move()
{
    cout << "car is Moving" << endl;
}

void Car::stop()
{
    cout << "Car is Stopping" << endl;
}

double Car::getMileage()
{
    return mileage;
}

int Car::getWeight()
{
    return weight;
}

void Car::setMileage(double x)
{
    mileage = x;
}

void Car::setWeigth(int x)
{
    weight = x;
}

void Car::outputDetails(ostream &out)
{
    out << "Car Details: " << endl;
    out << "Mileage: " << getMileage() << endl;
    out << "Weight: " << getWeight() << endl;
}

int main()
{
    Car c1;
    c1.setMileage(900);
    c1.setWeigth(1000);
    c1.outputDetails(cout);

 ofstream outStream("output.txt");

    Car c2;
    c2.setMileage(700);
    c2.setWeigth(1000);
    c2.outputDetails(outStream);

    return 0;
}