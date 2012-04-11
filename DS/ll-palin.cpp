#include<iostream>
#include<cstring>
using namespace std;
struct node{
	char ch;
	node* next;
};
void print(node* head)
{
	if(head->next==NULL) return;
	cout<<head->ch;
	print(head->next);
}
void insert(node* head, char* s)
{
	node* temp = head;
	for(int i=0;i<strlen(s);i++)
	{
		temp->ch=s[i];
		temp->next=NULL;
		if(i<strlen(s)) {
			temp->next=new node();
			temp=temp->next;
		}
	}
	//print(head);
}
bool ispalin(node** head,node* last)
{
	if(last->next==NULL) return true;
	
	bool temp = (ispalin(head,last->next) && ((*head)->ch == last->ch));
	
	(*head)=(*head)->next;
	return temp;
}

int main()
{
	node *head=new node();
	node *temp=head;
	insert(head, "abccba");
	cout<<ispalin(&head,temp)<<endl;;
	print(temp);
	return 0;
}
