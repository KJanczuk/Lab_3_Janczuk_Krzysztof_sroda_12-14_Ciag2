#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "winbgi2.h"
#include "kwad.h"

double f1(double x); // prototyp funkcji 1/x^2
double f2(double x); // prototyp funkcji 1/x

void main()
{
	double a, b, cn_t, cn_s,cn_g, ca_1, ca_2 , err_t, err_s,err_g;
	int *n, m;

	FILE* f = fopen("Calkowanie_wyniki.txt", "w");

	printf("Podaj parametr m\n");
	scanf("%d", &m);

	n = (int*)malloc(m * sizeof(int));

	printf("Podaj przedzial:\n");
	scanf("%lf %lf", &a, &b);

	ca_1 = -1. / b + 1. / a; // wartoœæ analityczna ca³ki funkcji 1/x^2
	ca_2 = log(b) - log(a); // wartoœæ analityczna ca³ki funkcji 1/x

	cn_g = gauss(a, b, f2); // wartoœæ uzyskana metod¹ gaussa
	err_g = fabs(cn_g - ca_2);

	fprintf(f, "Calka analityczna: %lf\n\nMetoda Gaussa: %lf\nBlad met. Gaussa: %lf\n\n",ca_2,cn_g,err_g);
	fprintf(f, "n\tMetoda trapezow\tBlad met. trapezow\tMetoda Simpsona\tBlad met. Simpsona\n");
	for (int i = 0; i < m; i++)
	{
		n[i] = pow(2., i+1);

		cn_t = trapez(a, b, f2, n[i]);
		err_t = fabs(cn_t - ca_2);

		cn_s = simpson(a, b, f2, n[i]);
		err_s = fabs(cn_s - ca_2);

		fprintf(f,"%d\t%lf\t%lf\t%lf\t%lf\n", n[i],cn_t,err_t,cn_s,err_s);
	}


	free(n);
	fclose(f);
}

double f1(double x)
{
	return 1. / (pow(x, 2));
}

double f2(double x)
{
	return 1. / x;
}