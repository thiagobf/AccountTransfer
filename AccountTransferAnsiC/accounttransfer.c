#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "accounttransfer.h"
/*
 * accounttransfer.c
 *
 *  Created on: 23 de mai de 2020
 *      Author: thiago
 */
struct Accounts *head = NULL;
struct Accounts *current = NULL;

void InsertAccount(long AccountSerial, char *AccountNumber)
{
	struct Accounts *account = (struct Accounts *)malloc(sizeof(struct Accounts));
	static char WhoAmI[] = "InsertAccount";
	printf("[%s]*Enter[%ld][%s]*\n", WhoAmI, AccountSerial, AccountNumber);

	account->AccountSerialNumber = AccountSerial;
	memcpy(account->AccountNumber, AccountNumber, sizeof(account->AccountNumber));
	account->next = head;
	head = account;
	printf("[%s]*Exit*\n",WhoAmI);

}
void printListAccounts()
{
	struct Accounts *pointer = head;
	static char WhoAmI[] = "printListAccounts";
	printf("[%s]*Enter*\n",WhoAmI);
	printf("Accounts List....\n");
	while (pointer != NULL)
	{
		printf("Account# [%ld][%s]\n", pointer->AccountSerialNumber, pointer->AccountNumber);
		pointer = pointer->next;
	}
	printf("[%s]*Exit*\n",WhoAmI);
}
bool IsEmpty()
{
	return head == NULL;
}
struct Accounts* findAccountByAccountNumber(char *AccountNumber)
{
	struct Accounts *current = head;
	static char WhoAmI[] = "findAccountByAccountNumber";
	printf("[%s]*Enter - ACCT#[%s]*\n", WhoAmI, AccountNumber);
	if (IsEmpty())
	{
		printf("[%s]*Empty Linked List...\n", WhoAmI);
		return NULL;
	}

	while (memcmp(current->AccountNumber, AccountNumber,
			sizeof(current->AccountNumber)) || current->next != NULL)
	{
		printf("[%s]*Account Number [%s]\n", WhoAmI,current->AccountNumber);
		if (current->next == NULL)
		{
			printf("[%s]*Exit*NULL\n",WhoAmI);
			return NULL;
		}
		else
		{
			current = current->next;
		}
	}
	printf("[%s][%s]*Exit*\n",WhoAmI, current->AccountNumber);
	return current;
}
int main ()
{
	struct Accounts *acct;
	if (IsEmpty())
	{
		printf("Empty!.....\n");
	}
	InsertAccount(1239, "000012");
	InsertAccount(1234, "000015");
	printListAccounts();
	if (IsEmpty())
	{
		printf("This is not empty!....\n");
	}
	acct = findAccountByAccountNumber("000012");
	if (acct != NULL)
		printf("Account Number [%ld] - [%s]\n", acct->AccountSerialNumber, acct->AccountNumber);
	printf("Exit");
	return 0;
}
