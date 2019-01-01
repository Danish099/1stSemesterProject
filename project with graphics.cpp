#include<stdio.h>z
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

#include<graphics.h>

void find(int ,int);
int password(void);
void input (void) ;
void display (void);
void gotoxy(int ,int);
float salary_calculation(int ,int ,int);
void menu();

struct bio
{
int id;
char name[20];
char fname[20];
int age;
struct doj
        {
        int day;
        int month;
        int year;
        }d;
unsigned int number1;
unsigned int number2;
unsigned int code;
char address[100];
struct salary
        {
        int delivery;
        int working_hours;
        int holidays;
        }s;
};


char other,oth,another,flag;
char dname[15];
int choice,record;
float net_salary;
struct bio b;
FILE *fp,*ft;
char sname[15];
long int reach_location;
int tag_password,flag_search;


int main()
{

   int gd = DETECT, gm, x, y,angle = 0;
   struct arccoordstype a;


   initgraph(&gd, &gm,"");
   initwindow(1000,1000);


   delay(2000);
   while(angle<=360)
{
      setcolor(RED);
      arc(500,getmaxy()/4,angle,angle+2,100);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      setcolor(GREEN);
      arc(500,getmaxy()/4,angle,angle+2,150);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;

      setcolor(BLUE);
      arc(500,getmaxy()/4,angle,angle+2,100);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);

      setcolor(DARKGRAY);
      arc(500,getmaxy()/4,angle,angle+2,150);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;

      setcolor(YELLOW);
      arc(500,getmaxy()/4,angle,angle+2,100);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);

      setcolor(MAGENTA);
      arc(500,getmaxy()/4,angle,angle+2,150);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;


      setcolor(CYAN);
      arc(500,getmaxy()/4,angle,angle+2,50);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;
      delay(150);
   }
   getch();
   closegraph();


 system("COLOR 8F");
printf("*************************SALARY MANAGEMENT DATABASE OF SERVICE DELIVERY EMPLOYEES*********************************");
gotoxy(40,5);
printf("WELCOME");
gotoxy(72,14);
printf("SUBMITTED TO :");
gotoxy(72,15);
printf("**SIR WASEEMULLAH**");
gotoxy(72,17);
printf("MEMBERS:");
gotoxy(72,18);
printf("*ZAID RAZA         CT-039\n");
gotoxy(72,19);
printf("*UZAIR KHAN        CT-050\n");
gotoxy(72,20);
printf("*DANISH JAWAID     CT-042\n");
gotoxy(5,24);
printf("press enter to continue...................");
_getch();


