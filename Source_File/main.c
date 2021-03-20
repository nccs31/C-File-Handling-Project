#include<stdio.h>
#include<stdlib.h>
FILE *f1,*f2;
int val; //for do..while loop ans

//structure
typedef struct{
	int id;
	char fname[18];
	char lname[18];
	int age;
	int level;
}student;

//display records
void displayRecord(){
	student std;
	f1=fopen("studentDetail.txt","r"); //opening file in read mode
	printf("---------------------------------------------------\n");
	printf("Id First Name        Last Name         Age  Level\n");
	printf("---------------------------------------------------\n");
	while(fscanf(f1,"%d %s %s %d %d",&std.id,std.fname,std.lname,&std.age,&std.level)!=EOF){
		printf("%2d %-18s %-18s %2d %6d\n",std.id,std.fname,std.lname,std.age,std.level);
	}
	printf("Press any key to continue..\n");
	//getch();
	fclose(f1);
}

//write all records
void writeRecord(){
	f1=fopen("studentDetail.txt","w"); //opening file in write mode
	student std; //defining structure varaible
	if(f1==NULL){
		printf("File creation error");
		exit(1);
	}
	do {
		fflush(stdin);
		printf("Enter the id of student:");
		scanf("%d",&std.id);
		printf("Enter the first name of student:");
		scanf("%s",std.fname);
		printf("Enter the last name of student:");
		scanf("%s",std.lname);
		printf("Enter the age of student:");
		scanf("%d",&std.age);
		printf("Enter the level of student:");
		scanf("%d",&std.level);
		
		//adding to the file
		fprintf(f1,"%d %s %s %d %d\n",std.id,std.fname,std.lname,std.age,std.level);
		printf("Added a new record..\n");
		printf("Do you want to add another record?\n");
		printf("NOTE:Enter \'1\' to add another record and press any key to continue.\n");
		printf("->");
		scanf("%d",&val);
		system("cls");
	}while(val==1);
	printf("\nAdded all the new recorders to new file.\n");
	fclose(f1);
	displayRecord();
}

//add record in existing file.
void addRecord(){
	displayRecord();
	f1=fopen("studentDetail.txt","a"); //opening file in apoend mode
	student std; //defining structure varaible
	if(f1==NULL){
		printf("File creation error");
		exit(1);
	}
	do {	
		fflush(stdin);
		printf("Enter the id of student:");
		scanf("%d",&std.id);
		printf("Enter the first name of student:");
		scanf("%s",std.fname);
		printf("Enter the last name of student:");
		scanf("%s",std.lname);
		printf("Enter the age of student:");
		scanf("%d",&std.age);
		printf("Enter the level of student:");
		scanf("%d",&std.level);
		
		//adding to the file
		fprintf(f1,"%d %s %s %d %d\n",std.id,std.fname,std.lname,std.age,std.level);
		printf("Added a new record..\n");
		printf("Do you want to add another record?\n");
		printf("NOTE:Enter \'1\' to add another record and press any key to continue.\n");
		printf("->");
		scanf("%d",&val);
		system("cls");
	}while(val==1);
	printf("Added all the new recorders to new file.");
	fclose(f1);
}

//update record
void updateRecord(){


}

//delete record
void deleteRecord(){
	int id;
	displayRecord();
	f1=fopen("studentDetail.txt","r"); //opening file in apoend mode
	f2=fopen("temp.txt","w");//temporary write file
	student std; //defining structure varaible
	if(f1==NULL){
		printf("File creation error");
		exit(1);
	}
	printf("Enter the id of a student to delete:");
	scanf("%d",&id);
	while(fscanf(f1,"%d %s %s %d %d",&std.id,std.fname,std.lname,&std.age,&std.level)!=EOF){
		if(std.id==id){
			printf("Successfully deleted.");
			continue;
		}
		fprintf(f2,"%d %s %s %d %d\n",std.id,std.fname,std.lname,std.age,std.level);
	}
	fclose(f1);
	fclose(f2);
	int a=remove("studentDetail.txt");
	int b=rename("temp.txt","studentDetail.txt");

}

//used for switch used statement, line 18
void switchFunc(int n){
	switch(n){
		case 1:
			system("cls");
			printf("-----------------------\n");
			printf("            Add new record\n");
			printf("(this will delete all the previous records)\n");
			printf("-----------------------\n");
			writeRecord();
			break;
		case 2:
			system("cls");
			printf("-----------------------\n");
			printf("Add new record\n");
			printf("-----------------------\n");
			addRecord();
			break;
		case 3:
			system("cls");
			printf("-----------------------\n");
			printf("Update new record\n");
			printf("-----------------------\n");
			updateRecord();
			break;
		case 4:
			system("cls");
			printf("-----------------------\n");
			printf("Delete a file...\n");
			printf("-----------------------\n");
			deleteRecord();
			break;
		case 5:
			system("cls");
			printf("-----------------------\n");
			printf("Displaying all the records..\n");
			printf("-----------------------\n");
			displayRecord();
			break;
		case 6:
			printf("Enter any key to exit...");
			//getch();
			printf("Exiting from the program..");
			exit(1);
		default:
			printf("You have enter wrong index number...\n");
			printf("Please try again..\n");
			//displayMenu();
	}
}	


void displayMenu(){
	int choose;
	printf("-----------------------\n");
	printf("Displaying menu..\n");
	printf("-----------------------\n");
	printf("1.Write all record\n");
 	printf("2.Add a record\n");
 	printf("3.Update a record\n");
 	printf("4.Delete a record\n");
	printf("5.View all the record\n");
 	printf("6.Exit\n");
 	printf("-----------------------\n");
 	printf("Enter the index:");
 	scanf("%d",&choose);
 	switchFunc(choose);
 	system("cls");
 	displayMenu();//calling itself	 
}


void main(){
	displayMenu();
	fclose(f1);
}


