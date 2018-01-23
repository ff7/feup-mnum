#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Gauss-Seidel Method

int main()
{
	double m[4][5] = { {6, 0.5, 3, 0.25, 25},{1.2,3,0.25,0.2,10},{-1,0.25,4,2,7}, {2,4,1,8,-12} };

	double x0 = 2.05351;
	double x1 = 2.42006;
	double x2 = 4.03330;
	double x3 = -3.72757;

	x0 = (m[0][4] - m[0][1] * x1 - m[0][2] * x2 - m[0][3] * x3) / m[0][0];
	x1 = (m[1][4] - m[1][0] * x0 - m[1][2] * x2 - m[1][3] * x3) / m[1][1];
	x2 = (m[2][4] - m[2][0] * x0 - m[2][1] * x1 - m[2][3] * x3) / m[2][2];
	x3 = (m[3][4] - m[3][0] * x0 - m[3][1] * x1 - m[3][2] * x2) / m[3][3];

	cout << "X0: " << x0 << endl << "X1: " << x1 << endl << "X2: " << x2 << endl << "X3: " << x3 << endl;

	system("pause");
	return 0;
}