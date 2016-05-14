#include<stdio.h>
#include<math.h>


#define M 0.0000001
#define N 7

void sor(double w, double mat[][N], double b[], double x[], double xold[])
{
	//double a = 0.0;
	int i=0, j=0;//, N;
	double a;
	for(i=0; i<N; i++)
	{
		xold[i] = x[i];
		//printf("\nAqui x[i] = %f!\n", x[i]);
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
		//printf("\nAqui na sor a = %d!\N", a);
	x[i] = w*(b[i] - a)/mat[i][i];
	x[i] = x[i] - (w-1)*xold[i];
	}
	//for(i=0; i<N; i++)
	
	
	
}

/*double erro(double *x, double *xold)
{
	int = i;
	double e = 0.0;
	for(i=0; i<N; i++)
	{
		e = e + ((x[i] - xold[i])*(x[i] - xold[i]));
	}
	e = sqrt(e);
	return e;
}*/

 int main()
 {
 	//int i=0, k=0, N;
 	
 	int i, j, k = 0, ibiza, t = 50;
 	//printf("Qual sera a dimensao da matriz A? ");
 	//scanf("%d", &n);
	double mat[N][N], xold[N];
	double b[N];
	double e = 1.0;
	/*for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("[%d,%d]=%.1f ", i, j, mat[i][j]);
		printf("\n");	
	}*/
	for (i=0; i<N; i++)
	{
		//printf("\nAqui2!\n");
		for (j=0; j<N; j++)
		{
			if(i==j && i>0)
			{	//printf("\nAqui!\n");
				mat[i][j] = 9.5;
				//break;
			}
			else if(j==i+1 && j>1)
			{
				mat[i][j] = 2.0;
				//break;
			}
			else if(j==i-1 && i>1)// && i<N-1)
			{
				mat[i][j] = 2.0;
				//break;
			}
			else if(j==i+2)// && i<=N-2)
			{
				mat[i][j] = -1.0;
				//break;
			}
			else if(j==i-2)// && i<N-2)
			{
				mat[i][j] = -1.0;
				//break;
			}
			else if(j==i+3)// && i<N-3)
			{
				mat[i][j] = -1.0;
				//break;
			}
			else if(j==i-3)// && i<N-3)
			{
				mat[i][j] = -1.0;
				//break;
			}
			else
			{
			//printf("\nAqui! else FORA do if\n");
				//if(mat[i][j] != 7.5 && mat[i][j] != 5.5 && mat[i][j] != -1.0 && mat[i][j] != 2.0 && mat[i][j] != 9.5)
				
					//printf("\nAqui! esle caiu no if\n");
					mat[i][j] = 0.0;
				
			}
		}
	} 
	
	mat[0][0] = 7.5;
	mat[0][1] = 5.5;
	mat[1][0] = 5.5;
	//printf("\nAqui! %f\n", mat[1][0]);
	/*for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("[%d,%d]=%.1f ", i, j, mat[i][j]);
		printf("\n");	
	}*/
	//printf("\nAqui3!\n");
	
 	//int i;
	for(i = 0; i < N; i++)
	{
		b[i] = 1.0/(i+1);
		printf("\nAqui! b[i] = %f\n", b[i]);
		//printf("\nEntre com o valor de b%f: ", i+1);
		//scanf("%f", &b[i];
	}
 	
	double x[N];//, b[n]; 
 	double w= 1.0;
 
 	//b = fillb(n);
 	//for abaixo eh para os diferentes w
 	for(ibiza=0; ibiza<=10; ibiza++)
 	{
 	//	printf("\nAqui!%d\n", ibiza);
 		//cria o vet k = 0
		for(i = 0; i<N; i++)
		{
			x[i] = 1;
		}
		printf("\nAqui!%d\n", t);
		e = 1.0;
	 	while((k<=t)&&(e>=M))
	 	{
	 		//printf("\nAqui entrou no while %d %d!\n", k, t);
	 		sor(w, mat, b, x, xold);
	 		//erro(x, xold);
	 		
	 		
			//int = i;
			e = 0.0;
			for(i=0; i<N; i++)
			{
				e = e + ((x[i] - xold[i])*(x[i] - xold[i]));
			}
			e = sqrt(e);
			//return e;
			k++;
	 	}
			printf("A solucao com a w = %f eh:\n", w);
	 		for(i=0; i<N; i++)
	 		{
	 			printf("%f\n", x[i]);
			}	
		printf("\nNumero de iteracoes: %d\n", k);
	 	k = 0;
		w = w + 0.1;
	}
	
 }
 
 /*double *createmat(int n)
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
				mat[i][j] = -1.0;
			}
			if(j==i+3 && i<n-3)
			{
				mat[i][j] = -1.0;
			}
			if(j==i-3 && i<n-3)
			{
				mat[i][j] = -1.0;
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
}*/

/*double *fillb(n)
{
	int i;
	double b[n];
	for(i = 0; i < n; i++)
	{
		b[i] = 1/(i+1);
		//printf("\nEntre com o valor de b%f: ", i+1);
		//scanf("%f", &b[i];
	}
	return b;
}*/
