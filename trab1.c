#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sor(double **mat, double *b, double emax, double w, int t)
{
	int i, j, k=0, N=t/5; /*N eh a ordem da matriz e recebe t/5, onde 
	t eh a quantidade maxima de iteracoes, definida como t = n*5*/
	double a, e=1.0;
	double *x = malloc(N*sizeof(double)); //aloca o espaco necessario para os vetores da iteracao x(k) e x(k+1)
	double *xold = malloc(N*sizeof(double));	
	//esse for preenche a aproximacao inicial
	for(i = 0; i<N; i++){
		x[i] = 1; //nesse caso todos os elementos sao igual a 1
	}
	e = 1.0;
	while((k<=t-1)&&(e>=emax)){	
		int i=0, j=0;
		for(i=0; i<N; i++) //copia a iteracao atual na velha
		{
			xold[i] = x[i];
		}
		for(i=0; i<N; i++) //trabalha na iteracao atual
		{
			a = 0.0;
			for(j=0; j<N; j++)
			{
				if(j != i)
				{
					a = a + (mat[i][j])*(x[j]);
				}
			}
		//aqui o metodo SOR eh aplicado	
		x[i] = w*(b[i] - a)/mat[i][i];
		x[i] = x[i] - (w-1)*xold[i];
		}
		e = 0.0; 
			for(i=0; i<N; i++) //calcula o erro
			{
				e = e + ((x[i] - xold[i])*(x[i] - xold[i]));
			}
			e = sqrt(e); 
			k++;
	}
	if(e <= emax) //se o erro eh menor que a precisao requerida, o metodo converge
 		{
			printf("\n\nO sistema converge para w = %.2f e sua solucao eh:\n\n", w);
	 		for(i=0; i<N; i++) //imprime a solucao
	 		{
	 			printf("%f\n", x[i]);
			}	
			printf("\nNumero de iteracoes: %d\n\n", k);
		}
		else if(k = t) //se alcancou o numero maximo de iteraçoes, o metodo nao convergiu para a solucao do sistema
		{
			printf("\nO sistema diverge para w = %.2f ou nao converge em menos de %d iteracoes\n", w, t);
		}
 	k = 0; //zera o contador de iteracoes
}

int main()
{
 	int i, j, k = 0, p, t, N, ibiza;
 	double emax;
 	double **mat, *b;
	double e = 1.0;
 	double w = 0.0;
 	printf("Ola, este programa ira resolver um sistema linear pelo metodo SOR Ax = b\n");
 	printf("Qual sera a dimensao da matriz A? ");
 	scanf("%d", &N);
 	printf("Quantas casas decimais de precisao voce deseja?");
 	scanf("%d", &p);
 	emax = pow(0.1, p); //calcula a precisao pedida
 	mat = malloc(N*sizeof(double *));//aloca o espaco para a matriz A (chamada de mat)
 	for(i=0; i<N; i++)
 	{
 		mat[i] = malloc(N*sizeof(double));//mat eh estruturada como um vetor de ponteiros para vetores
	}
	b = malloc(N*sizeof(double));//aloca o espaco para a matriz b
	t = 5*N;// t eh o numero maximo aceito de iteracoes
	for (i=0; i<N; i++)//esse for cria a matriz mat
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

	for(i = 0; i < N; i++)//preenche a matriz b
	{
		b[i] = 1.0/(i+1);
	}
 	printf("Sua matriz A eh:\n\n");
	for(i=0; i<N; i++)//fornece a matriz mat impressa
	{
		for(j=0; j<N; j++)
		{
			printf("%4.1f ", mat[i][j]);
		}
			printf("\n");	
	}
	printf("\nSua matriz b eh:\n\n");//fornece a matriz b impressa
	for(i = 0; i < N; i++)
	{
		printf("b[%d] = %f\n", i+1, b[i]);
	}
		e = 1.0;
		//chama a funcao sor para as 20 diferentes aplicacoes para w variando de 0 a 2
		for(j=0; j<=20; j++)
		{
			sor(mat, b, emax, w, t);
			w = w + 0.1;
		}
 }
 
