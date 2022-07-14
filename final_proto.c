#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct item
{
	char productname[20];
	int quantity;
	int price;
};
struct customer
{
    char custoname[50];
    char date [50];
    int itemssold;
    char mobile[20];
    struct item item1[50];
}c;
void invoice(char name[50],char date[50],char phone[20]);
void bodyinvoice(char productname[20],int quantity,int price);
void grandtot(float total);
void add_item();
void displayall();
void searchinvoice();
void login();
void deletefun();
void displayitem();
void menu();

void invoice(char name[50],char date[50],char phone[20])
{

	printf("\n\n");
	printf("\t     BILLING SYSTEM      \n");
	printf("\t      SUPERMARKET   \n");
	printf("\t      TEL:+25078888888   ");

	printf("\n\t    -----------------------");

	printf("\nDate:%s",date);
	printf("\nInvoice To : %s",name);
	printf("\nMobile no. : %s",phone);
	printf("\n");
	printf("--------------------------------------------------\n");
	printf("Items\t\tQty\t\tTotal\t\t");
	printf("\n--------------------------------------------------\n\n");
	}
void bodyinvoice(char productname[20],int quantity,int price)
{
       printf("%s\t\t%d\t\t%d\t\t\n",productname,quantity,quantity*price);


}
void grandtot(float total)
{
    printf("\n-------------------------------------------------------");
    printf("\nTotal\t\t\t%.2f",total);
    printf("\n-------------------------------------------------------");
}
void add_item()
{
    system("cls");
    char bill;
    char cont;
    int i,n;
    FILE *f1;

    float total=0;
    fgetc(stdin);
    printf("\nPlease enter the name of the customer:\t");
    fgets(c.custoname,50,stdin);
    c.custoname[strlen(c.custoname)-1] = 0;
    printf("\nPlease enter the date:\t\t\t");
    fgets(c.date,50,stdin);
    c.date[strlen(c.date)-1]=0;
    printf("\nPlease enter the number of tel: \t");
    fgets(c.mobile,20,stdin);
    c.mobile[strlen(c.mobile)-1] = 0;
    printf("Please enter the number of items: \t");
    scanf("%d",&n);
    c.itemssold=n;
    for(i=0;i<n;i++)
    {
        fgetc(stdin);
        printf("\n\n");
        printf("Please enter the product: %d\t",i+1);
        fgets(c.item1[i].productname,20,stdin);
        c.item1[i].productname[strlen(c.item1[i].productname)-1] = 0;
        printf("Please enter the quantity:\t");
        scanf("%d",&c.item1[i].quantity);
        printf("Please enter the unit price:\t");
        scanf("%d",&c.item1[i].price);
        total+=c.item1[i].quantity*c.item1[i].price;
    }
    invoice(c.custoname,c.date,c.mobile);
    for (i=0;i<c.itemssold;i++)
    {
     bodyinvoice(c.item1[i].productname,c.item1[i].quantity,c.item1[i].price);
    }
    grandtot(total);
    printf("\n DO YOU WANT TO SAVE THE FOLLOWING TRANSACTION (Y/N)");
    scanf("%s",&bill);
    if(!bill=='y');
    {
        f1 =fopen("invoice.txt","a+");
        fwrite(&c,sizeof(c),1,f1);
        if(!fwrite==0)
            printf("\n SAVED SUCCESSFULLY");
        else
            printf("\n NOT SAVED");
        fclose(f1);
    }
    system("cls");
    menu();


}


void displayall()
{
    system("cls");
    int toto;
    FILE *f2;
    int i;
    f2 =fopen("invoice.txt","r");
    printf("\n======= INVOICES =========");
    while(fread(&c,sizeof(c),1,f2))
    {
        toto = 0;
    invoice(c.custoname,c.date,c.mobile);
   for (i=0;i<c.itemssold;i++)
    {
     bodyinvoice(c.item1[i].productname,c.item1[i].quantity,c.item1[i].price);
     toto+=c.item1[i].quantity*c.item1[i].price;
    }
     grandtot(toto);
    }
    getch();
    system("cls");
    menu();

}
void searchinvoice()
{
    char cname[50];
    int tot;
    int i;
    int invoicecount = 0;
    FILE *f1;

    fgetc(stdin);
    printf("ENTER THE NAME OF THE CUSTOMER: \t");
    fgets(cname,50,stdin);
    cname[strlen(cname)-1] = 0;
    system("cls");
    f1=fopen("invoice.txt","r");
    printf("\n ======INVOICE OF %s ======",cname);
   while(fread(&c,sizeof(struct customer),1,f1)==1)
			{
			tot = 0;
			 if(!stricmp(c.custoname,cname))
        {
        invoice(c.custoname,c.date,c.mobile);
            for(i=0;i<c.itemssold;i++)
            {
                bodyinvoice(c.item1[i].productname,c.item1[i].quantity,c.item1[i].price);
                tot+=c.item1[i].quantity*c.item1[i].price;
            }
            grandtot(tot);
            invoicecount = 1;
        }
}
    if(!invoicecount){
    printf("\n\nSorry the invoice for %s does not exist",cname);}
        fclose(f1);
    printf("\n\n\n\tPRESS ANY KEY TO RETURN TO MAIN MENU");
    getch();
    system("cls");
    menu();
}


