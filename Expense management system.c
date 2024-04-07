#include<stdio.h>
#include<stdlib.h>
//structure 
struct item{
	char name[20];
	float cost;
	float total;
	int date;
};

struct expenses {
    struct item *items; 
    int count;
};

//declaring functions
void menu();
struct expenses loaddata();
void clear();
void add(struct expenses *e);
void display(struct expenses e);
void saveExpenses(struct expenses e);

int main()
{
	struct expenses e;
	int n;
	char ch;
	e=loaddata();
	do{
		menu();
		printf("\n\t\t\tEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				add(&e);
				break;
			case 2:
				display(e);
				break;
			case 3:
				clear(e);
			case 4:
				saveExpenses(e);
				exit(0);
			default:
				printf("\t\t\tWrong Choice!!!\n");
				printf("\t\t\tEnter 1 to 4 only:");
		}
		
		printf("do you want to continue(y/n): ");
		scanf(" %c", &ch);
	}while(ch=='y'||ch=='Y');
	system("cls");
	return 0;
}

//menu function
void menu()
{
	system("cls");
    printf("\n\n");
    printf("\t\t\t_________________________________\n");
    printf("\t\t\t|   EXPENSE MANAGEMENT SYSTEM   |\n");
    printf("\t\t\t|_______________________________|\n\n\n\n\n");
    printf("\t\t\t_________________________________\n");
    printf("\t\t\t|   1. Add Expenses             |\n");
    printf("\t\t\t|   2. Display expenses         |\n");
    printf("\t\t\t|   3. Clear Expenses           |\n");
    printf("\t\t\t|   4. Save Expenses and Exit   |\n");
    printf("\t\t\t|_______________________________|\n");
}


//function to add expenses
void add(struct expenses *e)
{
	struct item item;
	fflush(stdin);
	printf("\n\t\t\tEnter expens on: ");
	scanf("%s",&item.name);
	printf("\n\t\t\tEnter cost: ");
	scanf("%f",&item.cost);
	
	e->items[e->count++]=item;
	printf("\n\t\t\tExpense Added\n");

	
}

//function to clear all expenses
void clear()
{
	FILE*fp;
	fp=fopen("expenses.txt","w");
	if(fp==NULL)
	{
		printf("Error clearing file!!!\n");
		exit(0);
	}
	fclose(fp);
	printf("Expenses cleared successfully\n");
}

//function to save the expenses to a file
void saveExpenses(struct expenses e)
{
	FILE *fp;
	fp=fopen("expenses.txt","wb");
	if(fp==NULL)
	{
		printf("Error opening file!!!");
		exit(0);
	}
	fwrite(&e,sizeof(e),1,fp);
	fclose(fp);
}

//functoin to load expenses
struct expenses loaddata()
{
	FILE *fp;
	struct expenses e;
	fp=fopen("expenses.txt","rb");
	if(fp==NULL)
	{
		printf("Error opening file!!!");
		e.count=0;
		return e;
	}
	fread(&e,sizeof(e),1,fp);
	fclose(fp);
	return e;
}

//function to display expenses
void display(struct expenses e)
{
	int i=0,sn=1,tcost=0;
	if(e.count==0)
	{
		printf("\n\t\t\t NO EXPENSES DONE !!!");
		exit(0);
	}
	
	printf("\t\t\tExpenses on         Cost      \n");
	printf("\t\t\t______________________________\n");
	for (i=0;i<e.count;i++)
	{
		printf("\t\t\t%-20s%-10.2f\n",e.items[i].name,e.items[i].cost);
		tcost+=e.items[i].cost  ;    
	}
	printf("\t\t\tTotal Cost of %d expens is: %d",e.count,tcost);
//	for (i = 0; i < e.count; i++) {
//        printf("%-20s $%-10.2f\n", e.items[i].name,e.items[i].cost);
//    }
//    printf("--------------------------------------------------------\n");
//    printf("Total items in inventory: %d\n", e.count);
}


