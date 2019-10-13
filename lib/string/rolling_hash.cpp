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
class RollingHash {
    static const ll base1 = 1009;
    static const ll base2 = 2009;
    static const ll mod1 = 1000000007;
    static const ll mod2 = 1000000009;
    vector<ll> hash1, hash2, pow1, pow2;

public:
    RollingHash(const string &S) {
        int n = (int) S.size();
        hash1.assign(n + 1, 0);
        hash2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            hash1[i + 1] = (hash1[i] * base1 + S[i]) % mod1;
            hash2[i + 1] = (hash2[i] * base2 + S[i]) % mod2;
            pow1[i + 1] = (pow1[i] * base1) % mod1;
            pow2[i + 1] = (pow2[i] * base2) % mod2;
        }
    }

    /**
     * S の [l, r) のハッシュ値を返す
     * O(1)
     */
    inline pair<ll, ll> get(int l, int r) const {
        ll res1 = hash1[r] - hash1[l] * pow1[r - l] % mod1;
        if (res1 < 0) res1 += mod1;
        ll res2 = hash2[r] - hash2[l] * pow2[r - l] % mod2;
        if (res2 < 0) res2 += mod2;
        return make_pair(res1, res2);
    }

    /**
     * S のハッシュ値を返す
     * O(1)
     */
    inline pair<ll, ll> hash() const {
        return get(0, (int) hash1.size() - 1);
    }

    /**
     * LCP (Longest Common Prefix)
     */
    inline int getLCP(int a, int b) const {
        int len = min((int) hash1.size() - a, (int) hash1.size() - b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (get(a, a + mid) != get(b, b + mid)) high = mid;
            else low = mid;
        }
        return low;
    }

    /**
     * hash h1 と 長さ h2_len の文字列の hash h2 を結合
     */
    pair<ll, ll> concat(pair<ll, ll> h1, pair<ll, ll> h2, int h2_len) {
        return make_pair((h1.first * pow1[h2_len] + h2.first) % mod1, (h1.second * pow2[h2_len] + h2.second) % mod2);
    }
};
/**
 * --------------------------------------------------------
 */

/**
 * E - Who Says a Pun?
 * https://atcoder.jp/contests/abc141/tasks/abc141_e
 */
void Main() {
    int N;
    string S;
    cin >> N >> S;
    RollingHash rollingHash(S);
    ll ans = 0;
    rep(i, N) {
        rep2(j, i + 1, N) {
            ll lcp = rollingHash.getLCP(i, j);
            lcp = min(lcp, j - i);
            ans = max(ans, lcp);
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
