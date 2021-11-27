#include <stdio.h>
#include <stdlib.h>
typedef struct stud
{
    int info;
    struct stud *next_link;
} Node;
Node *start = NULL;
void add_Newnode(int data)
{
    Node *newNode = NULL, *ptr;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;
    newNode->next_link = NULL;
    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        ptr = start;
        while (ptr->next_link != NULL)
        {
            ptr = ptr->next_link;
        }
        ptr->next_link = newNode;
    }
}
void display()
{
    Node *ptr;
    ptr = start;
    while (ptr)
    {
        printf("%d ->", ptr->info);
        ptr = ptr->next_link;
    }
    printf("NULL \n");
}
int insertion_inBeggning()
{
    int inserted_data;
    printf("Enter your inserted data");
    scanf("%d", &inserted_data);
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    ptr->info = inserted_data;
    ptr->next_link = start;
    while (ptr)
    {
        printf("%d ->", ptr->info);
        ptr = ptr->next_link;
    }
    printf("NULL \n");
}
int insertion_inEnd()
{
    int insert_data;
    printf("Enter your inserting data\n");
    scanf("%d",&insert_data);
    Node *addNode,*ptr;
    addNode=(Node*)malloc(sizeof(Node));
    addNode->info=insert_data;
    addNode->next_link=NULL;
    ptr=start;
    while (ptr->next_link!=NULL)
    {
        ptr=ptr->next_link;
    }
    ptr->next_link=addNode;
    while (start)
    {
        printf("%d ->", start->info);
        start = start->next_link;
    }
    printf("NULL \n");
}
int insertionAtIndex()
{
    Node *newNode, *ptr;
    int index,data;
    printf("Enter the index which you want to add your Node \n");
    scanf("%d",&index);
    printf("Enter the data which you want to insert\n");
    scanf("%d",&data);
    newNode=(Node*)malloc(sizeof(Node));
    newNode->info=data;
    ptr=start;
    int i=0;
    while (i!=index-1)
    {
        ptr=ptr->next_link;
        i++;
    }
    newNode->next_link=ptr->next_link;
    ptr->next_link=newNode;
    while (start)
    {
        printf("%d ->", start->info);
        start = start->next_link;
    }
    printf("NULL \n");
    
}
int main()
{
    int data;
    char user_Choice;
    while (1)
    {
        printf("Press Y to add a new Node\n");
        scanf("%c", &user_Choice);
        if (user_Choice == 'y' || user_Choice == 'Y')
        {
            printf("Enter your value\n");
            scanf("%d", &data);
            add_Newnode(data);
            fflush(stdin);
        }
        else
        {
            break;
        }
    }
    display();
    insertion_inBeggning();
    insertion_inEnd();
    insertionAtIndex();

}
