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
template<class T>
map<T, int> compress_value(vector<T> &x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    map<T, int> zip;
    for (int i = 0; i < (int) x.size(); ++i) {
        zip[x[i]] = i;
    }
    return zip;
}
/**
 * --------------------------------------------------------
 */


/**
 * ABC036 C - 座圧
 * https://atcoder.jp/contests/abc036/tasks/abc036_c
 */
void Main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    auto B = A;
    map<int, int> res = compress_value(B);
    rep(i, N) {
        cout << res[A[i]] << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