void login()
{
    int j=0,i=0;
    char username[10],a;
    char password[10];
    do
{
    system("cls");
    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &username);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    password[i]=getch();
	    a=password[i];
	    if(a==13) break;
	    else printf("*");
	    i++;
	}
	password[i]='\0';

	i=0;

		if(stricmp(username,"ADMIN")==0 && strcmp(password,"admin")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		j++;

		getch();//holds the screen
		system("cls");


	}
}
	while(j<=2);
	if (j>2)
	{
		printf("\nSORRY YOU HAVE ENTERED THE WRONG USERNAME AND PASSWORD FOR FOUR TIMES!!!\n");

        printf("\n\n\n\tPRESS ANY KEY TO EXIT\n");

		getch();
		exit(0);
		}

}

void deletefun()
{
    char cname[50];
    int tot;
    int i;
    int invoicecount = 0;
    FILE*ft;
    FILE *f1;
    char a;
    int found = 0;
    fgetc(stdin);
    f1=fopen("invoice.txt","r");
    ft=fopen("temp.txt","w");
        printf("ARE SURE YOU WANT TO DELETE IT \t");
        fgets(cname,50,stdin);
        cname[strlen(cname)-1] = 0;

        rewind(f1);
        while(fread(&c,sizeof(struct customer),1,f1))
        {
            if(strcmp(c.custoname,cname)){
                found=1;
            }
            else
                fwrite(&c,sizeof(c),1,ft);

                //printf("\nThe Record has been Deleted Successfully.");
        }
                fclose(f1);
                fclose(ft);
            if(found)
            {
                    ft=fopen("temp.txt","r");
                    f1=fopen("invoice.txt","w");

            while(fread(&c,sizeof(struct customer),1,ft))
                {
                   fwrite(&c,sizeof(c),1,ft);
                }

            }
            printf("WIPED THE WHOLE SYSTEM");

            getch();
            menu();
}
void displayitem()
{
    system("cls");
    int toto;
    FILE *f2;
    int i;
    f2 =fopen("invoice.txt","r");
    printf("\n======= ITEMS SOLD =========");
    printf("\n--------------------------------------------------\n");
    printf("Items\t\tQty\t\tTotal\t\t");
    printf("\n--------------------------------------------------\n\n");
    while(fread(&c,sizeof(c),1,f2))
    {
        toto = 0;
   for (i=0;i<c.itemssold;i++)
    {
     bodyinvoice(c.item1[i].productname,c.item1[i].quantity,c.item1[i].price);
     printf("\n--------------------------------------------------\n\n");
    }

    }
    getch();
    system("cls");
    menu();
}

void menu()
{
    int open;

        printf("\t\t -----------------------------------------------");
        printf("\n\t\t\t       Please Select an Option: \n");
        printf("\t\t -----------------------------------------------");
        printf("\n\t\t\t\t01. CREATE AN INVOICE \n\t");
        printf("\t\t\t02. DISPLAY ALL INVOICES \n\t");
        printf("\t\t\t03. SEARCH CUSTOMER CART \n\t");
        printf("\t\t\t04. LIST OF ALL SOLD ITEMS \n\t");
        printf("\t\t\t05. WIPE ALL THE ENTRY \n\t");
        printf("\t\t\t06. EXIT \n\n\t");
        printf("Please Enter an Option: ");

    scanf("%d",&open);
    switch(open)
           {
               system("cls");
               case 1: add_item(); break;
               case 2: displayall(); break;
               case 3: searchinvoice();  break;
               case 5: deletefun(); break;
               case 4: displayitem(); break;
               case 6: ; break;

           }


}

void main()
{
        int password;
	int phonenumber;
	char choice;
	int i;
	char a = 177,b = 219;

    system("cls");
	system("cls");

    printf("\t\t=======================================================");
	printf("\n\t\t\t------WELCOME TO THE BILLING SYSTEM------\n");
    printf("\t\t=======================================================\n");

	printf("\n\n\n\t\t Press Any Key To Continue. . ");
	getch();
    system("cls");
	login();
    system("cls");
    menu();
}
