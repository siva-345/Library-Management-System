#include<stdio.h>
#include<string.h>
#include<time.h>
struct book
{
    char bn[200],an[200];
    int id,f;
}b[100];
int i,tot=0,t=0;
void addbook()
{
    char a[100];
    int n;
    printf("\nEnter No Of Books : ");
    scanf("%d",&n);
    tot+=n;
    for(i=t;i<tot;i++)
    {
        printf("\nAdmin Name : ");
        scanf("%s",a);
        printf("\nEnter Book Name : ");
        scanf("%s",b[i].bn);
        printf("\nEnter Author Name : ");
        scanf("%s",b[i].an);
        printf("\nEnter Book Id : ");
        scanf("%d",&b[i].id);
        time_t t=time(NULL);
        struct tm*tm=localtime(&t);
        printf("\ncurrent date:\n");
        printf("%s\n",asctime(tm));
        b[i].f=1;
    }
    t=i;
}
void viewbook()
{
    char s[100],a[100];
    int w;
    printf("\n1.Student or 2.Admin : ");
    scanf("%d",&w);
    printf(w==1?"\nStudent":"\nAdmin");
    for(i=0;i<tot;i++)
    {
        if(b[i].f==1)
        printf("\n\nbook name : %s\t\nAuthor Name : %s\t\nBook Id : %d\n",b[i].bn,b[i].an,b[i].id);
    }
}
void landbook()
{
    char x[100],s[100];
    int tid,f1=1;
    printf("\nStudent Name : ");
    scanf("%s",s);
    printf("\nEnter Book Name : ");
    scanf("%s",x);
    printf("\nEnter Book Id : ");
    scanf("%d",&tid);
    time_t t=time(NULL);
    struct tm*tm=localtime(&t);
    printf("\ncurrent date:\n");
    printf("%s\n",asctime(tm));
    for(i=0;i<tot;i++)
    {
        if(!strcmp(x,b[i].bn)&&tid==b[i].id&&b[i].f==1)
        {
            b[i].f=0;
            f1=0;
        }
    }
    if(f1)
    printf("\nInvalide Book Detailes\n");
    else
    printf("\nBook Issued Successfully\n");
}
void returnbook()
{
    
    char x[100],s[100];
    int tid,f1=1;
    printf("\nStudent Name : ");
    scanf("%s",s);
    printf("\nEnter Book Name : ");
    scanf("%s",x);
    printf("\nEnter Book Id : ");
    scanf("%d",&tid);
    time_t t=time(NULL);
    struct tm*tm=localtime(&t);
    printf("\ncurrent date:\n");
    printf("%s\n",asctime(tm));
    for(i=0;i<tot;i++)
    {
        if(!strcmp(x,b[i].bn)&&tid==b[i].id&&b[i].f==0)
        {
            b[i].f=1;
            f1=0;
        }
    }
    if(f1)
    printf("Invalide Book Detailes\n");
    else
    printf("Book Returned Successfully\n");
}
int main()
{
    int n,f=1;
    float l;
    char a[100];
    printf("\n-------------------- Liabrary Module Project In C -------------------------\n");
    printf("\n____________________________________________________________________________\n");
    printf("   $$$$$$$$$$$$$$$$$$$$$$$$$$$$  Welocom  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("   $$$$$$$$$$$$$$$$$$$$$$$$$$$$     To    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("   $$$$$$$$$$$$$$$$$$$$$$$$$$$$  Library  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("____________________________________________________________________________\n");
    printf("\n\t\t\t log in id : ");
    scanf("%f",&l);
    printf("\n\t\t\t Password : ");
    scanf("%s",a);
        while(1)
        {
            printf("\n1.Add Book\n\n2.View Book\n\n3.Land Book\n\n4.Return Book\n\n5.exit\n");
            scanf("%d",&n);
            switch(n)
            {
                case 1:addbook();break;
                case 2:viewbook();break;
                case 3:landbook();break;
                case 4:returnbook();break;
                case 5:f=0;printf("\n\t\t\t\tThanks For Using...\n");break;
                case 6:printf("\n Invalid Option\n");
            }
          if(f==0)
          break;
        }
}







