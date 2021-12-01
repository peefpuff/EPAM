#include "currency.h"

currency::currency(std::string str, double rate, double val) : name(str), toUSD(rate), amount(val)
{
}

currency currency::operator+(currency cur)
{
	return currency("USD", 1, amount * toUSD + cur.amount * cur.toUSD);
}

currency currency::operator+(double val)
{
	return currency(name, toUSD, amount + val);
}

std::string currency::print()
{
	return std::string("Currency: " + name + " amount: " + std::to_string(amount) + " exchange rate: " + std::to_string(toUSD));
}
