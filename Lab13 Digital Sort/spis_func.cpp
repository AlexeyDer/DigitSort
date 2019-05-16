#include "spis_func.h"

SList* IncQueue(SList *&head, SList *&tail, int n)
{
	SList *p;
	head = tail = new SList;
	head->data = 1;
	head->next = NULL;
	for (int i = 1; i < n; i++) {
		p = new SList;
		p->data = i + 1;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	return head;
}


SList* DecQueue(SList* head, SList *tail, int n)
{
	SList *p;
	head = tail = new SList;
	tail->data = n;
	tail->next = NULL;
	for (int i = 1; i < n; i++) {
		p = new SList;
		p->data = n - i;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	return head;
}

SList* RandQueue(SList *head, SList *tail, int n)
{
	SList *p;
	head = tail = new SList;
	tail->data = rand() % 100;
	tail->next = NULL;
	for (int i = 1; i < n; i++) {
		p = new SList;
		p->data = rand() % 100;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	return head;
}

SList* IncStack(SList *head, int n)
{
	SList *p;
	for (int i = 0; i < n; i++)
	{
		p = new SList;
		p->data = n - i;
		p->next = head;
		head = p;
	}
	return head;
}

SList* DecStack(SList *head, int n)
{
	SList *p;
	head = new SList;
	head->data = 1;
	head->next = NULL;
	for (int i = 1; i < n; i++)
	{
		p = new SList;
		p->data = i + 1;
		p->next = head;
		head = p;
	}
	return head;
}

SList* RandStack(SList *head, int n)
{
	SList *p;
	head = new SList;
	head->data = rand() % 100;
	head->next = NULL;
	for (int i = 0; i < n; i++) {
		p = new SList;
		p->data = rand() % 100;
		p->next = head;
		head = p;
	}
	return head;
}

int SumList(SList *head)
{
	int sum = 0;
	for (SList *p = head; p; p = p->next)
		sum += p->data;
	return sum;

}

int SericeList(SList *head)
{
	int sum = 1;
	for (SList *p = head; p; p = p->next)
		if (p->next != NULL && p->data > p->next->data)
			++sum;
	return sum;
}

void PrintList(SList *head)
{
	if (head != NULL) {
		for (SList *p = head; p; p = p->next)
			cout << p->data << " ";
		cout << endl;
	}
}

void DeleteList(SList *head)
{
	for (SList *p = head; head; p = head) {
		head = p->next;
		delete (p);
	}
	head = NULL;
}
