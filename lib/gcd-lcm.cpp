//
// Created by ta7uw on 2019-06-24.
//
ll gcd(ll a, ll b) {
    if (x < y)swap(x, y);
    if (y == 0)return x;
    return gcd(y, x % y);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}