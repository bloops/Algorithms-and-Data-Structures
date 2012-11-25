const int MOD = 1e9 + 7;
const int S = 110;

template <typename T>
class matrix {
    T A[S][S];
public:
    int n, m;
    matrix(int _n, int _m) : n(_n), m(_m) {
        memset(A,0,sizeof(A));
    }
    T* operator[](int i) { return A[i]; }
};

template <typename T> 
matrix<T> operator*(matrix<T>& A, matrix<T>& B){
    int n = A.n, m = B.m, k = A.m;
    matrix<T> ret(n,m); lli t;
    FOR(i,n) FOR(j,m) {
        t = 0;
        FOR(l,k) t += (lli)A[i][l] * B[l][j];
        ret[i][j] = t % MOD2;
    }
    return ret;
}

template <typename T> 
matrix<T> pow(matrix<T> A, int k, matrix<T>& id){
    if(k == 0) return id;
    matrix<T> ret = pow(A,k/2,id);
    ret = ret * ret;
    if(k % 2 == 1) ret = ret * A;
    return ret;
}

template <typename T> 
matrix<T> pow_slow(matrix<T> A, int k, matrix<T>& id){
    matrix<T> ret = id;
    FOR(i,k) ret = ret * A;
    return ret;
}

template <typename T> 
matrix<T> pow_iter(matrix<T> A, int k, matrix<T>& id){
    matrix<T> ret = id, p = id;
    FOR(i,31) {
        p = i == 0 ? A : p*p;
        if(k & (1<<i)) ret = ret * p;
    }
    return ret;
}
