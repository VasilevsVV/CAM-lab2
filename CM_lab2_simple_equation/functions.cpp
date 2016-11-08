#include "functions.h"

double func(double x)
{
	return x*x*x - x + cos(x + M_PI / 4.0) - 1;
}

double phi_func(double x)
{
	return 0;
}

double deriv_func(double x)
{
	return 2 * x*x - 1 - sin(x + M_PI / 4.0);
}
