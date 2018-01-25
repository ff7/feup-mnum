#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// MNUM - Exame 2012/13 - Epoca Normal

// Pergunta	1

double fy(double t, double z)
{
	return z;
}

double fz(double t, double z)
{
	return 0.5 + pow(t, 2) + t * z;
}

void euler()
{
	double h = 0.25;
	double t = 0;
	double y = 0;
	double z = 1;

	cout << "Iteracao 0: " << endl << "T: " << t << endl << "Y: " << y << endl << endl;

	for (unsigned int i = 0; i < 2; i++)
	{
		y = y + h * fy(t, z);
		z = z + h * fz(t, z);

		t = t + h;

		cout << "Iteracao "<<i+1<<": " << endl << "T: " << t << endl << "Y: " << y << endl << endl;
	}
}

void rk4()
{
	double h = 0.25;
	double t = 0;
	double y = 0;
	double z = 1;

	double dy1, dy2, dy3, dy4;
	double dz1, dz2, dz3, dz4;

	cout << "Iteracao 0: " << endl << "T: " << t << endl << "Y: " << y << endl << endl;

	for (unsigned int i = 0; i < 2; i++)
	{
		dy1 = h * fy(t, z);
		dz1 = h * fz(t, z);

		dy2 = h * fy(t + h/2, z + dz1/2);
		dz2 = h * fz(t + h/2, z + dz1/2);

		dy3 = h * fy(t + h/2, z + dz2/2);
		dz3 = h * fz(t + h/2, z + dz2/2);

		dy4 = h * fy(t + h, z + dz3);
		dz4 = h * fz(t + h, z + dz3);

		y = y + dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		z = z + dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;

		t = t + h;

		cout << "Iteracao " << i + 1 << ": " << endl << "T: " << t << endl << "Y: " << y << endl << endl;
	}
}

// Pergunta 3

double f2(double x, double y)
{
	return 3 * x*x - x * y + 11 * y + y * y - 8*x;
}

double dx(double x, double y)
{
	return 6 * x - y - 8;
}

double dy(double x, double y)
{
	return -x + 11 + 2 * y;
}
void gradiente()
{
	double x = 2;
	double y = 2;
	double h = 0.5;

	double xc;
	double yc;

	cout << "Iteracao 0: " << endl << "X: " << x << endl << "Y: " << y << endl << "F: " << f2(x, y) << endl << endl;

	for (unsigned int i = 0; i < 1; i++)
	{
		xc = x - h * dx(x, y);
		yc = y - h * dy(x, y);

		cout << "Iteracao " << i + 1 << ": " << endl << "X: " << xc << endl << "Y: " << yc << endl <<"F: " << f2(xc,yc) << endl << endl;
	}

}

// Pergunta 4

double f3(double x)
{
	return exp(1.5*x);
}

void trap(double h)
{
	double a = 1;
	double b = 1.5;
	double n = (b - a) / h;
	double st = 0;

	for (unsigned int i = 1; i < n; i++)
	{
		st += f3(a + h * i) * 2;
	}
	st += f3(a) + f3(b);
	st = st * h / 2;

	cout << "Trap: O valor do integral usando um step de " << h << " corresponde a: " << st << endl << endl;
}

double simpson(double h)
{
	double a = 1;
	double b = 1.5;
	double n = (b - a) / h;
	double ss = 0;

	for (unsigned int i = 1; i < n; i++)
	{
		if (i % 2 == 0)
		{
			ss += f3(a + h * i) * 2;
		}
		else
		{
			ss += f3(a + h * i) * 4;
		}
	}

	ss += f3(a) + f3(b);
	ss = ss * h / 3;

	//cout << "Simpson: O valor do integral usando um step de " << h << " corresponde a: " << ss << endl << endl;

	return ss;
}

void qc()
{
	double qc;
	qc = (simpson(0.125 / 2) - simpson(0.125)) / (simpson(0.125 / 4) - simpson(0.125 / 2));

	cout << "O quociente de convergencia usando a regra de Simpson e: " << qc << endl << endl;
}

void erro_rel()
{
	double erro;
	erro = (simpson(0.125 / 4) - simpson(0.125 / 2));
	erro = erro / 3;

	cout << "O erro relativo usando a regra de Simpson e: " << erro << endl << endl;
}


void pergunta4()
{
	//trap(0.125);
	//simpson(0.125);
	//simpson(0.125 / 2);
	//simpson(0.125 / 4);
	qc();
	erro_rel();
}

// Pergunta 5

double f5(double x)
{
	return (x - 3.7) + pow((cos(x + 1.2)), 3);
}

double df5(double x)
{
	return 1 - 3 * pow(cos(x + 1.2), 2)*sin(x + 1.2);
}

void newton()
{
	double x = 3.8;

	x = x - f5(x) / df5(x);
	cout << "Newton: O valor de x e: " << x << endl;
}


//--------------------------------------------------------------------------------------------

int main()
{
	cout.precision(7);
	//euler();
	//rk4();
	//gradiente();
	//pergunta4();
	newton();
	system("pause");
	return 0;
}