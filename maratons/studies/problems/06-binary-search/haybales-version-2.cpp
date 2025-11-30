#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>

using namespace std;

bool binary_search_exists(const vll &values, ll target)
{
    ll left = 0;
    ll right = values.size() - 1;

    while (left <= right)
    {
        ll mid = left + (right - left) / 2;

        if (values[mid] == target)
            return true;
        else if (values[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main()
{
    ll fardos_feno, querys;
    vll final_result;
    cin >> fardos_feno >> querys;
    vll fardos_feno_vector(fardos_feno);

    // fardos inputs
    for (ll i = 0; i < fardos_feno; i++)
    {
        cin >> fardos_feno_vector[i];
    }

    sort(fardos_feno_vector.begin(), fardos_feno_vector.end());

    // querys inputs
    for (ll i = 0; i < querys; i++)
    {
        ll A, B;
        ll total = 0;
        cin >> A >> B;

        ll a = lower_bound(fardos_feno_vector.begin(), fardos_feno_vector.end(), A) - fardos_feno_vector.begin();
        ll b = upper_bound(fardos_feno_vector.begin(), fardos_feno_vector.end(), B) - fardos_feno_vector.begin();
        cout << abs(b - a) << '\n';

        return 0;
    }
}