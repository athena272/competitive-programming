#include <bits/stdc++.h>

using namespace std;

int main()
{
    int quantity, lowest, lowest_position;
    cin >> quantity;
    vector<int> vec(quantity);

    for(int i = 0; i < quantity; i++)
    {
        cin >> vec[i];
        //first iteration
        if(i == 0)
        {
            lowest = vec[i];
            lowest_position = i;
        } 
        else
        {
            if (vec[i] < lowest)
            {
                lowest = vec[i];
                lowest_position = i;
            }
        } 
    }

    cout << "Menor valor: " << lowest << endl;
    cout << "Posicao: " << lowest_position << endl;
}   