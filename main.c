#include "stdio.h"
#include "strings.h"
#include "stdlib.h"
FILE *logstat, *prefs, *file, *accounts;
char filenam[500];
char name[100];
char nemail[50];
char temp[10];
char tempname[50];
int logged, logaction;
struct credencials
{
    char logemail[50];
    int pin;
}cred;
void main()
{

	logstat = fopen("files/logstat.dat", "rb+");
	accounts = fopen("files/accounts.dat", "ab+");
	prefs = fopen("files/prefs.dat", "rb+");

	if(logstat==NULL)
	{
		printf("Error acessing logstat");
		exit(0);
	}
	if(accounts==NULL)
	{
		printf("Error acessing accounts");
		exit(0);
	}
	if(prefs==NULL)
	{
		printf("Error acessing prefs");
		exit(0);
	}

	fscanf(logstat, "%d", &logged);

	if(logged == 0)
	{
		lout();
	}
	if(logged == 1)
	{
		lind();
	}

	fclose(logstat);
	fclose(accounts);
	fclose(prefs);
}
void lout()
{
	char mail[50];
	int logpin;
	printf("Looks like you are not logged in. 1. log in or 2. create account to get started: ");
	scanf("%d", &logaction);

	if(logaction == 1)
	{
		printf("\nEnter email: ");
		scanf("%s", mail);
		fseek(accounts, 0, SEEK_SET);

		printf("Invalid email...Press any key to exit...");
		getch();
		exit(0);
	}
	if(1)


	if(logaction == 2)
	{
		printf("Enter name, email, PIN: ");
		scanf("");

		fclose(logstat);
		logstat=fopen("files/logstat.dat", "wb+");
		fprintf(logstat, "1");
		fclose(accounts);
		fclose(logstat);
		names = fopen("files/names.dat", "rb+");
		lind();
	}
}
 void lind()
{
	char lines[100];
	int log;

	printf("Hello! Welcome to notepad. Enter 1 to open file, enter 2 to logout: ");
	scanf("%d", &log);

	if(log==2)
	{
	    fclose(logstat);
		logstat = fopen("files/logstat.dat", "w+");
		logged=0;
		fprintf(logstat, "%d",logged);
		lout();
	}
    if(log==1)
    {
        printf("Enter the filepath: ");
        scanf("%s", filenam);
    }

	file=fopen(filenam,"a+");
	if(file==NULL)
	{
		puts("Cannot open file");
		getch();
		exit(0);
	}

	puts("\nEnter a few lines of text: ");
	fflush(stdin);
	while(strlen(gets(lines))>0)
	{
		fputs(lines,file);
		fputs("\n",file);
	}
	fclose(file);
}













