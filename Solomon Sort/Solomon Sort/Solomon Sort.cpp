#include "stdafx.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int counter = 0;

int* Solomon(int *b, int n, int *result)
{
	int i = 0, max = INT64_MIN, min = INT64_MAX, ind = 0, f = 0, j = 0;
	double delta = 0;

	int **a = new int*[2]; // две строки в массиве
	for (i = 0; i < 2; i++)
		a[i] = new int[n];
	int *temp = new int[n];
	for (i = 0; i < n; i++)
	{
		temp[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		a[0][i] = b[i];

		if (a[0][i] > max)
			max = a[0][i];

		if (a[0][i] < min)
			min = a[0][i];

		a[1][i] = 0;
	}

	delta = ((max - min) / n);

	max = (max - min) / delta + 1;

	int **Nnew = new int*[n]; // n строк в массиве
	for (i = 0; i < n; i++)
		Nnew[i] = new int[max + 1];

	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < max + 1; j++)
		{
			Nnew[i][j] = 0;
		}
	}

	int *index = new int[max + 1];
	for (i = 0; i <= max; i++)
	{
		index[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		ind = (a[0][i] - min) / delta + 1; // подписываем индекс каждого элемента под ним
		a[1][i] = ind;
		index[ind]++;
	}

	for (i = 1; i <= max; i++)
	{
		ind = index[i];
		while (ind > 0)
		{
			for (j = 0; j < n; j++)
			{
				if (a[1][j] == i)
				{
					Nnew[index[i] - ind][i] = a[0][j];
					ind--;
				}
			}
		}
	}

	for (i = 0; i <= max; i++)
	{
		switch (index[i])
		{
		case 0:
			break;
		case 1:
			result[counter] = Nnew[0][i];
			counter++;
			cout << Nnew[0][i] << " ";
			break;
		case 2:
			if (Nnew[0][i] < Nnew[1][i])
			{
				result[counter] = Nnew[0][i];
				counter++;
				result[counter] = Nnew[1][i];
				counter++;
				cout << Nnew[0][i] << " " << Nnew[1][i] << " ";
			}
			else
			{
				result[counter] = Nnew[1][i];
				counter++;
				result[counter] = Nnew[0][i];
				counter++;
				cout << Nnew[1][i] << " " << Nnew[0][i] << " ";
			}
			break;
		case 3:
			if (Nnew[0][i] < Nnew[1][i])
				if (Nnew[0][i] < Nnew[2][i])
				{
					result[counter] = Nnew[0][i];
					counter++;
					cout << Nnew[0][i] << " ";
					if (Nnew[1][i] < Nnew[2][i])
					{
						result[counter] = Nnew[1][i];
						counter++;
						result[counter] = Nnew[2][i];
						counter++;
						cout << Nnew[1][i] << " " << Nnew[2][i] << " ";
					}
					else
					{
						result[counter] = Nnew[2][i];
						counter++;
						result[counter] = Nnew[1][i];
						counter++;
						cout << Nnew[2][i] << " " << Nnew[1][i] << " ";
					}
				}
				else
				{
					result[counter] = Nnew[2][i];
					counter++;
					result[counter] = Nnew[0][i];
					counter++;
					result[counter] = Nnew[1][i];
					counter++;
					cout << Nnew[2][i] << " " << Nnew[0][i] << " " << Nnew[1][i] << " ";
				}
			else
			{
				if (Nnew[0][i] < Nnew[2][i])
				{

					result[counter] = Nnew[1][i];
					counter++;
					result[counter] = Nnew[0][i];
					counter++;
					result[counter] = Nnew[2][i];
					counter++;
					cout << Nnew[1][i] << " " << Nnew[0][i] << " " << Nnew[2][i] << " ";
				}
				else
				{
					if (Nnew[1][i] < Nnew[2][i])
					{
						result[counter] = Nnew[1][i];
						counter++;
						result[counter] = Nnew[2][i];
						counter++;
						result[counter] = Nnew[0][i];
						counter++;
						cout << Nnew[1][i] << " " << Nnew[2][i] << " " << Nnew[0][i] << " ";
					}
					else
					{
						result[counter] = Nnew[2][i];
						counter++;
						result[counter] = Nnew[1][i];
						counter++;
						result[counter] = Nnew[0][i];
						counter++;
						cout << Nnew[2][i] << " " << Nnew[1][i] << " " << Nnew[0][i] << " ";
					}
				}

			}
			break;
		default:
			for (f = 0; f < n; f++)
			{
				if (Nnew[f][i] == 0)
					break;
				temp[f] = Nnew[f][i];
			}
			//f--;
			Solomon(temp, f, result);
		}
	}

	return *a;
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": " << a[i] << endl;
	}
}

int main()
{
	int n = 0, i = 0;
	cout << "Enter n: ";
	cin >> n;
	int *a = new int[n];
	int *result = new int[n];

	cout << "Enter the numbers: ";
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		result[i] = 0;
	}
	Solomon(a, n, a);
	cout << "counter:" << counter << endl;
	printArray(a, n);
	system("Pause");
	return 0;
}

