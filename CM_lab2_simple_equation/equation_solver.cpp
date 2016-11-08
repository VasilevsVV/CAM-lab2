# include "equation_solver.h"

double max(double a, double b)
{
	if (a >= b)
		return a;
	else
		return b;
}

double min(double a, double b)
{
	if (a <= b)
		return a;
	else
		return b;
}

double eq_solver::get_lambda(double a, double b, d_func deriv_func)
{
	double f_a = deriv_func(a),
		f_b = deriv_func(b);
	double max = (f_a > f_b) ? f_a : f_b;
	return 1 / max;
}

result eq_solver::iteration(double eps, double a, double b, d_func func, d_func deriv_func)
{
	double lambda = get_lambda(a, b, deriv_func);
	d_func phi_func;
	if (deriv_func((a + b) / 2.0) > 0)
		phi_func = [lambda, func](double x)
	{return x - lambda * func(x); };
	else
	phi_func = [lambda, func](double x)
		{return x - lambda * (-func(x));};
	int steps = 0;
	double fd_a = abs(deriv_func(a)),
		fd_b = abs(deriv_func(b));
	double q = 1 - min(fd_a, fd_b) / max(fd_a, fd_b);
	double xk, x0 = a;
	xk = phi_func(x0);
	while (abs(xk - x0) > (1 - q) / q * eps)
	{
		x0 = xk;
		xk = phi_func(x0);
		steps++;
	}
	result res;
	res.accuracy = q * abs(xk - x0) / (1 - q);
	res.value = xk;
	res.steps = steps;
	return res;
}

result eq_solver::bisection(double eps, double a, double b, d_func func)
{
	double c;
	int steps = 0;
	while ((b - a) >= eps * 2)
	{
		c = (b + a) / 2;
		if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
		steps++;
	}
	result res;
	res.value = (b + a) / 2.0;
	res.steps = steps;
	res.accuracy = (b - a) / 2.0;
	return res;
}