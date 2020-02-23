const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
bool initialized = false;

/**
 * @fn
 * This function must be called at first.
 */
void combination_init() {
    initialized = true;
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

/**
 * @fn
 * Calculates the combination  ( nCK % p: N choose K mod p).
 *
 * @brief constraint: 1 ≤ k ≤ n ≤ 10^7
 * @return nCK % MOD
 */
long long combination(int n, int k) {
    assert(initialized);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/**
 * @fn
 * Calculates the factorial of the number.
 *
 * @return N! % MOD
 */
long long factorial(int n) {
    assert(initialized);
    if (n < 0) return 0;
    return fac[n] % MOD;
}

/**
 * @fn
 * Calculates the combination ( nCK % p: N choose K mod p).
 *
 * @brief constraint: 1 ≤ k ≤ 10^7 and 1 ≤ n ≤ 10^9
 * @return nCK % MOD
 */
long long combination2(int n, int k) {
    assert(initialized);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    ll res = 1;
    k = min(k, n - k);
    for (long long x = 1; x <= k; x++) {
        res *= (n - x + 1);
        res %= MOD;
        res *= inv[x];
        res %= MOD;
    }
    return res;
}
