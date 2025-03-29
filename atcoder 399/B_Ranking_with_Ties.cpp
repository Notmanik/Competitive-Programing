#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io()            \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> sorted_v = v;
    sort(sorted_v.rbegin(), sorted_v.rend());

    unordered_map<int, int> rank_map;
    for (int i = 0; i < n; i++)
    {
        if (rank_map.find(sorted_v[i]) == rank_map.end())
        {
            rank_map[sorted_v[i]] = i + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << rank_map[v[i]] << endl;
    }
}

int32_t main()
{
    fast_io();

    solve();

    return 0;
}
