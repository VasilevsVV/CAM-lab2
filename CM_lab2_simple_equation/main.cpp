#include "equation_solver.h"
#include "functions.h"
#include "tests.h"

void main()
{
	/*cout << eq_solver::iteration(1e-15, -2, 0, func, deriv_func).value << endl;
	cout << eq_solver::bisection(1e-15, -2, 0, func).value << endl;*/
	test_iteration(0, 2);
	test_bisection(0, 2);
	test_speed(0, 2);
}
