/*---------------------------------------------------
                
                CONTACT MANAGEMENT                   
                
------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void main_menu();
void options(int choice);
struct info{
	char name[50];
	long long int phone_num;
	char address[50];//address is 'email address'
}list;
	int i,j,choice,found,total=0;
	FILE *fp,*ft;
	char names[50],search;
	
int main()
{
	struct info list;
	main_menu();	
}
void main_menu()
{
	printf("\n\n\n");
	printf("\t\t\t\t\t***Contact Management***\n\n");
	printf("\t\t\t\t========================================\n");
	printf("\t\t\t\t\tPress 1:create new Contact\n\t\t\t\t\tPress 2:Edit Contact\n\t\t\t\t\tPress 3:Delete Contact\n\t\t\t\t\tPress 4:Contact List\n\t\t\t\t\tPress 5 to Exist");
	printf("\n\n\t\t\t\t\tEnter Your Choice:");
	scanf("%d",&choice);
	options(choice);
}
void options(int choice)
{
	switch(choice)
	{
		case 1://==============saving contact=================
        	system("cls");
        	fp=fopen("contact.txt","a");  
			for (;;)
        	{
            	fflush(stdin);
            	printf("Press space enter to exit\nEnter Your name:");
            	gets(list.name);
            	if(strcmp(list.name,"")==0 || strcmp(list.name," ")==0)
    				break;
				fflush(stdin);
            	printf("Phone Num:");
            	scanf("%lld",&list.phone_num);
            	fflush(stdin);
            	printf("Emailaddress:");
            	gets(list.address);
            	total++;
            	fflush(stdin);
            	printf("\n");
            	fwrite(&list,sizeof(list),1,fp);
           	}
			printf("press any key to goto main menu.");
			fclose(fp);
			if(getch())
			{	system("cls");
			   	main_menu();
			}
        	break;
		case 2:	//==============editing Contact===================
			system("cls");
	        fp=fopen("contact.txt","r");
    	    ft=fopen("temp.txt","w");
        	fflush(stdin);
        	printf("\t\t***Edit contact***\n\tEnter the name of contact to edit:");
        	gets(names);

       		while(fread(&list,sizeof(list),1,fp))
        	{
            	if(strcmp(names,list.name)!=0)
                	fwrite(&list,sizeof(list),1,ft);
        	}
        	fflush(stdin);
        	printf("\nEditing %s\n\n",names);
     	    printf("Name(Use identical):");
        	gets(list.name);
        	fflush(stdin);
        	printf("Phone:");
        	scanf("%lld",&list.phone_num);
        	fflush(stdin);
        	printf("Emailaddress:");
        	gets(list.address);
        	fflush(stdin);
        	printf("\n");
        	fwrite(&list,sizeof(list),1,ft);
        	fclose(fp);
        	fclose(ft);
        	remove("contact.txt");
        	rename("temp.txt","contact.txt");
        	printf("press any key to goto main menu.");
			if(getch())
			{	system("cls");
			   	main_menu();
			}
    	    break;
		case 3://==================deleting contact===================
			system("cls");
        	
        	printf("\n\n\t***DELETE A CONTACT***\nEnter the name of contact to delete:");
			fflush(stdin);
			gets(names);
		
        	fp=fopen("contact.txt","r");
        	ft=fopen("temp.txt","a");
       		while(fread(&list,sizeof(list),1,fp))
            {
             
				if(strcmp(names,list.name)!=0)
                	fwrite(&list,sizeof(list),1,ft);
        	}
    		fclose(fp);
        	fclose(ft);
        	remove("contact.txt");
        	rename("temp.txt","contact.txt");
        	printf("Deleted sucessfully");
        	printf("press any key to goto main menu.");
        	if(getch())
			{
				system("cls");
		 		main_menu();
			}
       		break;
		case 4://====================list of contact==================
		system("cls");
        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS");
        for(i=97; i<=122; i=i+1)
        {
            fp=fopen("contact.txt","r");
            fflush(stdin);
            found=0;
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.name[0]==i || list.name[0]==i-32)
                {
                    printf("\nName\t: %s\nPhone\t: %lld\nEmailAddress\t: %s\n",list.name,
                           list.phone_num,list.address);
                    found++;
                }
            }
            
            fclose(fp);
        }
        if(getch())
			{
				system("cls");
		 		main_menu();
			}
        	break;
		case 5:
			exit(0);
		default:
			printf("\n\t\t\t\t\t***invalid choice***");
			getch();
			system("cls");
			main_menu();
	}
}