#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define ios_sync() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Typedefs & Aliases
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;

// Constants
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX;
const double EPS = 1e-9;
const double PI = acos(-1.0);

// Macros
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'

// Debugging
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

// Power Function with Modulo
ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// GCD Function
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM Function
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<int> primes(n + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i)
                primes[j] = 0;
        }
    }
    return primes;
}

// Disjoint Set Union (DSU)
struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        return (v == parent[v]) ? v : (parent[v] = find(parent[v]));
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    
    // Check if any number is already divisible by k
    bool divisible_by_k = false;
    
    // For k=4 case, count numbers divisible by 2
    int count_div_by_2 = 0;
    // For k=2 case, check product parity
    bool product_odd = true;
    vector<int> dp(n);
    for (auto &x : nums) {
        cin >> x;
        
        // Check divisibility by k
        if (x % k == 0) divisible_by_k = true;
        
        // For k=2
        if (x % 2 == 0) product_odd = false;
        
        // For k=4
        if (x % 2 == 0) count_div_by_2++;
    }
    
    // If already divisible by k
    if (divisible_by_k) {
        cout << 0;
        return;
    }
    
    int min_ops = INT_MAX;
    int m = 0;
    // Case k=2
    if (k == 2) {
        if (!product_odd) {
            // Product already has a factor of 2
            min_ops = 0;
        } else {
            // Need to make one number even
            min_ops = 1;
        }
    } 
    // Case k=3
    else if (k == 3) {
        for(int i = 0;i<n;i++){
            int temp = nums[i] % k;
            m = max(m,temp);
        }
        min_ops = 3 - m;
    } 
    // Case k=4
    else if (k == 4) {
        if (count_div_by_2 >= 2) {
            // Already have two numbers divisible by 2
            min_ops = 0;
        } else if (count_div_by_2 == 1) {
            // Need one more number divisible by 2
            min_ops = 1;
        } else {
            for(int i = 0;i<n;i++){
                int temp = nums[i] % k;
                m = max(m,temp);
            }
            min_ops = 4 - m;
            min_ops = min(2,min_ops);
        }
    } 
    else if (k == 5) {
        for(int i = 0;i<n;i++){
            int temp = nums[i] % k;
            m = max(m,temp);
        }
        min_ops = 5 - m;
    }
    
    cout << min_ops;
}
// Main function
int main() {
    ios_sync();
    
    int t = 1;
    cin >> t;
    while (t--) {
        // Your code here
        solve();
        cout<<endl;
    }

    return 0;
}
