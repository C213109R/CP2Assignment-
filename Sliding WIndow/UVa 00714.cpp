#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> books;

// Check if it's possible to partition books such that
// no scribe gets more than 'maxPages' pages.
bool isPossible(long long maxPages) {
    int scribes = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; ++i) {
        if (books[i] > maxPages)
            return false;  // A single book exceeds maxPages, not possible

        if (currentSum + books[i] > maxPages) {
            ++scribes;
            currentSum = books[i];
        } else {
            currentSum += books[i];
        }
    }

    return scribes <= k;
}

// Function to actually print the partition based on limit
void printPartition(long long maxPages) {
    vector<pair<int, bool>> result(n);  // (page, isSeparator)
    int count = k;
    long long currentSum = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (currentSum + books[i] > maxPages || i + 1 < count) {
            result[i].second = true;  // Mark separator
            currentSum = books[i];
            --count;
        } else {
            currentSum += books[i];
        }
        result[i].first = books[i];
    }

    // Print with '/' for separators
    for (int i = 0; i < n; ++i) {
        cout << result[i].first;
        if (result[i].second)
            cout << " /";
        if (i != n - 1)
            cout << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        books.resize(n);

        long long total = 0;
        long long maxBook = 0;
        for (int i = 0; i < n; ++i) {
            cin >> books[i];
            total += books[i];
            maxBook = max(maxBook, (long long)books[i]);
        }

        // Binary search for minimum maximum pages
        long long low = maxBook, high = total, best = total;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (isPossible(mid)) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        printPartition(best);
    }

    return 0;
}