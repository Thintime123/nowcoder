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

    int a, b, c;
    cin >> a >> b >> c;

    if(a == 0) {
        if(abs(b) == 1 && c == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    } else if(abs(a) == 1) {
        if(b == 0 && c == -a) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}