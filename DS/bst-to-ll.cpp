#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void insert(node **root,int d)
{
	
	if(*root==NULL) {
		*root = new node();
		(*root)->data = d;
		(*root)->left=(*root)->right=NULL;
		
		return;
	}
	
	if(d > (*root)->data) 
	insert(&(*root)->right,d);
	else 
	insert(&(*root)->left,d);
}
void print(node **root)
{
	
	if(*root==NULL) return;
	print(&(*root)->left);
	cout<<(*root)->data<<' ';
	print(&(*root)->right);
}
void print_list(struct node *head)
{
	cout<<(head)->data<<",";
	if(head->right!=NULL)
	print_list((head)->right);
}

node* bst2list(struct node **root)
{
	struct node* curr = *root;
	if(root==NULL) return NULL;
	while(curr->left!=NULL || curr->right!=NULL)
	{
		if(curr->left == NULL)
		{
			struct node* temp=curr->right;
			struct node* pre=curr->right;
			while(pre->left!=NULL) pre=pre->left;
			curr->right=pre;
			curr=temp;
			
		}
		else 
		{
			struct node* pre = curr->left;
			while(pre->right!=NULL) pre=pre->right;
			pre->right = curr;
			curr=curr->left;
			pre->right->left=NULL;
			cout<<pre->data<<" ------ "<<pre->right->data<<" ------- "<<curr->data<<endl;
		}
		
	}
	return curr;
}
static node** bst2list_(struct node** tree,struct node** root)
{
	if((*root)==NULL) return NULL;
	(root) = bst2list_(&((*tree)->left),root);
	(*tree)->left=*root;
	return bst2list_(&(*tree)->right,root);
	/*
	node* aList;
	node* bList;
    if(root==NULL) {
		return NULL;
	}
	if((*root)->left==NULL && (*root)->right==NULL)
		return *root;
	if((*root)->left!=NULL) {
		node* pre=(*root)->left;
		while(pre->right!=NULL) pre=pre->right;
		aList=bst2list_(&(*root)->left);
		node* end=aList;
		while(end->right!=NULL) end=end->right;
		pre->right=*root;
	}
	if((*root)->right!=NULL) {
		bList=bst2list_(&(*root)->right);
		(*root)->right=bList;
	}
	return aList;
	* */
}


int main()
{
	struct node *root=NULL;
	root = new node();
	root = NULL;
	
	for(int i=1;i<15;i++)
	{
		int r=rand();
		r=r%100;
		cout<<r<<' ';
		insert(&root,r);
		
	}
	cout<<endl;
	
	print(&root);
	
	static node *head = root;
	
	//while((head)->left!=NULL) (head)=(head)->left;
	
	//bst2list(&root);
	//node **h=bst2list_(&root,&root);
	//cout<<endl;
	print_list(bst2list(&head));
	
	return 0;
}
