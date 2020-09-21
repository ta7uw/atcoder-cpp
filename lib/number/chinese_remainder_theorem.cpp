inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

/**
 * 拡張 Euclid の互除法
 * @return ap + bq = gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターンします
 */
long long extGcd(long long a, long long b, long long &p, long long &q) {
    if (b == 0) {
        p = 1;
        q = 0;
        return a;
    }
    long long d = extGcd(b, a % b, q, p);
    q -= a / b * p;
    return d;
}

/**
 * Chinese remainder theorem (中国剰余定理)
 * ref. https://qiita.com/drken/items/ae02240cd1f8edfc86fd
 * @return リターン値を (r, m) とすると解は x ≡ r (mod. m), 解なしの場合は (0, -1) をリターン
 */
pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2) {
    long long p, q;
    long long d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
    if ((b2 - b1) % d != 0) return make_pair(0, -1);
    long long m = m1 * (m2 / d); // lcm of (m1, m2)
    long long tmp = (b2 - b1) / d * p % (m2 / d);
    long long r = mod(b1 + m1 * tmp, m);
    return make_pair(r, m);
}
