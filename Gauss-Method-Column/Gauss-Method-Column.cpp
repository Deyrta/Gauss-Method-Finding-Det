#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, k;
	double d, w, y;
	cin >> n;

	double** A = new double *[n];
	for (int i = 0; i < n; i++)
		A[i] = new double[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	d = 1;
	for (int i = 0; i <= n; i++)
	{
		k = i; y = A[i][i];
		for (int j = i + 1; j <= n; j++)
		{
			w = A[j][i];
			if (fabs(w) > fabs(y))
			{
				k = j; y = w;
			}
		}
		d = d * y;
		if (d != 0)
		{
			if (i != k)
			{
				d = -d;
				for (int j = i; j <= n; j++)
				{
					w = A[k][j];
					A[k][j] = A[i][j];
					A[i][j] = w;
				}
			}
			for (int j = i + 1; j <= n; j++)
			{
				w = A[j][i] / y;
				for (int k = i + 1; k <= n; k++)
					A[j][k] = A[j][k] - w * A[i][k];
			}
		}
	}
	cout << "Det=" << d;
}
