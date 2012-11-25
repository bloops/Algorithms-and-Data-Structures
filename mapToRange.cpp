#include <iostream>
#include <sstream>
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

#define FOR(i, n) for(int i=0;i<int(n);i++)
#define FOR1(i, n) for(int i=1;i<=int(n);i++)
#define FORA(i, a, n) for(int i=a;i<int(n);i++)
#define FORR(i, n) for(int i=n-1;i>=0;i--)
#define FORE(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define ALL(c) c.begin(), c.end()
#define CLR(c,v) memset(c,v,sizeof(c))

typedef long long int lli;
typedef pair<int,int> ii;

int main()
{
    ios::sync_with_stdio(false);
    int n = 10;
    int A[] = {4,1,2,2,4,5,6,0,9,9};
    map<int,int> M;
    FOR(i,n) M[A[i]] = 0;

    int cur = 0;
    FORE(it,M) {
        it->second = ++cur;
    }

    FOR(i,n) cout << M[A[i]] << ' '; cout << endl;
    return 0;
}

