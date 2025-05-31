#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Constants
int p, q, r, s, t, u;

// The function f(x)
double f(double x) {
    return p * exp(-x)
         + q * sin(x)
         + r * cos(x)
         + s * tan(x)
         + t * x * x
         + u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> p >> q >> r >> s >> t >> u) {
        double low = 0.0, high = 1.0;
        bool hasSolution = false;

        // Check if solution exists
        if (f(0.0) * f(1.0) > 0) {
            cout << "No solution\n";
            continue;
        }

        // Binary search
        for (int i = 0; i < 100; ++i) {  // Enough iterations for precision
            double mid = (low + high) / 2.0;
            double value = f(mid);

            if (fabs(value) < 1e-9) {
                hasSolution = true;
                low = mid;
                break;
            }

            if (f(low) * value < 0) {
                high = mid;
            } else {
                low = mid;
            }
        }

        cout << fixed << setprecision(4) << low << "\n";
    }

    return 0;
}