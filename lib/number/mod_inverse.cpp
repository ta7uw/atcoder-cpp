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
ll mod_inverse(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}
/**
 * --------------------------------------------------------
 */

/**
 * D. Santa's Bot
 * https://codeforces.com/contest/1279/problem/D
 */
void Main() {
    ll N;
    cin >> N;
    vector<vector<int>> A(N);
    map<ll, ll> cnt;
    rep(i, N) {
        int K;
        cin >> K;
        vector<int> tmp(K, 0);
        rep(k, K) cin >> tmp[k];
        A[i] = tmp;
        rep(k, K) cnt[A[i][k]]++;
    }
    ll ans = 0;
    ll mod = mod = 998244353;
    ll rev = mod_inverse(N * N, mod);
    rep(i, N) {
        ll k = A[i].size();
        ll k_inv = mod_inverse(k, mod);
        for (ll a: A[i]) {
            ans += (((k_inv * rev) % mod) * cnt[a]) % mod;
            ans %= mod;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
