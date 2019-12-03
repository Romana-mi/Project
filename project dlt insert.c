//***********INSERT or DELETE data from FILE************
#include<stdio.h>
#include<conio.h>
void main()
{
    FILE *readfile, *writefile;
    writefile = fopen("C:\\Users\\rashe\\OneDrive\\Documents\\write.txt","w");
//    writefile = fopen("C:\read\Users\\rashe\\O neDrive\\Documents\\write.txt","w");

    int a[100],i,n,p,d,select,value;
    printf("\t\t\t\aProject: INSERT or DELETE data from FILE\n\n  Enter the number of element:\n\t >");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        fprintf(writefile,"%d\n", a[i]);
    }
    printf("\n  %d Elements Of Array Is Loaded From READ.TXT File: \n\t",n);
    for(i=1;i<=n;i++)
    {
        printf("   %d ",a[i]);
    }
    start:
    printf("\n\n\a  What you want to do? Enter the number Of Your Choice:\n\t\t1. INSERT\n\t\t2. DELETE\n\t\t3. EXIT\n\t>");
    scanf("%d",&select);
    switch(select)
    {
    case 1 :
        {
            ins:
            printf("\a\n  Please Enter The Position Where To INSERT: \n\t>");
            scanf("%d",&p);
            if(p<=n)
            {
                printf("\a\n  Please Enter The Value Of Position %d: \n\t>",p);
                scanf("%d",&value);

                a[p] = value;

                printf("\n  Resultant Array Is Also Saved In WRITE.TXT File\n\t");
                for (i = 1; i <= n; i++)
                fprintf(writefile,"\n%d",a[i]);

                for (i = 1; i <= n; i++)
                printf("  %d", a[i]);
            }
            else
            {
                printf("\n  Ops! INSERTING isn't possible for position of %d!!, Try Again\n",p);
                goto ins;
            }
            break;
        }
    case 2 :
        {
        del:
        printf("\a\n\tPlease Enter the DELETE position: \n\t\t");
        scanf("%d",&d);

        if(d>n){
        printf("Ops! DELETING isn't possible for position of %d!!, Try Again\n",d);
        goto del;
        }
        else
        {
        for (i = d; i <= n; i++)
        a[i] = a[i+1];
        printf("\nResultant array is also saved in WRITE.TXT file\n\t");
        for (i = 1; i < n; i++)
            fprintf(writefile,"\n%d",a[i]);

        for (i = 1; i < n; i++)
            printf("   %d", a[i]);
        }
        }
    case 3 : {
        printf("\n\t\t\t Thanks a lot!");
        break;
        }
    default : {
        printf("  Ops!Please Choice a value from below:");
        goto start;
        }
    }

}
