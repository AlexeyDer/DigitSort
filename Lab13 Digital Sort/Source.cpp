#include "spis_func.h"
using byte = unsigned char;

void QuickSort_2(int *a, int L, int R);

int M = 0, C = 0;


SList* DigitSort_straight(SList *&S, int L)
{
	tLE Q[256];
	SList *p;
	M = 0;
	

	for (int j = L; j > 0; --j) {
		for (int i = 0; i < 256; i++)
			Q[i].tail = (SList*)&Q[i].head;

		p = S;
		int k = p->KDI[j];
		while (p) {
			++M;
			int d = p->Digit[k];
			Q[d].tail->next = p;
			Q[d].tail = p;
			p = p->next;
		}
		
		p = (SList*)&S; 
		for (int i = 0; i < 256; i++) {
			if (Q[i].tail != (SList*)&Q[i].head) {
				++M;
				p->next = Q[i].head;
				p = Q[i].tail;
			}
		}
		p->next = NULL;
	}
	return S;
}

SList* DigitSort_back(SList *&S, int L)
{
	tLE Q[256];
	SList *p;
	M = 0;


	for (int j = L; j > 0; --j) {
		for (int i = 255; i >= 0; i--)
			Q[i].tail = (SList*)&Q[i].head;

		p = S;
		int k = p->KDI[j];
		while (p) {
			++M;
			int d = p->Digit[k];
			Q[d].tail->next = p;
			Q[d].tail = p;
			p = p->next;
		}

		p = (SList*)&S;
		for (int i = 255; i >= 0; i--){
			if (Q[i].tail != (SList*)&Q[i].head) {
				++M;
				p->next = Q[i].head;
				p = Q[i].tail;
			}
		}
		p->next = NULL;
	}
	return S;
}


#define N 500

int main()
{
	srand(time(NULL));

		cout << "Write bits: " << endl;
		int L;
		cin >> L;
		system("cls");
		cout << "1.Stright\n2.Back" << endl;
		int c;
		cin >> c;
		system("cls");

		SList *p = NULL;

		cout << "Print Inc Massive: " << "\nBefor: ";
		p = IncStack(p, N);
		PrintList(p);
		cout << "\nAfter: ";
		if (c == 1)
			p = DigitSort_straight(p, L);
		else
			p = DigitSort_back(p, L);
		PrintList(p);
		cout << "Sum series: " << SericeList(p);
		cout << "\nSum Moves: " << M << endl << endl;
		DeleteList(p);

		cout << "Print Dec Massive: " << "\nBefor: ";
		p = DecQueue(p, p, N);
		PrintList(p);
		cout << "\nAfter: ";
		if (c == 1)
			p = DigitSort_straight(p, L);
		else
			p = DigitSort_back(p, L);
		PrintList(p);
		cout << "Sum series: " << SericeList(p);
		cout << "\nSum Moves: " << M << endl << endl;

		cout << "Print Rand Massive: " << "\nBefor: ";
		p = RandQueue(p, p, N);
		PrintList(p);
		cout << "\nAfter: ";
		if (c == 1)
			p = DigitSort_straight(p, L);
		else
			p = DigitSort_back(p, L);
		PrintList(p);
		cout << "Sum series: " << SericeList(p);
		cout << "\nSum Moves: " << M << endl << endl;
		DeleteList(p);
	

	
		
	

	cin.get();
	cin.get();
	return 0;
}
