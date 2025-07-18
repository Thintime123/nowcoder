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

const int MOD = 998244353;
const int N = 2e5 + 2;
const int inf = 1e9;

struct DSU {
	int n;
	vector<int> fa, sz;

	// 节点编号从 1 开始
	DSU(int n) : n(n) {
		fa.resize(n + 1);
		iota(all(fa), 0);
		sz.resize(n + 1, 1);
	}

	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}

	void merge(int x, int y) {
		int rx = find(x), ry = find(y);
		if(rx != ry) {
			if(sz[rx] < sz[ry]) swap(rx, ry);
			fa[ry] = rx;
			sz[rx] += sz[ry];
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	int size(int x) {
		return sz[find(x)];
	}
};

ll fpow(ll a, int b) {
	ll res = 1;
	while(b) {
		if(b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void solve() {
    int n;
    cin >> n;
    DSU uf(n);

    fer(u, 1, n + 1) {
    	int v;
    	cin >> v;
    	uf.merge(u, v);
    }
    set<int> st;
    fer(i, 1, n + 1) st.insert(uf.find(i));

    vector<int> odd, even;
    for(auto rt : st) {
    	int sz = uf.size(rt);
    	if(sz & 1) odd.push_back(sz);
    	else even.push_back(sz);
    }
    if(odd.size() == 1 || odd.size() > 2) {
    	cout << 0 << '\n';
    	return;
    }

    ll ans = 0;
	ll t = 1;
	int cnt1 = 0, cnt2 = 0;
	for(auto sz : even) {
		if(sz > 2) cnt1++;
		else cnt2++;
	}

    if(odd.size() == 2) {
    	t = fpow(2, cnt1);
    	ans = (1LL * odd[0] * odd[1] % MOD * t) % MOD;
    } else {
		for(auto sz : even) {
			if(sz == 2) t = fpow(2, cnt1);
			else t = fpow(2, cnt1 - 1);
			ans = (ans + 1LL * sz / 2 * sz / 2 % MOD * t) % MOD;
		}
    }
    cout << ans << '\n';
}

signed main() {
    IOS;

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}