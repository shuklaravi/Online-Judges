
using namespace std;
#include <iostream>
#include <map>
#include <vector>



#define REP(i,a) for((i)=0;(i)<(a);(i)++)

#define SZ(x) sizeof(x)
#define MEM(m,i) memset((m),(i),SZ(m))

#define scanInt(x) scanf("%d",&x)
#define printInt(x) printf("%d\n",x)

//END_TEMPLATE_BY_PRATYUSH_VERMA
int c,p,s;
vector<pair<int, vector<pair<int, int> > > > grid[10005];
int dist[10005];

int main()
{
    int i,j,x,y,z;
    MEM(dist, 9999999);
    scanInt(c);scanInt(p);scanInt(s); s--;
    REP(i,p) {
        scanInt(x);scanInt(y);scanInt(z); x--; y--;
        grid[x].push_back(make_pair(y,z));
        grid[y].push_back(make_pair(x,z));
    }
    int h,f,w;
    int res = 0;
    scanInt(h);

    dist[s] = 0;
    REP(i,c)
    {
        cout<<i<<" : \n";
        REP(j,grid[i].size())
        {

        }
    }
    REP(i,c)
    {
        REP(j,grid[i].size())
        {
            if((dist[i] + grid[i][j].second) < dist[j])
            {
                dist[grid[i][j].first] = dist[i] + grid[i][j].second;
            }

        }
    }
    REP(i,c)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
    REP(i,h) {
        scanInt(f);scanInt(w);
        res += w*dist[f-1];
    }
    printInt(res);
//	system("pause");
	return 0;
}
