#include "TVector.h"
#include <math.h>
#include <iostream>

bool TVector::perp(const TVector& vec)
{
	double sum = 0;

	if (len != vec.len)
	{
		return false;
	} 
	else 
	{
		for (size_t i = 0; i < len; i++)
		{
			sum += arr[i] * vec.arr[i];
		}
		return sum == 0;
	}
	
}

bool TVector::parall(const TVector& vec)
{
	bool b = true;
	if (len != vec.len)
	{
		return false;
	}
	if (len == 1 && vec.len == 1)
	{
		return true;
	}
	else
	{
		for (size_t i = 1; i < len; i++)
		{
			b = b && (( arr[i-1] / vec.arr[i-1] ) == (arr[i] / vec.arr[i]));
		}
		return b;
	}
}

double TVector::length()
{
	double sum = 0;
	for (size_t i = 0; i < len; i++)
	{
		sum += arr[i] * arr[i];
	}
	return sqrt(sum);
}

std::ostream& operator << (std::ostream& out, const TVector& v)
{
	for (size_t i = 0; i < v.len; i++)
	{
		out << v.arr[i] << " ";
	}
	return out;
}

std::istream& operator >> (std::istream& in, TVector& v)
{
	for (size_t i = 0; i < v.len; i++)
	{
		in >> v[i];
	}
	return in;
}