#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

/**
 * Library
 * --------------------------------------------------------
 */
template<typename T>
class BinaryIndexedTree2D {
    int H;
    int W;
    vector<vector<T> > data2d;
public:
    BinaryIndexedTree2D(int H, int W) : H(H), W(W) {
        data2d.resize(H + 1, vector<T>(W + 1, 0));
    }

    T sum(int h, int w) {
        T res = 0;
        for (int i = h; i > 0; i -= i & -i) {
            for (int j = w; j > 0; j -= j & -j) {
                res += data2d[i][j];
            }
        }
        return res;
    }

    /**
     * 左上の座標(h1, w1), 右下の座標(h2, w2) に含まれる値のの累積和
     */
    T sum(int h1, int w1, int h2, int w2) {
        return sum(h2, w2) - sum(h1 - 1, w2) - sum(h2, w1 - 1) + sum(h1 - 1, w1 - 1);
    }

    void add(int h, int w, ll x) {
        for (int i = h; i <= H; i += i & -i) {
            for (int j = w; j <= W; j += j & -j) {
                data2d[i][j] += x;
            }
        }
    }
};
/**
 * --------------------------------------------------------
 */

/**
 * Taiyaki-Master and Eater
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
 */
int main() {
    int H, W, T, Q;
    cin >> H >> W >> T >> Q;
    BinaryIndexedTree2D<ll> completed(H, W), notCompleted(H, W);
    queue<pair<ll, P> > queue;
    for (int q = 0; q < Q; ++q) {
        int t, c, h1, w1, h2, w2;
        cin >> t >> c >> h1 >> w1;
        while (!queue.empty()) {
            pair<ll, P> p = queue.front();
            if (p.first > t) break;
            queue.pop();
            int h = p.second.first;
            int w = p.second.second;
            completed.add(h, w, 1);
            notCompleted.add(h, w, -1);
        }

        if (c == 0) {
            notCompleted.add(h1, w1, 1);
            queue.push({t + T, {h1, w1}});
        } else if (c == 1) {
            if (completed.sum(h1, w1, h1, w1) == 1) {
                completed.add(h1, w1, -1);
            }
        } else {
            cin >> h2 >> w2;
            cout << completed.sum(h1, w1, h2, w2) << " " << notCompleted.sum(h1, w1, h2, w2) << '\n';
        }
    }
    return 0;
}
