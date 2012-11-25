
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
    int n;
    cin >> n;
    vector<int> V(n);
    REP(i,n) cin >> V[i];
    sort(V.begin(), V.end());
    int x;
    cin >> x;

    int lo = 0, hi = n;
    while(hi - lo > 1){
        int mi = (lo + hi) / 2;
        if(V[mi] > x) hi = mi;
        else lo = mi;
    }
    if(V[lo] == x) cout << "At " << lo << endl;
    else cout << "Nope." << endl;
}
