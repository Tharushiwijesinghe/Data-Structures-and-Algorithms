#include <stdio.h>
#define MAXLIST 10

typedef enum {FALSE,TRUE}Boolean;
typedef int ListData;
typedef int position;

typedef struct
{
    int count;
    ListData entry[MAXLIST];
}list;

//create list
void CreateList(list *l)
{
    l->count = 0;
}

//empty list
Boolean IsListEmpty(const list *l)
{
    return(l->count==0);
}

//full list
Boolean IsListFull(const list *l)
{
    return(l->count==MAXLIST);
}

//List Size
int ListSize(const list *l)
{
    return(l->count);
}

//insert Last
void insertLast(ListData x, list *l)
{
    if(IsListFull(l))
    {
        printf("List is Full");
    }
    else
        {
            l->entry[l->count++]=x;
        }
}

//insert list
void insertList(position p, ListData x, list *l)
{
    int i;
    if(IsListFull(l))
    {
        printf("List is Full");
    }
    else if(p<0||p>ListSize(l))
    {
        printf("invalid position");
    }
    else
    {
        for(i=ListSize(l); i>p; i--)
        {
            l->entry[i+1]=l->entry[i];

        }
            l->entry[p]=x;
            l->count++;

    }
}

//DeleteList
void DeleteList(position p, ListData *x, list *l)
{
    int i;
    if(IsListEmpty(l))
    {
        printf("List is Empty");
    }
    else if(p<0||p>=ListSize(l))
    {
        printf("invalid position");
    }
    else
    {
        *x = l->entry[p];
        for(i=p; i<ListSize(l); i++)
        {
            l->entry[i] = l->entry[i+1];
        }
        l->count--;
    }
}

//retrive list
void RetrieveList(position p , ListData *x, const list *l)
{
    if(IsListEmpty(l))
    {
        printf("Empty List");
    }
    else if(p<0||p>ListSize(l))
    {
        printf("Invalid position");
    }
    else
    {
        *x = l->entry[p];
    }
}

//replace list
void ReplaceList(position p, ListData x, list *l)
{
    int i;
    if(IsListEmpty(l))
    {
        printf("EmptyList");
    }
    else if(p<0 || p>=ListSize(l))
    {
        printf("invalid position");
    }
    else
        {
            l->entry[p] = x;
        }
}

//TraverselList
void TraverselList(const list *l)
{
    int i;
    for(i=0; i<ListSize(l)-1; i++)
    {
        (l->entry[i]);
    }
}

void main()
{
    list l;
    int n,i;
    ListData x;
    CreateList(&l);
    printf("How many number you want to add this: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("Enter the number: ");
        scanf("%d",&x);
        insertList(i,x,&l);
    }

    for(i=0;i<ListSize(&l); i++)
    {
        RetrieveList(i,&x,&l);
        printf("%d",x);
    }
}
