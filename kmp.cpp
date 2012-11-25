
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

int main() {
    string p;
    cin >> p;

    int n = p.length(); 
    vector<int> F(n);

    F[0] = -1;
    for(int i = 1; i < n; i++){
        int j = F[i-1];
        while(p[j+1] != p[i] and j != -1)
            j = F[j];
        F[i] = p[j+1] == p[i] ? j+1 : -1;
    }

    REP(i,n) cout << F[i] << ' ';
    cout << endl;

    string s;
    cin >> s;
    int state = -1;
    REP(i,s.length()){
        while(p[state + 1] != s[i] and state != -1)
            state = F[state];
        if(p[state + 1] == s[i])
            state++;
        else state = -1;
        cout << state << ' ';
        if(state == n-1){
            // cout << "Match: " << i << endl;
            state = F[state];
        }
    }

}
