#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sor(double **mat, double *b, double emax, double w, int t)
{
	int i, j, k=0, N=t/5;
	double a, e=1.0;
	double *x = malloc(N*sizeof(double));
	double *xold = malloc(N*sizeof(double));	
	//for(j=0; j<=20; j++)
	//{	
		for(i = 0; i<N; i++)
		{
			x[i] = 1;
		}
		e = 1.0;
		while((k<=t-1)&&(e>=emax))
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
		if(e <= emax)
	 		{
				printf("\n\nO sistema converge para w = %.2f e sua solucao eh:\n\n", w);
		 		for(i=0; i<N; i++)
		 		{
		 			printf("%f\n", x[i]);
				}	
				printf("\nNumero de iteracoes: %d\n\n", k);
			}
			else if(k = t)
			{
				printf("\nO sistema diverge para w = %.2f ou nao converge em menos de %d iteracoes\n", w, t);
			}
	 	k = 0;
	//}
}

int main()
{
 	int i, j, k = 0, p, t, N, ibiza;
 	double emax;
 	double **mat, *b;
	double e = 1.0;
 	double w = 0.1;
 
	printf("Ola, este programa ira resolver um sistema linear pelo metodo SOR Ax = b\n");
 	printf("Qual sera a dimensao da matriz A? ");
 	scanf("%d", &N);
 	printf("Quantas casas decimais de precisao voce deseja?");
 	scanf("%d", &p);
 	emax = pow(0.1, p);
 	printf("\n\nprecisao usada: %f\n\n", emax);
 	mat = malloc(N*sizeof(double *));
 	for(i=0; i<N; i++)
 	{
 		mat[i] = malloc(N*sizeof(double));
	}
	b = malloc(N*sizeof(double));
	t = 5*N;
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

	for(i = 0; i < N; i++)
	{
		b[i] = 1.0/(i+1);
	}
 	printf("Sua matriz A eh:\n\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%4.1f ", mat[i][j]);
		}
			printf("\n");	
	}
	printf("\nSua matriz b eh:\n\n");
	for(i = 0; i < N; i++)
	{
		printf("b[%d] = %f\n", i, b[i]);
	}
		e = 1.0;
		for(j=0; j<=19; j++)
		{
			sor(mat, b, emax, w, t);
			w = w + 0.1;
		}
 }
 
