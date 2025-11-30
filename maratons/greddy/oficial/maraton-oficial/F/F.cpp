#include <bits/stdc++.h>
#include <cmath>
#define ll long long

using namespace std;

int main()
{
    ll num_estudantes, guiches, min_atend;
    cin >> num_estudantes >> guiches >> min_atend;
    ll estudantes_atendidos = 0;
    if(num_estudantes % guiches == 0)
    {
        estudantes_atendidos = num_estudantes / guiches;
    }
    else 
    {
        estudantes_atendidos = (num_estudantes / guiches) + 1;
    }
    
    ll tempo = estudantes_atendidos * min_atend;
    cout << tempo << endl;
    return 0;
}