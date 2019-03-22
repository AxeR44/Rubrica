#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define INITIALDIM 10
#include "data.h"
int addContact(contact, rubrica*);
contact* searchByName(char*, rubrica);
void approxSearchByName(char*, rubrica);
void printr(rubrica);
int printMenu();
void rubricAlloc(rubrica*, int);
void rubricRealloc(rubrica*);
void rubricFree(rubrica*);
#endif