tag_password=password();
if(tag_password==1)
  {
     menu();

     while(1)
     {
     switch(choice)
        {
             case '1' :
             {
              fp=fopen("project.txt","ab");
               if(fp==NULL)
                  {
                   printf("file cannot open");
                   exit(1);
                   }
              do
                  {
                   system("cls");
                   input();
                   net_salary= salary_calculation(b.s.delivery,b.s.working_hours,b.s.holidays);
                   fwrite(&b,sizeof(b),1,fp);
                   printf("\ndo you want to enter another data(y/n)\n");
                   }
                   while( _getch()=='y' || _getch()=='Y' );
                   fclose(fp);
                   printf("\n\nPRESS ENTER TO CONTINUE ..........");
                   _getch();
                   menu();
         }
         break;

           case '2' :
           fp=fopen("project.txt","rb");
            if(fp==NULL)
               {
               printf("the file cannot open");
               exit(1);
               }
            rewind(fp);
            system("cls");
             while( fread(&b,sizeof(b),1,fp)==1)
             {
             net_salary= salary_calculation(b.s.delivery,b.s.working_hours,b.s.holidays);
             display();
             printf("\n DO YOU WANT READ ANOTHER RECORD(y/n)\n");
             flag=_getch();
             if( flag=='y' || flag=='Y')
             printf("\n");
             else
             break;
             }
            if(fread(&b,sizeof(b),1,fp)==0)
            printf("THERE IS NO MORE DATA TO READ\n");
            fclose(fp);
            printf("PRESS ENTER TO CONTINUE........");
            _getch();
            menu();
            break;

        case '3' :
        fp=fopen("project.txt","rb+");
        if(fp==NULL)
            {
            printf("you cannot open file");
            exit(1);
            }
        do
             {
             system("cls");
             printf("ENTER THE NAME OF SERVICE MAN TO MODIFY\n");
             fflush(stdin);
             gets(sname);
             rewind(fp);
             while(fread(&b,sizeof(b),1,fp)==1)
                  {
                       if(strcmp(b.name,sname)==0)
                       {
                        printf("ENTER NEW DATA:\n");
                        printf("\n");
                        input();
                        net_salary= salary_calculation(b.s.delivery,b.s.working_hours,b.s.holidays);
                        fseek(fp,-sizeof(b),SEEK_CUR);
                        fwrite(&b,sizeof(b),1,fp);
                        printf("SUCESSFULLY MODIFIED\n");
                        break;
                        }
                  }
               if (fread(&b,sizeof(b),1,fp)==0)
               printf("NO RECORD EXIST BY THIS NAME\n");
               printf("DO YOU WANT TO MODIFY ANOTHER DATA:(y/n)\n");
              oth=_getch();
             }
             while( oth ==  'y' || oth =='Y' );
             fclose(fp);
             printf("\nPRESS ENTER TO CONTINUE ...........");
             _getch();
             menu();
             break;

         case '4':
          fp=fopen("project.txt","rb");
          if(fp==NULL)
             {
              printf("FILE CANNOT OPEN");
              exit(1);
             }
         system("cls");
         do
            {
            system("cls");
            printf("ENTER THE RECORD NO;\n");
            scanf("%d",&record);
            rewind(fp);

            while(fread(&b,sizeof(b),1,fp)==1)
                     {
                     if(record==b.id)
                            {
                            flag_search=1;
                            break;
                            }
                     }
              if(flag_search!=1)
               printf("\n RECORD DONOT EXIST\n");
            net_salary= salary_calculation(b.s.delivery,b.s.working_hours,b.s.holidays);
            find(flag_search,record);
            printf("DO YOU WANT TO SEARCH ANOTHER RECORD(y/n):");
            another=_getch();
           }
         while(another=='y' || another=='Y');
          fclose(fp);
         printf("\nPRESS ENTER TO CONTINUE..................");
         _getch();
         menu();
         break;

        case '5' :
        fp=fopen("project.txt","rb");
        if(fp==NULL)
           {
           printf("YOU CANNOT OPEN FILE\n");
           exit(1);
           }
       do
          {
           system("cls");
           printf("ENTER THE NAME OF PERSON TO DELETE THE DATA:\n");
           fflush(stdin);
           gets(dname);
           ft=fopen("projectd.txt","wb");
           rewind(fp);
           while( fread(&b,sizeof(b),1,fp)==1 )
                {
                 if(strcmp(b.name,dname)!=0)
                 fwrite(&b,sizeof(b),1,ft);
               }
         fclose(fp);
         fclose(ft);
         remove("project.txt"); /* remove() deletes the file */
         rename("projectd.txt","project.txt");
         fp=fopen("projectd.txt","rb+");
         if(strcmp(b.name,dname)!=0)
           {
            printf("NO RECORD EXIST BY THIS NAME\n");
            break;
           }
       if(strcmp(b.name,dname)==0)
           printf("RECORD DELETED SUCESSFULLY\n");
        printf("\nDELETE ANOTHER RECORDS:(y/n)\n");
       other=_getch();
       fflush(stdin);
       fclose(fp);
        }
        while(other=='y' || other=='Y');
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE....................");
        _getch();
        menu();
        break;

        case '6' :
           exit(0);

        default:
          printf("INVALID CHOICE");
        }
     }
printf("\t\t\t\t\t\t\tTHE END");
  }
return(0);
}

float salary_calculation(int pd,int pwh,int ph )
{
int sa,cut,sc,swh,sh,sd,cu;
float ns;
sd=( pd*100);
if(ph>2)
   {
    cut=ph-2;
    sh=(cut*500);
    }
 else
sh=0;
cu=300-pwh;
swh=(cu*50);
ns=(sd)-(sh)-(swh)+15000;
return(ns);
}

