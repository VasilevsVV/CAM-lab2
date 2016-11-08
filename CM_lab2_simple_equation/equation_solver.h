#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

typedef std::function<double(double)> d_func;
struct result
{
	double value;
	int steps;
	double accuracy;
};

double max(double a, double b);
double min(double a, double b);

class eq_solver
{
public:
	static result iteration(double, double, double, d_func, d_func);
	static result bisection(double, double, double, d_func);
private:
	static double get_lambda(double, double, d_func);
};