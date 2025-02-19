#ifndef __KWAD_H__
#define __KWAD_H__

//////////////////////////////////////////////////////////////////
// oblicza metoda trapezow calke funkcji pf w przedziale <a,b> 
// w oparciu o n punktow (n >= 2)
//////////////////////////////////////////////////////////////////
double trapez(double a, double b, double (*pf)(double), int n);

//////////////////////////////////////////////////////////////////
// oblicza metoda simpsona calke funkcji pf w przedziale <a,b> 
// w oparciu o n punktow (n >= 2)
//////////////////////////////////////////////////////////////////
double simpson(double a, double b, double (*pf)(double), int n);

double gauss(double a, double b, double (*pf)(double));

#endif // __KWAD_H__