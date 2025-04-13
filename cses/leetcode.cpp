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
    string A = "124";
    int start , finish;
    start = 1;
    finish = 6000;
    string S = to_string(start);
    string F = to_string(finish);
    if(A < F){
        cout<<"A > F -> True";
        cout<<endl;
    }
    if(S < F){
        cout<<"S > F -> True";
        cout<<endl;
    }
    if(A > S){
        cout<<"A > S -> True";
        cout<<endl;
    }
    return 0;
}
