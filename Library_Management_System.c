#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include<time.h>

void mainmenu();
void add_boks();
void delete_boks();
void search_books();
void issue_books();
void view_books();
void return_books();
struct date
 {
 int dd,mm,yy;
};
struct books
{
  int rack,quantity,year;
  char branch[50],bookid[20],name[50],author[50],stname[100],stusn[10];
  struct date issued;
  struct date due;
  };
struct books a;
int main()
{
char password[10];
char s[20]={"mini"};
printf("\n**********PASSWORD PROTECTED**********\n");
printf("\nENTER PASSWORD: ");
scanf("%s",password);
if(strcmp(s,password)==0)
{
    printf("\nWELCOME!\nLOGIN SUCCESSFUL\n");
    system("cls");
    mainmenu();
    return;
}
else
    {
    printf("\nINVALID PASSWORD\n");
    return;
}
}
void mainmenu()
{
    int ch;
printf("\n1.ADD BOOKS\n2.DELETE BOOKS\n3.SEARCH BOOKS\n4.ISSUE BOOKS\n5.VIEW BOOKS\n6.RETURN BOOKS\n7.CLOSE THE APPLICATION\n");
printf("Enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
    add_books();
    break;
case 2:
    delete_books();
    break;
case 3:
    search_books();
    break;
case 4:
    issue_books();
     break;
case 5:
    view_books();
    break;
case 6:
    return_books();
    break;
case 7:
    exit(0);
    break;
default:
    printf("\nWRONG CHOICE\nENTER THE NUMBER BETWEEN 1 TO 7");
}
}
void add_books()
{
    system("cls");
int ch=1;
FILE *f1;
 f1=fopen("aboutbook.txt","a");
fseek(f1,0,SEEK_CUR);
while(ch==1)
    {
    printf("\nENTER THE INFORMATION OF THE BOOK\n");
    printf("\nBRANCH:");
scanf("%s",a.branch);
printf("\nBOOK ID:");
scanf("%s",a.bookid);
printf("\nBOOK NAME:");
scanf("%s",a.name);
printf("\nAUTHOR:");
scanf("%s",a.author);
printf("\nQUANTITY:");
scanf("%d",&a.quantity);
printf("\nRACK NUMBER:");
scanf("%d",&a.rack);
fwrite(&a,sizeof(a),1,f1);
    printf("\nTHE BOOK DETAILS ARE SUCCESSFULLY SAVED!\n");
printf("\nDO YOU WANT TO ADD MORE BOOKS?\tPRESS 1 IF YES OR 0 IF NO.\n");
scanf("%d",&ch);
system("cls");
    }
    fclose(f1);
    mainmenu();
}
void delete_books()
{
system("cls");
char delid[50];
int ch=1,q=0,s=0;
FILE *f1,*ft;
while(ch==1)
{
printf("\nENTER THE BOOK ID TO BE DELETED\n");
scanf("%s",delid);
f1=fopen("aboutbook.txt","r");
rewind(f1);
 while(fread(&a,sizeof(a),1,f1)==1)
        {
if(strcmp(a.bookid,delid)==0)
{
    printf("\nBOOK FOUND\n");
    printf("\nBOOK NAME:%s\n",a.name);
    printf("\nAUTHOR:%s\n",a.author);
    printf("\nRACK NUMBER:%d\n",a.rack);
q=1;
 break;
 }
}
if(q==1)
{
printf("\nARE YOU SURE OF DELETING THE BOOK\tIF YES PRESS 1\n");
 scanf("%d",&s);
 if(s==1)
 {
 ft=fopen("temp.txt","w");
 rewind(f1);
  while(fread(&a,sizeof(a),1,f1)==1)
    {
     if(strcmp(a.bookid,delid)!=0)
     {
            fseek(ft,0,SEEK_CUR);
            fwrite(&a,sizeof(a),1,ft);
     }
    }
    fclose(f1);
    fclose(ft);
        remove("aboutbook.txt");
    rename("temp.txt","aboutbook.txt");
 }
 printf("\nTHE BOOK IS SUCCESSFULLY DELETED\n");
 printf("\nDO YOU WANT TO DELETE MORE BOOKS\tPRESS 1 IF YES\n");
 scanf("%d",&ch);
}
else
{
    printf("\nNO BOOK WITH THE REUIRED BOOKID FOUND\n");
    printf("\nD YOU WANT TO CONTINUE\n");
    scanf("%d",&ch);
}}
system("cls");
mainmenu();
}
void search_books()
{
system("cls");
int ch=0,e=1,f=0;
char b[50];
FILE *f1;
while(e==1)
{
printf("\n**********SEARCH BOOKS**********\n");
printf("\nSEARCH BY \n1.BOOK ID \n2.BOOK NAME\n");
scanf("%d",&ch);
switch(ch)
{
 case 1:
     {
         ch=1;
         char b[50];
         system("cls");
         printf("\nENTER THE BOOK ID\n");
         scanf("%s",b);
         f1=fopen("aboutbook.txt","r");
  while(fread(&a,sizeof(a),1,f1)==1)
  {
      if(strcmp(a.bookid,b)==0)
      {
          f=1;
      break;
      }
     }
     if(f==1)
     {
          printf("\nTHE BOOK IS AVAILABLE\n");
          printf("\nTHE BOOK DETAILS ARE:\nBRANCH:%s\nBOOK NAME:%s\nAUTHOR:%s\nRACK:%d\n",a.branch,a.name,a.author,a.rack);
     break;
     }
     else
        printf("\nTHE BOOK NOT FOUND\n");
     }
     break;
 case 2:
    {
    system("cls");
   ch=2;
    char n[50];
    printf("\nENTER THE BOOK NAME\n");
   scanf("%s",n);
     f1=fopen("aboutbook.txt","r");
  while(fread(&a,sizeof(a),1,f1)==1)
  {
   if(strcmp(a.name,n)==0)
   {
        f=1;
   break;
   }
}
    if(f==1)
    {
          printf("\nTHE BOOK IS FOUND\n");
    printf("\nTHE BOOK DETAILS ARE:\nBRANCH:%s\nBOOK NAME:%s\nBOOK ID:%s\nAUTHOR:%s\nRACK:%d\n",a.branch,a.name,a.bookid,a.author, a.rack);
   break;
    }
     else
   printf("\nTHE BOOK IS NOT FOUND\n");
    }
break;
}
printf("\nDO YOU WANT TO CONTINUE SEARCHING?\tPRESS 1 IF YES\n");
scanf("%d",&e);
}
system("cls");
mainmenu();
}
void issue_books()
{
system("cls");
int s,o,x=0,p=1,d=0,m=0,y=0,f=0,n;
char b[50];
time_t now;
time(&now);
struct tm *local=localtime(&now);
d= local->tm_mday;
m= local->tm_mon+1;
y= local->tm_year+1900;
FILE *f1,*fb;
printf("\n**********ISSUE BOOKS**********\n");
printf("\n1.ISSUE BOOKS\n2.VIEW ISSUED BOOKS\n3.SEARCH ISSUED BOOKS\n4.MAINMENU\n");
printf("\nENTER A CHOICE\n");
scanf("%d",&o);
switch(o)
{
case 1:
    {
    while(p==1)
    {
        system("cls");
         printf("\nENTER THE BOOK ID TO BE ISSUED\n");
         scanf("%s",b);
         f1=fopen("aboutbook.txt","r");
         fb=fopen("issuedbook.txt","a");
         fseek(fb,0,SEEK_CUR);
  while(fread(&a,sizeof(a),1,f1)==1)
  {
      if(strcmp(b,a.bookid)==0)
      {
          f=1;
      break;
      }
        }
  if(f==1)
  {
      s=a.quantity;
      printf("\n %d BOOKS ARE AVAILABLE\n",a.quantity);
          printf("\nBOOK NAME:%s\nAUTHOR:%s\n",a.name,a.author);
          printf("\nENTER THE STUDENT DETAILS\n");
          printf("\nSTUDENT NAME:\n");
          scanf("%s",a.stname);
          printf("\nUSN\n");
          scanf("%s",a.stusn);
        printf("\nYEAR\n");
        scanf("%d",&a.year);
printf("\nTHE ISSUED DATE IS %d/%d/%d\n",d,m,y);
n=m+1;
a.due.dd=d;
a.due.mm=n;
a.due.yy=y;
printf("\nTHE BOOK SHOULD BE RETURNED ON OR BEFORE %d/%d/%d\n",a.due.dd,a.due.mm,a.due.yy);
   }
      else
        printf("\nTHE BOOK NOT FOUND\n");
printf("\nANY MORE BOOKS TO BE ISSUED?\tPRESS 1 IF YES\n");
scanf("%d",&p);
    }
    fclose(fb);
fclose(f1);
    mainmenu();
}
break;
case 2:
{
    int ch;
 system("cls");
 FILE *fb;
 printf("\n*****VIEW BOOKS*****\n");
 fb=fopen("issuedbook.txt","r");
 while(fread(&a,sizeof(a),1,fb)==1)
 {
printf("\nSTUDENT NAME:%s\nSTUDENT USN:%s\nBOOK ID:%s\nNAME:%s\nISSUED DATE:%d/%d/%d\nDUE DATE:%d/%d/%d\n" ,a.stname,a.stusn,a.bookid,a.name,d,m,y,a.due.dd,a.due.mm,a.due.yy);
 }
 fclose(fb);
 printf("\nENTER 1 TO RETURN TO MAINMENU\n");
 scanf("%d",&ch);
 if(ch==1)
 {
     system("cls");
 mainmenu();
}
}
break;
case 3:
    {
      system("cls");
int e=1,f=0;
char b[50];
FILE *fb;
while(e==1)
{
printf("\n*****SEARCH ISSUED BOOKS*****\n");
         printf("\nENTER THE BOOK ID\n");
         scanf("%s",b);
         fb=fopen("issuedbook.txt","r");
  while(fread(&a,sizeof(a),1,fb)==1)
  {
      if(strcmp(b,a.bookid)==0)
      {
          f=1;
      }}

  if(f==1)
  {
      printf("\nTHE BOOK IS AVAILABLE\n");
          printf("\nSTUDENT NAME:%s\nSTUDENT USN:%s\nBOOK ID:%s\nBOOK NAME:%s\nISSUED DATE:%d/%d/%d\nRETURN DATE:%d/%d/%d\n",a.stname,a.stusn,a.bookid,a.name,d,m,y,a.due.dd,a.due.mm,a.due.yy);
  }
  else
  {
      printf("\nBOOK NOT FOUND\n");
  }
        printf("\nDO YOU WANT TO SEARCH MORE BOOKS\n");
        scanf("%s",&e);
}
issue_books();
}
case 4:
    system("cls");
    mainmenu();
  break;
system("cls");
mainmenu();
}
}
void return_books()
{
system("cls");
char delid[50];
int ch=1,q=0,s=0,d=0,m=0,y=0;
FILE *fb,*ft;
time_t now;
time(&now);
struct tm *local=localtime(&now);
d = local->tm_mday;
m = local->tm_mon+1;
y = local->tm_year+1900;
while(ch==1)
{
   printf("\nENTER THE BOOK ID TO BE RETURNED\n");
scanf("%s",delid);
 fb=fopen("issuedbook.txt","r");
rewind(fb);
while(fread(&a,sizeof(a),1,fb)==1)
        {
if(strcmp(a.bookid,delid)==0)
{
    printf("\nBOOK FOUND\n");
    printf("\nBOOK NAME:%s\n",a.name);
    printf("\nAUTHOR:%s\n",a.author);
    printf("\nTODAY'S DATE:%d/%d/%d\n",d,m,y);
    printf("\nDUE DATE:%d/%d/%d\n",a.due.dd,a.due.mm,a.due.yy);
q=1;
 break;
 }
}
if(q==1)
{
printf("\nARE YOU SURE OF RETURNING THE BOOK\tIF YES PRESS 1\n");
 scanf("%d",&s);
 if(s==1)
 {
 ft=fopen("delete.txt","w");
 rewind(fb);
  while(fread(&a,sizeof(a),1,fb)==1)
    {
     if(strcmp(a.bookid,delid)!=0)
     {
            fseek(ft,0,SEEK_CUR);
            fwrite(&a,sizeof(a),1,ft);
     }
    }
    fclose(fb);
    fclose(ft);
    remove("issuedbook.txt");
    rename("delete.txt","issuedbook.txt");
 }
 printf("\nTHE BOOK IS SUCCESSFULLY RETURNED\n");
 printf("\nDO YOU WANT TO RETURN MORE BOOKS\tPRESS 1 IF YES\n");
 scanf("%d",&ch);
}
else
{
    printf("\nNO BOOK WITH THE REUIRED BOOKID FOUND\n");
    printf("\nENTER ANY KEY TO GO TO THE MAINMENU\n");
ch=0;
}}
system("cls");
mainmenu();
}
void view_books()
{
    int ch;
system("cls");
 FILE *f1;
printf("\n**********VIEW BOOKS**********\n");
 f1=fopen("aboutbook.txt","r");
 while( fread(&a,sizeof(a),1,f1)==1)
 {
 printf("\nBRANCH: %s\nBOOK ID: %s\nBOOK NAME: %s\nAUTHOR: %s\nQUANTITY: %d\nRACK: %d\n",a.branch,a.bookid,a.name,a.author,a.quantity,a.rack);
}
 fclose(f1);
 printf("\nENTER 1 TO RETURN TO MAINMENU\n");
 scanf("%d",&ch);
 if(ch==1)
 {
system("cls");
 mainmenu();
}
}
