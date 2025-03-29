#include <bits/stdc++.h>
using namespace std;

#define int long long

// Function to get the top 3 max values and their indices from an array
vector<pair<int, int>> get_top_three(const vector<int> &arr) {
    vector<pair<int, int>> top;
    for (int i = 0; i < arr.size(); i++) {
        top.push_back({arr[i], i});
    }
    sort(top.rbegin(), top.rend()); // Sort in descending order
    return {top[0], top[1], top[2]}; // Return top 3 elements
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;
    
    // Get the top 3 elements with their indices
    auto topA = get_top_three(a);
    auto topB = get_top_three(b);
    auto topC = get_top_three(c);
    
    int maxSum = 0;
    
    // Try all combinations of top 3 elements ensuring distinct indices
    for (auto [ax, x] : topA) {
        for (auto [by, y] : topB) {
            if (x == y) continue; // Ensure distinct days
            for (auto [cz, z] : topC) {
                if (x == z || y == z) continue;
                maxSum = max(maxSum, ax + by + cz);
            }
        }
    }
    
    cout << maxSum << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
