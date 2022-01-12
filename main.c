#include "stdio.h"
#include "strings.h"
#include "stdlib.h"
FILE *logstat, *file, *accounts;
char filenam[500];
int logged, logaction;
struct credencials
{
    char logemail[50];
    int pin;
}cred;
struct newAccount
{
    char nemail[100];
    char name[100];
    int npin;
}newAcc;
struct tempAcc
{
    char logemail[100];
    char name[100];
    int pin;
}tempAcc;

//If logged out this will try to log you in.

void loggedOut()
{
	char mail[50];
	int logpin;
	printf("Looks like you are not logged in. 1. log in or 2. create account to get started: ");
	scanf("%d", &logaction);

	if(logaction == 1)
	{
        fclose(accounts);
		fopen("files/accounts.dat", "rb+");
		int login = 0;
        while(login == 0)
        {
            printf("\nEnter email and pin: ");
            scanf("%s %d", cred.logemail, &cred.pin);
            while(fread(&tempAcc, sizeof(tempAcc), 1, accounts)!=NULL)
            {
                if(strcmp(cred.logemail, tempAcc.logemail)==0)
                {
                    if(tempAcc.pin==cred.pin)
                    {
                        login = 1;
                        loggedIn();
                    }

                }
            }
            printf("\nInvalid ID");
        }
        getch();
        exit(0);
	}

	if(logaction == 2)
	{
		printf("\nEnter email, name and pin: ");
		scanf("%s %s %d", newAcc.nemail, newAcc.name, &newAcc.npin);
		fwrite(&newAcc, sizeof(newAcc), 1, accounts);

		loggedIn();
	}
}

//Main NotePad code

void loggedIn()
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
		loggedOut();
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

//All the code that runs to check everything is fine and also initialises files and error checks.

void main()
{

	logstat = fopen("files/logstat.dat", "rb+");
	accounts = fopen("files/accounts.dat", "ab+");

	if(logstat==NULL)
	{
		printf("Error acessing logstat");
		getch();
		exit(0);
	}
	if(accounts==NULL)
	{
		printf("Error acessing accounts");
		getch();
		exit(0);
	}
	fscanf(logstat, "%d", &logged);

	if(logged == 0)
	{
		loggedOut();
	}
	if(logged == 1)
	{
		loggedIn();
	}

	fclose(logstat);
	fclose(accounts);
	fclose(file);
}
