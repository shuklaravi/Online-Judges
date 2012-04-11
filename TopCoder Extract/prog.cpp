#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <functional>
#include <deque>
#include <memory>
#include <cstring>

using namespace std;

int gt[ 20 ][ 20 ][ 20 ][ 20 ];

bool wal[ 20 ][ 20 ];

int dx[] = { 0, 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, 0, -1 };

deque< pair< pair< int, int >, pair< int, int > > > daq;

bool vald( int x, int y ) {
  return x >= 0 && y >= 0 && x < 20 && y < 20 && !wal[ x ][ y ];
};

class PathFinding {
  public:
  int minTurns(vector <string> a) {
    memset( gt, 0x40, sizeof( gt ) );
    memset( wal, 0xff, sizeof( wal ) );
    int ax = -1;
    int ay = -1;
    int bx = -1;
    int by = -1;
    for( int i = 0; i < a.size(); i++ ) {
      for( int j = 0; j < a[ 0 ].size(); j++ ) {
        switch( a[ i ][ j ] ) {
        case '.':
          wal[ j ][ i ] = false;
          break;
        case 'X':
          wal[ j ][ i ] = true;
          break;
        case 'A':
          ax = j;
          ay = i;
          wal[ j ][ i ] = false;
          break;
        case 'B':
          bx = j;
          by = i;
          wal[ j ][ i ] = false;
          break;
        }
      }
    }
    gt[ ax ][ ay ][ bx ][ by ] = 0;
    daq.push_back( make_pair( make_pair( ax, ay ), make_pair( bx, by ) ) );
    while( daq.size() ) {
      pair< pair< int, int >, pair< int, int > > ti = *daq.begin();
      daq.pop_front();
      int td = gt[ ti.first.first ][ ti.first.second ][ ti.second.first ][ ti.second.second ] + 1;
      pair< int, int > na;
      pair< int, int > nb;
      for( int x = 0; x < 9; x++ ) {
        if( vald( ti.first.first + dx[ x ], ti.first.second + dy[ x ] ) ) {
          na = ti.first;
          na.first += dx[ x ];
          na.second += dy[ x ];
          for( int y = 0; y < 9; y++ ) {
            if( vald( ti.second.first + dx[ y ], ti.second.second + dy[ y ] ) ) {
              nb = ti.second;
              nb.first += dx[ y ];
              nb.second += dy[ y ];
              if( ( na != ti.second || nb != ti.first ) && na != nb ) {
                if( gt[ na.first ][ na.second ][ nb.first ][ nb.second ] > td ) {
                  gt[ na.first ][ na.second ][ nb.first ][ nb.second ] = td;
                  daq.push_back( make_pair( na, nb ) );
                }
              }
            }
          }
        }
      }
    }
    if( gt[ bx ][ by ][ ax ][ ay ] > 1000000 ) {
      return -1;
    } else {
      return gt[ bx ][ by ][ ax ][ ay ];
    }
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
