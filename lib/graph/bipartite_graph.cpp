#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))


/**
 * Library
 * --------------------------------------------------------
 */
int colors[100005];
bool is_bipartite_graph(const Graph &graph, int v, int c) {
    colors[v] = c;
    for (int u: graph[v]) {
        if (colors[u] == c) {
            return false;
        }
        if (colors[u] == 0 && !is_bipartite_graph(graph, u, -c)) {
            return false;
        }
    }
    return true;
}
/**
 * --------------------------------------------------------
 */


/**
 * C - 3 Steps
 * https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_c
 */
void Main() {
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (is_bipartite_graph(graph, 0, 1)) {
        int b = 0;
        rep(i, ARRAY_SIZE(colors)) {
            if (colors[i] == 1)b += colors[i];
        }
        int w = N - b;
        cout << (ll) b * w - M << '\n';
    } else {
        cout << (ll) N * (N - 1) / 2 - M << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
