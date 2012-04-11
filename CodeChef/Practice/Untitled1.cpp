#include<iostream>
#include<cstring>
using namespace std;
int main()
{
char arr[]="MOOZMOOZMOOZ";
		for(int i=0; i < strlen(arr); i++)
		{
                
		for(int j=i+1; j < strlen(arr); j++)
		{
                    
			if( arr[i] ^ arr[j] )
				{
	arr[i]^=arr[j]^=arr[i]^=arr[j];
}
}
		}
		cout<<arr<<"\n";
getchar();
return 0;
}
