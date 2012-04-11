#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
const int MAX_CELL=14;
int N;
char maze[MAX_CELL][MAX_CELL];
int dist[MAX_CELL][MAX_CELL][1<<MAX_CELL];
int cont[MAX_CELL][MAX_CELL];
class cell{
	public:
	int x,y,state;
	cell(int a=0,int b=0,int s=0):x(a),y(b),state(s){
	}
	void changestate(){
		if(maze[x][y] == '*')
			state|=(1<<cont[x][y]);
	}
	bool isvalid(){
		return ( x>=0&&x<N && y>=0&&y<N && maze[x][y]!='#' );
	}
	bool end(int n){
		return ( state==((1<<n)-1) && x==N-1 && y==N-1 );
	}
};

//BFS
int compute(int n){
	cell p,tempcell;
	queue<cell>Q;
	Q.push(p);
	dist[0][0][0]=0;
	while(!Q.empty()){
		p=Q.front();
		if((tempcell=cell(p.x,p.y+1,p.state)).isvalid()){
				tempcell.changestate();
				if(dist[tempcell.x][tempcell.y][tempcell.state]==-1){
					dist[tempcell.x][tempcell.y][tempcell.state]=dist[p.x][p.y][p.state]+1;
					Q.push(tempcell);
					if(tempcell.end(n))
						return dist[tempcell.x][tempcell.y][tempcell.state];
					}
		}
		if((tempcell=cell(p.x,p.y-1,p.state)).isvalid()){
				tempcell.changestate();
                                if(dist[tempcell.x][tempcell.y][tempcell.state]==-1){
                                        dist[tempcell.x][tempcell.y][tempcell.state]=dist[p.x][p.y][p.state]+1;
                                        Q.push(tempcell);
                                        if(tempcell.end(n))
                                                return dist[tempcell.x][tempcell.y][tempcell.state];
                                        }
		}
		if((tempcell=cell(p.x+1,p.y,p.state)).isvalid()){
				tempcell.changestate();
                                if(dist[tempcell.x][tempcell.y][tempcell.state]==-1){
                                        dist[tempcell.x][tempcell.y][tempcell.state]=dist[p.x][p.y][p.state]+1;
                                        Q.push(tempcell);
                                        if(tempcell.end(n))
                                                return dist[tempcell.x][tempcell.y][tempcell.state];
                                        }
		}
		if((tempcell=cell(p.x-1,p.y,p.state)).isvalid()){
				tempcell.changestate();
                                if(dist[tempcell.x][tempcell.y][tempcell.state]==-1){
                                        dist[tempcell.x][tempcell.y][tempcell.state]=dist[p.x][p.y][p.state]+1;
                                        Q.push(tempcell);
                                        if(tempcell.end(n))
                                                return dist[tempcell.x][tempcell.y][tempcell.state];
                              }
		}
	Q.pop();
	}
	return -1;
}

int main(){
	int t;
	scanf("%d",&t);
	int index;
	while(t--){
		memset(dist,-1,sizeof(dist));
		index=0;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%s",maze[i]);
			for(int j=0;j<N;j++)
				cont[i][j]=(maze[i][j]=='*')?index++:0;
		}
		printf("%d\n",compute(index));
	}
}
