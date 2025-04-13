#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constants
const int INF = 1e9;
const ll LINF = 1e18;

// Debugging
#define debug(x) cout << #x << " = " << (x) << endl;
#define print_vec(v)                   \
    for (auto x : v) cout << x << " "; \
    cout << endl;

bool canProduceSound(const string& hits, const string& sounds)
{
    int n = hits.size(), m = sounds.size();
    vector<bool> dp_prev(m + 1, false), dp_curr(m + 1, false);
    dp_prev[0] = true;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (!dp_prev[j])
                continue;

            char ch = hits[i];
            if (j < m && sounds[j] == ch)
            {
                dp_curr[j + 1] = true;
            }
            
            if (j + 1 < m && sounds[j] == ch && sounds[j + 1] == ch)
            {
                dp_curr[j + 2] = true;
            }
        }
        dp_prev = dp_curr;
        fill(dp_curr.begin(), dp_curr.end(), false); 
    }

    return dp_prev[m];
}

// Main function
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string hits, sounds;
        cin >> hits >> sounds;

        cout << (canProduceSound(hits, sounds) ? "YES" : "NO") << '\n';
    }

    return 0;
}
