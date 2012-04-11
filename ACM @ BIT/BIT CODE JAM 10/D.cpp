
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
string sto[500];
bool cmp( string a,string b){
          int lena = a.length(), lenb = b.length();
          int posa = 0, posb = 0;
            //cout<<"a is "<<a<<endl;
       //    cout<<"b is "<<b<<endl;
          while (1)
          {
                    bool t = 1;
                    while (posa < lena && posb < lenb)
                    {
                              if (a[posa] != b[posb])
                              {
                                        t = 0;
                                        break;
                              }
                              posa++, posb++;
                    }
                    if (!t)break;
                    if(posa==lena&&posb==lenb)
                    {
                              break;
                    }
                    if (posa == lena){
                              posa = 0;
                    }else{
                              posb = 0;
                    }
          }
   //       cout<<"now the pa is "<<a[pa]<<"-->"<<"now the pb is "<<b[pb]<<endl;
          if(a[posa]<b[posb])
          {
                    return 0;
          }
          else
          {
                    return 1;
          }
}

int main()
{
   string str;
          while (1){
                //              getline(cin,str);
                getline(cin, str,' ');
                int x=0,y=0,z=0;
                    for(;y<str.length();y++,x++)
                    {
                            z=0;
                            while(str[y]!=' ' && str[y]!='\n')
                            sto[x][z++]=str[y++];
                            sto[x][z]='\0';
                            cout<<sto[x]<<endl;
                            }

/*                    for (int i = 0;i < N;i++){
                              cin >> sto[i];
                    }
  */
                    N=x-1;
                    for(int i=0;i<3;i++)
                    cout<<sto[i]<<endl;
                    sort(sto, sto + N, cmp);
                    for (int i = 0;i < N;i++){
                              cout << sto[i];
                    }cout << endl;
          }
          return 0;
}
