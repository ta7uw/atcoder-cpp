#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


/**
 * Library
 * --------------------------------------------------------
 */
template<typename T>
class BinaryIndexedTree {
    int N;
    vector<T> data;
public:
    BinaryIndexedTree(int N) : N(N) {
        data.resize(N + 1, 0);
    }

    T sum(int k) {
        T res = 0;
        for (; k > 0; k -= k & -k) {
            res += data[k];
        }
        return res;
    }

    void add(int k, T x) {
        for (; k <= N; k += k & -k) {
            data[k] += x;
        }
    }

    /**
     * v1 + v2 + ⋯ + vx ≧ W となる最小の 𝑥 を求める
     */
    int lowerBound(int w) {
        if (w <= 0) return 0;
        int x = 0;
        int k = 1;
        while (k * 2 <= N) k *= 2;
        for (; k > 0; k /= 2) {
            if (x + k <= N && data[x + k] < w) {
                w -= data[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};
/**
 * --------------------------------------------------------
 */

/**
 * DSL_2_B Range Sum Query (RSQ)
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
 */

int main() {
    int N, Q;
    cin >> N >> Q;
    BinaryIndexedTree<ll> bit(N);
    while (Q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 1) {
            cout << bit.sum(y) - bit.sum(x - 1) << '\n';
        } else {
            bit.add(x, y);
        }
    }
    return 0;
}
