#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create_node();
void add_first(int data);
void display();
void add_last(int data);
void add_at_specific_pos(int data,int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_specific_pos(int pos);
void selection_sort();

int main()
{
    add_first(50);
    add_first(65);
    add_first(40);
    //forward_display();
    //backward_display();
    add_last(75);
    add_last(95);
    //forward_display();
    //backward_display();
    //delete_first();
    printf("Before sort\n");
    display();
    //forward_display();
    printf("After sort\n");
    selection_sort();

    //delete_last();
    display();
    return 0;
}

struct node* create_node()
{
   struct node *ptr = (struct node*) malloc(sizeof(struct node));

   ptr->data =0;
   ptr->next = NULL;

   return ptr; // return 700
}

void add_first(int data) // 30
{
    // 1. create a node
   struct node *ptr =  create_node();//return address hence stored in ptr with datatype struct node543eww
   ptr->data = data;

   // 2. attach the node to the linked list
   // a. if the linked list is empty
   if(head == NULL)
   {
        head = ptr;
   }
   else // the list contains multiple nodes
   {
    // attach it at the first position
    // step 1: create the link/ connection between the new node and first node
    ptr->next = head;

    // step 2: update the head pointer to point to new node
    head = ptr;
   }
}

void display()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else
    {
        struct node *trav = head;

        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}

void add_last(int data)
{
    // 1. create a node
    struct node *ptr = create_node();
    ptr->data = data;

    // 2. attach the node to the list
    // a. if the list is empty
    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        // traverse and stop at the last node
        struct node *trav = head;

        while(trav->next != NULL)
        {
            trav = trav->next;
        }
        // attach the new node with the last node
        trav->next = ptr;
    }

}

void add_at_specific_pos(int data,int pos)
{
    if(head == NULL)//LL IS EMPTY
    {
        if(pos==1)
        {
            add_first(data);
        }
        else
        {
            printf("Invalid\n");
        }
    }
    else if(pos == 1)  // LL CONTAINS MULTIPLE NODE 
        add_first(data);
    else if(pos == count_nodes()+1)
        add_last(data);
    else if(pos < 1 || pos > count_nodes() + 1)
    {
        printf("Invalid !\n");
    }
    else
    {
        struct node *ptr = create_node();
        ptr->data = data;
        // traverse till pos -1 node

        struct node *trav = head;
        for(int i =1; i< pos-1; i++)
        {
            trav = trav->next;
        }
        // create a connection between new node and position node
        ptr->next = trav->next;

        trav->next = ptr;
    }
}

int count_nodes()
{
    int count = 0;
    if(head == NULL)
        printf("List is empty !\n");
    else
    {
        struct node *trav = head;
        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

void delete_first()
{
    if(head == NULL) //LIST IS EMPTY
        printf("List is Empty !\n");
    else if(head->next == NULL) // if list contains only one node
    {
        free(head);
        head = NULL;
    }
    else
    {
        // if the list contains multiple nodes
        //take a backup of the first node

        struct node *temp = head;
        // attach head to 2nd node
        head = head->next;
        // OR head = temp->next;

        // free the temp node
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *trav = head;

        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
}

void delete_at_specific_pos(int pos)
{
    if(head == NULL)
        printf("List is Empty !\n");
    else if(pos == 1)
        delete_first();
    else if(pos == count_nodes())
    {
        delete_last();
    }
    else if(pos <1 || pos > count_nodes())
        printf("Invalid !\n");
    else
    {
        struct node *trav = head;
        for(int i =1; i< pos-1; i++)
        {
            trav = trav->next;
        }
        // take a backup of pos node
        struct node *temp = trav->next;

        trav->next = temp->next;
        // trav->next = trav->next->next

        free(temp);
        temp = NULL;
    }
}

void selection_sort()
{
    struct node *i, *j;
    for(i=head;i->next != NULL;i=i->next){
        for(j=i->next;j != NULL;j=j->next)
        {
            if(i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}



