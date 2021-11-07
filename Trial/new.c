#include<stdio.h>
   int c=0;
int ret()
{
    c++;
    return c;
}
int main()
{
    int k=1,a;
    while (k!=0)
    {
        printf("\npress\n");
        scanf("%d",&k);
        switch (k)
        {
        case 1:
             a=ret();
            printf("Person now %d",a);
            break;
        default:
            break;
        }
    }
    
}