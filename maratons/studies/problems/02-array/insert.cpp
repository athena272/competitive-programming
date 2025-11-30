#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vec(10, -1);

    cout << "Original vector" << endl;
    cout << "Size: " << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " " ;
    }
    cout << endl;

    //Insert element
    vec.insert(vec.begin(), 19);
    vec.insert(vec.begin() + 2, 20);

    cout << "New vector" << endl;
    cout << "New size: " << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " " ;
    }
    cout << endl;
    
     // Printing first element using vector begin
    cout << "Printing first element using vector begin: " << *(vec.begin()) << endl;
    
    return 0;
}