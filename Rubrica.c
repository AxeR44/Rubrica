#include<stdlib.h>
#include<stdio.h>
#include "include\data.h"
#include "include\functions.h"

//TODO cancellazione di un contatto per indice o per nome

int main(void){
	rubrica rub;
	contact dC, *res;
	int scelta;
	char nome[40];
	rubricAlloc(&rub, INITIALDIM);
	while(1){
		scelta = printMenu();
		switch(scelta){
			case 0:
				rubricFree(&rub);
				return EXIT_SUCCESS;
				break;
			case 1:
				printf("Inserisci nome: ");
				scanf("%s", dC.name);
				printf("Inserisci telefono: ");
				scanf("%s", dC.phone);
				if(!addContact(dC, &rub)){
					printf("Aggiunto con successo\n\n");
				}else{
					printf("Errore: contatto non aggiunto\n\n");
				}
				break;
			case 2:
				printf("Inserisci il nome da cercare: ");
				scanf("%s", nome);
				if((res = searchByName(nome, rub)) == NULL){
					printf("Nome non trovato\n");
				}else{
					printf("Il contatto e' stato trovato\n\nNome\t\t\tTelefono\n%s\t\t\t%s\n\n", res -> name, res-> phone);
				}
				break;
			case 3:
				printf("Inserisci il nome da cercare: ");
				scanf("%s", nome);
				approxSearchByName(nome, rub);
				break;
			case 4:
				printr(rub);
				break;
			default:
				printf("Opzione non valida: riprova");
		}
	}
}