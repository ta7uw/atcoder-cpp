class mint {
public:
    long long x;

    constexpr mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}

    constexpr mint operator-() const {
        return mint(-x);
    }

    constexpr mint &operator+=(const mint &rhs) {
        if ((x += rhs.x) >= MOD) x -= MOD;
        return *this;
    }

    constexpr mint &operator-=(const mint &rhs) {
        if ((x += MOD - rhs.x) >= MOD) x -= MOD;
        return *this;
    }

    constexpr mint &operator*=(const mint &rhs) {
        (x *= rhs.x) %= MOD;
        return *this;
    }

    constexpr mint operator+(const mint &rhs) const {
        mint res(*this);
        return res += rhs;
    }

    constexpr mint operator-(const mint &rhs) const {
        mint res(*this);
        return res -= rhs;
    }

    constexpr mint operator*(const mint &rhs) const {
        mint res(*this);
        return res *= rhs;
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

    mint &operator/=(mint rhs) {
        return *this *= rhs.inv();
    }

    mint operator/(const mint rhs) const {
        return mint(*this) /= rhs;
    }

    constexpr bool operator==(const mint &rhs) const noexcept {
        return this->x == rhs.x;
    }

    constexpr bool operator!=(const mint &rhs) const noexcept {
        return this->x != rhs.x;
    }

    bool operator<(const mint &rhs) const noexcept {
        return this->x < rhs.x;
    }

    bool operator>(const mint &rhs) const noexcept {
        return this->x > rhs.x;
    }

    bool operator<=(const mint &rhs) const noexcept {
        return this->x <= rhs.x;
    }

    bool operator>=(const mint &rhs) const noexcept {
        return this->x >= rhs.x;
    }

    friend istream &operator>>(istream &is, mint &a) {
        long long t;
        is >> t;
        a = mint(t);
        return is;
    }

    friend ostream &operator<<(ostream &os, const mint &a) {
        return os << a.x;
    }
};
