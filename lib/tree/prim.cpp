#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    vector<vector<int>> group;

    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        group.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
            group[i].push_back(i);
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = find(par[x]);
            return par[x] = r;
        }
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    bool unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        } else {
            if (rank[x] < rank[y]) {
                swap(x, y);
            }
            if (rank[x] == rank[y]) {
                ++rank[x];
            }
            par[y] = x;
            size[x] += size[y];
            return true;
        }
    }

    int get_size(int x) {
        return size[find(x)];
    }

    void merge_tech(int x, int y) {
        x = find(x);
        y = find(y);
        if (group[x].size() > group[y].size()) {
            swap(x, y);
        }
        copy(group[y].begin(), group[y].end(), back_inserter(group[x]));
        group[y].clear();
        par[y] = x;
    }
};

template<typename T>
struct edge {
    int from, to;
    T cost;
};

template<typename T>
T prim(vector<vector<edge<T>>> &edges, int V) {
    using Pi = pair<T, int>;

    T res = 0;
    vector<bool> used(V, false);
    priority_queue<Pi, vector<Pi>, greater<>> priorityQueue;
    priorityQueue.emplace(0, 0);
    while (!priorityQueue.empty()) {
        Pi p = priorityQueue.top();
        priorityQueue.pop();
        if (used[p.second]) continue;
        used[p.second] = true;
        res += p.first;
        for (edge<T> &e : edges[p.second]) {
            if (!used[e.to]) priorityQueue.push({e.cost, e.to});
        }
    }
    return res;
}

struct town {
    int x, y, idx;
};

/**
 * D - Built?
 * https://atcoder.jp/contests/abc065/tasks/arc076_b
 */
void Main() {
    int N;
    cin >> N;
    vector<town> towns;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        towns.push_back({x, y, (int) i});
    }
    vector<town> towns2 = towns;
    sort(towns.begin(), towns.end(), [](const town &a, const town &b) {
        return a.x < b.x;
    });
    sort(towns2.begin(), towns2.end(), [](const town &a, const town &b) {
        return a.y < b.y;
    });
    vector<vector<edge<ll>>> edges(N);
    rep2(i, 1, N) {
        town ox = towns[i - 1];
        town nx = towns[i];
        edges[ox.idx].push_back({ox.idx, nx.idx, (ll) abs(ox.x - nx.x)});
        edges[nx.idx].push_back({nx.idx, ox.idx, (ll) abs(ox.x - nx.x)});
        town oy = towns2[i - 1];
        town ny = towns2[i];
        edges[oy.idx].push_back({oy.idx, ny.idx, (ll) abs(ny.y - oy.y)});
        edges[ny.idx].push_back({ny.idx, oy.idx, (ll) abs(ny.y - oy.y)});
    }
    cout << prim(edges, N) << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
