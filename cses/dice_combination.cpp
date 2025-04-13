#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll LINF = 1e18;

// Debugging
#define debug(x) cout << #x << " = " << (x) << endl;
#define print_vec(v) for (auto x : v) cout << x << " "; cout << endl;

void calculateParityBits(vector<int> &data, int m, int r) {
    for (int i = 0; i < r; i++) {
        int parityPos = (1 << i);
        int parity = 0;

        for (int j = 1; j <= m + r; j++) {
            if (j & parityPos) {
                parity ^= data[j];
            }
        }
        data[parityPos] = parity;
    }
}

void detectError(vector<int> &data, int m, int r) {
    int errorPos = 0;
    for (int i = 0; i < r; i++) {
        int parityPos = (1 << i);
        int parity = 0;

        for (int j = 1; j <= m + r; j++) {
            if (j & parityPos) {
                parity ^= data[j];
            }
        }

        if (parity) errorPos += parityPos;
    }

    if (errorPos) {
        cout << "Error at position: " << errorPos << endl;
        data[errorPos] ^= 1; 
        cout << "Corrected data: ";
        for (int i = 1; i <= m + r; i++) {
            cout << data[i];
        }
        cout << endl;
    } else {
        cout << "No error detected." << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
       #ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin); 
       freopen("output.txt","w",stdout); 
  #endif
       cout<<"Implementing hamming code for (7,4)"<<endl;
       string input;
    cout << "Enter 4-bit data (e.g., 1011): ";
    cin >> input;

    int m = 7;
    int r = 3;

    

    vi data(m + r + 1); 

    
    int j = 0;
    for (int i = 1; i <= m + r; i++) {
        if ((i & (i - 1)) == 0) continue; 
        data[i] = input[j++] - '0';
    }

    calculateParityBits(data, m, r);

    cout << "Encoded data: ";
    for (int i = 1; i <= m + r; i++) {
        cout << data[i];
    }
    cout << endl;


    int errorBit;
    cout << "Enter position to simulate error (0 for none): ";
    cin >> errorBit;
    if (errorBit != 0 && errorBit <= m + r) {
        data[errorBit] ^= 1;
    }

    detectError(data, m, r);

    
       
  #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
    return 0;
}