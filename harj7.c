#include <stdio.h>
#include <stdlib.h>

void savetofile(char* name)
{
	FILE *file = fopen("test.txt", "a");
	fputs(name,file);
	fputs("\n",file);
	fclose(file);
}

void printfile()
{
	int c;
	FILE *file;
	file = fopen("test.txt", "r");
	if (file) {
		while ((c = getc(file)) != EOF)
		    putchar(c);
		fclose(file);
	}
}

int main(void)
{
	char choice = 'a';
    	char *name;
	
	do
	{
		printf("\n\nMenu\n====\n");
                printf("a) Ask a name\n");
	 	printf("s) Save\n");
		printf("p) Print\n");
	 	printf("q) Quit\n");
	 	scanf(" %c", &choice); 
	 	switch (choice)
	 	{
			case 'a' :	printf("\nEnter a name: ");
					scanf("%s", name);
					break;
			case 's' :	savetofile(name);
					break;
			case 'p' : 	printf("\nNames\n=====\n");
					printfile();
		    			break;
			case 'q' : 	printf("Goodbye\n");
					exit(0); 
					break;
			default: 	printf("Wrong Choice. Enter again\n");
		    			break; 
		}
		 
	} while (choice != 'q');
}
