#pragma once
#ifndef POLY_H_
#define POLY_H_

class Poly_4 
{
	private:
		float mem_0,
			  mem_1,
			  mem_2,
			  mem_3;

	public:

		Poly_4();
		Poly_4(float a, float b, float c, float d);
		Poly_4(const Poly_4 &P);

		float getMem_0() { return mem_0; }
		float getMem_1() { return mem_1; }
		float getMem_2() { return mem_2; }
		float getMem_3() { return mem_3; }

		void setMem_0(float m) { mem_0 = m; }
		void setMem_1(float m) { mem_1 = m; }
		void setMem_2(float m) { mem_2 = m; }
		void setMem_3(float m) { mem_3 = m; }

		float count(float x);

		bool operator == (Poly_4 P);
		void operator += (float n);
		void operator -= (float n);
};

void output_Poly(Poly_4 P);

#endif