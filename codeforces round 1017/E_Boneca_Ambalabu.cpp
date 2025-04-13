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


int selectMaxLowerPowerOf2(const vector<int>& arr) {
    int maxPower = -1;
    int result = -1;

    for (int num : arr) {
        if (num == 0) continue;

        int power = 1 << (int)log2(num);  // largest power of 2 <= num

        if (power > maxPower) {
            maxPower = power;
            result = num;
        } else if (power == maxPower && num < result) {
            result = num;
        }
    }

    return result;
}



// Main function
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vi v(n);
        
        for(auto &x:v){
            cin>>x;
        }
        int k = selectMaxLowerPowerOf2(v);
        // cout<<k<<endl;
        int sum = 0;
        for(auto &x:v){
            sum = sum + (k ^ x);
        }
        cout<<sum<<"\n";
    }
    return 0;
}
