#include <stdio.h>
#include <stdlib.h>

typedef struct node* it;
struct node
{
    int coeff;
    int exp;
    it nextnode;
};

typedef struct node* it;

it createlist(int c,int e)
{
    it firstnode=(it)malloc(sizeof(struct node));
    firstnode->coeff=c;
    firstnode->exp=e;
    firstnode->nextnode=NULL;
    return firstnode;
}
it insert_order(int c,int e,it firstnode)
{
    it temp=firstnode;
    it prev = NULL;
    if(temp== NULL)
    {
        firstnode=createlist(c,e);
        return firstnode;
    }
    while(temp->exp > e)
    {
        prev = temp;
        temp = temp->nextnode;
    }
    if(prev == NULL)
    {
        it new = (it)malloc(sizeof(struct node));
        new->coeff = c;
        new->exp = e;
        new->nextnode = firstnode;
        firstnode = new;
        return firstnode;
    }
    else if(temp->exp==e)
    {
        temp->coeff+=c;
        return firstnode;
    }
    else if(temp->exp>e)
    {
        it newnode=(it)malloc(sizeof(struct node));
        newnode->coeff=c;
        newnode->exp=e;
        newnode->nextnode=temp->nextnode;
        temp->nextnode=newnode;
        return firstnode;
    }
    else if(temp->nextnode==NULL)
    {
        it newnode=(it)malloc(sizeof(struct node));
        newnode->coeff=c;
        newnode->exp=e;
        newnode->nextnode=NULL;
        temp->nextnode=newnode;
        return firstnode;
    }
    else
    {
        temp=temp->nextnode;
        return firstnode;
    }
}
it insert_end(int c,int e,it poly)
    {
        it temp=poly;
        if(temp=NULL)
        {
           poly=createlist(c,e);
           return poly;
        }
        while(temp->nextnode!=NULL)
        {
        temp=temp->nextnode;
        }
        it newnode=(it)malloc(sizeof(struct node));
        newnode->coeff=c;
        newnode->exp=e;
        newnode->nextnode=NULL;
        temp->nextnode=newnode;
        return poly;
    }
it add(it poly,it poly1,it poly2)
{
    while(poly1!=NULL && poly2!=NULL)
    {
        if(poly1->exp>poly2->exp)
        {
            poly=insert_end(poly1->coeff,poly1->exp,poly);
            poly1=poly1->nextnode;
        }
        else if(poly2->exp>poly1->exp)
        {
            poly=insert_end(poly2->coeff,poly2->exp,poly);
            poly2=poly2->nextnode;
        }
        else
        {
            poly=insert_end(poly1->coeff+poly2->coeff,poly1->exp,poly);
            poly1=poly1->nextnode;
            poly2=poly2->nextnode;
        }
        it temp=poly;
     while(temp->nextnode!=NULL)
     {
        temp=temp->nextnode;
     }
      if(poly1==NULL && poly2!=NULL)
         {
             temp->nextnode=poly2;
         }
      else if(poly2==NULL && poly1!=NULL)
         {
             temp->nextnode=poly1;
         }
    }
    return poly;
}
void display(it firstnode)
{
    it temp=firstnode;
    while(temp->nextnode!=NULL)
    {
        printf("%dx%d + ",temp->coeff, temp->exp);
        temp=temp->nextnode;
    }
    printf("%dx%d\n", temp->coeff, temp->exp);
}
int main()
{
    it poly1 = 0;
    it poly2 = 0;
    int terms1, terms2;
    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &terms1);
    
    for(int i=0;i<terms1;i++)
    {
        int coeff, exp;
        printf("Enter the coeficient and exponent for %d term of first polynomial: ",(i+1));
        scanf("%d%d", &coeff, &exp);
        poly1 = insert_order(coeff, exp, poly1);
    }
    display(poly1);
    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &terms2);
    
    for(int i=0;i<terms2;i++)
    {
        int coeff, exp;
        printf("Enter the coeficient and exponent for %d term of second polynomial: ",(i+1));
        scanf("%d%d", &coeff, &exp);
        poly2 = insert_order(coeff, exp, poly2);
    }
    display(poly2);
    // it poly = add(NULL,poly1,poly2);
    // display(poly);
}