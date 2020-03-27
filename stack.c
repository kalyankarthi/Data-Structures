#include <stdio.h>
#include<stdlib.h>

 struct Stack
{
	int data;
	struct Stack *next;
} ;
struct Head
{
  int size;
  struct Stack *head;	
};
typedef struct Head Head;
Head* createNode()
{
	Head *h = malloc(sizeof(h));
	h->size=-1;
	h->head=NULL;
	return h;
}
void push(Head* h,int data)
{
	struct Stack *n= malloc(sizeof(n));
	n->data=data;
	n->next=NULL;
	struct Stack *p = h->head;
	if(p==NULL)
	{
      h->head=n;
      h->size++;
	}
	else
	{
		h->head=n;
		n->next=p;
		h->size++;
	}
}
 int pop(Head *h)
 {
 	h->size--;
 	h->head = h->head->next; 
 	return h->size;
 	
 }
 void show(Head *h)
 {
 	struct Stack* p = h->head;
 	while(p!=NULL)
 	{
 		printf("%d head: %d\n",p->data,h->size);
 		p=p->next;
 	}
 } 
int main()
{
  Head *a=createNode();	
  int n,val;
  while(1){
	printf("There are four operations here\n1.push\n2.pop\n3.show\n4.exit\nEnter your choice:");
	scanf("%d",&n);
    switch(n)
    {
    	case 1:
    	printf("Enter the value to be pushed\n");
    	scanf("%d",&val);
    	push(a,val);
    	break;
    	case 2:
    	pop(a);
    	break;
    	case 3:
        show(a);	
    	break;
    	case 4:
    	exit(0);
    	break;
    	default:
    	printf("Enter the proper value\n");

    }
   }
	return 0;
}