#include<bits/stdc++.h>

using namespace std;

#define IOS cin.tie(nullptr) -> ios::sync_with_stdio(false)
#define ll long long
#define ull unsigned long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cerr << #x << char(61) << x << " ###\n"
#define dbg_arr(a, i) cerr << #a << '[' << i << "]=" << a[i] << " ###\n";

#define lowbit(x)  ((x) & -(x))
#define popcount(x)  __builtin_popcount(x)
#define popcountll(x)  __builtin_popcountll(x)
#define clz(x)  __builtin_clz(x)
#define ctz(x)  __builtin_ctz(x)

using u32 = unsigned;
using i64 = ll;
using u64 = ull;
using i128 = __int128;
using u128 = unsigned __int128;

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    fer(i, 0, n) cin >> arr[i];

    ll dp[2]{}, cnt[2]{};
    dp[0] = 1;

    for(int x : arr) {
    	ll c0 = 0, c1 = 0;
    	ll cnt0 = 0, cnt1 = 0;
    	if(x != 1) {
    		c0 = (dp[0] + dp[1]) % MOD;
    		cnt0 = (cnt[0] + cnt[1]) % MOD;
    	}
    	if(x != 0) {
    		c1 = (dp[0] + dp[1]) % MOD;
    		cnt1 = (cnt[0] + dp[0] + cnt[1]) % MOD;
    	}

    	dp[0] = c0, dp[1] = c1;
    	cnt[0] = cnt0, cnt[1] = cnt1;
    }
    cout << (cnt[0] + cnt[1]) % MOD << '\n';
}

signed main() {
    IOS;

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}