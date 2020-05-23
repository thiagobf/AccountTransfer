/*
 * accounttransfer.h
 *
 *  Created on: 23 de mai de 2020
 *      Author: thiago
 */

#ifndef ACCOUNTTRANSFER_H_
#define ACCOUNTTRANSFER_H_
#define MAX_SIZE_ACCTNUMBER 20


typedef struct Accounts{
	long AccountSerialNumber;
	char AccountNumber[MAX_SIZE_ACCTNUMBER];
	double balance;

	struct Accounts *next;
} ;

#endif /* ACCOUNTTRANSFER_H_ */
