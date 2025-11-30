#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>

using namespace std;

ll binary_search(const vll values, ll target)
{
    ll left = 0; 
    ll right = values.size() - 1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;

        if (values[mid] == target)
        {
            return mid;
        }
        else if (values[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
    
}

int main()
{
    // Criar array com números de 0 até 100
    vll values(101);
    for (ll i = 0; i <= 100; i++)
    {
        values[i] = i;
    }

    ll number;
    cin >> number;

    ll result = binary_search(values, number);

    if (result != -1)
    {
        cout << "Encontrado no índice: " << result << endl;
    }
    else
    {
        cout << "Não encontrado" << endl;
    }

    return 0;
}