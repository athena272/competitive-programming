#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>

using namespace std;

int main()
{
    ll N;
    cin >> N;
    vll numbers(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    
    for (ll i = 0; i < N; i++)
    {
        ll num = numbers[i];
        bool ehPrimo = true;
        
        if (num <= 1)
        {
            ehPrimo = false;
        }
        else if (num == 2)
        {
            ehPrimo = true;
        }
        else if (num % 2 == 0)
        {
            ehPrimo = false;
        }
        else
        {
            for (ll j = 3; j * j <= num; j += 2)
            {
                if (num % j == 0)
                {
                    ehPrimo = false;
                    break;
                }
            }
        }
        
        if (ehPrimo)
        {
            cout << num << " eh primo\n";
        }
        else
        {
            cout << num << " nao eh primo\n";
        }
    }

    return 0;
}