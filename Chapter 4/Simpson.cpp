#include <iostream>
#include <cmath>

using namespace std;

// Simpson's Method

double f(double x)
{
	return exp(1.5 * x);
}

int main()
{
	double a = 1;
	double b = 1.5;
	double h = 0.125;
	double n = (b - a) / h;

	double ss = 0;

	for (unsigned int i = 1; i < n; i++)
	{
		if (i % 2 == 0)
			ss += f(a + i * h) * 2;
		else
			ss += f(a + i * h) * 4;
	}

	ss += f(a) + f(b);
	ss = ss * (h / 3);

	cout << "The value of L is: " << ss << endl;
	
	system("pause");
	return 0;
}