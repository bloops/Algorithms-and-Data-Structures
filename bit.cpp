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




const int BN = 256;
struct BIT {
    int size;
    int bit[BN];
    BIT() { memset(bit,0,sizeof(bit)); }
    int read(int i){
        int sum = 0;
        while(i > 1) sum += bit[i], i -= i&-i;
        return sum;
    }
    void increment(int i, int x){
        while(i < BN) bit[i] += x, i += i&-i;
    }
};
  


int main()
{
    ios::sync_with_stdio(false);
    int n = 10;
    int i, x;
    BIT T;
    while(cin >> i >> x){
        T.increment(i,x);
        FOR1(j,n) cout << T.read(j) << ' '; cout << endl;
    }
    
    return 0;
}

