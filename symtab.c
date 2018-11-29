#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
struct SYMTAB
{
    char symbol[30];
    char addr[10];
} s[100];
int top=-1;
void place(char symbol[], char address[])
{
    top++;
    if(top==MAXSIZE)
    {
        printf("No space to place the symbol\n");
        return;
    }
    strcpy(s[top].symbol,symbol);
    strcpy(s[top].addr,address);
    printf("Symbols added successfully\n");
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("No symbol found\n");
        return;
    }
    printf("Symbol table is\n");
    for(i=0;i<=top;i++)
    {
        printf("%s\t%s\n",s[i].symbol,s[i].addr);
    }
}
int search(char symbol[])
{
    int i;
    for(i=0;i<top;i++)
    {
        if(strcmp(s[i].symbol,symbol)==0)
        {
            return i;
        }
    }
    return -1;
}
void modify(char symbol[],char address[])
{
    int i;
    i=search(symbol);
    if(i==-1)
    {
        printf("No symbol found\n");
        return;
    }
    strcpy(s[i].addr,address);
    printf("Symbol updated successfully\n");
}
void main()
{
    int ch,i;
    char symbol[30],addr[30];
    while(1)
    {
        printf("1.Insert a symbol\n2.Modify a symbol\n3.Search a symbol\n4.Display a symbol\n5.Exit\n.Enter your choice:");
        scanf("%d",symbol);
        switch(ch)
        {
            case 1:
            printf("Enter symbol:");
            scanf("%s",symbol);
            printf("Enter address");
            scanf("%s",addr);
            place(symbol,addr);
            break;

            case 2:
            printf("Enter symbol:");
            scanf("%s",symbol);
            printf("Enter the address:");
            scanf("%s",addr);
            modify(symbol,addr);
            break;

            case 3:
            printf("Enter the symbol:");
            scanf("%s",symbol);
            i=search(symbol);
            if(i==-1)
            {
                printf("No symbol found!\n");
            }
            else
            {
                printf("Symbol found at location %d\n",i);
                printf("Address of the symbol %s\n",s[i].addr);
            }
            break;
            
            case 4:
            display();
            break;

            default:
            exit(0);
        }
    }
}
