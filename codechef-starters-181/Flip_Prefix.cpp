#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        set<string> seen;
        queue<string> q;
        
        seen.insert(s);
        q.push(s);
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += (curr[i] == '1' ? 1 : -1);
                
                if (count == 0 && i + 1 > 0) {
                    string next = curr;
                    for (int j = 0; j <= i; j++) {
                        next[j] = (next[j] == '0' ? '1' : '0');
                    }
                    
                    if (seen.find(next) == seen.end()) {
                        seen.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        
        cout << seen.size() << "\n";
    }
    
    return 0;
}