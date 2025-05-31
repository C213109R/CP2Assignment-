#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m, n || m) {
        vector<vector<int>> matrix(n, vector<int>(m));

        // Read the matrix
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> matrix[i][j];

        int q;
        cin >> q;
        while (q--) {
            int L, U;
            cin >> L >> U;

            int max_len = 0;
            for (int i = 0; i < n; ++i) {
                // Use binary search to find the first element >= L in the current row
                auto it = lower_bound(matrix[i].begin(), matrix[i].end(), L);
                int col = it - matrix[i].begin();

                for (int size = max_len; size < n && i + size < n && col + size < m; ++size) {
                    if (matrix[i + size][col + size] <= U) {
                        max_len = size + 1;
                    } else {
                        break;
                    }
                }
            }

            cout << max_len << "\n";
        }

        cout << "-\n";  // Separator after each test case
    }

    return 0;
}