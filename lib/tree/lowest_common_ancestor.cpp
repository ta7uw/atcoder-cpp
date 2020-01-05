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
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

/**
 * Library
 * --------------------------------------------------------
 */
class LowestCommonAncestor {
public:
    explicit LowestCommonAncestor(const Graph &graph) : graph(graph) {
        n = (int) graph.size();
        depth.resize(n, 0);
        log = 32 - __builtin_clz(n);
        table.resize(log, vector<int>(n, -1));
    }

    /**
     * Executes this Preprocessing method before `query(u, v)`.
     * @param root root vertex ( 0-indexed )
     */
    void build(int root) {
        dfs(root, -1, 0);
        for (int k = 0; k + 1 < log; k++) {
            for (int i = 0; i < n; i++) {
                if (table[k][i] == -1) {
                    table[k + 1][i] = -1;
                } else {
                    table[k + 1][i] = table[k][table[k][i]];
                }
            }
        }
    }

    /**
     * Gets vertex of lowest common ancestor between u and v.
     * @param u vertex( 0-indexed )
     * @param v vertex ( 0-indexed )
     * @return vertex of lowest common ancestor between u and v ( 0-indexed )
     */
    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int i = log - 1; i >= 0; i--) {
            if (((depth[v] - depth[u]) >> i) & 1) v = table[i][v];
        }
        if (u == v) return u;
        for (int i = log - 1; i >= 0; i--) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    int diff(int u, int v) {
        int lca = query(u, v);
        return depth[u] + depth[v] - 2 * depth[lca];
    }

private:
    void dfs(int u, int par, int d) {
        table[0][u] = par;
        depth[u] = d;
        for (int v : graph[u]) {
            if (v != par) dfs(v, u, d + 1);
        }
    }

    int n;
    int log;
    vector<int> depth;
    Graph graph;
    vector<vector<int>> table;
};
/**
 * --------------------------------------------------------
 */

/**
 * ABC014 D - 閉路
 * https://atcoder.jp/contests/abc014/tasks/abc014_4
 */
void Main() {
    int N;
    cin >> N;
    Graph graph(N);
    rep(i, N - 1) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    LowestCommonAncestor lowestCommonAncestor(graph);
    int Q;
    cin >> Q;
    lowestCommonAncestor.build(0);
    rep(q, Q) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ll distance = lowestCommonAncestor.diff(a, b);
        cout << distance + 1 << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
