#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>

using namespace std;

int main()
{
    vll numbers(10);
    for (ll i = 0; i < 10; i++)
    {
        cin >> numbers[i];
    }

    vll array_respota = {1, 2, 3, 4};
    ll total = 4;
    for (ll i = 0; i < 10; i++)
    {
        if(numbers[i] == array_respota[0])
        {
            total--;
            array_respota[0] = 5;
        }
        if(numbers[i] == array_respota[1])
        {
            total--;
            array_respota[1] = 5;
        }
        if(numbers[i] == array_respota[2])
        {
            total--;
            array_respota[2] = 5;
        }
        if(numbers[i] == array_respota[3])
        {
            total--;
            array_respota[3] = 5;
        }
    }
    
    cout << total << endl;
}

