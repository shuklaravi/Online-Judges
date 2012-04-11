#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cfloat>
#include <queue>

using namespace std;

class GameOfEight {
public:
    string b;
    map<string, int> memo;

    /*void dfs(string p) {
        int r = memo[p];
        int ind;
        for(int ind = 0; ind < 9; ind++) if(p[ind] == '.') break;
        int i = ind / 3;
        int j = ind % 3;
        if(i >= 1) {
            string t = p;
            int k = (i-1) * 3 + j;
            swap(t[ind],t[k]);
            if(!memo.count(t)) {
                memo[]
            }
        }
    }*/

    int fewestMoves( vector <string> board ) {
        b = board[0];
        b += board[1];
        b += board[2];
        memo["12345678."] = 0;
        queue<string> bfs;
        string st = "12345678.";
        bfs.push(st);
        while(!bfs.empty()) {
            string p = bfs.front();
            int num = memo[p];
            bfs.pop();



            int ind;
            for(ind = 0; ind < 9; ind++) if(p[ind] == '.') break;
            int i = ind / 3;
            int j = ind % 3;
            if(i >= 1) {
                string t = p;
                int k = (i-1) * 3 + j;
                swap(t[ind],t[k]);
                if(!memo.count(t)) {
                    memo[t] = num + 1;
                    bfs.push(t);
                }
            }
            if(i < 2) {
                string t = p;
                int k = (i+1) * 3 + j;
                swap(t[ind],t[k]);
                if(!memo.count(t)) {
                    memo[t] = num + 1;
                    bfs.push(t);
                }
            }
            if(j >= 1) {
                string t = p;
                int k = (i) * 3 + j-1;
                swap(t[ind],t[k]);
                if(!memo.count(t)) {
                    memo[t] = num + 1;
                    bfs.push(t);
                }
            }
            if(j < 2) {
                string t = p;
                int k = (i) * 3 + j+1;
                swap(t[ind],t[k]);
                if(!memo.count(t)) {
                    memo[t] = num + 1;
                    bfs.push(t);
                }
            }

        }
        if(memo.count(b)) return memo[b];
        return -1;
    }
};

// BEGIN CUT HERE
namespace moj_harness {
    int run_test_case(int);
    void run_test( int casenum = -1 ) {
        if ( casenum != -1 ) {
            if ( run_test_case( casenum ) == -1 )
                cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
            return;
        }

        int correct = 0, total = 0;
        for ( int i=0;; ++i ) {
            int x = run_test_case(i);
            if ( x == -1 ) {
                if ( i >= 100 ) break;
                continue;
            }
            correct += x;
            ++total;
        }

        if ( total == 0 ) {
            cerr << "No test cases run." << endl;
        } else if ( correct < total ) {
            cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
        } else {
            cerr << "All " << total << " tests passed!" << endl;
        }
    }

    int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) {
        cerr << "Example " << casenum << "... ";

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }

        if ( expected == received ) {
            verdict = "PASSED";
        } else {
            verdict = "FAILED";
        }

        cerr << verdict;
        if (!info.empty()) {
            cerr << " (";
            for (int i=0; i<(int)info.size(); ++i) {
                if (i > 0) cerr << ", ";
                cerr << info[i];
            }
            cerr << ")";
        }
        cerr << endl;

        if (verdict == "FAILED") {
            cerr << "    Expected: " << expected << endl;
            cerr << "    Received: " << received << endl;
        }

        return verdict == "PASSED";
    }

    int run_test_case( int casenum ) {
        switch( casenum ) {
        case 0: {
            string board[]            = {"123", "485", "76."};
            int expected              = 4;

            clock_t moj_start_time    = clock();
            int received              = GameOfEight().fewestMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }
        case 1: {
            string board[]            = {"123", "456", "78."};
            int expected              = 0;

            clock_t moj_start_time    = clock();
            int received              = GameOfEight().fewestMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }
        case 2: {
            string board[]            = {".23", "456", "781"};
            int expected              = -1;

            clock_t moj_start_time    = clock();
            int received              = GameOfEight().fewestMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }

        // custom cases

/*      case 3: {
            string board[]            = ;
            int expected              = ;

            clock_t moj_start_time    = clock();
            int received              = GameOfEight().fewestMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }*/
/*      case 4: {
            string board[]            = ;
            int expected              = ;

            clock_t moj_start_time    = clock();
            int received              = GameOfEight().fewestMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }*/
/*      case 5: {
            string board[]            = ;
            int expected              = ;

            clock_t moj_start_time    = clock();
            int received              = GameOfEight().fewestMoves( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }*/
        default:
            return -1;
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
}
