/*****************************************************************************/
/*
*	filename:source.c
*	about:
*		Code for Benchmark Testing (Fibonacci number)
*		
*	caution:
*
*	history:
*		2024/04/19:K.Yamada :create file
*/
/*****************************************************************************/
/*****************************************************************************/
/*                         include headerfile                                */
/*****************************************************************************/
/*standard library*/
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include <source.h>

/*****************************************************************************/
/*                               define const                                */
/*****************************************************************************/
/*none*/

/*****************************************************************************/
/*                         define variable (global)                          */
/*****************************************************************************/
/*none*/

/*****************************************************************************/
/*                         define structure (global)                         */
/*****************************************************************************/
/*none*/

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
	clock_t start_clock, end_clock;
	uint64_t n_1 = 40, ans = 0;
	double runTime[n_1];
	struct timespec startTime, endTime;
	FILE *fp;

	if(argv[1] == NULL)
	{
		printf("Error:not command line argument\r\n");
		return -1;
	}

	printf("Calculate Fibonacci numbers(0 ~%3ld)\r\n", n_1 - 1);


	for(uint64_t run_index = 0 ; run_index < n_1 ; run_index++)
	{
		clock_gettime(CLOCK_REALTIME, &startTime);
		ans = Fibonacci(run_index);
		clock_gettime(CLOCK_REALTIME, &endTime);

		runTime[run_index] = (endTime.tv_sec - startTime.tv_sec)
					+ (endTime.tv_nsec - startTime.tv_nsec) / 1e9;

		fprintf(stderr, "\rTime:%.10lf [s], Fibonacci number(%3ld) = %12ld",
				runTime[run_index], run_index, ans);
	}

	if( (fp = fopen( argv[1], "w")) == NULL)
	{
		printf("can not open file.\r\n");
		return -2;
	}
	for(uint64_t run_index = 0 ; run_index < n_1 ; run_index++)
	{
		fprintf(fp, "%3ld, %.10lf\r\n", run_index, runTime[run_index]);
	}
	fclose(fp);

	printf("\r\nFinish!\r\n");

	return 0;
}
