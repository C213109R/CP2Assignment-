#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_TIME = 10005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> songs(n);
    for (int i = 0; i < n; ++i)
        cin >> songs[i];

    // DP table: dp[time] = max number of songs used to reach that time
    vector<int> dp(MAX_TIME, -1);
    vector<int> track(MAX_TIME, 0);  // track number of songs used
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = t - 1 - songs[i]; j >= 0; --j) {
            if (dp[j] != -1 && dp[j + songs[i]] < dp[j] + 1) {
                dp[j + songs[i]] = dp[j] + 1;
                track[j + songs[i]] = max(track[j + songs[i]], dp[j + songs[i]]);
            }
        }
    }

    int maxSongs = 0, maxTime = 0;
    for (int i = 0; i <= t - 1; ++i) {
        if (dp[i] > maxSongs || (dp[i] == maxSongs && i > maxTime)) {
            maxSongs = dp[i];
            maxTime = i;
        }
    }

    // +1 for the final fixed song
    cout << maxSongs + 1 << " " << maxTime + 678 << "\n";

    return 0;
}