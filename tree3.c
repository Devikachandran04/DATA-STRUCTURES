#include<stdlib.h>
#include<stdio.h>
typedef struct node_tree
{
 int value;
 struct node_tree *left;
 struct node_tree *right;

}node_tree;

typedef struct node
{

 node_tree *data;
 struct node *link;
}node;

node* createhead()
{
 node *head;
 head=malloc(sizeof(node));
 head->link=NULL;
 return head;
}

node* createnode()
{
        node *newnode;
 newnode=malloc(sizeof(node));
 return newnode;
}



void insertlast(node *head,node_tree *node1)
{
 node *newnode=createnode();
 newnode->data=node1;
 if(head->link==NULL)
  {
  head->link=newnode;
  newnode->link=NULL;

  }
 else
  {
  node *current=head;
  while(current->link!=NULL)
  {
  current=current->link;
  }
  newnode->link=current->link;
  current->link=newnode;

  }

}

node_tree* deletefirst(node *head)
{
   node_tree *temp=NULL;
 if(head->link!=NULL)
 {
   temp=head->link->data;
   head->link=head->link->link;
 }
return temp;
}

node* createqueue()
{
node *head=createhead();
return head;
}

void enqueue(node *head,node_tree *node)
{
  insertlast(head,node);
}

node_tree* dequeue(node *head)
{
 return(deletefirst(head));
}

node_tree* createnode_tree()
{
        node_tree *newnode;
 newnode=malloc(sizeof(node_tree));
 return newnode;
}

node_tree* insert(node_tree *root,int data)
{
 node_tree *newnode=createnode_tree();
 newnode->value=data;


 if(root==NULL)
  {

  root=newnode;
  root->left=NULL;
  root->right=NULL;

  }
 else
  {
  node_tree *current= root;
  node_tree *prev=root;
  int flag=0;
  while(current!=NULL)
  {
  if(current->value > data)
  {
  prev=current;
  current=current->left;
  flag=1;
  }
  else
  {
  prev=current;
  current=current->right;
  flag=2;
  }
  }
  if(flag==1)
  {
  prev->left=newnode;
  newnode->left=newnode->right=NULL;
  }
  else
  {
prev->right=newnode;
  newnode->left=newnode->right=NULL;
  }


   }
return root;
}

int search(node_tree* root, int key) {

    if (root == NULL)
    {
        return 2;
    }
    if (root->value == key)
    {
        return 1;
    }
    if (root->value < key)
    {
        return search(root->right, key);
    }
    if (root->value > key)
    {
    return search(root->left, key);
    }
}
node_tree* inorder_successor(node_tree *current)
{

    while (current->left != NULL)
        current = current->left;

    return current;
}
node_tree* deleteNode(node_tree *root, int key)
{

    if (root == NULL) return root;
    if (key < root->value)
        root->left = deleteNode(root->left, key);
    else if (key > root->value)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL)&&(root->right == NULL))
        {
        root=NULL;
        return root;
        }
        else if (root->left == NULL)
        {
            node_tree *temp=root->right;
            free(root);
            root=temp;
            return temp;
        }
        else if (root->right == NULL)
        {
        node_tree *temp=root->left;
        free(root);
        root=temp;
        return temp;
        }

        struct node_tree* temp = inorder_successor(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}
void inorder(node_tree *root)
{
 if(root!=NULL)
   {
  inorder(root->left);
  printf("%d ",root->value);
  inorder(root->right);

  }
}

void main()
{
node_tree *root=NULL;
int data,ch,key;
while (1)
{
printf("\n1. Insertion\n2. Search\n3. Deletion\n4. Display\n5. Exit\n");
printf("Enter the choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the value: ");
scanf("%d",&data);
root=insert(root,data);
break;

case 2:
printf("Enter the element to be searched: ");
scanf("%d",&key);
int val=search(root,key);
if (val == 1)
{
printf("Element found");
}
else
{
printf("Element not found");
}
break;

case 3:
printf("Enter the element to be deleted: ");
scanf("%d",&key);
node_tree *d=deleteNode(root,key);
break;

case 4:
inorder(root);
break;

case 5:
exit(0);
break;

default:
printf("Invalid choice");
exit(0);
}
}
}