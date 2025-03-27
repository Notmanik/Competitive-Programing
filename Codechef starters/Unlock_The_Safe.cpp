#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i=0; i<N; i++) cin >> A[i];
        for (int i=0; i<N; i++) cin >> B[i];
        
        int S_min = 0;
        
        int best_delta = 1e9; 
        
        for (int i=0; i<N; i++){
           
            int up;
            if(B[i] >= A[i])
                up = B[i] - A[i];
            else
                up = B[i] + 9 - A[i];
            
            int down;
            if(A[i] >= B[i])
                down = A[i] - B[i];
            else
                down = A[i] + 9 - B[i];
            
           
            int m = min(up, down);
            S_min += m;
            
            
            int alt = (m == 0 ? 9 : (9 - m));
            int delta = alt - m;  
            best_delta = min(best_delta, delta);
        }
        
        if(K < S_min){
            cout << "No" << "\n";
            continue;
        }
        
        int X = K - S_min;
        if(X % 2 == 0){
            cout << "Yes" << "\n";
        } else {
            
            if(best_delta <= X)
                cout << "Yes" << "\n";
            else
                cout << "No" << "\n";
        }
    }
    return 0;
}
