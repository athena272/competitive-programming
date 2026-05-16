#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    double delta = static_cast<double>(b) * b - 4.0 * a * c;
    double x1 = (-b + sqrt(delta)) / (2.0 * a);
    double x2 = (-b - sqrt(delta)) / (2.0 * a);

    cout << fixed << setprecision(3) << x1 << ' ' << x2 << '\n';
    return 0;
}