#include<bits/stdc++.h>

using namespace std;

#define IOS cin.tie(nullptr) -> ios::sync_with_stdio(false)
#define ll long long
#define ull unsigned long long
//#define int ll
#define pii pair<int, int>
#define pll pair<ll, ll>
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

double get(int x, int y) {
	double agl = atan2(y, x);
	if(agl < 0) agl += 2 * M_PI;
	return agl;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<pii> arr(n);

    fer(i, 0, n) cin >> arr[i].first >> arr[i].second;

    // int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    // fer(i, 1, n) {
    // 	int x1 = arr[i].first - arr[i - 1].first;
    // 	int y1 = arr[i].second - arr[i - 1].second;
    // 	int x2 = arr[i - 1].first - x;
    // 	int y2 = arr[i - 1].second - y;

    // 	if(1LL * x1 * y2 - 1LL * x2 * y1 < 0) cnt1++;
    // 	else if(1LL * x1 * y2 - 1LL * x2 * y1 > 0) cnt2++;
    // 	else cnt3++;

    // 	if(cnt1 && cnt2 && cnt3 != 2) {
    // 		cout << fixed << setprecision(15) << 2 * M_PI << '\n';
    // 		return;
    // 	}
    // }

    // 相对的r2
	auto r2 = [&](pii c) -> ll {
		ll a = c.first - x, b = c.second - y;
		return 1LL * a * a + 1LL * b * b;
	};
    std::ranges::sort(all(arr), [&](pii a, pii b) {
    	return r2(a) > r2(b);
    });

    ll max_r2 = r2(arr[0]);

    vector<double> v;
    for(auto p : arr) {
    	if(r2(p) == max_r2) {
    		v.push_back(get(p.first - x, p.second - y));
    	} else {
    		break;
    	}
    }

    sort(all(v));

    if(v.size() == 1) {
    	cout << fixed << setprecision(15) << 2 * M_PI << '\n';
    	return;
    }

    double mx_gap = 2 * M_PI - v.back() + v.front();
    fer(i, 1, v.size()) {
    	mx_gap = max(mx_gap, v[i] - v[i - 1]);
    }
    cout << fixed << setprecision(15) << mx_gap << '\n';
}

signed main() {
    IOS;

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}