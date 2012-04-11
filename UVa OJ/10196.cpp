/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int set(char b[][10],char ch)
{
    char r,b1,q,k,n,p;
    int i,j;
    bool check=false;
    bool cas;
    if(islower(ch)) cas=false;
    else if(isupper(ch)) cas=true;
    if(cas) {r='r';b1='b';q='q';k='k';n='n';p='p';}
    else {r='R';b1='B';q='Q';k='K';n='N';p='P';}
//    cout<<"CHECKING FOR "<<ch<<endl;
   for(i=0;i<8;i++)
     {
                    for(j=0;j<8;j++)
                    {
                                    if(b[i][j]==p)
                                    {
                                                  if(p=='p')
                                                  {
                                                            if(b[i+1][j-1]==ch)
                                                            {
                                                                               check=true;
                                                                               break;
                                                                               }
                                                            if(b[i+1][j+1]==ch)
                                                            {
                                                                               check=true;
                                                                               break;
                                                                               }
                                                            }
                                                  else if(p=='P')
                                                  {
                                                            if(b[i-1][j-1]==ch)
                                                            {
                                                                               check=true;
                                                                               break;
                                                                               }
                                                            if(b[i-1][j+1]==ch)
                                                            {
                                                                               check=true;
                                                                               break;
                                                                               }
                                                            }
                                                  if(check) break;
                                    }
                                    if(b[i][j]==r)
                                    {
//                                                                  cout<<endl<<"rook found at "<<i<<","<<j<<endl<<endl;
                                                                  for(int x=0;x<8;x++)
                                                                  {
                                                                          if(x==j) continue;
                                                                          if(b[i][x]!='.' && b[i][x]!=ch) break;
                                                                          if(b[i][x]==ch)
                                                                          {
  //                                                                                        cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
    //                                                                      cout<<"changing value at "<<i<<","<<x<<endl;
//                                                                        b[i][x]='~';
                                                                          }
                                                                  if(check) break;
                                                                  for(int x=0;x<8;x++)
                                                                  {
                                                                          if(x==i)continue;
                                                                          if(b[x][j]!='.' && b[i][x]!=ch) break;
                                                                          if(b[x][j]==ch)
                                                                          {
//                                                                                          cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
  //                                                                        cout<<"changing value at "<<x<<","<<j<<endl;
//                                                                        b[x][j]='~';
                                                                          }
                                                                  if(check) break;
                                                                  }
                                    if(b[i][j]==b1)
                                    {
                                                                  for(int x=1;x<8&&(i-x)!=-1&&(j-x)!=-1;x++)
                                                                  {
  //                                                                cout<<endl<<"bishop found at "<<i<<","<<j<<" "<<b[i-x][j-x]<<endl<<endl;
                                                                          if(b[i-x][j-x]!='.' && b[i-x][j-x]!=ch) break;
                                                                          if(b[i-x][j-x]==ch)
                                                                          {
      //                                                                                    cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
//                                                                          if(x==j) continue;
        //                                                                  cout<<"changing value at "<<i-x<<","<<j-x<<endl;
//                                                                        b[i-x][j-x]='~';
                                                                          }
                                                                  if(check) break;
                                                                  for(int x=1;x<8&&(i-x)!=-1&&(j+x)!=8;x++)
                                                                  {
    //                                                                      cout<<"2 analysing bishop at "<<i-x<<" "<<j-x<<endl;
                                                                          if(b[i-x][j+x]!='.' && b[i-x][j+x]!=ch) break;
                                                                          if(b[i-x][j+x]==ch)
                                                                          {
          //                                                                                cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
//                                                                          if(x==j) continue;
            //                                                              cout<<"changing value at "<<i-x<<","<<j+x<<endl;
//                                                                        b[i-x][j+x]='~';
                                                                          }
                                                                  if(check) break;
                                                                  for(int x=1;x<8&&(i+x)!=8&&(j-x)!=0;x++)
                                                                  {
      //                                                                    cout<<"3 analysing bishop at "<<i-x<<" "<<j-x<<endl;
                                                                          if(b[i+x][j-x]!='.' && b[i+x][j-x]!=ch) break;
                                                                          if(b[i+x][j-x]== ch)
                                                                          {
              //                                                                            cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
//                                                                          if(x==j) continue;
                //                                                          cout<<"changing value at "<<i+x<<","<<j-x<<endl;
//                                                                        b[i+x][j-x]='~';
                                                                          }
                                                                  for(int x=1;x<8&&(i+x)!=8&&(j+x)!=8;x++)
                                                                  {
        //                                                                  cout<<"4 analysing bishop at "<<i-x<<" "<<j-x<<endl;
                                                                          if(b[i+x][j+x]!='.' && b[i+x][j+x]!=ch) break;
                                                                          if(b[i+x][j+x]== ch)
                                                                          {
//                                                                                          cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
//                                                                          if(x==j) continue;
  //                                                                        cout<<"changing value at "<<i+x<<","<<j+x<<endl;
//                                                                        b[i+x][j+x]='~';
                                                                          }
                                                                  if(check) break;
                                                                  }
                                    if(b[i][j]==q)
                                    {
    //                                                              cout<<endl<<"queen found at (horizontal) "<<i<<","<<j<<endl<<endl;
                                                                  for(int x=0;x<8;x++)
                                                                  {
                                                                          if(b[i][x]!='.' && b[i][x]!=ch) break;
                                                                          if(b[i][x]==ch )
                                                                          {
      //                                                                                    cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
                                                                          if(x==j) continue;
        //                                                                  cout<<"changing value at "<<i<<","<<x<<endl;
//                                                                        b[i][x]='~';
                                                                          }
                                                                  if(check) break;
                                                                  for(int x=0;x<8;x++)
                                                                  {
                                                                          if(b[x][j]!='.' && b[x][j]!=ch) break;
                                                                          if(b[x][j]==ch )
                                                                          {
//                                                                                          cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
                                                                          if(x==i)continue;
  //                                                                        cout<<"changing value at "<<x<<","<<j<<endl;
//                                                                        b[x][j]='~';
                                                                          }
                                                                  if(check) break;
    //                                                              cout<<endl<<"queen found at (diagonal) "<<i<<","<<j<<endl<<endl;
                                                                  for(int x=1;x<8&&(i-x)!=-1&&(j-x)!=-1;x++)
                                                                  {
                                                                          if(b[i-x][j-x]!='.' && b[i-x][j-x]!=ch) break;
                                                                          if(b[i-x][j-x]==ch )
                                                                          {
      //                                                                                    cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
//                                                                          if(x==j) continue;
        //                                                                  cout<<"changing value at "<<i-x<<","<<j-x<<endl;
//                                                                        b[i-x][j-x]='~';
                                                                          }
                                                                  if(check) break;
                                                                  for(int x=1;x<8&&(i-x)!=-1&&(j+x)!=8;x++)
                                                                  {
                                                                          if(b[i-x][j+x]!='.' && b[i-x][j+x]!=ch) break;
                                                                          if(b[i-x][j+x]==ch )
                                                                          {
          //                                                                                cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
//                                                                          if(x==j) continue;
            //                                                              cout<<"changing value at "<<i-x<<","<<j+x<<endl;
//                                                                        b[i-x][j+x]='~';
                                                                          }
                                                                  if(check) break;
                                                                  for(int x=1;x<8&&(i+x)!=8&&(j-x)!=0;x++)
                                                                  {
                                                                          if(b[i+x][j-x]!='.' && b[i+x][j-x]!=ch) break;
                                                                          if(b[i+x][j-x]==ch )
                                                                          {
//                                                                                          cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
//                                                                          if(x==j) continue;
  //                                                                        cout<<"changing value at "<<i+x<<","<<j-x<<endl;
//                                                                        b[i+x][j-x]='~';
                                                                          }
                                                                  if(check) break;
                                                                  for(int x=1;x<8&&(i+x)!=8&&(j+x)!=8;x++)
                                                                  {
                                                                          if(b[i+x][j+x]!='.' && b[i+x][j+x]!=ch) break;
                                                                          if(b[i+x][j+x]==ch )
                                                                          {
    //                                                                                      cout<<"CONFLICT FOUND"<<endl;
                                                                                          check=true;
                                                                                          break;
                                                                                          }
//                                                                          if(x==j) continue;
      //                                                                    cout<<"changing value at "<<i+x<<","<<j+x<<endl;
//                                                                        b[i+x][j+x]='~';
                                                                          }
                                                                  if(check) break;
                                                                  }
                                    if(b[i][j]==k)
                                    {
        //                                                          cout<<endl<<"king found at "<<i<<","<<j<<endl<<endl;
                                                                  if((i-1)!=-1&&b[i-1][j]==ch )
                                                                  check=true;
                                                                  if((j-1)!=-1&&b[i][j-1]==ch )
                                                                  check=true;
                                                                  if((i+1)!=8&&b[i+1][j]==ch )
                                                                  check=true;
                                                                  if((j+1)!=8&&b[i][j+1]==ch )
                                                                  check=true;
                                                                  if((j+1)!=8&&(i+1)!=8&&b[i+1][j+1]==ch )
                                                                  check=true;
                                                                  if((j-1)!=-1&&(i+1)!=8&&b[i-1][j+1]==ch )
                                                                  check=true;
                                                                  if((j+1)!=8&&(i-1)!=-1&&b[i+1][j-1]==ch )
                                                                  check=true;
                                                                  if((j-1)!=-1&&(i-1)!=-1&&b[i-1][j-1]==ch )
                                                                  check=true;
                                                                  if(check) break;
                                                                  }
                                    if(b[i][j]==n)
                                    {
//                                                                  cout<<endl<<"knight found at "<<ch<<" "<<i<<","<<j<<endl<<endl;
  //                                                                cout<<"checking... "<<((j-2)!=-1&&(i-1)!=-1&&b[i-1][j-2]==ch)<<endl;
                                                                  if((j-2)!=-1 && (i-1)!=-1 && b[i-1][j-2]==ch)
                                                                  check=true;
                                                                  if((j-1)!=-1 && (i-2)!=-1 && b[i-2][j-1]==ch)
                                                                  check=true;
                                                                  if((j+1)!=8 && (i-2)!=-1 && b[i-2][j+1]==ch)
                                                                  check=true;
                                                                  if((j+2)!=-1 && (i-1)!=8 && b[i-1][j+2]==ch)
                                                                  check=true;
                                                                  if((j+2)!=-1 && (i+1)!=-1 && b[i+1][j+2]==ch)
                                                                  check=true;
                                                                  if((j+1)!=-1 && (i+2)!=-1 && b[i+2][j+1]==ch)
                                                                  check=true;
                                                                  if((j-1)!=-1 && (i+2)!=-1 && b[i+2][j-1]==ch)
                                                                  check=true;
                                                                  if((j-2)!=-1 && (i+1)!=-1 && b[i+1][j-2]==ch)
                                                                  check=true;
                                                                  if(check) break;
                                                                  }
                                    }
                    if(check) break;
     }
     if(check) return -1;
     return 0;
}
int main()
{
    char board[10][10];
    char blk[10][10],whi[10][10];
    int i,j,I,J;
    bool last=false;
    int no=0;
    do {
        last=false;
    for(i=0;i<8;i++)
    {
                    scanf("%s",&board[i]);
                    strcpy(blk[i],board[i]);
                    strcpy(whi[i],board[i]);
                    }
    for(i=0;i<8;i++)
    {
                    for(j=0;j<8;j++)
                    {
                                    if(board[i][j]!='.')
                                    {
                                                        last=true;
                                                        break;
                                                        }
                                    }
                    if(last) break;
                    }
    if(last)
    {
            cout<<"Game #"<<++no<<": ";
            int stat1=set(blk,'k');
            if(stat1==-1)
            cout<<"black king is in check.\n";
            
            int stat2=set(blk,'K');
            if(stat2==-1)
            cout<<"white king is in check.\n";

            if(stat1!=-1 && stat2!=-1)
            cout<<"no king is in check.\n";
            }
    } while(last);
return 0;
}
/* @END_OF_SOURCE_CODE */
/*   for(i=0;i<8;i++)
     {
                    for(j=0;j<8;j++)
                    {
                                    if(b[i][j]=='k'||b[i][j]=='K')
                                    {
                                                                  cout<<"KING AT "<<i<<","<<j<<endl<<endl;
                                                                  if((i-1)!=-1&&b[i-1][j]=='.')
                                                                  b[i-1][j]='`';
                                                                  if((j-1)!=-1&&b[i][j-1]=='.')
                                                                  b[i][j-1]='`';
                                                                  if((i+1)!=8&&b[i+1][j]=='.')
                                                                  b[i+1][j]='`';
                                                                  if((j+1)!=8&&b[i][j+1]=='.')
                                                                  b[i][j+1]='`';
                                                                  if((j+1)!=8&&(i+1)!=8&&b[i+1][j+1]=='.')
                                                                  b[i+1][j+1]='`';
                                                                  if((j-1)!=-1&&(i+1)!=8&&b[i-1][j+1]=='.')
                                                                  b[i-1][j+1]='`';
                                                                  if((j+1)!=8&&(i-1)!=-1&&b[i+1][j-1]=='.')
                                                                  b[i+1][j-1]='`';
                                                                  if((j-1)!=-1&&(i-1)!=-1&&b[i-1][j-1]=='.')
                                                                  b[i-1][j-1]='`';
                                                                  }
                                    }
                    }
*/
