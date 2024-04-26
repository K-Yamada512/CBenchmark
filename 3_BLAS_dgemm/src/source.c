/*****************************************************************************/
/*
*	filename:source.c
*	about:
*		C code template main file
*		
*	attention:
*
*	history:
*		2024/04/26:K.Yamada :create file
*/
/*****************************************************************************/
/*****************************************************************************/
/*                         include headerfile                                */
/*****************************************************************************/
/*standard library*/
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
	double *a, *b, *c;
	double alpha, beta;
	uint32_t lda, ldb, ldc;
	struct timespec startTime, endTime;

	if(argv[1] == NULL)
	{
		printf("Error:not command line argument\r\n");
		return -1;
	}

	FILE *fp;
	if( (fp = fopen( argv[1], "w" )) == NULL)
	{
		printf("can not open file.\r\n");
		return -2;
	}

	for(int32_t i = 0 ; i < 9; i ++)
	{
		m = (i + 1) * 10;
		n = (i + 1) * 10;
		k = (i + 1) * 10;

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

		clock_gettime(CLOCK_REALTIME, &startTime);
		dgemm_("N", "N", &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc);
		clock_gettime(CLOCK_REALTIME, &endTime);

		fprintf(stderr, "%6d, %.10f\r", (i + 1) * 10, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);
		fprintf(fp, "%6d, %.10f\n", (i + 1) * 10, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);

		free(a);
		free(b);
		free(c);
	}

	for(int32_t i = 0 ; i < 9; i ++)
	{
		m = (i + 1) * 100;
		n = (i + 1) * 100;
		k = (i + 1) * 100;

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

		clock_gettime(CLOCK_REALTIME, &startTime);
		dgemm_("N", "N", &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc);
		clock_gettime(CLOCK_REALTIME, &endTime);

		fprintf(stderr, "%6d, %.10f\r", (i + 1) * 100, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);
		fprintf(fp, "%6d, %.10f\n", (i + 1) * 100, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);

		free(a);
		free(b);
		free(c);
	}

	for(int32_t i = 0 ; i < 10; i ++)
	{
		m = (i + 1) * 1000;
		n = (i + 1) * 1000;
		k = (i + 1) * 1000;

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

		clock_gettime(CLOCK_REALTIME, &startTime);
		dgemm_("N", "N", &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c, &ldc);
		clock_gettime(CLOCK_REALTIME, &endTime);

		fprintf(stderr, "%6d, %.10f\r", (i + 1) * 1000, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);
		fprintf(fp, "%6d, %.10f\n", (i + 1) * 1000, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);

		free(a);
		free(b);
		free(c);
	}

	printf("\nFinish!\r\n");

	fclose(fp);

	return 0;
}