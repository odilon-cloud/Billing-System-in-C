#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct items{
	char item[20];
	float price;
	int qty;
};

struct orders
{
	char customer[50];
	char date[50];

	char mobile[20];
	int numOfItems;
	struct items itm[50];
};
void generateBillHeader(char name[50],char date[50],char mobile[20]){
	printf("\n\n");
	printf("\t     PARADISE Restaurant");
	printf("\n\t     --------------------");
	printf("\nDate:%s",date);;
	printf("\nInvoice To : %s",name);
	printf("\nMobile no. : %s",mobile);
	printf("\n");
	printf("--------------------------------------------------\n");
	printf("Items\t\t");
	printf("Qty\t\t");
	printf("Total\t\t");
	printf("\n--------------------------------------------------");
	printf("\n\n");
}
void generateBillBody(char item[30],int qty,float price){
	printf("%s\t\t",item);
	printf("%d\t\t",qty);
	printf("%.2f\t\t",qty*price);
	printf("\n");
}
void generateBillFooter(float total){
printf("\n");
float dis = 0.1*total;
float nettotal=total-dis;
float cgst=0.09*nettotal,grandtotal=nettotal+2*cgst; // Grand Total = Net Total + CGST + SGST (CGST = SGST = 9% OF Net total)
printf("-------------------------------------\n");
printf("Sub Total\t\t\t%.2f",total);
printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
printf("\n\t\t\t\t-------");
printf("\nNet Total\t\t\t%.2f",nettotal);
printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
printf("\n-------------------------------------------------------");
printf("\nGrand Total\t\t\t%.2f",grandtotal);
printf("\n-------------------------------------------------------");
}

int main()
{
	int opt,n,i,OPT,invoicefound;
	float total,tot;
	char saveBill = 'y',continuetask = 'y';
	char name[50];
	char mobilenumber[30];
	struct orders ord;
	struct orders order;
	FILE *fp;
	//Dashboard

	while(continuetask == 'y'||continuetask =='Y')
	{

		total = 0;
		invoicefound=0;


	printf("\t########## PARADISE RESTAURANT ########## ");
	printf("\nPlease select your preferred task\t\t\t\t");
	printf("\n1.Generate Invoice");
	printf("\n2.Show all Invoices");
	printf("\n3.Search Invoice");
	printf("\n4.Exit");

	printf("\n\nYour Option\t");
	scanf("%d",&opt);
	fgetc(stdin);
	switch(opt)
	{
		case 1:

			system("cls");

			printf("\nPlease enter the name of the customer:\t");
			fgets(ord.customer,50,stdin);
			ord.customer[strlen(ord.customer)-1] = 0;
			printf("\nPlease eneter the date:\t\t\t");
			fgets(ord.date,50,stdin);
			ord.date[strlen(ord.date)-1] = 0;
			printf("\nEnter the mobile no.of  the customer:\t");
			fgets(ord.mobile,20,stdin);
			ord.mobile[strlen(ord.mobile)-1] = 0;
			printf("\nPlease enter the number of items-->\t");
			scanf("%d",&n);
			ord.numOfItems = n;
	        for(i=0;i<n;i++)
			{
				fgetc(stdin);
				printf("\n\n");
				printf("Please enter the item--> %d\t",i+1);
				fgets(ord.itm[i].item,20,stdin);
				ord.itm[i].item[strlen(ord.itm[i].item)-1] = 0;
		        printf("Please enter the quantity:\t");
		        scanf("%d",&ord.itm[i].qty);
		        printf("Please enter the unit price:\t");
		        scanf("%f",&ord.itm[i].price);
		        total+=ord.itm[i].qty*ord.itm[i].price;
			}

			generateBillHeader(ord.customer,ord.date,ord.mobile);
			for(i=0;i<ord.numOfItems;i++)
			{
				generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);

			}
			generateBillFooter(total);
			printf("\nDo you want to save the invoice than press y if not than press n:\t");
			scanf("%s",&saveBill);
			if(!saveBill=='y');
			{
				fp = fopen("RestaurantBillsd.txt","a+");
				fwrite(&ord,sizeof(struct orders),1,fp);
				if(!fwrite==0)
				printf("\nSucessfully Saved");
				else
				printf("\nSorry! Error in saving");
				fclose(fp);
			}
			break;
			case 2:

				system("cls");
				fp = fopen("RestaurantBillsd.txt","r");
				printf("\n ======== PREVIOUS INVOICES ========");
			while(fread(&order,sizeof(struct orders),1,fp))
			{
			tot = 0;
			generateBillHeader(order.customer,order.date,order.mobile);
			for(int i=0;i<order.numOfItems;i++)
			{
				generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
				tot+=order.itm[i].qty*order.itm[i].price;
			}
			generateBillFooter(tot);
		}
		fclose(fp);
		break;

		case 3:

				printf("Enter the name of the customer:\t");
			fgets(name,50,stdin);
			name[strlen(name)-1] = 0;

			system("cls");
				fp = fopen("RestaurantBillsd.txt","r");
				printf("\n ======== INVOICE of %s ========",name);
			while(fread(&order,sizeof(struct orders),1,fp))
			{
			tot = 0;

			if(!stricmp(order.customer,name))
			{
	     generateBillHeader(order.customer,order.date,order.mobile);
			for(int i=0;i<order.numOfItems;i++)
			{
				generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
				tot+=order.itm[i].qty*order.itm[i].price;
			}
			generateBillFooter(tot);
			invoicefound = 1;

		}

        }
        if(!invoicefound)
        {
        	printf("\n\nSorry the invoice for %s doesnot exist",name);
		}


		fclose(fp);
		break;

		case 4:
			printf("\n\n\n\t\t Bye Bye Bye :)\n\n\n ");
			exit(0);
			break;

			default:
				printf("Sorry you have chosen invalid option");
				break;
			}

			printf("\n\nIf you wanto perform another task than press y if not than press n:\t");
			scanf("%s",&continuetask);
			printf("\n");


			}

	return 0;
}
