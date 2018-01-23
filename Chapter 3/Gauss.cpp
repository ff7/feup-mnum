#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Gauss Method

void rowop(double m[3][4], int i, int j, double k)
{
	for (unsigned int a = 0; a < 4; a++)
		m[i][a] -= k * m[j][a];
}

int main() 
{
	double m[3][4] = { { 1,5,6,2 },{ 7,4,2,3 },{ -3,6,7,5 } };

	for (unsigned int i = 0; i < 3; i++)
	{
		rowop(m, i, i, 1 - 1 / m[i][i]);
		for (unsigned j = 0; j < 3; j++)
			if (i != j)
				rowop(m, j, i, m[j][i]);
	}

	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << "\n\n";
	}

	system("pause");
	return 0;
}


// Estabilidade Externa

/*
Para calcular a estabilidade externa dadas duas matrizes sA e sB, sendo que uma delas � uma matriz coluna e a outra uma
matriz quadrangular � s� aplicar a f�rmula: sB - sA.X -> X � a solu�ao da matriz inicial
Depois � s� substituir o valor que nos deu na f�rmula na matriz onde estava o X
*/

// Estabilidade Interna

/*
� s� resolver o sistema em ordem ao res�duo
*/