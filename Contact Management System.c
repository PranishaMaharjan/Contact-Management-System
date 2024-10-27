#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


struct data{
	
	long long int num;
	char name[30];
	char address[20];
	char email[50];
}d;



int main()
{
	
	FILE *fp,*fq;
	int choice;
	int i=0,l;
	char add,menu,searchmore,exit;
	char search[40],edit[40],name[30],del[40];
	int found,compare;
	
	
	printf("\n");
	printf("\n\t*************************************************\n");
	printf("\t#\tWELCOME TO CONTACT MANAGEMENT SYSTEM\t#\t");
	printf("\n\t*************************************************\n\n");
	
	
	label:
		
	printf("\n\t\tMAIN MENU\n");
	printf("\t\t---------\n");
	printf("\t\t*=======================*\n");
	printf("\t\t|   1. ADD a CONTACT\t|\n");
	printf("\t\t*-----------------------*\n");
	printf("\t\t|   2. LIST OF CONTACTS\t|\n");
	printf("\t\t*-----------------------*\n");
	printf("\t\t|   3. SEARCH CONTACTS\t|\n");
	printf("\t\t*-----------------------*\n");
	printf("\t\t|   4. EDIT CONTACTS\t|\n");
	printf("\t\t*-----------------------*\n");
	printf("\t\t|   5. DELETE CONTACTS\t|\n");
	printf("\t\t*-----------------------*\n");
	printf("\t\t|   0. EXIT\t\t|\n");
	printf("\t\t*=======================*\n\n\n");
	
	printf("\n\tChoose a Number: ");
	scanf("%d",&choice);
	printf("\n\n\n");
	
	
	
	switch(choice){
		
		
		
		
		case 1:
			
			system("cls");
			
			printf("\n\n\t\t*===========*\n");
			printf("\t\t ADD CONTACT\n");
			printf("\t\t*===========*\n\n\n");
			
			fp=fopen("contact.dat","a");
			
			do{
				printf("\n\t\tEnter name: ");
				fflush(stdin);
				gets(d.name);
				printf("\t\tEnter address: ");
				fflush(stdin);
				gets(d.address);
				printf("\t\tEnter phone number: ");
				scanf("%lld",&d.num);
				printf("\t\tEnter email address: ");
				fflush(stdin);
				gets(d.email);
				printf("\n\t\tAdd another contact? (y/n): ");
				fflush(stdin);
				scanf("%c",&add);
				
				fwrite(&d,sizeof(d),1,fp);
				
				i++;
				
			}
			
			while(add=='y');
			printf("\n\n\t\t---------------------------");
			printf("\n\t\tYOUR CONTACT HAS BEEN SAVED");
			printf("\n\t\t---------------------------");
			
			fclose(fp);
			
			printf("\n\n\t************************************************************");
			printf("\n\n\tDo you want to go to menu? (y/n): ");
			fflush(stdin);
			scanf("%c",&menu);
			
			if(menu=='y'){
				system("cls");
				printf("\n\n");
				goto label;
			}
			
			break;




		case 2:
			
			system("cls");
			
			printf("\n\n\t\t*================*\n");
			printf("\t\t LIST OF CONTACTS\n");
			printf("\t\t*================*\n\n\n");
			
			for(i=97;i<=122;i++){
				
				fp=fopen("contact.dat","r");
				
				fflush(stdin);
				found=0;
				while(fread(&d,sizeof(d),1,fp)==1){
					
					if(d.name[0]==i || d.name[0]==i-32){
						
						printf("\t\tName: %s\n",d.name);
						printf("\t\tAddress: %s\n",d.address);
						printf("\t\tPhone number: %lld\n",d.num);
						printf("\t\tEmail address: %s\n",d.email);
					
						found++;
					}
				}
				if(found!=0){
					printf("\t\t______________________________________\n\n");
				}
				fclose(fp);
			}
	
			
			
			printf("\n\n\t************************************************************");
			printf("\n\n\tDo you want to go to menu? (y/n): ");
			fflush(stdin);
			scanf("%c",&menu);
			
			if(menu=='y'){
				system("cls");
				printf("\n\n");
				goto label;
			}
			
			break;
			
			
	
		
		case 3:

			system("cls");
			
			printf("\n\n\t\t*==================*\n");
			printf("\t\t SEARCH OF CONTACTS\n");
			printf("\t\t*==================*\n\n");
			
			search:
			found=0;
			
			printf("\n\t\tEnter the name of the contact to search: ");
			fflush(stdin);
			gets(search);
			
			l=strlen(search);
			
			fp=fopen("contact.dat","r");
			
			while(fread(&d,sizeof(d),1,fp)==1){
				for(i=0;i<=l;i++)
					
					name[i]=d.name[i];
					name[l]='\0';
				
					if(strcmp(name,search)==0){
						
						found++;
						printf("\n\t\t----------------------------------\n");
						printf("\t\tName: %s\n",d.name);
						printf("\t\tAddress: %s\n",d.address);
						printf("\t\tPhone number: %lld\n",d.num);
						printf("\t\tEmail address: %s\n",d.email);
						printf("\t\t----------------------------------\n");
						
					}
						
			}
			
			if(found==0){
				printf("\n\t\t-----------------");
				printf("\n\t\tCONTACT NOT FOUND");
				printf("\n\t\t-----------------");
			}
			
			printf("\n\n\t\tDo you want to search more contacts? (y/n): ");
			fflush(stdin);
			scanf("%c",&searchmore);
			if(searchmore=='y')
			{
				goto search;
			}
						
			fclose(fp);
			
			printf("\n\n\t************************************************************");
			printf("\n\n\tDo you want to go to menu? (y/n): ");
			fflush(stdin);
			scanf("%c",&menu);
			
			if(menu=='y'){
				system("cls");
				printf("\n\n");
				goto label;
			}
			
			break;
		
		

		
		case 4:
			
			system("cls");
			
			printf("\n\n\t\t*==============*\n");
			printf("\t\t EDIT CONTACTS\n");
			printf("\t\t*==============*\n\n\n");
			
			found=0; 
			
			printf("\t\tEnter the email of the contact you want to edit: ");
			fflush(stdin);
			gets(edit);
			
			fp=fopen("contact.dat","r");
			fq=fopen("copy.dat","a");
			
			fflush(stdin);
			while(fread(&d,sizeof(d),1,fp)){
				if(strcmp(edit,d.email)!=0){
					
					fwrite(&d,sizeof(d),1,fq);
				}
				
				else{
					
					found++;
				}
				
			}
			if(found!=0){
				
				printf("\n\n\t\tEnter name: ");
				fflush(stdin);
				gets(d.name);
				printf("\t\tEnter address: ");
				fflush(stdin);
				gets(d.address);
				printf("\t\tEnter phone number: ");
				fflush(stdin);
				scanf("%lld",&d.num);
				printf("\t\tEnter email address: ");
				fflush(stdin);
				gets(d.email);
			
				fwrite(&d,sizeof(d),1,fq);
			
				fclose(fp);
				fclose(fq);
			
				remove("contact.dat");
				rename("copy.dat","contact.dat");
				
				printf("\n\n\t\t---------------------------");
				printf("\n\t\tCONTACT EDITED SUCCESSFULLY");	
				printf("\n\t\t---------------------------");
			}	
			else{
				printf("\n\t\t-----------------");
				printf("\n\t\tCONTACT NOT FOUND");
				printf("\n\t\t-----------------");
			}
			
			
			printf("\n\n\t************************************************************");
			printf("\n\n\tDo you want to go to menu? (y/n): ");
			fflush(stdin);
			scanf("%c",&menu);
			
			if(menu=='y'){
				system("cls");
				printf("\n\n");
				goto label;
			}
			
			break;
			
			
			
			
		case 5:
			
			system("cls");
			
			printf("\n\n\t\t*===============*\n");
			printf("\t\t DELETE CONTACTS\n");
			printf("\t\t*===============*\n\n\n");
			
			printf("\t\tEnter the email of the contact to delete: ");
			fflush(stdin);
			gets(del);
			
			fp=fopen("contact.dat","r");
			fq=fopen("copy.dat","w");
			
			fflush(stdin);
        	while(fread(&d,sizeof(d),1,fp)){
        		if (strcmp(del,d.email)!=0){
        			fwrite(&d,sizeof(d),1,fq);
				}		
			}
			
	        fclose(fp);
    	    fclose(fq);
    	    
    	    remove("contact.dat");
    	    rename("copy.dat","contact.dat");
    	    
    	    printf("\n\n\t\t----------------------------");
    	    printf("\n\t\tCONTACT DELETED SUCCESSFYLLY");
			printf("\n\t\t----------------------------");
			
			printf("\n\n\t************************************************************");
			printf("\n\n\tDo you want to go to menu? (y/n): ");
			fflush(stdin);
			scanf("%c",&menu);
			
			if(menu=='y'){
				system("cls");
				printf("\n\n");
				goto label;
			}
			
			break;
			
			
			
			
		case 0:
				
				system("cls");
				
				printf("\n\n\t\tDo you want to exit? (y/n): ");
				fflush(stdin);
				scanf("%c",&exit);
				
				break;
				
			
			
			
			default:
				
				break;
				
		
			
				
	}
	
	getch();
	return 0;
	
}
