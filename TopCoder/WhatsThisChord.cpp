// BEGIN CUT HERE

// END CUT HERE
#line 5 "WhatsThisChord.cpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;

class WhatsThisChord {
	public:
	string classify(vector <int> chord) {
		map<char, int> m;
		m['C']=0; m['c']=1; m['D']=2; m['d']=3; m['E']=4; m['F']=5; m['f']=6; m['G']=7; m['g']=8; m['A']=9; m['a']=10; m['B']=11;
//		C, C#, D, D#, E, F, F#, G, G#, A, A#, B.
		string val="CcDdEFfGgAaB";
		string indx="EADGBE";
		bool v[12]={false};
		string avail="";
		for(int i=0;i<chord.size();i++)
		{
			if(chord[i]==-1) continue;
			if(chord[i]==0 && !v[m[indx[i]]])
			{
				v[m[indx[i]]]=true;
				avail+=indx[i];
			}
			else if(!v[(m[indx[i]]+chord[i])%12])
			{
				v[(m[indx[i]]+chord[i])%12]=true;
				avail+=val[(m[indx[i]]+chord[i])%12];
			}
			if(avail.length()==3) break;
		}
		if(avail.length()!=3) return "";
		cout<<" AVAILABLE "<<avail<<endl;
		string major="CEG";
		string maj[12];
//		memset(maj,"",sizeof(maj));
		for(int i=0;i<12;i++)
		{
			for(int j=0;j<3;j++)
			maj[i]+=val[(m[major[j]]+i)%12];
			sort(maj[i].begin(),maj[i].end());
			cout<<i<<" MAJOR "<<maj[i]<<endl;
		}
        string minor="CdG";
		string min[12];
//		memset(min,"",sizeof(min));
		for(int i=0;i<12;i++)
		{
			for(int j=0;j<3;j++)
			min[i]+=val[(m[minor[j]]+i)%12];
			sort(min[i].begin(),min[i].end());
			cout<<i<<" MINOR "<<min[i]<<endl;
		}
		string res="";
		string cmp="";
		sort(avail.begin(), avail.end());
		for(int i=0;i<12;i++)
		{
			cout<<"................"<<avail<<" "<<maj[i]<<endl;
			if(avail==maj[i])
			{
				if(islower(maj[i][0]))
				{
//					string ch(avail[0]-'a'+'A');
					char chr=(char)(avail[0]-'a'+'A');
					string ch (&chr, 1);
					ch+="#";
					cout<<ch<<endl;
					res+=ch;
				}
				else
				{
					cout<<maj[i][0];
					res+=maj[i][0];
				}
				res+=" Major";
				cout<<" Major\n";
				return res;
			}
		}
		for(int i=0;i<12;i++)
		{
			if(avail==min[i])
			{
				if(islower(min[i][0]))
				{
					cout<<toupper(min[i][0])<<"#";
					res+=toupper(min[i][0])+"#";
				}
				else
				{
					cout<<min[i][0];
					res+=min[i][0];
				}
				res+=" Minor";
				cout<<" Minor\n";
				return res;
			}
		}
		return "";
	}
};
