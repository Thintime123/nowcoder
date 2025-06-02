#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cout << #x << ' ' << char(61) << ' ' << x << '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> mp;
    for(char c : s) mp[c]++;

    if(mp.size() == 1) {
        cout << 1 << '\n';
        return;
    }
    char c1 = mp.begin()->first, c2 = (++mp.begin())->first;
    
    int ans = 0, cnt = 1;
    fer(i, 1, n) {
        if(s[i] == s[0]) cnt++;
        else break;
    }
    if(cnt == mp[s[0]]) {
        if(s[0] == c1) ans = 1 + min(3, mp[c2]);
        else ans = 1 + min(3, mp[c1]);
    } else {
        ans = 2;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}