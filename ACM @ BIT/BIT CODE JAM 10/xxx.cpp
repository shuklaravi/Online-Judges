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

using namespace std;

class MiniPaint {
public:
    int best[60][3001];
    int bs[60][60];
    int b[60][60];

    int leastBad( vector <string> picture, int maxStrokes ) {
        int m = picture.size();
        int n = picture[0].size();
        if(maxStrokes >= m * n) return 0;
        for(int i = 0; i < m; i++) {
            string p = picture[i];
            memset(b,-1,sizeof(b));
            for(int j = 0; j < n; j++) {
                for(int s = 0; s <= n; s++) {
                    if(s == 0) b[j][s] = j + 1;
                    else if(s >= j+1) b[j][s] = 0;
                    else {
                        int t = 0;
                        for(int k = j; k >= 0; k--) {
                            t += p[k] == 'B';
                            int score = min(t,j-k+1-t);
                            if(k > 0) score += b[k-1][s-1];
                            if(b[j][s] == -1 || b[j][s] > score) b[j][s] = score;
                        }
                    }
                }
            }
            for(int s = 0; s <= n; s++) {
                bs[i][s] = b[n-1][s];
            }
        }
        memset(best,-1,sizeof(best));
        for(int r = 0; r < m; r++) {
            for(int s = 0; s <= maxStrokes; s++) {
                if(r == 0) best[r][s] = bs[r][s];
                else for(int c = 0; c <= min(n,s); c++) {
                    int score = best[r-1][s-c] + bs[r][c];
                    if(best[r][s] == -1 || best[r][s] > score) best[r][s] = score;
                }
            }
        }
        return best[m-1][maxStrokes];
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
            string picture[]          = { "BBBBBBBBBBBBBBB", "WWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWW", "WWWWWBBBBBWWWWW"};
            int maxStrokes            = 6;
            int expected              = 0;

            clock_t moj_start_time    = clock();
            int received              = MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }
        case 1: {
            string picture[]          = { "BBBBBBBBBBBBBBB", "WWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWW", "WWWWWBBBBBWWWWW"};
            int maxStrokes            = 4;
            int expected              = 5;

            clock_t moj_start_time    = clock();
            int received              = MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }
        case 2: {
            string picture[]          = { "BBBBBBBBBBBBBBB", "WWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWW", "WWWWWBBBBBWWWWW"};
            int maxStrokes            = 0;
            int expected              = 60;

            clock_t moj_start_time    = clock();
            int received              = MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }
        case 3: {
            string picture[]          = { "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW"};
            int maxStrokes            = 100;
            int expected              = 40;

            clock_t moj_start_time    = clock();
            int received              = MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }
        case 4: {
            string picture[]          = {"B"};
            int maxStrokes            = 1;
            int expected              = 0;

            clock_t moj_start_time    = clock();
            int received              = MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }

        // custom cases

/*      case 5: {
            string picture[]          = ;
            int maxStrokes            = ;
            int expected              = ;

            clock_t moj_start_time    = clock();
            int received              = MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }*/
/*      case 6: {
            string picture[]          = ;
            int maxStrokes            = ;
            int expected              = ;

            clock_t moj_start_time    = clock();
            int received              = MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes );
            return verify_case( casenum, expected, received, clock()-moj_start_time );
        }*/
/*      case 7: {
            string picture[]          = ;
            int maxStrokes            = ;
            int expected              = ;

            clock_t moj_start_time    = clock();
            int received              = MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes );
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
