#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomi(int min, int max) {
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main(void)
{
	int luku = 1;
	int arvaus = 0;
	int arvausmaara = 0;

	srand(time(NULL));
	luku = randomi(1, 100);

	do {
		printf("\nArvaa luku väliltä (1-100): ");
		scanf("%d", &arvaus);
		arvausmaara++;

		if(arvaus > luku) {
			printf("\nArvaamasi luku on suurempi kuin arpomani luku! ");
		}
		else if(arvaus < luku) {
			printf("\nArvaamasi luku on pienempi kuin arpomani luku!");
		}
	} while (arvaus != luku);

	printf("\nArvasit luvun %d. Yrityksia oli %d\n\n", luku, arvausmaara);

	return 0;
}
