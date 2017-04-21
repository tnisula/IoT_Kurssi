#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
	char ostoksen_nimi[80];
	double hinta;
	int ostos_id;
} ostos;

int main(int argc, char *argv[])
{
	int id_count = 0;
	int ostos_count = 0;
	ostos *A, buffer;
	ostos myOstos[MAX_ITEMS];
	char tiedostonimi[80];
	char choice = 'a';

	if(argc == 2) {
		FILE *fileoutp;
		if ((fileoutp = fopen(argv[1], "rb")) == NULL) {
			printf("\nError opening file.\n");
			return 1;
		}
		int index=0;
		A = (ostos*) malloc(sizeof(ostos) * MAX_ITEMS);
		while (fread(&buffer, sizeof(ostos), 1, fileoutp) == 1) {
			
			strcpy((A+index)->ostoksen_nimi, buffer.ostoksen_nimi);
			(A+index)->hinta = buffer.hinta;
			(A+index)->ostos_id = buffer.ostos_id;
			index++;
		}

		fclose(fileoutp);

		for(int i=0; i<index; i++)
		{
			printf("\nOstoksen id: %d", (A+i)->ostos_id);
			printf("\nOstoksen nimi: %s", (A+i)->ostoksen_nimi);
			printf("\nOstoksen hinta: %lf\n", (A+i)->hinta);
		}
		free(A);
		return 0;
	} else if(argc > 2) {
		printf("\nLiian monta parametria.\n\n");
		return 1;
	}

	printf("\nTeen ostoslistaa. Maximi %d itemia.\n", MAX_ITEMS);
	printf("Kirjoitan itemit tiedostoon, kun annat tiedoston nimen.\n");
	printf("Jos haluat tulostaa pelkän ostoslistan, niin anna ostoslistan nimi\n");
	printf("ohjelman argumentiksi käynnistyksen yhteydessä.\n");
	
	do
	{
		printf("\n\nMenu\n====\n");
                printf("k) Kysy\n");
	 	printf("t) Talleta\n");
		printf("p) Printtaa näytölle\n");
	 	printf("q) Quit\n");
	 	scanf(" %c", &choice);
	 	switch (choice)
	 	{
			case 'k' :	printf("\nAnna ostoksen nimi: ");
					scanf("%s", myOstos[id_count].ostoksen_nimi);
					printf("\nAnna ostoksen hinta: ");
					scanf("%lf", &myOstos[id_count].hinta);
					myOstos[id_count].ostos_id = id_count;
					id_count++;
					break;
			case 't' :	printf("\nAnna ostoslistan nimi (esim. lista): ");
					scanf("%s", tiedostonimi);
					strcat(tiedostonimi, ".bin");
					printf("\nId count: %d", id_count);
					FILE *fileinp;
					if((fileinp = fopen(tiedostonimi, "wb")) == NULL) {
						printf("\nError opening file\n");
						return 1;
					}
					for (int m=0; m<id_count; m++) {
						fwrite(myOstos+m, 1, sizeof(ostos), fileinp);
					}
					fclose(fileinp);
					printf("\nKirjoitin ostoslistan tiedostoon %s.\n\n", tiedostonimi);
					break;
			case 'p' : 	printf("\nOstoslista\n==========\n");
					for(int k=0; k<id_count; k++) {
						printf("\nOstoksen id: %d", myOstos[k].ostos_id);
						printf("\nOstoksen nimi: %s", myOstos[k].ostoksen_nimi);
						printf("\nAnna ostoksen hinta: %lf", myOstos[k].hinta);
					}
		    			break;
			case 'q' : 	printf("Heippa!\n");
					exit(0); 
					break;
			default: 	printf("Väärä valinta. Valitse uudelleen!\n");
		    			break; 
		}
		 
	} while (choice != 'q');
	
	return 0;
}


