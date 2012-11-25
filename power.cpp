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
#define foreach(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef long long int lli;
typedef pair<int,int> ii;
typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;

const int MOD = 1000000007;
const int N = 1010;
int C[N][N];

int power(int a, int k){
    if(k == 0) return 1;
    lli ret = power(a,k/2);
    ret *= ret, ret %= MOD;
    return (ret * (k % 2 ? a : 1)) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    
    C[0][0] = 1;
    FOR1(i,1000) {
        C[i][0] = 1;
        FOR1(j,i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }

    FOR(n,1000){
        int sum = 0;
        FOR(k,n+1) sum += C[n][k], sum %= MOD;
        assert(sum == power(2,n));
    }
    return 0;
}


