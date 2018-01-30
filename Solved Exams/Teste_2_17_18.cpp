#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// MNUM - 2 Teste de 2017/2018

// Pergunta 1

void rowop(double m[3][4], int i, int j, double k)
{
	for (unsigned int a = 0; a < 4; a++)
	{
		m[i][a] -= k * m[j][a];
	}
}

void gauss_estabilidade()
{
	double m[3][4] = { {18,-1,1,0.3151518},{3,-5,4,0.3151518 },{6,8,29,0.3151518 } };

	for (unsigned int i = 0; i < 3; i++)
	{
		rowop(m, i, i, 1 - 1 / m[i][i]);
		for (unsigned int j = 0; j < 3; j++)
		{
			if (i != j)
				rowop(m, j, i, m[j][i]);
		}
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

// Pergunta 2

void gauss_seidel()
{
	double x0 = 2.05351;
	double x1 = 2.42006;
	double x2 = 4.03330;
	double x3 = -3.72757;

	double m[4][5] = { {6,0.5,3,0.25,25},{1.2,3,0.25,0.2,10},{-1,0.25,4,2,7},{2,4,1,8,-12} };

	x0 = (m[0][4] - x1 * m[0][1] - x2 * m[0][2] - x3 * m[0][3]) / m[0][0];
	x1 = (m[1][4] - x0 * m[1][0] - x2 * m[1][2] - x3 * m[1][3]) / m[1][1];
	x2 = (m[2][4] - x1 * m[2][1] - x0 * m[2][0] - x3 * m[2][3]) / m[2][2];
	x3 = (m[3][4] - x1 * m[3][1] - x2 * m[3][2] - x0 * m[3][0]) / m[3][3];

	cout << "X0: " << x0 << endl << "X1: " << x1 << endl << "X2: " << x2 << endl << "X3: " << x3 << endl;

}

// Pergunta 6

double fy(double t, double z)
{
	return z;
}

double fz(double t, double z)
{
	return 1 + t * t + t * z;
}

void euler()
{
	double h = 0.5;
	double t = 0;
	double y = 1;
	double z = 2;

	for (unsigned int i = 0; i < 2; i++)
	{
		y += h * fy(t, z);
		z += h * fz(t, z);

		t = t + h;
	}

	cout << y << endl;
}

void rk4()
{
	double h = 0.5;
	double t = 0;
	double y = 1;
	double z = 2;

	double dy1, dy2, dy3, dy4, dz1, dz2, dz3, dz4;

	for (unsigned int i = 0; i < 2; i++)
	{
		dy1 = h*fy(t, z);
		dz1 = h*fz(t, z);

		dy2 = h*fy(t + h / 2, z + dz1 / 2);
		dz2 = h*fz(t + h / 2, z + dz1 / 2);

		dy3 = h*fy(t + h / 2, z + dz2 / 2);
		dz3 = h*fz(t + h / 2, z + dz2 / 2);

		dy4 = h*fy(t + h , z + dz3);
		dz4 = h*fz(t + h , z + dz3);

		y += dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		z += dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;

		t = t + h;

	}

	cout << y << endl;

}

int main()
{
	cout.precision(7);
	//gauss_estabilidade();
	//gauss_seidel();
	euler();
	rk4();
	system("pause");
	return 0;
}