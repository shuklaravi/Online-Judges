#include <string>
#include <vector>
#include <iostream>
using namespace std;
class RobotSimulation {
	public:
	int cellsVisited(string program,int times) {
		int arr[100][100]={0};
		int i=50,j=50;
		int count=1,time[50]={1};
		int len=program.length();
		arr[i][j]=1;
/*		for(int k=0;k<len;k++)
		{
			if(program[k]=='U')
			i--;
			else if(program[k]=='D')
			i++;
			else if(program[k]=='L')
			j--;
			else if(program[k]=='R')
			j++;
			if(arr[i][j]==0) count++;
			arr[i][j]=1;
		}
		times--;
*/		for(int z=0;z<len && times>0;z++,times--)
		{
		for(int k=0;k<len;k++)
		{
			if(program[k]=='U')
			i--;
			else if(program[k]=='D')
			i++;
			else if(program[k]=='L')
			j--;
			else if(program[k]=='R')
			j++;
			if(arr[i][j]==0) time[z]++;
			arr[i][j]=1;
		}
		}
		int p,res=0;
		for(p=0;p<len;p++)
		res+=time[p];
		res+=(time[p-1]*(times-len+3));
		for(int q=0;q<len;q++)
		cout<<q<<" "<<time[q]<<endl;
		return res;
	}
};
int main()
{
	RobotSimulation d;
	string str="RRUUULLDD";
	int t=3603602;
	cout<<d.cellsVisited(str,t);
	return 0;
}
