#include<stdio.h>

double *createmat(int n)
{
	int i, j;
	double mat[n][n];
	mat[0][0] = 7.5;
	mat[0][1] = 5.5;
	mat[1][0] = 5.5;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if(i==j && i>0)
			{
				mat[i][j] = 9.5;
			}
			if(j==i+1 && j>1)
			{
				mat[i][j] = 2.0;
			}
			if(j==i-1 && i>0 && i<n-1)
			{
				mat[i][j] = 2.0;
			}
			if(j==i+2 && i<n-2)
			{
				mat[i][j] = -1.0;
			}
			if(j==i-2 && i<n-2)
			{
				mat[i][j] = -1.0
			}
			if(j==i+3 && i<n-3)
			{
				mat[i][j] = -1.0;
			}
			if(j==i-3 && i<n-3)
			{
				mat[i][j] = -1.0
			}
		}
	}
	
	
	return mat;
}
