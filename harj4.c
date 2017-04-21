#include <stdio.h>
#include <math.h>

double yhteenlasku(double lu1, double lu2)
{
	return lu1 + lu2;
}

double vahennyslasku(double lu1, double lu2)
{
	return lu1 - lu2;
}

double kertolasku(double lu1, double lu2)
{
	return lu1 * lu2;
}

double jakolasku(double lu1, double lu2)
{
	return lu1 / lu2;
}

int main(void)
{
	double luku1 = 0;
	double luku2 = 0;
	char ch;

	printf("\nAnna luku1: ");
	scanf("%lf", &luku1);
	printf("\nAnna luku2: ");
	scanf("%lf", &luku2);
        printf("\nAnna laskutoimitus(+,-,* tai /) : ");
	scanf(" %c", &ch);

	switch (ch)
 	{
		case '+' :	printf("\nLuvut laskettuna yhteen: %.2lf\n\n", yhteenlasku(luku1, luku2));
				break;
		case '-' :	printf("\nLuvut vähennettynä: %.2lf\n\n", vahennyslasku(luku1, luku2));
				break;
		case '*' : 	printf("\nLuvut kerrottuna yhteen: %.2lf\n\n", kertolasku(luku1, luku2));
	    			break;
		case '/' : 	printf("\nLuvut jaettuna: %.2lf\n\n", jakolasku(luku1, luku2));
				break;
		default: 	printf("Väärä laskutoimitus.\n");
	    			break; 
	}
        
	return 0;
}
