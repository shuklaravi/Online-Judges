using namespace std;
# include<iostream>
# include<cstdio>
# include<cstring>
# include<stack>
int main()
{
    int i,cases;
    char str[200];
    stack<char> brace;
    stack<char> sq;
    scanf("%d",&cases);
    cin.getline(str,200);
    while(cases-->0)
    {
         cin.getline(str,200);
         for(i=0;str[i]!='\0';i++)
         {
              if(str[i]=='(')
                   brace.push('(');
              else if(str[i]==')')
              {
                   if(brace.empty())
                   {
                      brace.push('(');
                      break;
                   }  
                   brace.pop();     
              }
              
              else if(str[i]=='[')
                   sq.push('[');
              else if(str[i]==']')
              {
                   if(sq.empty())
                   {
                      sq.push('[');
                      break;
                   }  
                   sq.pop();
              }
         }
         if(sq.empty() && brace.empty())
              printf("Yes\n");
         else
              printf("No\n");
              
         while(!brace.empty())
              brace.pop();
              
         while(!sq.empty())
              sq.pop();            
    }
    return 0;
}
