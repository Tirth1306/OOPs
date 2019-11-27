#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
}*head = NULL,*newnode,*temp;

int main()
{
    int ch;
    void insert_beg();
    void insert_end();
    int insert_pos();
    void display();
    void delete_beg();
    void delete_end();
    int delete_pos();
 
    do
    {
        printf("\n\n---- Singly Linked List(SLL) Menu ----");
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n\n");
        printf("Enter your choice(1-4):");
        scanf("%d",&ch);
 
        switch(ch)
        {
            case 1:
                    printf("\n---- Insert Menu ----");
                    printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);
 
                    switch(ch)
                    {
                        case 1: insert_beg();
                                break;
                        case 2: insert_end();
                                break;
                        case 3: insert_pos();
                                break;
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
                    break;
 
            case 2: display();
                    break;
 
            case 3: printf("\n---- Delete Menu ----");
                    printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);
 
                    switch(ch)
                    {
                        case 1: delete_beg();
                                break;
                        case 2: delete_end();
                                break;
                        case 3: delete_pos();
                                break;
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
                    break;
            case 4: printf("Thank You!");
                    break;

            default: printf("Wrong Choice!!");
        }
    }while(ch!=4);
    return 0;
}

void insert_beg()
{
    int num;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter You Data : ");
    scanf("%d",&num);
    newnode->data=num;

    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }

    else
    {
        newnode->next=head;
        head=newnode;
    }
    
}

void insert_end()
{
    int num;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter You Data : ");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
    }

    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newnode;
    }
    
}

int insert_pos()
{
    if(head==NULL)
    {
        printf("List is Empty!");
        return 0;
    }
    int num,pos;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter You Data : ");
    scanf("%d",&num);
    newnode->data=num;
    printf("Enter the Position You want to insert data : ");
    scanf("%d",&pos);
    temp=head;

    for(int i=1;i<pos-1;i++)
    {
        if(temp->next==NULL)
        {
            printf("There are less Elements in List!");
            return 0;
        }

        temp=temp->next;
    }
        newnode->next=temp->next;
        temp->next=newnode;
        return 0;
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty!!");
    }

    else
    {
        printf("Your List is:");
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void delete_beg()
{
    if(head==NULL)
    {
        printf("List Empty!");
    }
    else
    {
        temp=head;
        head=head->next;
        printf("Deleted Element is %d.",temp->data);
        free(temp);
    } 
}

void delete_end()
{
    if(head==NULL)
    {
        printf("List Empty!");
    }

    else
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=NULL;
        printf("Deleted Element is %d",temp->next->data);
        free(temp);
    }
    
}

int delete_pos()
{
    int pos;
    if(head==NULL)
    {
        printf("List Empty!");
        return 0;
    }

    else
    {
        printf("ENter Position You want to delete : ");
        scanf("%d",&pos);
        temp=head;
        for(int i=1;i<pos-1;i++)
        {
            if(temp->next!=NULL)
            {
                printf("There are less Elements in List!");
                return 0;
            }

            temp=temp->next;
        }
        printf("Deleted Element is %d",temp->next->data);
        temp->next=temp->next->next;
    }
    
}