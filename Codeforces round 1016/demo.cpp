#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll LINF = 1e18;

// Debugging
#define debug(x) cout << #x << " = " << (x) << endl;
#define print_vec(v)                   \
    for (auto x : v) cout << x << " "; \
    cout << endl;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int coins_num = 1;
    cin >> coins_num;
    int num = 1;
    cin >> num;
    vi coins(coins_num);
    for (auto &x : coins)
    {
        cin >> x;
    }
    vi dp(num + 1, INF);
    dp[0] = 0;
    for (auto c : coins)
    {
        for (int i = c; i <= num; ++i)
        {
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    if (dp[num] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << dp[num];
    }

    return 0;
}