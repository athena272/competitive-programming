#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    
    // Inserir elementos (automaticamente ordena e remove duplicatas)
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10);  // Ignorado (duplicata)
    // Resultado: s = {10, 20, 30} (ordenado)
    
    // Informações
    cout << "Tamanho: " << s.size() << endl;
    cout << "Menor elemento: " << *s.begin() << endl;
    cout << "Maior elemento: " << *s.rbegin() << endl;
    
    // Verificar existência
    if(s.count(20)) {
        cout << "20 está no set" << endl;
    }
    
    // Usar find()
    auto it = s.find(10);
    if(it != s.end()) {
        cout << "Encontrado: " << *it << endl;
    }
    
    // Iterar (ordem crescente)
    cout << "Elementos (ordenados): ";
    for(int x : s) {
        cout << x << " ";  // 10 20 30
    }
    cout << endl;
    
    // Exemplo: Remover duplicatas de vetor
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    set<int> unicos(arr.begin(), arr.end());
    
    cout << "\nElementos únicos do vetor: ";
    for(int x : unicos) {
        cout << x << " ";  // 1 2 3 4 5 6 9
    }
    cout << endl;
    
    // Lower bound e Upper bound
    set<int> nums = {10, 20, 30, 40, 50};
    
    // Primeiro elemento >= 25
    auto lb = nums.lower_bound(25);
    if(lb != nums.end()) {
        cout << "Primeiro elemento >= 25: " << *lb << endl;  // 30
    }
    
    // Primeiro elemento > 30
    auto ub = nums.upper_bound(30);
    if(ub != nums.end()) {
        cout << "Primeiro elemento > 30: " << *ub << endl;  // 40
    }
    
    // Remover elemento
    s.erase(20);
    cout << "\nApós remover 20, tamanho: " << s.size() << endl;
    
    return 0;
}

