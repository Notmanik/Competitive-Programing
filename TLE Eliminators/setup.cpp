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

// GCD & LCM
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Sieve
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

// DSU
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
    // Your logic
}

int main() {
    ios_sync();

    #ifdef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

    #ifdef ONLINE_JUDGE
        fprintf(stderr, ">> Runtime: %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif

    return 0;
}