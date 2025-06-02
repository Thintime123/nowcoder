#include <algorithm>
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

    vector<int> a(3);
    int ind;
    cin >> a[0] >> a[1] >> a[2] >> ind;

    if(*max_element(all(a)) == a[ind - 1]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}