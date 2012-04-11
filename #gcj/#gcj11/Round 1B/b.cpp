#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
    int t,n,i,tim;
    scanf("%d", &t);
    double k, x, lpos, cur, max, tot,len, allow, p,mov;
    vector<double> u, v;
    while (t--)
    {
          u.clear();
          v.clear();
          scanf("%d%lf",&n,&k);
          scanf("%lf%d", &x,&tim);
          stringstream ss;
          len=0;
          len+=tim;
          cout<<"..\n"<<n<<endl;
          while(tim--) ss>>x;
          cout<<"!!\n";
          ss<<x;
          cout<<"**\n";
          len--;
          if (x > 0.0)
          {
             u.push_back(x);
             v.push_back(0);
          }
          cur = max = 0.0;
          lpos = x;
          for(i=1;i<n;i++)
          {
              scanf("%lf%d", &x,&tim);
              len+=tim;
              while(tim--) ss>>x;
          }
          cout<<"........."<<len<<" \n";
          for (i = 1; i < len; i++)
          {
                ss<<x;
              if (x - lpos >= k)
              {
                    if (x-lpos > k )
                    {
                       u.push_back(x-lpos-k);
                       v.push_back(0.0);
                    }
                    lpos = x;
              }
              else
              {
                  mov = k + lpos - x;
                  if (u.empty())
                  {
                      lpos += k;
                      if (max < lpos - x) max = lpos - x;
                  }
                  else
                  {
                       cur = tot = 0.0;

                       while (mov > 0.0 && !u.empty())
                       {
                             cur = v[v.size() - 1];
                             if (cur > tot)
                             {
                                 p = min(mov, cur-tot);
                                 x += p;
                                 mov -= p;
                                 tot += p;
                             }
                             p = min(u[u.size()-1], mov/2);
                             x += p;
                             tot += p;
                             u[u.size()-1] -= p;
                             v[v.size()-1] += p;
                             mov -= 2*p;
                             if (u[u.size()-1] <= 0.0)
                             {
                                 if (v.size()>1) v[v.size()-2] = v[v.size()-2]<v[v.size()-1]?v[v.size()-1]:v[v.size()-2];
                                 u.pop_back();
                                 v.pop_back();
                             }
                       }
                       if (mov > 0.0)
                       {
                               x += mov;
                               tot += mov;
                       }
                       lpos = x;
                       if (max < tot) max = tot;
                  }
              }
          };
          //max += 0.00005;

          printf("%0.4lf\n", max);
    }
    return 0;
}
