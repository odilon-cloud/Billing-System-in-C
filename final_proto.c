#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct item
{
	char productname[20];
	int quantity;
	int price;
}
item;
struct customer
{
    char custoname[50];
    char date [50];
    int itemssold;
    char phone[20];
    struct item item1[50];
}
c;
void invoice(char name[50],char date[50],char phone[20])
{

	printf("\n\n");
	printf("\t     BILLING SYSTEM      \n");
	printf("\t    PARADISE Restaurant   ");
	printf("\n\t    -----------------------");
	printf("\nDate:%s",date);
	printf("\nInvoice To : %s",name);
	printf("\nMobile no. : %s",phone);
	printf("\n");
	printf("--------------------------------------------------\n");
	printf("Items\t\tQty\t\tTotal\t\t");
	printf("\n--------------------------------------------------\n\n");
	}
void bodyinvoice(char productname[30],int quantity,float price)
{
       printf("%s\t\t%d\t\t%.2f\t\t\n",item.productname,quantity,quantity*price);

    printf("\n-------------------------------------------------------");
}
void grandtot(float total)
{
    printf("\nTotal\t\t\t%.2f",total);
    printf("\n-------------------------------------------------------");
}
void add_item()
{
    /*FILE *fp;
    int n=0;
    int i=0;
    fp =fopen("Records.txt","ab");
    if(fp == NULL)
    {
        printf("Error\n");
    }
    printf("\t ENTER THE NUMBER OF RECORDS: ");
    scanf("%d/n",&n);
    FILE *food;
    food=fopen ("index.txt","w");
    //fprintf(fp,"productid\t|ProductName\t|Quantity\t|Price\t\n");
    fprintf(food,"%d",&n);
    fclose(food);
    while(i<n)
    {
		printf("\t");
		printf("Enter Product Name:");
		scanf("%s",item.productname);
		printf("\t");
		printf("Enter Quantity:");
		scanf("%d",&item.quantity);
		printf("\t");
		printf("Enter Price:");
		scanf("%d",&item.price);
		printf("\n");
		i++;
        fprintf(fp,"%s\t\t%d\t\t%d\t\n",item.productname,item.quantity,item.price);
    }
    fclose(fp);
    printf("\t Records are Created \n\n");
    */
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
    scanf("%d",c.phone,20,stdin);
    c.phone[strlen(c.phone)-1] = 0;
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
        scanf("%f",&c.item1[i].price);
        total+=c.item1[i].quantity*c.item1[i].price;
    }
    invoice(c.custoname,c.date,c.phone);
    for (i=0;i<c.itemssold;i++)
    {
    bodyinvoice(c.item1[1].productname,c.item1[i].quantity,c.item1[i].price);
    }
    grandtot(total);
    printf("\n DO YOU WANT TO SAVE THE FOLLOWING TRANSACTION (Y/N)");
    scanf("%s",&bill);
    if(!bill=='y');
    {
        f1 =fopen("invoice.txt","a+");
        fwrite(&c,sizeof(struct item),1,f1);
        if(!fwrite==0)
            printf("\n SAVED SUCCESSFULLY");
        else
            printf("\n NOT SAVED");
        fclose(f1);
    }



}

void display()
{
    int a=0;
    FILE *f1;
    f1=fopen("Records.txt","r");
    if((f1=fopen("Records.txt","rb"))== NULL)
    {
        printf("Error in opening Files\n");
        exit(0);
    }
    printf("==============================================================\n");
	printf("|Product Number\t|Product Name\t|Quantity\t|Price\t\n");
	printf("==============================================================\n");
	while(1)
    {
        fread(&item,sizeof(item),1,f1);
        if(feof(f1))
        {
            break;
        }
    printf("%s\t%d\t%d\t\n\n",item.productname,item.quantity,item.price);
    }
    fclose(f1);
    printf("\n\n Press Any key to go back");
    //getch();

}
void deletefile()
{
    FILE *f2,*f3;
    char productname[20];
    f2=fopen("Records.txt","rb+");
    f3=fopen("rec1.txt","wb+");

        rewind(f2);
        printf("enter the product name to delete");
        scanf("%s",productname);
        while(fread(&item,sizeof(item),1,f2)==1)
    {
        if(strcmp(item.productname,productname)!=0)
        {
            fwrite(&item,sizeof(item),1,f3);
        }
        else
            printf("record deleted. ");
    }
    fclose(f2);
    fclose(f3);
    remove ("Records.txt");
    rename ("rec1.txt","Records.txt");


}




void main()
{
    int open;
    printf ("press \n");
    scanf("%d",&open);
    switch(open)
           {
               case 1: add_item(); break;
               case 2: display(); break;
               case 3:  break;
           }

}