void gotoxy(int x,int y)
{
COORD c;
c.X=x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void input(void)
{
fflush(stdin);
            printf("\tENTER YOUR NAME:\n\t");
            gets(b.name);
            printf("\n");
            printf("\tENTER YOUR FATHER NAME:\n\t");
            gets(b.fname);
            printf("\n");
            printf("\tenter you id:\n\t");
            scanf("%d",&b.id);
            printf("\n");
            printf("\tENTER YOUR AGE:\n\t");
            scanf("%d",&b.age);
            printf("\n");
            printf("\tENTER THE DAY,MONTH AND YEAR OF YOUR JOINING (DD/MM/YY):\n\t");
            scanf("%d/%d/%d",&b.d.day,&b.d.month,&b.d.year);
           printf("\n");
            printf("\tENTER YOUR PHONE NUMBER(xxxx-xxx-xxxx)\n\t");
            scanf("%u-%u-%u",&b.code,&b.number1,&b.number2);
            printf("\n");
            printf("\tENTER YOUR ADDRESS:\n\t");
            fflush(stdin);
            gets(b.address);
            printf("\n");
            printf("\tENTER YOUR TOTAL DELIVERIES , TOTAL WORKING HOUR(max 300 hrs) AND HOLIDAYS:\n\t");
            scanf("%d%d%d",&b.s.delivery,&b.s.working_hours,&b.s.holidays);
           printf("\n");
}

void display(void)
{
            puts("\n");
            puts("********************************************************************************************************************");
            printf("\t\t\tYOUR NAME:   %s\n",b.name);
            printf("\n\n");
            printf("\t\t\tFATHER NAME: %s\n",b.fname);
            printf("\n\n");
            printf("\t\t\tID:          %03d\n",b.id);
            printf("\n\n");
            printf("\t\t\tAGE:         %02d\n",b.age);
            printf("\n\n");
            printf("\t\t\tDOJ:         %02d/%02d/%04d\n",b.d.day,b.d.month,b.d.year);
            printf("\n\n");
            printf("\t\t\tCELL NO:     %u-%u-%u\n",b.code,b.number1,b.number2);
            printf("\n\n");
            printf("\t\t\tADDRESS:     %s\n",b.address);
            printf("\n\n");
            printf("\t\t\tNET SALARY:  %0.01f\n",net_salary);
            puts("******************************************************************************************************************");
}

void menu(void)
{
   system("cls");
gotoxy(35,5);
printf("1.INSERT RECORDS\n");
gotoxy(35,8);
printf("2.READ RECORD\n");
gotoxy(35,11);
printf("3.MODIFY RECORDS\n");
gotoxy(35,14);
printf("4.SEARCH RECORDS\n");
gotoxy(35,17);
printf("5.DELETE RECORDS\n");
gotoxy(35,20);
printf("6.EXIT\n");
gotoxy(5,23);
printf("ENTER YOUR CHOICE:\n");
choice=_getch();

}

int password()
{
 char ch;
char real_pass[ ]="project";
char pass[15];
int count=0,p,tag;
system("cls");
printf("**************************SERVICE DELIVERY PERSON SALARY MANAGMENT DATABASE****************************************");
gotoxy(50,5);
printf("WELCOME");
gotoxy(5,15);
printf("ENTER THE PASSWORD:\n");
do
    {
     p=0;
     tag=1;
    count++;

    while( (ch=_getch())!= '\r' )
               {
                pass[p]=ch;
                p++;
                printf("*");
               }
    pass[p]='\0';
    if(strcmp(pass,real_pass)!=0)
              {
              tag=0;
              if(count!=3)
                   {
                   printf("\nWRONG PASSWORD...........................TRY AGAIN\n");
                   }
              }
    }
   while(strcmp(pass,real_pass)!=0    &&   count<4);
   system("cls");
   if(tag==0)
      {
       printf("\n\n\n\t\t\tYOU ARE INTRUDER\n");
       _getch();
       exit(1);
      }
   return(tag);
}

void find(int flag_search,int record)
{
   if(flag_search==1)
      {
      rewind(fp);
      while(fread(&b,sizeof(b),1,fp)==1)
                 {
                 if(record==b.id)
                        {
                         printf("\n");
                         display();
                        }
                 }
      }
}
