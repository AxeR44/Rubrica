#ifndef DATA_H
#define DATA_H

typedef struct{
	char name[40];
	char phone[20];
}contact;

typedef struct{
	contact* contacts;
	int dimension, end;
}rubrica;

#endif