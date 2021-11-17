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
    long ph;
}list;
int p;

int main()
{
    FILE *fp;
    int i,ch,pno,home,found,opt;
    home:
    printf("\t\t\tCONTACT MANAGER\n\n");
    printf("\t\t\t[1] add new contact\n");
    printf("\t\t\t[2] show all contacts\n");
    printf("\t\t\t[3] search by number\n");
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
            fp=fopen("contacts.dll","a");
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
            if(("contacts.dll")==NULL){
                printf("no records found");
            }
            for(i = 97; i <= 122; i = i + 1){
                fp=fopen("contacts.dll","r");
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
	            printf("=========================================================== [%c]-(%d)\n",i - 32, found);
	        }
            printf("\t\t\t[1]To main menu\t[2]To exit\n");
            printf(">");
            scanf("%d",&opt);
            fflush(stdin);
            switch(opt){
                case 1:
                    system("cls");
                    goto home;
                case 2:
                    system("cls");
                    printf("---------------------program terminated----------------------");
                    break;
            }
   }
}