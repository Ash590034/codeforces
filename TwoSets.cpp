#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
const ll mod = 1e9+7;

ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

void solve() {
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << 0 << endl;
    } else {
        sum /= 2;
        vl dp(sum + 1, 0);
        dp[0] = 1;
        for (ll i = 1; i <= n; i++) {
            for (ll j = sum; j >= i; j--) {
                dp[j] = (dp[j] + dp[j - i]) % mod;
            }
        }
        ll result = dp[sum];
        ll inverse2 = modInverse(2, mod);
        cout << (result * inverse2) % mod << endl;
    }
}

int main() {
    solve();
    return 0;
}
