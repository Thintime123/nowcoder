#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cout << #x << ' ' << '=' << ' ' << x << '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> arr(n);

    fer(i, 0, n) cin >> arr[i];

    ll s = accumulate(all(arr), 0LL);

    fer(i, 0, n) {
        cout << s / (n - 1) - arr[i] << ' ';
    }

    return 0;
}