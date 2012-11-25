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

const int N = 55;
int DP[N][N]; // n,x = # of partitions of n ending with x

int main()
{
    ios::sync_with_stdio(false);
    int n = 50;

    DP[0][0] = 1;
    FOR1(i,n) FOR1(j,i) DP[i][j] = DP[i][j-1] + DP[i-j][min(i-j,j)];

    cout << DP[n][n] << endl;

    return 0;
}

