#include<stdio.h>
#include<string.h>
struct person
{
    char name[35];
    long int mble_no;
    char address[50];
    char father_name[35];
    char mother_name[30];
    char gender[8];
    char mail[100];
};
void menu();
void got();
void start();
void back();
void addrecord();
void listrecord();
void searchrecord();
void modifyrecord();
void deleterecord();

int main()
{
    system("color 3f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
    printf("\n\t\t --------  WELCOME TO PHONEBOOK MANAGEMENT SYSTEM --------");

    printf("\n\n\n\n\t\t  MENU \t\t\n\n");
    printf("\t1. Add New   \n\t2. Contact List   \n\t3. Search  \n\t4. Modify \n\t5. Delete \n\t6. Exit\n");

switch(getch())
{
    case '1':addrecord();
    break;
    case '2': listrecord();
    break;
    case '3': searchrecord();
    break;
    case '4': modifyrecord();
    break;
    case '5': deleterecord();
    break;
    case '6': exit(0);
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

menu();
}
}
    void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\n Enter name: ");
            got(p.name);
        printf("\nEnter phone no.: ");
            scanf("%ld",&p.mble_no);
        printf("\nEnter the address: ");
            got(p.address);
        printf("\nEnter father name: ");
            got(p.father_name);
        printf("\nEnter mother name: ");
            got(p.mother_name);
        printf("\nEnter gender: ");
            got(p.gender);
        printf("\nEnter e-mail: ");
            got(p.mail);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nRecord saved");

    fclose(f);
    printf("\n\nEnter any key");
    getch();
    system("cls");
    menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
    f=fopen("project","rb");
    if(f==NULL)
    {
    printf("\nFile opening error in listing ");
    exit(1);
    }
        printf("\n\n YOUR RECORD IS\n ");
        printf("\n Name            Mobile no       Address         Father name     Mother name     Gender          E-mail                    ");

    while(fread(&p,sizeof(p),1,f)==1)
    {
    printf("\n %-15s %-15ld %-15s %-15s %-15s %-15s %-25s",p.name,p.mble_no,p.address,p.father_name,p.mother_name,p.gender,p.mail);

    }
    fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}
void searchrecord()
{
    int flag = 0,c;
    long phone;
    struct person p;
    FILE *f;
    char name[100];

    f=fopen("project","rb");
    if(f==NULL)
     {
        printf("\n Error in opening\a\a\a\a");
        exit(1);
     }
    printf("1. Search by Name\n");
    printf("2. Search by Phone Number\n");

    scanf("%d", &c);

    if(c == 1)
    {
    printf("\n Enter name of person to search: ");
    got(name);
    while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        flag = 1;
        printf("\n\n Detail Information About %s",name);
        printf("\n\n Name:%s\n Mobile no:%ld\n Address:%s\n Father name:%s\n Mother name:%s\n Gender:%s\n E-mail:%s\n",p.name,p.mble_no,p.address,p.father_name,p.mother_name,p.gender,p.mail);
        break;
    }
}
    if(flag == 0)
        printf("\nNot found\n");

    fclose(f);
    }
    else if(c == 2)
    {
        printf("\n Enter phone number to search: ");
        scanf("%ld", &phone);
    while(fread(&p,sizeof(p),1,f)==1)
    {
        if(phone == p.mble_no)
          {
            flag = 1;
            printf("\n\n Detail Information About %ld",phone);
            printf("\n\n Name:%s\n Mobile no:%ld\n Address:%s\n Father name:%s\n Mother name:%s\n Gender:%s\n E-mail:%s\n",p.name,p.mble_no,p.address,p.father_name,p.mother_name,p.gender,p.mail);
            break;
          }
    }
    if(flag == 0)
        printf("\nNot found\n");

    fclose(f);
        }
    else
        {
        printf("Wrong Choice!! Press any key");
        getch();
        system("cls");
        searchrecord();
        }
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{
            printf("CONTACT'S DATA NOT ADDED YET.");
        }
	else
	{
		ft=fopen("temp.txt","wb+");
		if(ft==NULL)

        printf("file opening error");
		else
        {
        printf("\n Enter CONTACT'S NAME: ");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		  {
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		  }
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO CONTACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
        {
			remove("project");
			rename("temp.txt","project");
			printf("\n\n RECORD DELETED SUCCESSFULLY.\n");
        }
    }
}
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}
void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{
          printf("CONTACT'S DATA NOT ADDED YET.");
          exit(1);
        }
	else
	{
	    system("cls");
		printf("\n Enter CONTACT'S NAME TO MODIFY: ");
        got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {
                    printf("\n Enter name: ");
                    got(s.name);
                    printf("\n Enter phone no: ");
                    scanf("%ld",&s.mble_no);
                    printf("\n Enter the address: ");
                    got(s.address);
                    printf("\n Enter father name: ");
                    got(s.father_name);
                    printf("\n Enter mother name: ");
                    got(s.mother_name);
                    printf("\n Enter gender: ");
                    got(s.gender);
                    printf("\n Enter e-mail: ");
                    got(s.mail);

                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;
                }
                fflush(stdin);
            }
            if(flag==1)
            {
             printf("\n\n Your data is Modified\n");
            }
            else
            {
              printf(" \n Data is not found");
            }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
     system("cls");
	 menu();
}
void got(char *name)
{
   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                   *(name+i)=c;
                    putch(c);
                    i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }
                }
    }while(c!=13);
      *(name+i)='\0';
}
