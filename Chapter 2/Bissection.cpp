#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Bissection Method

double f(double x)
{
	return pow(x, 3) - 10 * sin(x) + 4.4;
}

int main()
{
	double a = 1.5;
	double b = 7;
	double m = (a + b) / 2;

	for (unsigned int i = 0; i < 2; i++)
	{
		if (f(a)*f(m) < 0)
			b = m;
		else
			a = m;
		m = (a + b) / 2;
	}

	cout << "A: " << a << endl << "B: " << b << endl;

	system("pause");
	return 0;
}