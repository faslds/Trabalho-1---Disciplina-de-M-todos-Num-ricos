#include<stdio.h>
#include<math.h>
#define T 666
#define M 0,0000001

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
			else
			{
				if(mat[i][j] != 7.5 || mat[i][j] != 5.5)
				{
					mat[i][j] = 0;
				}
			}
				
		}
	}
	return mat;
}

double *fillb(n)
{
	int i;
	double b[n];
	for(i = 0; i < n; i++)
	{
		printf("\nEntre com o valor de b%lf: ", i+1);
		scanf("%lf", &b[i];
	}
	return b;
}

void sor(double w, double *mat, double *b, double* x, double *xold)
{
	//double a = 0.0;
	int i=0, j=0;
	for(i=0; i<n; i++)
	{
		xold[i] = x[i];
	}
	for(i=0; i<n; i++)
	{
		a = 0.0;
		for(j=0; j<n; j++)
		{
			if(j != i)
			{
				a = a + mat[i][j]*x[j];
			}
		}
		x[i] = w*(b[i] - a)/mat[i][i];
	}
	for(i=0; i<n; i++)
	{
		x[i] = x[i] - (w-1)*xold[i];
	}
}

double erro(double *x, double *xold)
{
	int = i;
	double e = 0.0;
	for(i=0; i<n; i++)
	{
		e = e + ((x[i] - xold[i])*(x[i] - xold[i]));
	}
	e = sqrt(e);
	return e;
}

 int main()
 {
 	int i=0, k=0;
 	double x[n], b[n], 
 	//for abaixo eh para os diferentes w
 	for(i=0; i<=10; i++)
 	{
 		//cria o vet k = 0
		for()
	 	while(k < T || e >= M)
	 	{
	 		sor(w, mat, b, x, xold);
	 		erro(x, xold);
	 		k++;
		}
		w = w + 0.1;
		
	}
	
 }
