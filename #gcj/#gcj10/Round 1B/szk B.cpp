#include<iostream>
#include<string>
using namespace std;

struct node{
char name[105];
node* bro;
node* child;
};
int add(node*start,char path[105]){
int count=0,pos=1,i=0;
node*tmp=start;
while(path[pos]!=0){
char str[105];i=0;
while(path[pos+i]!=0&&path[pos+i]!='/'){str[i]=path[pos+i];i++;}
str[i]=0;
pos=pos+i;
if(i==0)return count;
if(tmp->child==NULL){
//count++;
node*p=new node;
int k=0;
while(str[k]){p->name[k]=str[k++];}
p->name[k]=0;
p->bro=NULL;
p->child=NULL;
count++;
tmp->child=p;
tmp=tmp->child;
//cout<<count<<" null "<<str<<endl;
}
else{
node* tmp2=tmp->child;
while(strcmp(tmp2->name,str)!=0&&tmp2->bro!=NULL){tmp2=tmp2->bro;}
if(strcmp(tmp2->name,str)!=0){
//node *p=new node;
node*p=new node;
int k=0;
while(str[k]){p->name[k]=str[k++];}
p->name[k]=0;
p->bro=NULL;
p->child=NULL;
tmp2->bro=p;
count++;
//cout<<count<<" bro "<<pos<<str<<endl;
tmp=p;
}
else{tmp=tmp2;
}

}
if(path[pos]==0)return count;
else if(path[pos]=='/')pos++;
}
return count;
}

int main(){
//node *start=new node;

int num=0,n,m,t;
cin>>t;
while(t--){
int i=0,count=0;
char str[100];
cin>>n>>m;
node *start=new node;
start->name[0]='\0';
start->bro=start->child=NULL;
//start->child=NULL;
for(i=0;i<n;i++){cin>>str;add(start,str);}
for(i=0;i<m;i++){cin>>str;count+=add(start,str);}
cout<<"Case #"<<++num<<": "<<count<<endl;
}
return 0;
}
