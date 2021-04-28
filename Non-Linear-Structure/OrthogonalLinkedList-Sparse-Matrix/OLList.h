#ifndef _OLLIST_H_
#define _OLLIST_H_

#include "main.h"

Status GetMat(OLList* M, Vector V);
	/*
	 * GetMat functions as follows:
	 * get the non-zero elements from the vector V
	 * get the location from the 0-1 matrix
	 * create a OLList to represent the matrix
	 */
#endif
