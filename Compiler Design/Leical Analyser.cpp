#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
int var(string str)
{
     int i;
     if(!(str[0]=='_' || isalpha(str[0])))
            {
                         return -1;
                           }
            for(i=1;i<str.length();i++)
            {
                                       if(!(str[i]=='_' || isalpha(str[i]) || isdigit(str[i]) || str[i]=='=' ))
                                       {
                                                        return -1;
                                                      break;
                                                      }
                                       if(str[i]=='=')
                                       {
                                                      return 1;
                                                      }
                                       }
            if(i==str.length() && i>1)
            {
                               return 0;
                               }
                               return 0;
 }
 bool keyword(char *pch)
 {
     ifstream fp("Key.txt");
     char temp[100];
     while(fp>>temp)
     {
                    if(strcmp(temp,pch)==0)
                    {
                                           return 1;
                                           }
                    }

      return 0;
  }
  bool number(char * pch)
  {
       int i,len=strlen(pch);
       for (i=0;i<len;i++)
       {
           if(!isdigit(pch[i]))
           {
                               return 0;
                               }
       }
       return 1;
   }
int main()
{
    int i,j,k,p,q;
    string s;
    while(1)
    {
            char str[10000];
            cin.getline(str,10000,'\n');
            fflush(stdin);
            char *pch;
            pch = strtok (str," ,.");
            while (pch != NULL)
            {
//               printf ("%s\n",pch);

               char temp[100];
               bool ident_oper=false;
               cout<<"CHECKING FOR KEYWORD \n";
               if(keyword(pch))
               {
                               cout<<"\t"<<pch<<" IS A KEYWORD\n";
                              }
               else
               {
                   cout<<"\t"<<pch<<" IS NOT A KEYWORD\n";
                   cout<<"\t\tCHECKING FOR IDENTIFIER\n";
                   if(var(pch)==0)
                   {
                               cout<<"\t\t\t"<<pch<<" IS A VALID IDENTIFIER\n";
                               }
                   else if(var(pch)==-1)
                   {
                       cout<<"\t\t\t"<<pch<<" IS AN INVALID IDENTIFIER\n";
                       }
                   else if(var(pch)==1)
                   {
                        ident_oper=true;
                        cout<<"\t\t\t\tCHECKING FOR OPERATORS\n";
                        char *pch1;
                        pch1 = strtok (pch,"=");
                        while (pch1 != NULL)
                        {
                              if(ident_oper==false)
                              {
                                                   if(number(pch1))
                                                   {
                                                                   cout<<"\t\t\t\t\t"<<pch1<<" IS A VALID ASSIGNMENT\t";
                                                                 }
                                                   else
                                                   {
                                                       cout<<"\t\t\t\t\t"<<pch1<<" IS NOT AN ASSIGNMENT\t";
                                                   }
                                                   }
                              else if(var(pch1)==0 && ident_oper==true)
                              {
                                                                  cout<<"\t\t\t\t\t"<<pch1<<" IS A VALID IDENTIFIER\n";
                                                                  ident_oper=false;
                              }
                              else
                              {
                                  cout<<"ERROR";
                              }
                              pch1 = strtok (NULL, "=");
                              }
                    }
               }

               pch = strtok (NULL, " ,.");
            }


    }
    return 0;
}

