#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
};

/**
 * DSL_2_B Range Sum Query (RSQ)
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
 */
void Main() {
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
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
