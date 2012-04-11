#include<string>
#include<vector>
#include<iostream>
using namespace std;
  int choose(vector <string> lyrics)
  {
    int ret = 987654321;
    int n = lyrics[0].size();
    for(int carols = 0; carols < (1<<n); ++carols)
    {
      bool succ = true;
      for(int i = 0; i < lyrics.size(); ++i)
      {
        bool sings = false;
        for(int j = 0; j < lyrics[i].size(); ++j)
          if(lyrics[i][j] == '1' && (carols & (1<<j)))
            sings = true;
        if(!sings) { succ = false; break; }
      }
      if(succ) ret <?= __builtin_popcount(carols);
    }
    return ret;
  }
  int main()
  {
        int test,i;
        cin>>test;
        string str;
        while(test--)
        {
            int m,n,k;
            cin>>n>>m>>k;
            vector<string> v;
            for(i=0;i<n;i++)
            {
                cin>>str;
                v.push_back(str);
            }
            cout<<choose(v)<<endl;

        }
        return 0;
        
    }
