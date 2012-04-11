#include<iostream>
using namespace std;
int a[1000000];
int main()
{
	int u,i,C,total=0;
	while(cin>>C)
	{
        
        int cc=C;
        i=0;
        while(cc--) cin>>a[i++]; //scanf("%d",&a[i++]);//cin>>a[i++];
        
        int b[C];
        int k=0;
        for(int i=0;i<C;i++){
            if(b[i]==1)continue;
            k++;
            int c=i;
            do{
                b[c]=1;
                c=a[c];
            }while(c!=i);
        }
        cout<<C-k<<endl;
    }
	return 0;
}
