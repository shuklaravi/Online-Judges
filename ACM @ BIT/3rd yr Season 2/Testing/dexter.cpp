using namespace std;
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define PI 3.1428571428571428571428571428571

class coordinate { public:
  int x,y; float angle;
  int equals(coordinate p){ return (p.x!=x||p.y!=y)?0:1; };
  float distance(coordinate p){ return sqrt( (p.x-x)*(p.x-x) + (p.y-y)*(p.y-y) ); }
  void print(){ if(1)printf("(%d,%d) ",x,y); else printf("(%d,%d,%f) ",x,y,angle); }
  };

vector<coordinate> point;
vector<coordinate> hull;

void first(){
  int i,k=-1; coordinate p;
  for(i=0;i<point.size();i++)
    if(k==-1 || point.at(i).x < point.at(k).x || (point.at(i).x == point.at(k).x && point.at(i).y < point.at(k).y) )
        k=i;
  if(k){ p = point.at(0); point.at(0) = point.at(k); point.at(k) = p; }
  }

void anglegen(){
  float dx,dy;
  point.at(0).angle=0;
  for(int i=1;i<point.size();i++){
    dx = point.at(i).x-point.at(0).x;
    dy = point.at(i).y-point.at(0).y;
    if(dx==0){ if(dy>0) point.at(i).angle = 0; else point.at(i).angle = PI; }
    if(dx>0){ if(dy==0) point.at(i).angle=PI/2; else if(dy>0) point.at(i).angle = atan(dx/dy);
    else point.at(i).angle = PI-atan(-dx/dy); }
    if(dx<0){ if(dy==0) point.at(i).angle=3*PI/2; else if(dy<0) point.at(i).angle = PI + atan(dx/dy); else point.at(i).angle = 2*PI-atan(-dx/dy); }
    //point.at(i).print(); cout<<dx<<" "<<dy<<" "<<point.at(i).angle<<endl;
    }
  }

bool sortangle(coordinate p, coordinate q){
  if(p.angle < q.angle) return 1;
  if(p.angle > q.angle) return 0;
  if(point.at(0).distance(p) < point.at(0).distance(q) ) return 1; else return 0;
  }

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i,j,k;
  float angle,length; // scanning angle
  coordinate p; p.angle=0;

  int m,n; float l;
  cin>>m;
  while(m--){
  cin>>l>>n;

  for(i=0;i<n;i++){ cin>>p.x>>p.y; point.push_back(p); }
  //while(cin>>p.x>>p.y) point.push_back(p);
  first();  // select the starting point
  point.push_back(point.front());
  //for(j=0;j<16;j++){
  angle=0; length=0;
  while( hull.size()==0 || !hull.front().equals(point.front()) ){
    anglegen(); // generate angles for all points wrt first point
    sort(point.begin()+1,point.end()-1,sortangle); // assuming first element is sorted, and sort the rest
    for(i=1;i<point.size() && point.at(i).angle<angle;i++); // selecting first point ahead of the scanning angle
    angle = point.at(i).angle; // update scanning angle
    k=point.size(); if(i!=k-1 && point.at(i).angle>point.at(k-1).angle)  i=k-1;
    hull.push_back( point.front() ); point.erase( point.begin() ); // transfer current point from point vector to hull vector
    if(i>1){ point.insert(point.begin(),point.at(i-1)); point.erase(point.begin()+i); } // transfer next point to head of point vector

    if(0){ // debugging code : display state
      point.at(0).print(); cout<<"~ "<<angle<<endl;
      for(k=0;k<hull.size();k++) hull.at(k).print(); cout<<endl;
      for(k=0;k<point.size();k++) point.at(k).print(); cout<<endl<<endl;
      }
  }
  hull.push_back( point.front() ); point.erase( point.begin() ); // complete the hull

  for(i=0;i<hull.size();i++){
    if(i) length+=hull.at(i).distance( hull.at(i-1) );
    }
    length+=hull.at(0).distance(hull.at(hull.size()-1));
  printf("%.5f\n",(length>l)?length:l);

  point.clear(); hull.clear();
  } // test case

  return 0;
  }
