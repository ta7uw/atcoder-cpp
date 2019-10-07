#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)

/**
 * Library
 * --------------------------------------------------------
 */
template<typename T>
class WeightedUnionFind {
    int N;
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    vector<T> weight;

public:
    explicit WeightedUnionFind(int n) : N(n + 1) {
        par.resize(n + 1);
        rank.resize(n + 1, 0);
        weight.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (par[x] == x) return x;
        int y = find(par[x]);
        weight[x] += weight[par[x]];
        par[x] = y;
        return y;
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    T get_weight(int x) {
        find(x);
        return weight[x];
    }

    /**
     * x -> y の重みの差分
     */
    T diff(int x, int y) {
        return get_weight(y) - get_weight(x);
    }

    /**
     * get_weight(y) - get_weight(x) = w となるように結合
     * @return true:　結合成功, false: すでに結合済み
     */
    bool unit(int x, int y, T w) {
        w += get_weight(x);
        w -= get_weight(y);
        x = find(x);
        y = find(y);
        if (x == y) return false;
        // 木の高さの低い方から高い方へ繋げる
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        weight[y] = w;
        size[x] += size[y];
        return true;
    }
};
/**
 * --------------------------------------------------------
 */

/**
 * D - People on a Line
 * https://atcoder.jp/contests/abc087/tasks/arc090_b
 */
void Main() {
    int N, M;
    cin >> N >> M;
    WeightedUnionFind<ll> weightedUnionFind(N);
    rep(i, M) {
        int l, r;
        ll d;
        cin >> l >> r >> d;
        if (weightedUnionFind.is_same(l, r)) {
            if (weightedUnionFind.diff(l, r) != d) {
                cout << "No" << '\n';
                return;
            }
        }else{
            weightedUnionFind.unit(l, r, d);
        }
    }
    cout << "Yes" << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
