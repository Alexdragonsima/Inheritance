#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;
};

class GroundVehicle :public Vehicle {};
class AirVehicle:public Vehicle
{
public:
	virtual void take_of() = 0;
	virtual void land() = 0;
};

class Bike :public GroundVehicle
{
public:
	void move()override
	{
		cout << "Harley Davidson ���� �� ���� �������" << endl;
	}
};
class Car :public GroundVehicle
{
public:
	void move()override
	{
		cout << "BMW ���� �� ������� �������" << endl;
	}
};

class AirPlane :public AirVehicle
{
public:
	void move()override
	{
		take_of();
		cout << "����� ����������" << endl;
		land();
	}
	void take_of()override
	{
		cout << "����� �������� ������" << endl;
	}
	void land()override
	{
		cout << "�������" << endl;
	}
};
class Helicopter :public AirVehicle
{
public:
	void move()override
	{
		take_of();
		cout << "����� ����������" << endl;
		land();
	}
	void take_of()override
	{
		cout << "���� �������� � ������ �������" << endl;
	}
	void land()override
	{
		cout << "��� ����� ��� � ����" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle vehical;
	//GroundVehicle gv;
	Bike harley_davidson;
	harley_davidson.move();

	Car bmw;
	bmw.move();

	AirPlane boeng;
	boeng.move();

	Helicopter blackHawk;
	blackHawk.move();
}