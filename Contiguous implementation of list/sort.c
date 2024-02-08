#include <stdio.h>
#define MAXLIST 10

typedef int ListData;
typedef enum{FALSE,TRUE}Boolean;
typedef int position;

typedef struct
{
    int count;
    ListData entry[MAXLIST];
}list;

//create list
void CreateList(list *l)
{
    l->count =0;
}

//isListEmpty
Boolean IsListEmpty(const list *l)
{
    return(l->count ==0);
}

//isListFull
Boolean IsListFull(const list *l)
{
    return(l->count==MAXLIST);
}

//listsize
int ListSize(const list *l)
{
    return(l->count);
}

//insertLast
void insertLast(ListData x, list *l)
{
    if(IsListFull(l))
       {
           printf("List is full");
       }
        else
            {
                l->entry[l->count++]=x;
            }
}

//insertlist
void insertList(position p, list *l, ListData x)
{
    if(IsListFull(l))
    {
        printf("List is full");
    }
    else if(p<0 || p>ListSize(l))
    {
        printf("invalid position");
    }
    else
        {
            int i;
            for(i=ListSize(l); i>p; i--)
            {
                l->entry[i+1] = l->entry[i];
            }
            l->entry[p] = x;
            l->count++;
        }
}

//deletelist
void DeleteList(position p, list *l, ListData *x)
{
    int i;
    if(IsListEmpty(l))
    {
        printf("List is Empty");
    }
    else if(p<0 || p>=ListSize(l))
    {
        printf("invalid position");
    }
    else
        {
            *x=l->entry[p];
            for(i=p; i<ListSize(l); i++)
            {
                l->entry[i] = l->entry[i+1];
            }
            l->count--;
        }
}

void RetrieveList(position p ,const list *l, ListData *x)
{
    if(IsListEmpty(l))
    {
        printf("List is Empty");
    }
    else if(p<0 || p>=ListSize(l))
    {
        printf("invalid position");
    }
    else
        {
         *x = l->entry[p];
        }
}

//replacelist
void  replaceList(position p ,list *l, ListData x)
{
    if(IsListEmpty(l))
    {
        printf("List is Empty");
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

//traverslist
void traversList(const list *l)
{
    int i;
    for(i=0; i<ListSize(l)-1; i++)
    {
        l->entry[i];
    }
}

//sorting
void sort(list *l)
{
   int i,j,temp;
   for(i=0; i<ListSize(l); i++)
    {
        for(j=0; j<ListSize(l)-i-1; j++)
            {
                if(l->entry[j]>l->entry[j+1])
                {
                    temp=l->entry[j];
                    l->entry[j] = l->entry[j+1];
                    l->entry[j+1] = temp;
                }
            }
    }
    for(i=0; i<ListSize(l); i++)
    {
        printf("%d ",l->entry[i]);
    }
}

void main()
{
    list l;
    ListData x;
    int n,i;
    CreateList(&l);
    printf("How many numbers you want to add this: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("Enter the number: ");
        scanf("%d",&x);
        insertList(i,&l,x);
    }

    for(i=0; i<ListSize(&l); i++)
    {
        RetrieveList(i,&l,&x);
        printf("%d ",x);
    }

    printf("\n");

    sort(&l);
}

