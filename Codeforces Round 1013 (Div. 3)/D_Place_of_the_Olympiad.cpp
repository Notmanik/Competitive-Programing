#include <iostream>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int max_bench_length = (k + n - 1) / n; // Equivalent to ceil(k / n)
    cout << min(max_bench_length, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}
