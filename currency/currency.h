#pragma once
#include <string>
class currency
{
public:
	currency(std::string str, double rate, double val);
	~currency() {};
	currency operator+ (currency cur);
	currency operator+ (double val);
	std::string print();

private:
	double amount;
	double toUSD;
	std::string name;

};

