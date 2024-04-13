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

	clock_t start_clock, end_clock;
	uint64_t n_1 = 45;

	FILE *fp;
	if( (fp = fopen( "build/result.csv", "w" )) == NULL)
	{
		printf("can not open file.\r\n");
		return -1;
	}

	for(uint64_t run_index = 0 ; run_index<n_1 ; run_index++)
	{
		start_clock = clock();
		Fibonacci(run_index);
		end_clock = clock();

		fprintf(fp, "%ld,%.10lf\r\n", run_index, (double)(end_clock - start_clock) / CLOCKS_PER_SEC);

	}

	fclose(fp);

	return 0;
}
