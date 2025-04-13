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

// Main function
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;  
    
    while (t--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        
        
        int r_prime = r;
        int l_prime = r - m;  // r' - (m+1) + 1
        
        
        cout << l_prime << " " << r_prime << endl;
    }
    
    return 0;
}
