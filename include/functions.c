#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions.h"
#include "data.h"

int addContact(contact newContact, rubrica* mRubrica){
	contact* tmp;
	if(mRubrica->dimension == 100 && mRubrica->end == 100){
		printf("Sono gia' presenti 100 contatti");
		return -1;
	}
	if((*mRubrica).end == mRubrica->dimension - 1 && mRubrica->dimension + 10 <= 100){
		rubricRealloc(mRubrica);
	}
	else if(mRubrica->dimension + 10 > 100){
		printf("Sono gia' presenti 100 contatti. Impossibile allocare la memoria");
		return -1;
	}
	tmp = mRubrica->contacts;
	tmp += mRubrica->end;
	strcpy(tmp->name, newContact.name);
	strcpy(tmp->phone, newContact.phone);
	++mRubrica->end;
	return 0;
}

contact* searchByName(char* name, rubrica mRubrica){
	contact* tmp = mRubrica.contacts;
	while(tmp < mRubrica.contacts + mRubrica.end){
		if(!strcmp(name, tmp->name))
			return tmp;
		++tmp;
	}
	return NULL;
}

void approxSearchByName(char* name, rubrica mRubrica){
	contact* tmp = mRubrica.contacts;
	int len = (int)strlen(name), found = 0;
	printf("Contatti trovati:\nNome\t\t\tTelefono\n\n");
	while (tmp < mRubrica.contacts + mRubrica.end) {
		if (!strncmp(name, tmp->name, len)) {
			//print result
			found = 1;
			printf("%s\t\t\t%s\n\n", tmp -> name, tmp -> phone);
		}
		++tmp;
	}
	if (!found) {
		printf("Nessun contatto trovato\n");
	}
}

void printr(rubrica mRubrica){
	contact* dummy = mRubrica.contacts;
	int offset = 0;
	printf("Indice\t\t\tNome\t\t\tTelefono\n");
	while(dummy + offset < mRubrica.contacts + mRubrica.end){
		printf("%d\t\t\t%s\t\t\t%s\n", offset + 1, (dummy+offset)->name, (dummy+offset)->phone);
		++offset;
	}
}

int printMenu(){
	int scelta;
	printf("********************Rubrica Menu'********************\n");
	printf("1) Aggiungi nuova voce in rubrica\n2) Ricerca esatta per nome\n3) Ricerca approssimata per nome\n4) Stampa completa rubrica\n0) Esci dal programma\nInserisci la tua scelta (0-4):");
	scanf("%d", &scelta);
	return scelta;
}

void rubricAlloc(rubrica* mRubrica, int dimension){
	mRubrica->contacts = (contact*)malloc(dimension * sizeof(contact));
	mRubrica->dimension = dimension;
	mRubrica->end = 0;
}

void rubricRealloc(rubrica* mRubrica){
	mRubrica->dimension += 10;
	mRubrica->contacts = (contact*)realloc(mRubrica->contacts, (mRubrica->dimension) * sizeof(contact));
}

void rubricFree(rubrica* mRubrica){
	free((*mRubrica).contacts);
}