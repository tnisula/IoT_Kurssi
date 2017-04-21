#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randomi(int min, int max) {
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main(void)
{
	int indeksi = 0;
	char nimi[80], vastaus[80];
	char *kysymyksia[12] = {"Kysymys0", "Kysymys1", "Kysymys2", 
				"Kysymys3", "Kysymys4", "Kysymys5",
				"Kysymys6", "Kysymys7", "Kysymys8",
				"Kysymys9", "Kysymys10", "Kysymys11"};
	
	srand(time(NULL));
	strcpy(nimi, "");
	strcpy(vastaus, "");
	

	printf("\nKirjoita nimesi: ");
	scanf("%s", nimi);

	while (strcmp(vastaus, "bye") != 0) {
		indeksi = randomi(0, 11);

		printf("\n%s: ", kysymyksia[indeksi]);
		scanf("%s", vastaus);
	} 

	printf("\nHyvää päivänjatkoa %s.\n\n", nimi);

	return 0;
}
