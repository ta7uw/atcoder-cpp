#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Graph = vector<vector<ll>>;

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
            for (int tar : graph[v]) {
                dfs(v);
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
};

int longest_path(const Graph &graph) {
    int N = graph.size();

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

vector<int> topological_sort(const Graph &graph) {
    int N = graph.size();
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
        res.emplace_back(u+1);
        for (int v : graph[u]) {
            in_cnt[v]--;
            if (in_cnt[v] == 0) {
                S.push(v);
            }
        }
    }
    return res;
}
