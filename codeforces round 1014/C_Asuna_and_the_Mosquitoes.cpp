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
#define print_vec(v) for (auto x : v) cout << x << " "; cout << endl;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    ll sum = 0;
    int odd = 0;
    ll maxi = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        maxi = max(maxi, (ll)a[i]); 
        if (a[i] % 2 == 1)
            odd++;
    }

    if (odd == 0 || odd == n) cout << maxi;
    else cout << sum - odd + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}