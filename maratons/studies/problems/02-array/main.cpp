#include <bits/stdc++.h>

using namespace std;

int main()
{
    // ===== FORMA 1: Usando push_back (seu código original) =====
    int n;
    cin >> n;
    vector<int> vec;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    // ===== FORMA 2: Mais eficiente - pré-alocar tamanho =====
    // vector<int> vec(n);
    // for(int i = 0; i < n; i++) {
    //     cin >> vec[i];
    // }

    // ===== OPERAÇÕES ÚTEIS =====
    
    // Acessar elementos
    if(!vec.empty()) {
        cout << "Primeiro: " << vec.front() << endl;
        cout << "Último: " << vec.back() << endl;
        cout << "Tamanho: " << vec.size() << endl;
    }

    // Ordenar
    sort(vec.begin(), vec.end());

    // Imprimir todos os elementos
    for(int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    // Buscar elemento
    int valor;
    cin >> valor;
    if(binary_search(vec.begin(), vec.end(), valor)) {
        cout << "Encontrado!" << endl;
    }

    return 0;
}