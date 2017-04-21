#include <stdio.h>

void tulosta(int kork, int lev)
{
	int i, j;
	printf("\n\n");
	for(i=1; i<=kork; i++)
	{
		for(j=1; j<=lev; j++)
		{
			printf("%c", '*');	
		}
		printf("\n");
	}
	printf("\n\n");
}

int main(void)
{
	int korkeus = 0;
	int leveys = 0;

	printf("\nAnna korkeus: ");
	scanf("%d", &korkeus);
	printf("\nAnna leveys: ");
	scanf("%d", &leveys);

	tulosta(korkeus, leveys);        
	return 0;
}
