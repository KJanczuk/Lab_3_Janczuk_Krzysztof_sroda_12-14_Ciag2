#include <math.h>

// oblicza calke metoda trapezow
double trapez(double a, double b, double (*pf)(double), int n)
{
	double h = (b - a) / (n - 1);
	double suma = 0.5 * (pf(a) + pf(b));
	double x = a;

	for (int i = 1; i < n - 1; i++)
	{
		x += h;
		suma += pf(x);
	}
	return suma * h;
}


// oblicza calke metoda simpsona
double simpson(double a, double b, double (*pf)(double), int n)
{
	double  x = a;
	int     nc = abs((n - 2) / 2 + 1) * 2 + 1;  // poprawione n tak by bylo nieparzyste i >= n_old
	double  h = (b - a) / (nc - 1);
	double  h2 = h * 2;
	double  suma = pf(a) + 4. * pf(a + h) + pf(b);

	for (int i = 3; i < nc; i += 2)
	{
		x += h2;
		suma += 2. * pf(x) + 4. * pf(x + h);
	}
	return suma * h / 3.;
}

// oblicza calke metoda gaussa
double gauss(double a, double b, double (*pf)(double))
{
	double x[5], w[5];

	x[0] = -0.9061798459386639927976269;
	x[1] = -0.5384693101056830910363144;
	x[2] = 0.0;
	x[3] = 0.5384693101056830910363144;
	x[4] = 0.9061798459386639927976269;

	w[0] = 0.2369268850561890875142640;
	w[1] = 0.4786286704993664680412915;
	w[2] = 0.5688888888888888888888889;
	w[3] = 0.4786286704993664680412915;
	w[4] = 0.2369268850561890875142640;

	double I = 0;

	for (int i = 0; i < 5; i++)
	{
		I += w[i] * pf(0.5 * a * (1 - x[i]) + 0.5 * b * (1 + x[i]));
	}

	return 0.5 * (b - a) * I;
}

