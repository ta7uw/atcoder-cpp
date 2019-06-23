//
// Created by ta7uw on 2019-06-24.
//
ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}