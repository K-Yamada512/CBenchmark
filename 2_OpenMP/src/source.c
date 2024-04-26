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
/*standard library*/
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

	if(argv[1] == NULL)
	{
		printf("Error:not command line argument\r\n");
		return -1;
	}

	n = omp_get_max_threads(); 

	printf("max threads (set): %ld\r\n", n);

	FILE *fp;
	if( (fp = fopen( argv[1], "w" )) == NULL)
	{
		printf("can not open file.\r\n");
		return -2;
	}

	L = pow(10,10);

	for(uint64_t core_num = 1 ; core_num < n ; core_num *= 2)
	{
		printf("L=%ld\r\n",L);
		total = 0;

		clock_gettime(CLOCK_REALTIME, &startTime);

		#pragma omp parallel for private(j) reduction(+:total) num_threads(core_num)
		for (i = 0; i < L; i++)
		{
			j = 2 * i + 1;
			j = 1.0 / j;
			if(i % 2 == 1) j *= -1;
			total += j;
		}

		clock_gettime(CLOCK_REALTIME, &endTime);

		fprintf(fp, "%4ld, %.10lf\r\n", core_num, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);

		fprintf(stderr, "threads(%4ld) ,elapsed time = %.10lf(sec)\r\n", core_num, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);
		fprintf(stderr, "result : %.20lf\r\n", total * 4);
		fprintf(stderr, "\033[3F");

	}
	
	printf("L=%ld\r\n",L);
	total = 0;

	clock_gettime(CLOCK_REALTIME, &startTime);

	#pragma omp parallel for private(j) reduction(+:total) num_threads(n)
	for (i = 0; i < L; i++)
	{
		j = 2 * i + 1;
		j = 1.0 / j;
		if(i % 2 == 1) j *= -1;
		total += j;
	}

	clock_gettime(CLOCK_REALTIME, &endTime);

	fprintf(fp, "%4ld, %.10lf\r\n", n, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);

	printf("threads(%4ld) ,elapsed time = %.10lf(sec)\r\n", n, (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec) / 1e9);

	printf("result : %.20lf\r\n", total * 4);

	printf("Finish!\r\n");

	fclose(fp);
	
	return 0;
}
