#include <bits/stdc++.h>
using namespace std;

bool isAdjacent(int x, int y) {
    return (std::abs(x - y) == 1);
}

bool canBecomeAdjacent(int p1, int p2, int q1, int q2) {
    if (isAdjacent(q1, p2) && isAdjacent(p1, q2)) return true;
    if (isAdjacent(q2, p2) && isAdjacent(p1, q1)) return true;
    if (isAdjacent(p1, q1) && isAdjacent(p2, q2)) return true;
    if (isAdjacent(p1, q2) && isAdjacent(p2, q1)) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> a(2 * N);
        for (int i = 0; i < 2 * N; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> positions(N + 1, {-1, -1});
        for (int i = 0; i < 2 * N; i++) {
            int label = a[i];
            if (positions[label].first == -1) positions[label].first = i;
            else positions[label].second = i;
        }

        long long answer = 0LL;

        for (int a = 1; a <= N; a++) {
            int p1 = positions[a].first, p2 = positions[a].second;
            if (p2 == p1 + 1) continue;

            for (int b = a + 1; b <= N; b++) {
                int q1 = positions[b].first, q2 = positions[b].second;
                if (q2 == q1 + 1) continue;

                if (canBecomeAdjacent(p1, p2, q1, q2)) {
                    answer++;
                }
            }
        }

        cout << answer << "\n";
    }
    return 0;
}
