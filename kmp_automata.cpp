
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

#define FOR(i,a,n) for(int i=int(a);i<int(n);i++)
#define REP(i,n) FOR(i,0,n)
#define FORE(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define ALL(c) c.begin(), c.end()
#define CLEAR(c,v) memset(c,v,sizeof(c))

typedef long long int lli;
typedef pair<int,int> ii;

const int N = 10010;
int A[N][26];

int main() {
    string p;
    cin >> p;

    REP(j,26) A[0][j] = 0;
    REP(i,p.size()){
        int k = A[i][p[i]-'a'];
        A[i][p[i]-'a'] = i+1;
        REP(j,26) A[i+1][j] = A[k][j];
    }

    string text;
    cin >> text;

    int state = 0;
    REP(i,text.size()){
        state = A[state][text[i]-'a'];
        cout << state << ' ';
    }
    cout << endl;
}
