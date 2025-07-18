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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    fer(i, 0, n) cin >> arr[i];

    int t = n / 2;
    vector<int> b(arr);
    sort(all(b), greater<int>());
    int cnt = 1;
    map<int, int> mp;
    mp[b[0]]++;
    fer(i, 1, n) {
    	cnt++;
    	if(b[i] != b[i - 1] && cnt > t) break;
    	mp[b[i]]++;
    }

    int res = cnt - 1;
    dbg(t);
    dbg(res);
    while(q--) {
    	int p, v;
    	cin >> p >> v;
    	p--;
    	int c = arr[p] + v;
    	arr[p] += v;
    	//fer(i, 0, n) dbg_arr(arr, i);

    	if(c < mp.begin()->first) {
    		cout << n - res << '\n';
    	} else if(mp[c]) {
    		mp[c] += 1;
    		res ++;
    		cout << n - res << '\n';
    	} else {
    		res -= mp.begin()->second;
    		mp.erase(mp.begin());
    		mp[c]++;
    		res++;
    		cout << n - res << '\n';
    	}
    }
}

signed main() {
    IOS;

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}