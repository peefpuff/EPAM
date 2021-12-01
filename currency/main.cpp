// задание на перегрузку operator+
#include <iostream>
#include "currency.h"

using std::cout;
using std::endl;

int main()
{
	currency usd("USD", 1, 518);
	currency usd2 = usd + 112;
	currency byn("BYN", 2.5, 1250);
	currency sum = byn + usd2;
	currency pln("PLN", 0.24, 15000);

	cout << "Simple USD - " << usd.print() << endl;
	cout << "Simple USD + val - " << usd2.print() << endl;
	cout << "Simple BYN - " << byn.print() << endl;
	cout << "Simple PLN - " << pln.print() << endl;
	cout << "USD + PLN - " << (usd + pln).print() << endl;
	cout << "BYN + USD - " << (usd+byn).print() << endl;

	return 0;
}