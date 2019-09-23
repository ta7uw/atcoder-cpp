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
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<bool> is_prime;

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
