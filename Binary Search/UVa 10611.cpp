#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> chimps(n);
    for (int i = 0; i < n; ++i)
        cin >> chimps[i];

    int q;
    cin >> q;

    while (q--) {
        int height;
        cin >> height;

        // lower_bound: first >= height
        // upper_bound: first > height
        auto lower = lower_bound(chimps.begin(), chimps.end(), height);
        auto upper = upper_bound(chimps.begin(), chimps.end(), height);

        // Previous of lower_bound is the tallest shorter chimp
        if (lower == chimps.begin()) {
            cout << "X ";
        } else {
            cout << *(lower - 1) << " ";
        }

        // upper_bound is the shortest taller chimp
        if (upper == chimps.end()) {
            cout << "X\n";
        } else {
            cout << *upper << "\n";
        }
    }

    return 0;
}