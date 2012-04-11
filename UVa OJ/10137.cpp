/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    double ppl,t,tt,temp,avg_dol,avg_dec;
    vector<double> dol;
    char ch;
    while(1)
    {
            dol.clear();
            cin>>ppl;
                   if(ppl==0)
                   break;
                   temp=ppl;
                   avg_dol=0;
                   while(temp--)
                   {
                                cin>>t;
                                t=t*100;
                                dol.push_back(t);
                                avg_dol+=t;
//                                cout<<t<<endl;
                                }
                   avg_dol/=ppl;
                   int res_dol_H=0,res_dol_L=0;
                   for(int i=0;i<ppl;i++)
                   {
                           if(dol[i]>avg_dol)
                           {
                                             res_dol_H+=(dol[i]-avg_dol);
      //                                       cout<<"///////"<<res_dol_H<<endl;
                                             }
                           else if(dol[i]<avg_dol)
                           {
                                res_dol_L+=(avg_dol-dol[i]);
                                }
                           }
                   double ttt,d,dd;
                   ttt=max(res_dol_L,res_dol_H);
    //               cout<<"ttt="<<ttt<<endl;
  //                 cout<<avg_dol<<endl;
//                   cout<<res_dol_H<<"\n";
                   ttt=ttt/100;
                   printf("$%.2lf\n", ttt);
                   }
return 0;
}
/* @END_OF_SOURCE_CODE */
