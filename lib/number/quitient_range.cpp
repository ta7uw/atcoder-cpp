/**
 * 計算量: O(√N)
 * 自然数 N の商の種類数を返す。
 * ⌊N/i⌋ = k となる最左の i を l , 最右の i を r とすると [l, r] で  N / i のあまりは等差数列になる。
 * verified: https://codeforces.com/contest/1263/problem/C
 * @param N 自然数 N
 * @return x <= i <= y を満たす整数の商 ⌊N/i⌋ が z であるとき, {{x, y}, z} と表す。x の昇順で返す
 */
vector<pair<P, ll>> quotient_range(ll N) {
    ll M;
    vector<pair<P, ll> > res;
    for (M = 1; M * M <= N; M++) {
        res.emplace_back(make_pair(M, M), N / M);
    }
    for (ll i = M; i >= 1; i--) {
        ll L = N / (i + 1) + 1;
        ll R = N / i;
        if (L <= R && res.back().first.second < L) res.emplace_back(make_pair(L, R), N / L);
    }
    return res;
}
