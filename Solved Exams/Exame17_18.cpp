#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// MNUM - Exame 2017/18 - Epoca Normal

// Pergunta 2

double f(double x)
{
	return sqrt(1 + pow(2 * exp(2 * x), 2));
}

double trap(double h)
{
	double a = 0;
	double b = 1;
	double n = (b - a) / h;
	double st = 0;

	for (unsigned int i = 1; i < n; i++)
	{
		st += f(a + h * i) * 2;
	}

	st += f(a) + f(b);
	st = st * (h / 2);
	return st;
}

double simpson(double h)
{
	double a = 0;
	double b = 1;
	double n = (b - a) / h;
	double ss = 0;

	for (unsigned int i = 1; i < n; i++)
	{
		if (i%2 == 0)
			ss += f(a + h * i) * 2;
		else
			ss += f(a + h * i) * 4;
	}

	ss += f(a) + f(b);
	ss = ss * (h / 3);
	return ss;
}

void tabela()
{
	double h = 0.125;
	cout << "H: " << '\t' << h << '\t' << h << endl;
	cout << "H1: " << '\t' << h/2 << '\t' << h/2 << endl;
	cout << "H2: " << '\t' << h/4 << '\t' << h/4 << endl;
	cout << "I: " << '\t' << trap(h) << '\t' << simpson(h) << endl;
	cout << "I: " << '\t' << trap(h/2) << '\t' << simpson(h/2) << endl;
	cout << "I: " << '\t' << trap(h/4) << '\t' << simpson(h/4) << endl;
	cout << "QC: " << '\t' << (trap(h / 2) - trap(h))/(trap(h / 4) - trap(h / 2)) << '\t' << (simpson(h / 2) - simpson(h)) / (simpson(h / 4) - simpson(h / 2)) << endl;
	cout << "Erro: " << '\t' << (trap(h / 4) - trap(h / 2))/3 << '\t' << (simpson(h / 4) - simpson(h / 2))/15 << endl;
}

// Pergunta 2

double fc(double c, double t)
{
	return (-exp(-0.5 / (t + 273)) * c);
}

double ft(double c, double t)
{
	return (30 * exp(-0.5 / (t + 273)) * c - 0.5*(t - 20));
}

void euler()
{
	double t = 0;
	double h = 0.1;
	double C = 2.5;
	double T = 25;

	double ct = C;
	double tt = T;

	for (unsigned int i = 0; i < 2; i++)
	{
		t = t + h;
		C += h * fc(ct, tt);
		T += h * ft(ct, tt);

		ct = C;
		tt = T;

		cout << "t: " << t << endl << "C: " << C << endl << "T: " << T << endl << endl;
	}
}

void rk4()
{
	double t = 0;
	double h = 0.1;
	double C = 2.5;
	double T = 25;

	double ct = C;
	double tt = T;

	double dc1, dc2, dc3, dc4, dt1, dt2, dt3, dt4;

	for (unsigned int i = 0; i < 2; i++)
	{
		dc1 = h * fc(ct, tt);
		dt1 = h * ft(ct, tt);

		dc2 = h * fc(ct + dc1/2, tt + dt1/2);
		dt2 = h * ft(ct + dc1 / 2, tt + dt1 / 2);

		dc3 = h * fc(ct + dc2 / 2, tt + dt2 / 2);
		dt3 = h * ft(ct + dc2 / 2, tt + dt2 / 2);

		dc4 = h * fc(ct + dc3, tt + dt3);
		dt4 = h * ft(ct + dc3, tt + dt3);

		t = t + h;
		C = C + dc1/6 + dc2/3 + dc3/3 + dc4/6;
		T = T + dt1 / 6 + dt2 / 3 + dt3 / 3 + dt4 / 6;
		
		ct = C;
		tt = T;

		cout << "t: " << t << endl << "C: " << C << endl << "T: " << T << endl << endl;
	}
}

// Pergunta 5

double f5(double x, double y)
{
	return -1.4*x*y + 12 * y + 7 * x*x - 8 * x;
}

double fx(double x, double y)
{
	return -1.4*y + 14 * x - 8;
}

double fy(double x, double y)
{
	return -1.4*x + 12;
}

void gradiente()
{
	double x = 2;
	double y = 5;
	double h = 0.1;

	double xt = x;
	double yt = y;

	for (unsigned int i = 0; i < 1; i++)
	{
		x -= h * fx(xt, yt);
		y -= h * fy(xt, yt);
	}
	
	cout << "O valor da funcao e: " << f5(x, y) << endl;
}

int main()
{
	cout.precision(7);
	//tabela();
	//euler();
	//rk4();
	gradiente();
	system("pause");
	return 0;
}
