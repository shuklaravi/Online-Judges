#include <iostream>
using namespace std;

void printAllPalindromes(char*);

char* subSequence(char*,int,int);
int res;
int main() {
 char *s = "aaaannnn";
 res=1;
 printAllPalindromes(s);
 cout<<res<<endl;
 getchar();
 return 0;
}

char* subSequence(char* mainSequence, int from, int to){
 char * tgt = new char[to-from+1];
 for(int i=0;i<(to-from);i++){
  tgt[i] = mainSequence[i+from];
 }
 tgt[to-from] = '\0';
 return tgt;
}

void printAllPalindromes(char* inputText) {
 //ODD Occuring Palindromes
 int len = strlen(inputText);
 for(int i=1;i<len-1;i++) {
  for(int j=i-1,k=i+1;j>=0&&k<len;j--,k++) {
   if(inputText[j] == inputText[k]) {
    char* subSeq = subSequence(inputText,j,k+1);
    cout<<"found "<<subSeq<<endl;
    res*=(strlen(subSeq)/2+1);//  cout<<subSeq<<endl;
    cout<<res<<endl;
    delete subSeq;
   } else {
    break;
   }
  }
 }
 //EVEN Occuring Palindromes
 for(int i=1;i<len-1;i++) {
  for(int j=i,k=i+1;j>=0&&k<len;j--,k++) {
   if(inputText[j] == inputText[k]) {
    char* subSeq = subSequence(inputText,j,k+1);
    cout<<"found "<<subSeq<<endl;
    res*=(strlen(subSeq)/2); //cout<<subSeq<<endl;
    cout<<res<<endl;
    delete subSeq;
   } else {
    break;
   }
  }
 }

}
