#include "Abstract.h"

int main()
{
	Supermarket super;
	super.setData();
	super.setFoodData();
	super.getFoodData();
	super.averageRentCost();

	Universam uni;
	uni.setData();
	uni.setFoodData();
	uni.getFoodData();
	uni.averageRentCost();

	HardwareStore hard;
	hard.setData();
	hard.setIndustrialData();
	hard.getIndustrialData();
	hard.totalProviders();

	ChemicalStore chem;
	chem.setData();
	chem.setIndustrialData();
	chem.getIndustrialData();
	chem.totalProviders();

	return 0;
}