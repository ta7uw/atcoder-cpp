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
