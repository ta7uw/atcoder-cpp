#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>

using namespace std;

const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)

ll dp[2050][2050] = {};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> s(N), t(M);
    rep2(i, 0, N) cin >> s[i];
    rep2(i, 0, M) cin >> t[i];

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1] + 1;
                dp[i][j] %= MOD;
            }
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % MOD - dp[i - 1][j - 1];
            if (dp[i][j] < 0) {
                dp[i][j] += MOD;
            } else {
                dp[i][j] %= MOD;
            }
        }
    }
    cout << (dp[N][M] + 1) % MOD << endl;
}
