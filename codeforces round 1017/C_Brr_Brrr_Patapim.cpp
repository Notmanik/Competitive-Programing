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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vi> v(n + 1,vector<int>(n + 1));
        for(int i = 1;i< n + 1;i++){
            for (int j = 1; j < n + 1; j++)
            {
                int temp;cin>>temp;
                v[i][j] = temp;
            }
        }
        vi ans(2 * n + 2,0);
        for(int i = 1;i<n + 1;i++){
            for (int j = 1; j < n + 1; j++)
            {
                int temp = i + j;
                if(ans[temp] != 0) continue;
                ans[temp] = v[i][j];
                
            }
        }
        long long sum = (2*n) * (2 * n + 1) / 2;
        for(auto &x:ans){
            sum -= x;
        }
        ans[1] = sum;
        for (int  i = 1; i <= 2 * n; i++)
        {
            cout<<ans[i]<<" ";
        } cout<<endl;
        
    }
    return 0;
}
