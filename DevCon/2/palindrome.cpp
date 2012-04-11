/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
long long invert(long long n){
    long long  k=0;
    while(n>0){
        k = k*10 + n%10 ;
        n /= 10;
    }
    return k;
}
int main(){
    int n,c;
    long long x,y;
    cin >> n;
    while(n--){
        c = 0;
        cin >> x;
        y = invert(x);
        while(x != y){
            x += y;
            y = invert(x);
            c++;
        }
        cout << c << " " << x << endl;
    }
    return 0;
}

/* @END_OF_SOURCE_CODE */
