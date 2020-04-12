const long long MOD = 1000000007;

class mint {
public:
    long long x;

    constexpr mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}

    constexpr mint operator-() const {
        return mint(-x);
    }

    constexpr mint &operator+=(const mint &a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }

    constexpr mint &operator-=(const mint &a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }

    constexpr mint &operator*=(const mint &a) {
        (x *= a.x) %= MOD;
        return *this;
    }

    constexpr mint operator+(const mint &a) const {
        mint res(*this);
        return res += a;
    }

    constexpr mint operator-(const mint &a) const {
        mint res(*this);
        return res -= a;
    }

    constexpr mint operator*(const mint &a) const {
        mint res(*this);
        return res *= a;
    }

    [[nodiscard]] constexpr mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    [[nodiscard]] constexpr mint inv() const {
        return pow(MOD - 2);
    }

    mint &operator/=(mint a) {
        return *this *= a.inv();
    }

    mint operator/(const mint a) const {
        return mint(*this) /= a;
    }

    constexpr bool operator==(const mint &a) const noexcept {
        return this->x == a.x;
    }

    constexpr bool operator!=(const mint &a) const noexcept {
        return this->x != a.x;
    }

    bool operator<(const mint &a) const noexcept {
        return this->x < a.x;
    }

    bool operator>(const mint &a) const noexcept {
        return this->x < a.x;
    }

    bool operator<=(const mint &a) const noexcept {
        return this->x <= a.x;
    }

    bool operator>=(const mint &a) const noexcept {
        return this->x >= a.x;
    }

    friend istream &operator>>(istream &is, mint &a) {
        is >> a.x;
        return is;
    }

    friend ostream &operator<<(ostream &os, const mint &a) {
        return os << a.x;
    }
};
