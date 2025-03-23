#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int &x : a) cin >> x;

    vector<pair<int, int>> operations;

    int mid = n / 2, r = n;

    // If there's a zero in the right half
    if (find(a.begin() + mid, a.end(), 0) != a.end()) {
        operations.push_back({mid + 1, n});
        r -= (n - mid - 1);
    }

    // If there's a zero in the left half
    if (find(a.begin(), a.begin() + mid, 0) != a.begin() + mid) {
        operations.push_back({1, mid});
        r -= (mid - 1);
    }

    // Final operation
    operations.push_back({1, r});

    // Output the operations
    cout << operations.size() << "\n";
    for (auto &[l, r] : operations) {
        cout << l << " " << r << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
