#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct _CRT_INTERNAL_SCANF_LEGACY_MSVCRT_COMPATIBILITY{
    char symbol[30];
    char addr[30];
    int flag;
}s[97];
int hash(char str[])
{
    int i,sum=0,h;
    for(i=0;i<strlen(str);i++)
    {
        sum+=(int)str[i];
    }
    h=sum%97;
    return h;
}
void place(char symbol[],char addr[])
{
    int h, repeat=0,i;
    h=hash(symbol);
    if(s[h].flag==0)
    {
        strcpy(s[h].symbol,symbol);
        strcpy(s[h].addr,addr);
        s[h].flag=1;
    }
    else
    {
        i=h+1;
        while(s[i].flag!=0)
        {
            if(i==h)
            {
                repeat=1;
                break;
            }
            i=(i+1)%97;
        }
        if(repeat==1)
        {
            printf("no place to print the symbol\n");
            return;
        }
        else
        {
            strcpy(s[i].symbol,symbol);
            strcpy(s[i].addr,addr);
            s[i].flag=1;
        }
    }
    printf("Symbol successfully placed\n");
}
int search(char symbol[])
{
    int h,i;
    h=hash(symbol);
    if(strcmp(s[h].symbol,symbol)==0)
    {
        return h;
    }
    i=h+1;
    while(strcmp(s[i].symbol,symbol)!=0 && s[i].flag!=0)
    {
        if(i==h)
        {
            return -1;
        }
        i=(i+1)%97;
    }
    if(s[i].flag==0)
    {
        return -1;
    }
    return i;
}
void main()
{
    int ch,i;
    char symbol[30],addr[30];
    for(i=0;i<97;i++)
    {
        s[i].flag=0;
    }
    while(1)
    {
        printf("1.Insert\n2.Search\n3.Display \n4.Exit\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the symbol:\n");
            scanf("%s",symbol);
            printf("Enter the address:");
            scanf("%s",addr);
            place(symbol,addr);
            break;

            case 2:
            printf("Enter the symbol:");
            scanf("%s",symbol);
            i=search(symbol);
            if(i==-1)
            {
                printf("No symbol found\n");
            }
            else
            {
                printf("Symbol found at location %d\n",i);
                printf("Address of the symbol is %s\n",s[i].addr);
            }
            break;

            case 3:
            printf("Symbol Table\n");
            for(i=0;i<97;i++)
            {
                if(s[i].flag==1)
                {
                    printf("%s\t%s\n",s[i].symbol,s[i].addr);
                }
            }
            break;
            case 4: exit(0);
        }
    }
}
