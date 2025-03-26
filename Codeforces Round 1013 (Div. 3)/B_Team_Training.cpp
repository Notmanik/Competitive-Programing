#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxStrongTeams(int n, int x, vector<int>& skills) {
    // Sort skills in ascending order
    sort(skills.begin(), skills.end());
    
    int teams = 0;
    long long totalStrength = 0;
    
    for (int i = 0; i < n; i++) {
        // Start a new team with the current student as the weakest
        long long currentMin = skills[i];
        
        // Calculate how many students can join this team
        int teamSize = 1;
        
        // Find team size that maximizes strength without exceeding x
        for (int j = i + 1; j < n; j++) {
            if (skills[j] < currentMin) continue;
            
            // Check if adding this student maintains team strength
            if ((long long)currentMin * (teamSize + 1) > x) break;
            
            teamSize++;
        }
        
        // If team is strong, form it and remove these students
        if ((long long)currentMin * teamSize >= x) {
            teams++;
            
            // Remove team members
            i += teamSize - 1;
        }
    }
    
    return teams;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        
        vector<int> skills(n);
        for (int i = 0; i < n; i++) {
            cin >> skills[i];
        }
        
        cout << maxStrongTeams(n, x, skills) << endl;
    }
    
    return 0;
}