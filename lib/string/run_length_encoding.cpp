/**
 * ランレングス圧縮
 */
vector<pair<char, ll>> RLE(const string &S) {
    ll cnt = 0;
    vector<pair<char, ll>> res;
    for (ll i = 0; i < (ll) S.size(); i++) {
        cnt++;
        if (i == (ll) S.size() - 1) {
            res.emplace_back(S[i], cnt);
            break;
        }
        if (S[i] != S[i + 1]) {
            res.emplace_back(S[i], cnt);
            cnt = 0;
        }
    }
    return res;
}
