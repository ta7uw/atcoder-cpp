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
struct edge {
    int from, to;
    ll cost;
};

class BellmanFord {
    int V;
    int E;
    vector<edge> edges;
    vector<ll> dist;
    vector<bool> negative;

public:
    BellmanFord(int v, int e) : V(v), E(e), negative(v) {
        dist.resize(V, INF);
    }

    void add_edge(int from, int to, ll cost) {
        edges.push_back({from, to, cost});
    }

    ll get_total_cost(int v) {
        return dist[v];
    }

    // v に到達するまでに負ループがあるかを検出する
    bool is_negative(int v) {
        return negative[v];
    }

    // ベルマンフォード法の実行・全辺の負閉路を検出 trueを返す時に負閉路を含む
    bool exec() {
        bool updated = false;
        dist[0] = 0;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < E; ++j) {
                edge edge = edges[j];
                if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.cost) {
                    dist[edge.to] = dist[edge.from] + edge.cost;
                    if (i == V - 1) updated = true;
                }
            }
        }

        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < E; ++j) {
                edge edge = edges[j];
                if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.cost) {
                    negative[edge.to] = true;
                }
                if (negative[edge.from]) {
                    negative[edge.to] = true;
                }
            }
        }
        return updated;
    }
};
/**
 * --------------------------------------------------------
 */

/**
 *  ABC061 D - Score Attack
 *  https://atcoder.jp/contests/abc061/submissions/7662112
 */
void Main() {
    int N, M;
    cin >> N >> M;
    BellmanFord bellmanFord(N, M);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        bellmanFord.add_edge(a, b, -c);
    }
    bellmanFord.exec();

    if (bellmanFord.is_negative(N - 1)) {
        cout << "inf" << '\n';
    } else {
        cout << -bellmanFord.get_total_cost(N - 1) << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
