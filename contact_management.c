/*----------------------------------------------------------------
                
                   CONTACT MANAGEMENT PROGRAM

------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<dos.h>
struct info
{
    char name[20];
    long int ph;
}list;
int p;
char name[20];
int main()
{
    FILE *fp,*ft;
    int i,ch,pno,home,found,opt;
    home:
    printf("\t\t\tCONTACT MANAGER\n\n");
    printf("\t\t\t[1] add new contact\n");
    printf("\t\t\t[2] show all contacts\n");
    printf("\t\t\t[3] Edit contact\n");
    printf("\t\t\t[0] exit\n");
    printf("\t\t\tenter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 0:
            break;
        
        case 1:
            /*===============creating a new contact==============*/
            system ("cls");
            fp=fopen("contact.txt","a");
            fflush(stdin);
            printf("enter name:");
            scanf("%[^\n]",&list.name);
            fflush(stdin);
            printf("enter phone number:");
            scanf("%ld",&list.ph);
            fflush(stdin);
            printf("\n\t\t\tcontact saved\n\n");
            fwrite(&list,sizeof(list),1,fp);
            fclose(fp);
            goto home;
        case 2:
            /*===============showing all the contacts===============*/
            system("cls");
            if(("contact.txt")==NULL){
                printf("no records found");
            }
            for(i = 97; i <= 122; i = i + 1){
                fp=fopen("contact.txt","r");
                fflush(stdin);
                found=0;
                while(fread(&list,sizeof(list),1,fp)==1){
                    if (list.name[0] == i || list.name[0] == i - 32){
                    printf("name:%s\tNumber:%ld\n",list.name,list.ph);
                    }
                found++;
                }
            }
            if (found != 0)
	        {
	            printf("=========================================================== [%c]-(%d)\n\n",i-32, found);
                getch();
            }
            fclose(fp);
            goto option;
            //===================editing contact=====================
        case 3:
            system("cls");
            fp=fopen("contact.txt","r");
            ft=fopen("temp.txt","w");
            fflush(stdin);
            printf("Edit contact\n===============================\n\n\tEnter the name of contact to edit:");
            scanf("%[^\n]",name);
            while(fread(&list,sizeof(list),1,fp))
            {
                if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
            }
            fflush(stdin);
            printf("\n\n..::Editing '%s'\n\n",name);
            printf("\tName(Use identical):");
            scanf("%[^\n]",&list.name);
            fflush(stdin);
            printf("\tPhone:");
            scanf("%ld",&list.ph);
            fflush(stdin);
            printf("\n");
            fwrite(&list,sizeof(list),1,ft);
            fclose(fp);
            fclose(ft);
            remove("contact.txt");
            rename("temp.txt","contact.txt");
            goto option;
             
   }
    option:
    printf("\n==================================\n");
    printf("\t\t\t[1]To main menu\t[0]To exit\n");
            printf(">");
            scanf("%d",&opt);
            fflush(stdin);
            switch(opt){
                case 1:
                    system("cls");
                    goto home;
                case 0:
                    system("cls");
                    printf("\n\n---------------------program terminated----------------------\n\n");
                    break;
            }
}