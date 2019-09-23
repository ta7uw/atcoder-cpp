// 素因数分解
map<ll, ll> prime_factorize(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res[i]++;
            N /= i;
        }
    }
    if (N != 1) res[N] = 1;
    return res;
}
