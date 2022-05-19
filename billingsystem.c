#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>



struct systemuser
{
char phonenumber[20];
char name[50];
float amount;
}s;

void main()
{
    int one;
    printf(" \n\n  1 : Add New Records.\n\n  2 : List Of Records \n\n  3 : Delete Records\n\n\n");


    printf("please enter your choice\t");
    one= getche();
    one= toupper(one);
    switch(one){
    case '1':
    addrecords();break;
    case '2':
    listrecords();break;
    case '3':
    deleterecords();break;
    case '4':
    ();break;

    }
}

void addrecords()
{
	FILE *p;
	int ch,i;
	char test;
	p=fopen("records.txt","ab+");
	if(p==0)
	{   p=fopen("records.txt","wb+");
        system("cls");
		printf("Please wait while we configure your computer");
		printf("\npress any key to continue");
		getch();
	}
	while(1) //loop runs indefinetly
	{
        system("cls");
		printf("\n Enter phone number: ");
		scanf("%s",&s.phonenumber);
    ch = strlen (s.phonenumber);
    for (i=0;i<ch; i++)
         if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            printf ("Entered input is not a number\n");
                break;
        }
		printf("\n Enter name: ");
		fflush(stdin);
		scanf("%s",&s.name);
		printf("\n Enter amount: ");
		scanf("%f",&s.amount);
		fwrite(&s,sizeof(s),1,p);
		fflush(stdin);
		printf("\n\n Record Is Successfully Added");
		printf("\n Press esc Key to exit or Press any other key to add other record:");
		test=getche();
		if(test==27)
            break;
	}
	fclose(p);
	system("cls");

}
void listrecords()
{
FILE *p;
	int i;
	if((p=fopen("records.txt","rb"))==NULL)
		exit(0);
	system("cls");
	printf("Phone Number\t\tUser Name\tAmount\n");
	for(i=0;i<79;i++)//for the table
		printf("-");
	while(fread(&s,sizeof(s),1,p)==1)//fread function
	{
		printf("\n%s\t\t%s\t\t$ %.2f /-",s.phonenumber,s.name,s.amount);
	}
	printf("\n");
	for(i=0;i<79;i++)//for the table design
		printf("-");

fclose(p);
printf("\n\nPress Any Key To Go Back");
getch();
system("cls");

}
void deleterecords()
{
	FILE *f,*t;
	char phonenumber[20];
	system("cls");
	f=fopen("records.txt","rb+");//read binary
	t=fopen("newrecords.txt","wb+");// write binary
	do{
	rewind(f);
	printf("Enter the phone number to be deleted from the Database: ");
	scanf("%s",phonenumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)!=0)
		{       	fwrite(&s,sizeof(s),1,t);

		}
		else
		printf("Record deleted successfully.");
	}

	fclose(f);
	fclose(t);
	remove("records.txt");
	rename("newrecords.txt","records.txt");

	f=fopen("records.txt","rb+");
	t=fopen("newrecords.txt","wb+");
    printf("\nDo you want to delete another record (y/n):\t");
	fflush(stdin);
	  }
    	while(getche()=='y'||getche()=='Y');
		fclose(f);
	getch();
	system("cls");
}
void searchrecords()
{
	FILE *f;
	char phonenumber[20];
	int flag=1;
	f=fopen("records.txt","rb+");

	fflush(stdin);
	system("cls");
	printf("Enter Phone Number to search in our database: ");
	scanf("%s", phonenumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{	system("cls");
			printf(" Record Found ");
			printf("\n\nPhonenumber: %s\nName: %s\nAmount: $%0.2f\n",s.phonenumber,s.name,s.amount);
			flag=0;
			break;
		}
		else if(flag==1)
		{	system("cls");
			printf("Requested Phone Number Not found in our database");
		}
	}
	getch();
	fclose(f);
	system("cls");
}
void modifyrecords()
{
		FILE *f;
	char phonenumber[20];
	long int size=sizeof(s);
	if((f=fopen("records.txt","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter phone number of the subscriber to modify: ");
	scanf("%s",phonenumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{
			system("cls");
			printf("\n Enter phone number: ");
			scanf("%s",&s.phonenumber);
			printf("\n Enter name: ");
			fflush(stdin);
			scanf("%[^\n]",&s.name);
			printf("\n Enter amount: ");
			scanf("%f",&s.amount);
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	fclose(f);
	system("cls");
}



