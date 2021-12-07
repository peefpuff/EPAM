#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 1
class Shop
{
public:
	Shop();
	~Shop();

	virtual void setData() = 0;
	virtual void getData() = 0;
};

// 2
class Food : public Shop // foodShop
{
protected:
	int totalSquare;
	string name;

public:
	Food();
	//Food(int square, string n);
	~Food();

	virtual void setData() override;
	virtual void getData() override;
	virtual void setFoodData() = 0;
	virtual void getFoodData() = 0;
};

class Industrial : public Shop // industrialShop
{
protected:
	int totalProviders;
	string name;

public:
	Industrial();
	//Industrial(int providers, string n);
	~Industrial();

	virtual void setData() override;
	virtual void getData() override;
	virtual void setIndustrialData() = 0;
	virtual void getIndustrialData() = 0;
};

// 3
class Supermarket : public Food
{
private:
	int supermarketSquare;
	int rentPrice;

public:
	Supermarket();
	//Supermarket(int sq, int rent);
	~Supermarket();

	virtual void setFoodData() override;
	virtual void getFoodData() override;
	void averageRentCost();
};

class Universam : public Food
{
private:
	int universamSquare;
	int rentPrice;

public:
	Universam();
	//Universam(int sq, int rent);
	~Universam();

	virtual void setFoodData() override;
	virtual void getFoodData() override;
	void averageRentCost();
};

class HardwareStore : public Industrial
{
private:
	int localProviders;
	int regionalProviders;

public:
	HardwareStore();
	//HardwareStore(int local, int regional);
	~HardwareStore();

	virtual void setIndustrialData() override;
	virtual void getIndustrialData() override;
	void totalProviders();
};

class ChemicalStore : public Industrial
{
private:
	int localProviders;
	int regionalProviders;

public:
	ChemicalStore();
	//ChemicalStore(int local, int regional);
	~ChemicalStore();

	virtual void setIndustrialData() override;
	virtual void getIndustrialData() override;
	void totalProviders();
};