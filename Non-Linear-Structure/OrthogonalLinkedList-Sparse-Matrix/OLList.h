#ifndef _OLLIST_H_
#define _OLLIST_H_

#include "main.h"

Status InitMat(OSMatrix *M, int i, int j);
	/*
	 * InitMat functions as follows:
	 * initialize rhead and chead with NULL
	 * initialize tu with 0, mu with i, nu with j 
	 */

Status GetMat(OSMatrix* M);
	/*
	 * GetMat functions as follows:
	 * get the non-zero elements from the vector V
	 * get the location from the 0-1 matrix
	 * create a OLList to represent the matrix
	 */
#endif
