const int N = 1 << 16;
ii A[N], B[N];

class CollectingPostmarks {
public:
    int amountOfMoney(vector <int> prices, vector <int> have, vector <int> values, int K) {
        int initial = 0;
        FOR(i,have.size()) initial += prices[have[i]];
        
        int n = prices.size();
        if(n % 2) prices.push_back(0), values.push_back(0), n++;
        int m = 1 << n/2;

        FOR(bitmask, m){
            int p = 0, v = 0;
            FOR(i,n/2) if(bitmask & (1<<i)) p += prices[i], v += values[i];
            A[bitmask] = ii(v,p);

            p = 0, v = 0;
            FOR(i,n/2) if(bitmask & (1<<i)) p += prices[n/2 + i], v += values[n/2 + i];
            B[bitmask] = ii(v,p);
        }

        sort(A,A+m), sort(B,B+m);

        int best = 1<<30;
        int j = m-1;
        FOR(i,m){
            while(j >= 0 and A[i].first + B[j].first >= K)
                best = min(best, A[i].second + B[j].second), j--;
        }
        if(best == 1<<30) return -1;
        return max(0, best - initial);
    }
};
