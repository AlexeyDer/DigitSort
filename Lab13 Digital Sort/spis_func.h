#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
using byte = unsigned char;

struct SList {
	SList *next;
	union 
	{
		int data;
		byte Digit[20];
		byte KDI[20];
	};
	
};

struct tLE {
	SList *head;
	SList *tail;
};

SList *IncStack(SList *head, int n);
SList *DecStack(SList *head, int n);
SList *RandStack(SList *head, int n);
void PrintList(SList *head);
int SumList(SList *head);
int SericeList(SList *head);
void DeleteList(SList *head);
SList *IncQueue(SList *&head, SList *&tail, int n);
SList *DecQueue(SList* head, SList *tail, int n);
SList *RandQueue(SList *head, SList *tail, int n);

