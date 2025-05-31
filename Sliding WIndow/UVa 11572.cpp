#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> snowflakes(n);
        for (int i = 0; i < n; ++i) {
            cin >> snowflakes[i];
        }

        unordered_map<int, int> lastSeen;
        int maxLen = 0, left = 0;

        for (int right = 0; right < n; ++right) {
            int current = snowflakes[right];

            // If we've seen this snowflake and it's inside the current window
            if (lastSeen.count(current) && lastSeen[current] >= left) {
                left = lastSeen[current] + 1;  // shrink the window
            }

            lastSeen[current] = right;  // update last seen position
            maxLen = max(maxLen, right - left + 1);
        }

        cout << maxLen << "\n";
    }

    return 0;
}