#include "tests.h"
#include <iomanip>
#include "functions.h"

void print_line(double eps, double n, double err)
{
	cout << setiosflags(ios::left);
	cout << setfill(' ') << setw(10) << eps << setw(17) << setprecision(12) << n << setw(10) << err << endl;
}

void print_line(double eps, int count_1, int count_2)
{
	cout << setiosflags(ios::left);
	cout << setfill(' ') << setw(8) << eps << setw(15) << count_1 << setw(15) << count_2 << endl;
}

void print_head(string s1, string s2, string s3, int t1, int t2, int t3)
{
	cout << setiosflags(ios::left);
	cout << setfill(' ') << setw(t1) << s1 << setw(t2) << s2 << setw(t3) << s3 << endl;
}

void test_iteration(double a, double b)
{
	cout << ":ITERATION > [" << a << ", " << b << "]" << endl;
	print_head("[eps]", "[value]", "[accuracy]", 10, 17, 10);
	double eps = 1e-2;
	result res;
	while (eps >= 1e-15)
	{
		res = eq_solver::iteration(eps, a, b, func, deriv_func);
		print_line(eps, res.value, res.accuracy);
		eps *= 1e-3;
	}
}

void test_bisection(double a, double b)
{
	cout << ":BSECTION > [" << a << ", " << b << "]" << endl;
	print_head("[eps]", "[value]", "[accuracy]", 10, 17, 10);
	double eps = 1e-2;
	result res;
	while (eps >= 1e-15)
	{
		res = eq_solver::bisection(eps, a, b, func);
		print_line(eps, res.value, res.accuracy);
		eps *= 1e-3;
	}
}

void test_speed(double a, double b)
{
	cout << "SPEED TEST > [" << a << ", " << b << "]" << endl;
	print_head("[eps]", "[iter steps]", "[bisect steps]", 8, 15, 15);
	double eps = 1e-2;
	result res_iter, res_bisect;
	while (eps >= 1e-15)
	{
		res_iter = eq_solver::iteration(eps, a, b, func, deriv_func);
		res_bisect = eq_solver::bisection(eps, a, b, func);
		print_line(eps, res_iter.steps, res_bisect.steps);
		eps *= 1e-3;
	}
}
