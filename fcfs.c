#include<stdio.h>
void main()
{
    int i, head, d[20], n, pos;
    printf("Enter the number of disk schedulings to do:\n");
    scanf("%d",&n);
    printf("Enter the position of the head:\n");
    scanf("%d",&head);
    d[0]=head;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the position:");
        scanf("%d",&d[i]);
    }
    printf("Order of FCFS is:\n");
    printf("%d\t",head);
    for(i=0;i<=n;i++)
    {
        printf("%d\t",d[i]);
    }
}