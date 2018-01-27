#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// MNUM - Exame 2014/15 - Epoca Normal

// Pergunta 1

double f(double x)
{
	return -0.25*(x - 37);
}

void euler()
{
	double h = 0.4;
	double t = 5;
	double T = 3;

	for (unsigned int i = 0; i < 2; i++)
	{
		t = t + h;
		T = T + h * f(T);
	}

	cout << "O valor da temperatura e: " << T << endl;
}


// Pergunta 3

void rowop(double m[3][4], int i , int j, double k)
{
	for (unsigned int a = 0; a < 4; a++)
	{
		m[i][a] -= k * m[j][a];
	}
}

void gauss()
{
	//double m[3][4] = { {1, (1 / 2.0), (1 / 3.0),-1}, {(1 / 2.0),(1 / 3.0),(1 / 4.0),1},{(1 / 3.0),(1 / 4.0),(1 / 5.0),1} };
	double m[3][4] = { { 1, (1 / 2.0), (1 / 3.0),-0.1 },{ (1 / 2.0),(1 / 3.0),(1 / 4.0),-0.1 },{ (1 / 3.0),(1 / 4.0),(1 / 5.0),-0.1 } };

	for (unsigned int i = 0; i < 3; i++)
	{
		rowop(m, i, i, 1 - 1 / m[i][i]);
		for (unsigned int j = 0; j < 3; j++)
			if (i != j)
				rowop(m, j, i, m[j][i]);
	}

	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << '\n';
	}
}

// Para a estabilidade externa o procedimento e igual, so muda a matriz

// Pergunta 4

double f3(double x)
{
	return 2 * log(2 * x);
}

void picard_peano()
{
	double x = 1.1;

	for (unsigned int i = 0; i < 1; i++)
	{
		cout << "Iteracao " << i << ": " << x << endl;
		x = f3(x);
		cout << "Iteracao " << i + 1<< ": " << x << endl;
	}
	// O residuo e o valor de I1 - I0;
}

// Pergunta 5

double f5(double x)
{
	return sqrt(1 + pow((2.5*exp(2.5*x)), 2));
}

double trap(double h)
{
	double a = 0.0;
	double b = 1.0;
	double n = (b - a) / h;
	double st = 0;

	for (unsigned int i = 1; i < n; i++)
	{
		st += f5(a + h * i) * 2;
	}
	st += f5(a) + f5(b);
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
		if (i % 2 == 0)
		{
			ss += f5(a + h * i) * 2;
		}
		else
		{
			ss += f5(a + h * i) * 4;
		}
	}
	ss += f5(a) + f5(b);
	ss = ss * (h / 3);
	return ss;
}

void tabela()
{
	double h = 0.125;
	cout << "H1: " << '\t' << h << '\t' << h << endl;
	cout << "H2: " << '\t' << h / 2 << '\t' << h / 2 << endl;
	cout << "H3: " << '\t' << h / 4 << '\t' << h / 4 << endl;
	cout << "L1: " << '\t' << trap(h) << '\t' << simpson(h) << endl;
	cout << "L2: " << '\t' << trap(h / 2) << '\t' << simpson(h / 2) << endl;
	cout << "L3: " << '\t' << trap(h / 4) << '\t' << simpson(h / 4) << endl;
	cout << "QC: " << '\t' << (trap(h / 2) - trap(h))/ (trap(h / 4) - trap(h/2)) << '\t' << (simpson(h / 2) - simpson(h)) / (simpson(h / 4) - simpson(h / 2)) << endl;
	cout << "Erro: " << '\t' << (trap(h / 4) - trap(h / 2))/3 << '\t' << (simpson(h / 4) - simpson(h / 2))/15 << endl;

}

// Pergunta 7

double f7(double x)
{
	return pow(x, 3) - 10 * sin(x) + 2.8;
}
void bissecao()
{
	double a = 1.5;
	double b = 4.2;
	double m = (b + a) / 2;

	for (unsigned int i = 0; i < 2; i++)
	{
		if (f7(a)*f7(m) < 0)
			b = m;
		else
			a = m;
		m = (b + a) / 2;
	}

	cout << "O valor de b e: " << b;
}

int main()
{
	cout.precision(6);
	//euler();
	//gauss();
	//picard_peano();
	//tabela();
	bissecao();
	system("pause");
	return 0;
}
