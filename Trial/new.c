#include<stdio.h>
#include<stdlib.h>
struct stack{
	int size;
	int top;
	int *arr;
};
void TOP_BOTTOM(struct stack *qtr){
	int d;
	printf("ENTER 1 FOR CHECKING STACK TOP , 2 FOR STACK BOTTOM:\n");
	scanf("%d",&d);
	switch(d)
	{
		case 1:
			printf("THE TOP VALUE IS %d\n",qtr->arr[qtr->top]);
			break;
		case 2:
			printf("THE BOTTOM VALUE IS %d\n",qtr->arr[0]);
			break;
		default:
		    printf("GALAT\n");	
			
	}
}
void PUSH(struct stack *ctr,int v){
	if(ctr->top==ctr->size-1){
		printf("STACK OVERFLOW\n");
	}
	else
	{
		int i,j;
		printf("ENTER THE VALUE OF THAT ELEMENT WHICH YOU WANT TO PUSH:\n");
		scanf("%d",&v);
        ctr->top++;
        ctr->arr[ctr->top]=v;
        printf("AFTER THE PUSHING OPERATION THE STACK LOOKS LIKE:\n");
        j=ctr->top;
        ctr->top=-1;
        for(i=0;i<=j;i++){
        	printf("TOP = %d\n",++ctr->top);
        	printf("ELEMENT %d is %d\n",i+1,ctr->arr[ctr->top]);
		}
	}
}
void POP(struct stack *ctr){
	if(ctr->top==-1)
	{
		printf("STACK UNDERFLOW\n");
	}
	else
	{
		int j,i,v=ctr->arr[ctr->top];
		ctr->top--;
		printf("%d HAS BEEN POPPED\n",v);
		printf("AFTER THE POPING OPERATION THE STACK LOOKS LIKE:\n");
		j=ctr->top;
		ctr->top=-1;
		for(i=0;i<=j;i++)
		{
			printf("TOP = %d\n",++ctr->top);
			printf("ELEMENT %d is %d\n",i+1,ctr->arr[ctr->top]);
		}
	}
}
void PEEP(struct stack *mtr,int c){
	printf("ENTER THE POSITION:\n");
	scanf("%d",&c);
	if(mtr->top-c+1<0)
	{
		printf("INVALID\n");
	}
	else
	{
	    printf("THE VALUE AT POSITION %d is %d\n",c,mtr->arr[mtr->top-c+1]);	
	}
}
int main()
{
	int i,n,o,p,w,k;
	struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
	sp->top=-1;
	printf("ENTER THE SIZE OF THE STACK:\n");
	scanf("%d",&sp->size);
	sp->arr=(int*)malloc(sp->size * sizeof(int));
	printf("ENTER THE NO OF ELEMENTS WHICH YOU WANT INITIALLY:\n");
	scanf("%d",&n);
	printf("ENTER THE ELEMENTS:\n");
	for(i=0;i<n;i++){
		scanf("%d",&sp->arr[++sp->top]);
	}
	sp->top=-1;
	printf("THE ELEMENTS ARE:\n");
	for(i=0;i<n;i++){
		printf("TOP = %d\n",++sp->top);
		printf("ELEMENT %d is %d\n",i+1,sp->arr[sp->top]);
	}
	do
	{
	printf("ENTER 1 FOR PUSH , 2 FOR POP , 3 FOR PEEP , 4 STACK TOP AND BOTTOM\n");
	scanf("%d",&o);
	switch(o)
	{
		case 1:
			PUSH(sp,w);
			break;
		case 2:
		    POP(sp);
			break;
		case 3:
		    PEEP(sp,p);
			break;
		case 4:
		    TOP_BOTTOM(sp);
			break;	
		default:
		printf("KAL ANA BETE\n");			
	}	
	printf("DO YOU WANT TO CHANGE OR CHECK MORE?\n 1->YES \n 2->NO\n");
	scanf("%d",&k);
	}while(k==1);
	return 0;
}