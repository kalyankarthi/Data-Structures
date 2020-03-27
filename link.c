#include<stdio.h>
#include<stdlib.h>
 struct Node
{
 int data;
 struct Node *next;
} ;
typedef struct Node Node;
typedef struct Head
 {
 	int size;
 	Node *next;
 } Head; 
 Head* createList()
 {
 	Head* h = malloc(sizeof(*h));
 	h->size=0;
 	h->next=NULL;
 	return h;
 }
void insert_last(Head *h,int a)
{
  Node *k =malloc(sizeof(k));
 k->data= a;
 k->next=NULL;
 Node *p = h->next;
  while(p!=NULL&&p->next!=NULL)
     {
     	p=p->next;
     }
  if(p==NULL)
  	h->next=k;
  else
  	p->next=k;
 ++h->size;
}
void insert_front(Head *h,int a)
{
	Node *b =malloc(sizeof(b));
    b->data= a;
    b->next=h->next;
    h->next=b;
    ++h->size;	
}
void insert_at(Head *h,int a,int i)
{
  int v=0;
 Node *k =malloc(sizeof(k));
 k->data= a;
 k->next=NULL;
 Node *p = h->next;
 if(i>h->size+1||i<1)
 	printf("Enter appropriate position\n");
 else{
 while(v<i-2)
 {
 	p=p->next;
 	++v;
 }
 if(i==1)
 {
 k->next=p;	
 h->next=k;
}
 else
 {
   Node* t=p->next;
   p->next=k;
   k->next=t;
 } 
}
}
int delete_front(Head *a){
a->size--;
a->next=a->next->next;
return a->size;
}
int delete_back(Head *a)
{
	a->size--;
	Node *p= a->next;
	while(p->next->next!=NULL)
	{
		p=p->next;
	}
	p->next=NULL;
	return a->size;
}
int delete_at(Head *a,int i)
{
	int j=1;
	if(i<=0||i>a->size)
		printf("Enter proper position\n");
	else{
	if(i==1)
     {
     	a->size--;
        a->next=a->next->next;
         return a->size;
     }
     else
     {
	    Node *p= a->next;
	    while(j<i-1)
	   {
         p=p->next;
	   }
	   p->next=p->next->next;
	   a->size--;
	   return a->size;
    }
  }
}
void print(Head *a)
{

 Node *p =a->next; 
 if(p==NULL)
 	printf("Linked List is Empty\n");
 while(p!=NULL)
     {
     	printf("%d\t  ",p->data );
     	p=p->next;
     }	
}
int main(int argc, char const *argv[])
{
	Head *a=createList();
	int n,val,pos;
    while(1){
	printf("There are Eight operations here\n1.insert front\n2.insert back\n3.insert at a position\n4.show\n5.delete front\n6.delete back\n7.delete at\n8.exit\nEnter your choice:");
	scanf("%d",&n);
    switch(n)
    {
    	case 1:
    	printf("Enter the value to be inserted\n");
    	scanf("%d",&val);
    	insert_front(a,val);
    	break;
    	case 2:
    	printf("Enter the value to be inserted\n");
    	scanf("%d",&val);
    	insert_last(a,val);
    	break;
    	case 3:
        printf("Enter the value to be inserted\n");
    	scanf("%d",&val);
    	printf("Enter the position  to be inserted\n");
    	scanf("%d",&pos);
    	insert_at(a,val,pos);    	
    	break;
    	case 4:
    	print(a);
    	break;
    	case 5:
    	delete_front(a);
    	break;
    	case 6:
    	delete_back(a);
    	break;
    	case 7:
    	printf("Enter the position  to be inserted\n");
    	scanf("%d",&pos);
    	delete_at(a,pos);
    	break;
    	case 8:
    	exit(0);
    	break;
    	default:
    	printf("Enter the proper value\n");

    }
   }
    
	return 0;
}