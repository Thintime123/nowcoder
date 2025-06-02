#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
using ull=unsigned long long;
const ll INF=100000000000000;
ll a[30004]={0};
ll n,k,m;
bool check(ll maxn) {
    vector<vector<ll>> dp(n+5,vector<ll>(k+5,INF));
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=k;++j){
            if(dp[i-1][j]+a[i]<=maxn)
                dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i]);
            if(j>0&&dp[i-1][j-1]!=INF)
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]/2);
        }
    }
    return dp[n][k]!=INF;
}
void solve() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll ans1, ans2 = 0;
    if (k * m >= n) {
        ans2 = 0;
    } else {
        vector<ll> prefix_sum(n + m + 5, 0);
        for (int i = 1; i <= n; ++i)
            prefix_sum[i] = prefix_sum[i - 1] + a[i];
        vector<vector<ll>> dp(n + 5, vector<ll>(k + 5, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (i - m >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + (prefix_sum[i] - prefix_sum[i - m]));
            }
        }
        ans2 = prefix_sum[n] - dp[n][k];
    }
    ll l = 0, r = ans2+7;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    ans1 = l;

    cout << min(ans1, ans2) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
//    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}
