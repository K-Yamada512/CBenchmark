/*****************************************************************************/
/*
*	filename:source.c
*	about:
*		C code template main file
*		
*	attention:
*
*	history:
*		2024/04/14:K.Yamada :create file
*/
/*****************************************************************************/
/*****************************************************************************/
/*                         include headerfile                                */
/*****************************************************************************/
//standard library
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
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
int main(uint64_t argc, char const* argv[])
{
	uint64_t i, L;
	int64_t n;
	double j,total;
	struct timespec startTime, endTime;

	n = omp_get_max_threads(); 

	printf("max threads (set): %ld\r\n", n);

	FILE *fp;
	if( (fp = fopen( "build/result.csv", "w" )) == NULL)
	{
		printf("can not open file.\r\n");
		return -1;
	}

	for(L = 10 ; L < pow(10,12) ; L *= 10)
	{
		printf("L=%ld\r\n",L);
		total = 0;

		clock_gettime(CLOCK_REALTIME, &startTime);

		#pragma omp parallel for private(j) reduction(+:total) num_threads(n)
		for (i = 0; i < L; i++)
		{
			j = 2*i + 1;
			j = 1/j;
			if(i % 2 == 1) j *= -1;
			total += j;
		}

		clock_gettime(CLOCK_REALTIME, &endTime);

		printf("elapsed time = ");
		if (endTime.tv_nsec < startTime.tv_nsec)
		{
			printf("%5ld.%09ld", endTime.tv_sec - startTime.tv_sec - 1,
			endTime.tv_nsec + (long int)1.0e+9 - startTime.tv_nsec);
			fprintf(fp, "%15ld,%5ld.%10ld,%.20lf\r\n", L,
			endTime.tv_sec - startTime.tv_sec - 1,
			endTime.tv_nsec + (long int)1.0e+9 - startTime.tv_nsec, total);
		}else
		{
			printf("%5ld.%09ld", endTime.tv_sec - startTime.tv_sec,
			endTime.tv_nsec - startTime.tv_nsec);
			fprintf(fp, "%15ld,%5ld.%10ld,%.20lf\r\n", L,
			endTime.tv_sec - startTime.tv_sec,
			endTime.tv_nsec - startTime.tv_nsec, total);
		}
		printf("(sec)\r\n");

		printf("result : %.20lf\r\n", total * 4);

	}
	
	fclose(fp);
	
	return 0;
}
