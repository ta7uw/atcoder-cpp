#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;


/**
 * Library
 * --------------------------------------------------------
 */
template<class T, class L>
class LazySegmentTree {
    int n;
    vector<T> data;
    vector<T> lazy;
    T def;
    T def_lazy;
    function<T(T, T)> operation;
    function<T(T, T)> lazy_operation;
    function<T(T, T)> lazy_updater;
    function<T(T, T)> lazy_calc;

    void eval(int l, int r, int k) {

        if (lazy[k] == def_lazy) return;
        data[k] = lazy_operation(data[k], lazy[k]);

        if (r - l > 1) {
            lazy[2 * k + 1] = lazy_updater(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = lazy_updater(lazy[2 * k + 2], lazy[k]);
        }
        data[k] = lazy_operation(data[k], lazy_calc(lazy[k], r - l));
        lazy[k] = def_lazy;
    }

    void update(int a, int b, T x, int k, int l, int r) {

        eval(l, r, k);

        if (b <= l || r <= a) return;

        if (a <= l || r <= b) {
            lazy[k] = lazy_updater(lazy[k], x);
            lazy_operation(data[k], lazy_calc(r - l));
            return;
        }

        query(a, b, x, 2 * k + 1, l, (l + r) / 2);
        query(a, b, x, 2 * k + 2, (l + r) / 2, r);
        data[k] = operation(data[2 * k + 1], data[2 * k + 2]);
    }

    T query(int a, int b, int k, int l, int r) {
        // 交差しない
        if (b <= l || r <= a) {
            return def;
        }

        eval(l, r, k);
        // 区間 [a, b) に l, r が含まれる
        if (a <= l && r <= b) {
            return data[k];
        }
        // 左の子
        T v1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
        // 右の子
        T v2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return operation(v1, v2);
    }

public:

    /**
     * @param _n _n size
     * @param _def  initial value
     * @param _def_lazy initial value for lazy evaluation
     * @param _operation operation for query
     * @param _updater operation for update
     * @param _lazy_operation operation for lazy evaluation
     * @param _lazy_updater operation for update of lazy evaluation
     */
    LazySegmentTree(size_t _n, T _def, T _def_lazy, function<T(T, T)> _operation, function<T(T, T)> _updater,
                    function<T(T, T)> _lazy_operation, function<T(T, T)> _lazy_updater)
            : def(_def), def_lazy(_def_lazy), operation(_operation), updater(_updater),
              lazy_operation(_lazy_operation), lazy_updater(_lazy_updater) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
        lazy = vector<T>(2 * n - 1, 0);
    }

    void update(int a, int b, T x) {
        update(a, b, x, 0, 0, n);
    }

    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    /**
     * 添字でアクセス
     * @param i index ( 0-indexed )
     */
    T operator[](int i) {
        return data[i + n - 1];
    }

};

/**
 * --------------------------------------------------------
 */

void Main() {


}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
