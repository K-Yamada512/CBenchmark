/*****************************************************************************/
/*
*	filename:calculate1.c
*	about:
*		calculate function 1
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
#include <stdlib.h>
#include <stdint.h>

#include <calculate1.h>

/*****************************************************************************/
/*                               define const                                */
/*****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

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
*	function name:Fibonacci
*	about:
*		calculate Fibonacci number
*
*	attention:
*		define Fibonacci(0)=0,Fibonacci(1)=1.
*
*	in	int64_t		n		:Fibonacci number index
*	out	int64_t				:calculate answer
*/
	uint64_t Fibonacci(uint64_t n)
	{
		if(n == 0)
			return 0;
		if(n == 1)
			return 1;

		return Fibonacci(n-1) + Fibonacci(n-2);
	}

#ifdef __cplusplus
}
#endif /*__cplusplus*/
