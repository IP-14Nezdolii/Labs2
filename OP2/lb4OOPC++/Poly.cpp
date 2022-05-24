
#include "Poly.h"
#include <iostream>

Poly_4::Poly_4()
{
	mem_0 = 1;
	mem_1 = 1;
	mem_2 = 1;
	mem_3 = 1;
}

Poly_4::Poly_4(float a, float b, float c, float d)
{
	mem_0 = a;
	mem_1 = b;
	mem_2 = c;
	mem_3 = d;
}

Poly_4::Poly_4(const Poly_4& P)
{
	mem_0 = P.mem_0;
	mem_1 = P.mem_1;
	mem_2 = P.mem_2;
	mem_3 = P.mem_3;
}

void output_Poly(Poly_4 P)
{
	std::cout << P.getMem_0() <<" + ("<< P.getMem_1() << "*x)" << " + (" << P.getMem_2() << "*(x^2))" <<" + ("<< P.getMem_3() << "*(x^3))" << "\n";
}

float Poly_4::count(float x)
{
	return mem_0 + mem_1*x + mem_2*x*x + mem_3*x*x*x;
}

bool Poly_4::operator == (Poly_4 P)
{
	if (mem_0 == P.mem_0 && mem_1 == P.mem_1 && mem_2 == P.mem_2 && mem_3 == P.mem_3)
	{
		return true;
	}
	else return false;

};

void Poly_4::operator += (float n)
{
	mem_0 += n;
	mem_1 += n;
	mem_2 += n;
	mem_3 += n;
}

void Poly_4::operator -= (float n)
{
	mem_0 -= n;
	mem_1 -= n;
	mem_2 -= n;
	mem_3 -= n;
}