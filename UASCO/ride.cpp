/*
ID: vermapr1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
// _____ FOR UASCO _____

int main() {
    ofstream out ("ride.out");
    ifstream in ("ride.in");
    char a[100], b[100];
    in >> a >> b;
    int al=strlen(a),ll=1;
    for(int i=0;i<al;i++)
    {
	 		ll*=(a[i]-'A'+1);
			}
	ll%=47;
	int bl=strlen(b),lll=1;
    for(int i=0;i<bl;i++)
	{
            lll*=(b[i]-'A'+1);
			}
	lll%=47;
	if(lll==ll)
    out << "GO" << endl;
    else
    out << "STAY" << endl;
    return 0;
}
