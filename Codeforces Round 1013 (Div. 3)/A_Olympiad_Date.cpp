#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int len;
        cin >> len;
        vector<int> date = {0, 0, 0, 1, 2, 2, 3, 5};
        bool found = false;

        for (int i = 0; i < len; i++) {
            int ele;
            cin >> ele;
            auto it = find(date.begin(), date.end(), ele);
            if (it != date.end()) {
                date.erase(it);
            }
            if (date.empty() && !found) {
                cout << i + 1 << endl;
                found = true;
            }
        }
        if (!found) cout << 0 << endl;
    }

    return 0;
}
