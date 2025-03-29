#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl;
#define print_vec(v) for (auto x : v) cout << x << " "; cout << endl;

int BFS(int start, vector<bool> &visited, unordered_map<int, list<int>> &adj_list) {
    queue<int> q;
    unordered_map<int, int> parent;  
    q.push(start);
    parent[start] = -1;
    visited[start] = true;

    int cycle_edges = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto &neighbor : adj_list[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = node;
            }
            
            else if (parent[node] != neighbor) {
                cycle_edges++;
            }
        }
    }

    return cycle_edges / 2; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    unordered_map<int, list<int>> adj_list;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<bool> visited(n + 1, false); 
    int cycle_edges = 0;
    for (int i = 1; i <= n; i++) { 
        if (!visited[i]) {
            cycle_edges += BFS(i, visited, adj_list);
        }
    }

    cout << cycle_edges;  
}
