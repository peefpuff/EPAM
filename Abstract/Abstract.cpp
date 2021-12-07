#include "Abstract.h"

// 1

Shop::Shop()
{
	cout << "Shop constructor" << endl;
}

Shop::~Shop()
{	 
	cout << "Shop destructor" << endl << endl;	 
}

// 2
//
// Food

Food::Food() 
{ 
	cout << "Food constructor" << endl;
}

Food::~Food()
{ 
	cout << "Food destructor" << endl; 
}

void Food::setData()
{
	totalSquare = 2750;
	name = "Horns&Hooves";
}

void Food::getData()
{
	cout << "---------------Food Shops---------------" << endl;
	cout << "Shops name: " << name << endl;
	cout << "Total square: " << totalSquare << " m2" << endl << endl;
}

// Industrial

Industrial::Industrial()
{ 
	cout << "Indusrtial constructor" << endl; 
}

Industrial::~Industrial()
{ 
	cout << "Indusrtial desstructor" << endl; 
}

void Industrial::setData()
{
	totalProviders = 137;
	name = "Bobr&Co";
}

void Industrial::getData()
{
	cout << "---------------industrial Shops---------------" << endl;
	cout << "Shops name: " << name << endl;
	cout << "Total providers: " << totalProviders << endl << endl;
}

// 3
//
// Food
// Supermarket

Supermarket::Supermarket()
{ 
	cout << "Supermarket constructor" << endl;	 
}

Supermarket::~Supermarket()
{	 
	cout << "Supermarket destructor" << endl; 
}

void Supermarket::setFoodData()
{
	supermarketSquare = 900;
	rentPrice = 3600;
}

void Supermarket::getFoodData()
{
	Food::getData();
	cout << "Supermarket \"" << name << "\"" << endl;
	cout << "Square: " << supermarketSquare << " m2" << endl;
	cout << "Rent price: " << rentPrice << " $" << endl;
}

void Supermarket::averageRentCost()
{
	cout << "Rent cost per m2: " << static_cast<double>(rentPrice) / supermarketSquare << " $" << endl;
	cout << "----------------------------------------" << endl;
}

// Universam

Universam::Universam()
{	 
	cout << "Universam constructor" << endl;	 
}

Universam::~Universam()
{	 
	cout << "Universam destructor" << endl;	 
}

void Universam::setFoodData()
{
	universamSquare = 400;
	rentPrice = 1300;
}

void Universam::getFoodData()
{
	Food::getData();
	cout << "Universam \"" << name << "\"" << endl;
	cout << "Square: " << universamSquare << " m2" << endl;
	cout << "Rent price: " << rentPrice << " $" << endl;
}

void Universam::averageRentCost()
{
	cout << "Rent cost per m2: " << static_cast<double>(rentPrice) / universamSquare << " $" << endl;
	cout << "----------------------------------------" << endl;
}

// Industrial
// Hardware Store

HardwareStore::HardwareStore()
{	 
	cout << "Hardware constructor" << endl;	 
}

HardwareStore::~HardwareStore()
{	 
	cout << "Hardware destructor" << endl;	 
}

void HardwareStore::setIndustrialData()
{
	localProviders = 54;
	regionalProviders = 31;
}

void HardwareStore::getIndustrialData()
{
	Industrial::getData();
	cout << "Hardware Store \"" << name << "\"" << endl;
	cout << "Local providers: " << localProviders << endl;
	cout << "Regional providers: " << regionalProviders << endl;
}

void HardwareStore::totalProviders()
{
	cout << "Total providers: " << regionalProviders + localProviders << endl;
	cout << "----------------------------------------" << endl;
}

// Chemical Store

ChemicalStore::ChemicalStore()
{	 
	cout << "Chemical constructor" << endl;	 
}

ChemicalStore::~ChemicalStore()
{	 
	cout << "Chemical destructor" << endl;	 
}

void ChemicalStore::setIndustrialData()
{
	localProviders = 38;
	regionalProviders = 14;
}

void ChemicalStore::getIndustrialData()
{
	Industrial::getData();
	cout << "Chemical Store \"" << name << "\"" << endl;
	cout << "Local providers: " << localProviders << endl;
	cout << "Regional providers: " << regionalProviders << endl;
}

void ChemicalStore::totalProviders()
{
	cout << "Total providers: " << regionalProviders + localProviders << endl;
	cout << "----------------------------------------" << endl;
}