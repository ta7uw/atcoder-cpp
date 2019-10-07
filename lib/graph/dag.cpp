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
class DAG {
    int N;
    Graph graph;
    vector<int> visited;

    void dfs(int v) {
        if (visited[v] == 2) {
            is_acyclic = false;
            return;
        }
        if (!visited[v]) {
            visited[v] = 2;
            for (int u : graph[v]) {
                dfs(u);
            }
            visited[v] = 1;
            sorted.push_back(v);
        }
    }

public:
    vector<int> sorted;

    DAG(int N) : N(N), graph(N), visited(N) {}

    DAG(Graph &graph) : N(graph.size()), graph(graph), visited(graph.size()) {}

    bool is_acyclic = true;

    void add_edge(int a, int b) {
        graph[a].push_back(b);
    }

    void topological_sort() {
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        reverse(sorted.begin(), sorted.end());
    }

    /**
     * 最長経路
     */
    int longest_path() {
        Graph inv(N);
        for (int i = 0; i < N; ++i) {
            for (int v: graph[i]) {
                inv[v].push_back(i);
            }
        }
        vector<int> path_len(N, -1);
        function<void(int)> set_len = [&](int v) {
            if (path_len[v] != -1) {
                return;
            }
            if (inv[v].empty()) {
                path_len[v] = 0;
                return;
            }
            int max_num = 0;
            for (int tar : inv[v]) {
                set_len(tar);
                max_num = max(max_num, path_len[tar]);
            }
            path_len[v] = max_num + 1;

        };
        for (int i = 0; i < N; ++i) {
            set_len(i);
        }
        return *max_element(path_len.begin(), path_len.end());
    }

    /**
     *  queueを使うトポロジカルソート
     */
    vector<int> topological_sort_2() {
        vector<int> in_cnt(N, 0);
        for (int i = 0; i < N; ++i) {
            for (int v : graph[i]) {
                in_cnt[v]++;
            }
        }
        queue<int> S;
        for (int i = 0; i < N; ++i) {
            if (in_cnt[i] == 0) S.push(i);
        }
        vector<int> res;
        while (!S.empty()) {
            int u = S.front(); S.pop();
            res.emplace_back(u);
            for (int v : graph[u]) {
                in_cnt[v]--;
                if (in_cnt[v] == 0) {
                    S.push(v);
                }
            }
        }
        return res;
    }
};
/**
 * --------------------------------------------------------
 */


/**
 * Educational DP Contest / DP まとめコンテスト G - Longest Path
 * https://atcoder.jp/contests/dp/submissions/7662174
 */
void Main() {
    int N, M;
    cin >> N >> M;
    DAG dag(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        dag.add_edge(a, b);
    }
    cout << dag.longest_path() << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
