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
ll N;
Graph graph;
vector<ll> dp;
vector<ll> centroids;

void findCentroids(ll v, ll prev) {
    bool isCntroids = true;
    dp[v] = 1;
    for (ll u : graph[v]) {
        if (u == prev) continue;
        findCentroids(u, v);
        if (dp[u] > N / 2) isCntroids = false;
        dp[v] += dp[u];
    }
    if (N - dp[v] > N / 2) isCntroids = false;
    if (isCntroids) centroids.emplace_back(v);
}
/**
 * --------------------------------------------------------
 */

/**
 * Codeforces Round #670 (Div. 2) C. Link Cut Centroids
 * http://codeforces.com/contest/1406/problem/C
 */
void solve() {
    ll T;
    cin >> T;
    while (T--) {
        cin >> N;
        graph.assign(N, vector<ll>());
        dp.resize(N, 0);
        centroids.clear();
        rep(i, N - 1) {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        findCentroids(0, -1);

        if (centroids.size() == 1) {
            ll centroid = centroids[0];
            cout << centroid + 1 << " " << graph[centroid][0] + 1 << '\n';
            cout << centroid + 1 << " " << graph[centroid][0] + 1 << '\n';
        } else {
            ll centroid1 = centroids[0];
            ll centroid2 = centroids[1];
            ll v = graph[centroid1][0];
            if (v == centroid2) v = graph[centroid1][1];
            cout << centroid1 + 1 << " " << v + 1 << '\n';
            cout << centroid2 + 1 << " " << v + 1 << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
