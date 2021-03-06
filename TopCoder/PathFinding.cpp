#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct node{
	   int aX,aY,bX,bY;
	   int steps;
	   node(int a, int b, int c, int d, int e){
				aX=a;aY=b;bX=c;bY=d;steps=e;
	   			}
	   node() {}
}parent;
class PathFinding {
	public:
	int bfs(bool visited[][20][20][20], int grid[][20], vector<string> board) {
		queue<node> s;
		s.push(parent);
		while(!s.empty())
		{
						 node temp=s.front();
						 s.pop();
						 if(temp.aX<0 || temp.aX>=board.size() || temp.aY<0 || temp.aY>=board[0].length()) continue;
						 if(temp.bX<0 || temp.bX>=board.size() || temp.bY<0 || temp.bY>=board[0].length()) continue;
						 if(temp.aX==temp.bX && temp.aY==temp.bY) continue;
						 if(parent.aX==temp.bX && parent.aY==temp.bY && parent.bX==temp.aX && parent.bY==temp.aY)
						 {cout<<"reached\n";
						 cout<<"A : "<<temp.aX<<" "<<temp.aY<<endl<<"B : "<<temp.bX<<" "<<temp.bY<<endl<<" in "<<temp.steps<<endl;
						 return temp.steps;}
						 if(visited[temp.aX][temp.aY][temp.bX][temp.bY]==true) continue;
						 if(grid[temp.aX][temp.aY]==-1) continue;
						 if(grid[temp.bX][temp.bY]==-1) continue;
						 visited[temp.aX][temp.aY][temp.bX][temp.bY]=true;
//						 cout<<"A : "<<temp.aX<<" "<<temp.aY<<endl<<"B : "<<temp.bX<<" "<<temp.bY<<endl;
						 for(int p1DelX=-1;p1DelX<2;p1DelX++)
						 for(int p1DelY=-1;p1DelY<2;p1DelY++)
						 for(int p2DelX=-1;p2DelX<2;p2DelX++)
						 for(int p2DelY=-1;p2DelY<2;p2DelY++)
						 {
						  		 if((p1DelX+temp.aX==temp.bX && p1DelY+temp.aY==temp.bY)||(p2DelX+temp.bX==temp.aX && p2DelY+temp.bY==temp.aY))
						  		 continue;
//						  		 node t(p1DelX+temp.aX, p1DelY+temp.aY, p2DelX+temp.bX, p2DelY+temp.bY);
						  		 s.push(node (p1DelX+temp.aX, p1DelY+temp.aY, p2DelX+temp.bX, p2DelY+temp.bY,temp.steps+1));
		 				 }
						 }
		return -1;
	}
	int minTurns(vector <string> board) {
        bool visited[20][20][20][20]={false};
//		memset(visited,0,25*25*25*25);
		int grid[20][20]={0};
		for(int i=0;i<board.size();i++)
		{
		 		for(int j=0;j<board[i].length();j++)
		 		{
						if(board[i][j]=='.' || board[i][j]=='A' || board[i][j]=='B') grid[i][j]=0;
						else if(board[i][j]=='X') grid[i][j]=-1;
						if(board[i][j]=='A') parent.aX=i,parent.aY=j;
						else if(board[i][j]=='B') parent.bX=i,parent.bY=j;
				 		}}
		parent.steps=0;
		return bfs(visited,grid,board);
	}
};
int main()
{
    int r,c,i,j,k;
    PathFinding p;
    while(cin>>r>>c)
    {
        string s;
        vector<string> grid;
        for(i=0;i<r;i++)
        {
            cin>>s;
            grid.push_back(s);
        }
        cout<<p.minTurns(grid)<<endl;
    }
}
