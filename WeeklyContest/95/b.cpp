#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
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
    vector<int> a(n + 1);
    fer(i, 1, n + 1) cin >> a[i];

    int q;
    cin >> q;
    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	fer(i, l, r + 1) {
    		if(i == l) cout << a[i] << ' ';
    		else cout << a[i] - a[i - 1] << " \n"[i == r];
    	}
    }

    return 0;
}