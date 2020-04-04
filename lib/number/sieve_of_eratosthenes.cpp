vector<ll> isPrime;

vector<int> sieveOfEratosthenes(int n) {
    isPrime.resize(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    vector<int> res;
    for (int i = 2; i * i<= n; i++) {
        if (isPrime[i]) {
            res.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return res;
}
