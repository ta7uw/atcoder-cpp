// 素数列挙
vector<int> prime_list(int n) {
    is_prime.resize(n + 1, true);
    vector<int> res;
    int i = 2;
    while (pow(i, 2) <= n) {
        if (is_prime[i]) {
            int j = i + i;
            while (j <= n) {
                is_prime[j] = false;
                j += i;
            }
        }
        i++;
    }
    for (int i = 0; i <= n; ++i) {
        if (is_prime[i] && i >= 2) {
            res.push_back(i);
        }
    }
    return res;
}
