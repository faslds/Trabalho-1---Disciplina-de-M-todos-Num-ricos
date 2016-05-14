#include<stdio.h>
#include<math.h>
#define M 0.0000001
#define N 7

void sor(double w, double mat[][N], double b[], double x[], double xold[], double e, int k, int t)
{
	int i, j;
	double a;
	for(j=0; j<=20; j++)
	{	
		for(i = 0; i<N; i++)
		{
			x[i] = 1;
		}
		e = 1.0;
		while((k<=t)&&(e>=M))
		{	
			int i=0, j=0;
			for(i=0; i<N; i++)
			{
				xold[i] = x[i];
			}
			for(i=0; i<N; i++)
			{
				a = 0.0;
				for(j=0; j<N; j++)
				{
					if(j != i)
					{
						a = a + (mat[i][j])*(x[j]);
					}
				}
			x[i] = w*(b[i] - a)/mat[i][i];
			x[i] = x[i] - (w-1)*xold[i];
			}
			e = 0.0;
				for(i=0; i<N; i++)
				{
					e = e + ((x[i] - xold[i])*(x[i] - xold[i]));
				}
				e = sqrt(e);
				k++;
		}
		if(e <= M)
	 		{
				printf("\n\nO sistema converge para w = %f e sua solucao eh:\n\n", w);
		 		for(i=0; i<N; i++)
		 		{
		 			printf("%f\n", x[i]);
				}	
				printf("\nNumero de iteracoes: %d\n\n", k);
			}
			else if(k = t)
			{
				printf("\nO sistema diverge para w = %f\n", w);
			}
	 	k = 0;
		w = w + 0.1;
	}
}

int main()
{
 	int i, j, k = 0, ibiza, t = 50;
 	//printf("Qual sera a dimensao da matriz A? ");
 	//scanf("%d", &n);
	double mat[N][N], x[N], b[N], xold[N];
	double e = 1.0;
 	double w = 0.0;
	/*for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("[%d,%d]=%.1f ", i, j, mat[i][j]);
		printf("\n");	
	}*/
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if(i==j && i>0)
			{	
				mat[i][j] = 9.5;
			}
			else if(j==i+1 && j>1)
			{
				mat[i][j] = 2.0;
			}
			else if(j==i-1 && i>1)
			{
				mat[i][j] = 2.0;
			}
			else if(j==i+2)
			{
				mat[i][j] = -1.0;
			}
			else if(j==i-2)
			{
				mat[i][j] = -1.0;
			}
			else if(j==i+3)
			{
				mat[i][j] = -1.0;
			}
			else if(j==i-3)
			{
				mat[i][j] = -1.0;
			}
			else
			{
				mat[i][j] = 0.0;
			}
		}
	} 
	mat[0][0] = 7.5;
	mat[0][1] = 5.5;
	mat[1][0] = 5.5;
	
	/*for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("[%d,%d]=%.1f ", i, j, mat[i][j]);
		printf("\n");	
	}*/

	for(i = 0; i < N; i++)
	{
		b[i] = 1.0/(i+1);
	}
	printf("Ola, este programa ira resolver um sistema linear pelo metodo SOR Ax = b\n");
 	printf("Sua matriz A eh:\n\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("[%d,%d]=%.1f ", i, j, mat[i][j]);
		printf("\n");	
	}
	printf("\nSua matriz b eh:\n\n");
	for(i = 0; i < N; i++)
	{
		printf("b[%d] = %f\n", i, b[i]);
	}
 	
 	//for(ibiza=0; ibiza<=20; ibiza++)
 	//{
	/*	for(i = 0; i<N; i++)
		{
			x[i] = 1;
		}/*/
		e = 1.0;
		sor(w, mat, b, x, xold, e, k, t);
	 	/*while((k<=t)&&(e>=M))
	 	{
	 		sor(w, mat, b, x, xold);
			e = 0.0;
			for(i=0; i<N; i++)
			{
				e = e + ((x[i] - xold[i])*(x[i] - xold[i]));
			}
			e = sqrt(e);
			k++;
	 	}
	 	sor(w, mat, b, x, xold, e, k, t);
	 		if(e <= M)
	 		{
				printf("\n\nO sistema converge para w = %f e sua solucao eh:\n\n", w);
		 		for(i=0; i<N; i++)
		 		{
		 			printf("%f\n", x[i]);
				}	
				printf("\nNumero de iteracoes: %d\n\n", k);
			}
			else if(k = t)
			{
				printf("\nO sistema diverge para w = %f\n", w);
			}
	 	k = 0;
		w = w + 0.1;
	}*/
	
 }
 
