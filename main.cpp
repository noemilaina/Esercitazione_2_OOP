#include <iostream>
#include "complex.hpp"

using namespace std;

int main(void)
{
	using comp = ComplexNumber<double>>;
	
	comp r1(2.3, -4.5);
	cout << "Visualizza numero: \n" <<r1<< "\n" << endl;
	
	comp r2 = conjugate(r1);
	cout << "Visualizza il coniugato: \n" << r2 << "\n" endl;
	
	comp r3(1.7, 1.2);
	cout "La somma vale: \n" << r2+r1 << endl;
	cout << r2 + r3 << endl;
	r1 += r3;
	cout << r1 << endl;
	cout << r1 + 3.4 << endl;
	cout << "Il prodotto vale: \n" << endl;
	r1 *= r3;
	cout <<r1<<endl;
	r2 = r1 * 0.4;
	cout << r2 * 0.4 << endl;
	cout << 2.5 *r2 << endl;
	
	return 0;
}