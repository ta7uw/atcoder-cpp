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

/**
 * ワーシャルフロイド法
 * 隣接行列で受け取り、全頂点間最短経路を算出
 */
void warshall_floyd(Graph &graph) {
    int V = graph.size();
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
/**
 * --------------------------------------------------------
 */

/**
 * https://atcoder.jp/contests/abc073/submissions/7665203
 * ABC 073 D - joisino's travel
 */
void Main() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r_list(R);
    rep(i, R) cin >> r_list[i];

    Graph graph(N, vector<ll>(N, INF));
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    warshall_floyd(graph);

    sort(r_list.begin(), r_list.end());

    ll ans = INF;
    do {
        int start = r_list[0] - 1;
        ll tmp = 0;
        rep2(i, 1, R) {
            tmp += graph[start][r_list[i] - 1];
            start = r_list[i] - 1;
        }
        ans = min(ans, tmp);
    } while ((next_permutation(r_list.begin(), r_list.end())));
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
