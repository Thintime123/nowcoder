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

    int n, m;
    cin >> n >> m;
    map<int, int> mp;

    fer(i, 0, n) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> arr(all(mp));
    sort(all(arr));
    if(m <= mp.rbegin()->second) {
        cout << m << '\n';
        return 0;
    }

    int ans = 0;
    int cnt = 0;

    for(auto it = mp.rbegin() - 1; it != mp.rend(); ++it) {
        if(it->first > (it + 1)->first) continue;

    }

    return 0;
}