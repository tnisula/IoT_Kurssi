#include <stdio.h>
#include <math.h>

int main(void)
{
	double kateetti1 = 0;
	double kateetti2 = 0;
	double hypotenuusa = 0;
 
	printf("\nAnna kateetti1: ");
	scanf("%lf", &kateetti1);
	printf("\nAnna kateetti2: ");
	scanf("%lf", &kateetti2);
        hypotenuusa = sqrt(pow(kateetti1, 2) + pow(kateetti2, 2));
	printf("\nHypotenuusa on: %.2f\n\n", hypotenuusa);

}
