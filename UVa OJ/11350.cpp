/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <list>
using namespace std;
int euclid(int a,int b)
{
   if(b==0)
        return a;
   else
        return euclid(b,a%b);
}
int main()
{
    int p,q,r,s;
    list<int> n;
    list<int> d;
    list<int>::iterator it;
    list<int>::iterator itr;
    n.clear();
    d.clear();
    n.push_back(0);
    n.push_back(1);
    d.push_back(1);
    d.push_back(0);
    string str;
    cin>>str;
    int t=str.length();
    while(t--)
    {
    int i=0;
    for(it=n.begin();it!=n.end();i++,it++)
    cout<<i<<"\t"<<*it<<"\n";
    cout<<".................................."<<endl<<endl;
    for(it=n.begin(),itr=d.begin();it!=n.end()&&itr!=d.end();)
    {
                 p=(*it);
                 cout<<"inserting by adding"<<p;
                 q=*(++it);
                 r=*(itr);
                 cout<<" "<<r<<" "<<p+r<<endl;
                 s=*(++itr);
                 p=p+r;
                 q=q+s;
//                 r=euclid(p,q);
  //               if(r!=1)cout<<"................................"<<r<<endl;
    //             p=p/r;
      //           q=q/r;
                 n.insert(it,p);
                 d.insert(itr,q);
                 it++;
                 itr++;
//                 cout<<*it<<"-------- inserted value\n";
                }
//                 cout<<*it<<" "<<endl;
    }
    cout<<"\n\n\nCOMPLETED\n\n";
    int i=0;
    for(it=n.begin();it!=n.end();i++,it++)
    cout<<i<<"\t"<<*it<<"\n";
    i=0;
    for(itr=d.begin();itr!=d.end();i++,itr++)
    cout<<i<<"\t"<<*itr<<"\n";
    cin>>i;
    return 0;
}
/* @END_OF_SOURCE_CODE */
