/*****************************************************************************/
/*
*	filename:source.c
*	about:
*		C code template main file
*		
*	attention:
*
*	history:
*		2024/04/13:K.Yamada :create file
*/
/*****************************************************************************/
/*****************************************************************************/
/*                         include headerfile                                */
/*****************************************************************************/
//standard library
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include <source.h>

/*****************************************************************************/
/*                               define const                                */
/*****************************************************************************/
//none

/*****************************************************************************/
/*                         define variable (global)                          */
/*****************************************************************************/
//none

/*****************************************************************************/
/*                         define structure (global)                         */
/*****************************************************************************/
//none

/*****************************************************************************/
/*                                 define function                           */
/*****************************************************************************/
/*
*	function name:main
*	about:
*		project main function
*
*	in	uint64_t	argc	:command line argument number
*	in	char*		argv[]	:command line argument pointer
*	out	int					:error code
*/
int main(uint64_t argc, char const *argv[])
{
	uint32_t m, n, k;
	uint32_t size;
	double *a, *b, *c;
	double alpha, beta;
	uint32_t lda, ldb, ldc;
	struct timespec ts1, ts2;

	FILE *fp;
	if( (fp = fopen( "build/result.csv", "w" )) == NULL)
	{
		printf("can not open file.\r\n");
		return -1;
	}

	for(size = 10;size < 100; size += 10)
	{
		m = size;
		n = size;
		k = size;

		a = (double *)malloc(sizeof(double) * m * k); // m x k matrix
		b = (double *)malloc(sizeof(double) * k * n); // k x n matrix
		c = (double *)malloc(sizeof(double) * m * n); // m x n matrix

		for (uint64_t i=0; i<m; i++)
		{
			for (uint64_t j=0; j<k; j++)
			{
				a[i + m * j] = rand() / (1.0 + RAND_MAX);
			}
		}

		for (uint64_t i=0; i<k; i++)
		{
			for (uint64_t j=0; j<n; j++)
			{
				b[i + k * j] = rand() / (1.0 + RAND_MAX);
			}
		}

		for (uint64_t i=0; i<m; i++)
		{
			for (uint64_t j=0; j<n; j++)
			{
				c[i + m * j] = 0;
			}
		}

		alpha = 1.;
		beta = 0.;
		lda = m; 
		ldb = k; 
		ldc = m; 

		clock_gettime(CLOCK_REALTIME, &ts1);
		dgemm_("N", "N", &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc);
		clock_gettime(CLOCK_REALTIME, &ts2);

		printf("%6d,%.10f\n", size, (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9);
		fprintf(fp, "%6d,%.10f\n", size, (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9);

		free(a);
		free(b);
		free(c);
	}

	for(size = 100;size < 1000; size += 100)
	{
		m = size;
		n = size;
		k = size;

		a = (double *)malloc(sizeof(double) * m * k); // m x k matrix
		b = (double *)malloc(sizeof(double) * k * n); // k x n matrix
		c = (double *)malloc(sizeof(double) * m * n); // m x n matrix

		for (uint64_t i=0; i<m; i++)
		{
			for (uint64_t j=0; j<k; j++)
			{
				a[i + m * j] = rand() / (1.0 + RAND_MAX);
			}
		}

		for (uint64_t i=0; i<k; i++)
		{
			for (uint64_t j=0; j<n; j++)
			{
				b[i + k * j] = rand() / (1.0 + RAND_MAX);
			}
		}

		for (uint64_t i=0; i<m; i++)
		{
			for (uint64_t j=0; j<n; j++)
			{
				c[i + m * j] = 0;
			}
		}

		alpha = 1.;
		beta = 0.;
		lda = m; 
		ldb = k; 
		ldc = m; 

		clock_gettime(CLOCK_REALTIME, &ts1);
		dgemm_("N", "N", &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc);
		clock_gettime(CLOCK_REALTIME, &ts2);

		printf("%6d,%.10f\n", size, (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9);
		fprintf(fp, "%6d,%.10f\n", size, (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9);

		free(a);
		free(b);
		free(c);
	}

	for(size = 1000;size < 10000+1; size += 1000)
	{
		m = size;
		n = size;
		k = size;

		a = (double *)malloc(sizeof(double) * m * k); // m x k matrix
		b = (double *)malloc(sizeof(double) * k * n); // k x n matrix
		c = (double *)malloc(sizeof(double) * m * n); // m x n matrix

		for (uint64_t i=0; i<m; i++)
		{
			for (uint64_t j=0; j<k; j++)
			{
				a[i + m * j] = rand() / (1.0 + RAND_MAX);
			}
		}

		for (uint64_t i=0; i<k; i++)
		{
			for (uint64_t j=0; j<n; j++)
			{
				b[i + k * j] = rand() / (1.0 + RAND_MAX);
			}
		}

		for (uint64_t i=0; i<m; i++)
		{
			for (uint64_t j=0; j<n; j++)
			{
				c[i + m * j] = 0;
			}
		}

		alpha = 1.;
		beta = 0.;
		lda = m; 
		ldb = k; 
		ldc = m; 

		clock_gettime(CLOCK_REALTIME, &ts1);
		dgemm_("N", "N", &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc);
		clock_gettime(CLOCK_REALTIME, &ts2);

		printf("%6d,%.10f\n", size, (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9);
		fprintf(fp, "%6d,%.10f\n", size, (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9);

		free(a);
		free(b);
		free(c);
	}


	fclose(fp);

	return 0;
}