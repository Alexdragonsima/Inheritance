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
		cout << "Harley Davidson едет на двех колесах" << endl;
	}
};
class Car :public GroundVehicle
{
public:
	void move()override
	{
		cout << "BMW едет на четырех колесах" << endl;
	}
};

class AirPlane :public AirVehicle
{
public:
	void move()override
	{
		take_of();
		cout << "Полет нормальный" << endl;
		land();
	}
	void take_of()override
	{
		cout << "Нужна взлетная полоса" << endl;
	}
	void land()override
	{
		cout << "Посадка" << endl;
	}
};
class Helicopter :public AirVehicle
{
public:
	void move()override
	{
		take_of();
		cout << "Летим потихоньку" << endl;
		land();
	}
	void take_of()override
	{
		cout << "Могу взлететь с любого огорода" << endl;
	}
	void land()override
	{
		cout << "Где хочку там и сяду" << endl;
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