#include <string>
#include <vector>
#include <iostream>
using namespace std;
class GirlsAndBoys {
	public:
	int func(string co,int len)
	{
		int i,k,j,count=0;
		char pres=co[len-1];
		for(i=1;i<len;i++)
		{
			if(co[i]!=co[i-1])
			break;
		}
		int temp=i;
		for(j=i+1;j<len;j++)
		{
			if(co[j]!=co[i])
			{
				count+=(j-temp);
				temp++;
			}
		}
		return count;
	}
	int sortThem(string row) {
		int i;
		int len=row.length();
		string co=row;
		int fir=func(co,len);
		for(i=0;i<len;i++)
		{
			if(co[i]=='B')
			co[i]='G';
			else if(co[i]=='G')
			co[i]='B';
		}
		int sec=func(co,len);
		return fir<sec?fir:sec;
	}
};
int main()
{
	GirlsAndBoys d;
	string str="BGGGGBB";
	cout<<d.sortThem(str);
	return 0;
}
