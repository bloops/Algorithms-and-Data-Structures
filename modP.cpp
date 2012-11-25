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
#define foreach(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define all(c) c.begin(), c.end()

typedef long long int lli;
typedef pair<int,int> ii;
typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;

int powMod(int a, int k, int mod){
    if(k == 0) return 1;
    lli ret = powMod(a,k/2,mod);
    ret *= ret, ret %= mod;
    return (ret * (k % 2 ? a : 1)) % mod;
}

int inverseModP(int a, int p){
    return powMod(a,p-2,p);
}

// a, b (a < b)

// a,r, b = aq + r
//     a(x-qy)+by = 1

pair<ii,int> extended_gcd(int a, int b){
    if(a > b) { 
        pair<ii,int> p = extended_gcd(b,a);
        swap(p.first.first,p.first.second);
        return p;
    }
    if(a == 0) return make_pair(ii(0,1),b);
    pair<ii,int> p = extended_gcd(a, b % a);
    p.first.first -= (b/a) * p.first.second;
    return p;
}

int inverseMod(int a, int m){
    pair<ii,int> p = extended_gcd(a,m);
    if(p.second != 1) return -1;
    return ((p.first.first % m) + m) % m;
}

int main()
{
    ios::sync_with_stdio(false);
    int big = 1<<28;
    srand(time(NULL));

    int M = 1000000007;
    int x = 30;
    cout << inverseModP(x,M) << endl;
    return 0;

    int T = 1e7, t = 0;
    while(t < T){
        int a = (rand() % big) + 1, m = (rand() % big) + 1;
        if(a > m) swap(a,m);
        if(__gcd(a,m) != 1) continue;
        int inv = inverseMod(a,m);
        if(!(inv > 0 and ((lli)inv * a) % m == 1)){
            cout << inv << ' ' << ' ' << a << ' ' << m << endl;
        }
        t++;
        if(t % (int)1e6 == 0) cout << t << endl;
    }
    return 0;
}

