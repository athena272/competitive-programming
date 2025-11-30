#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> dictionary;
    
    // Inserir elementos (chave-valor)
    dictionary["alice"] = 25;
    dictionary["bob"] = 30;
    dictionary["charlie"] = 35;
    
    // Outras formas de inserir
    dictionary.insert({"david", 40});
    dictionary.emplace("eve", 45);
    
    // Acessar elementos
    cout << "Idade de alice: " << dictionary["alice"] << endl;
    
    // ⚠️ CUIDADO: dictionary["frank"] cria elemento com valor 0!
    // Sempre verificar existência antes de acessar
    if(dictionary.count("bob")) {
        cout << "Idade de bob: " << dictionary["bob"] << endl;
    }
    
    // Usar find() para verificar e acessar
    auto it = dictionary.find("charlie");
    if(it != dictionary.end()) {
        cout << "Idade de charlie: " << it->second << endl;
    }
    
    // Iterar (ordenado por chave)
    cout << "\nTodos os elementos (ordenados por chave):" << endl;
    for(auto &[nome, idade] : dictionary) {
        cout << nome << " -> " << idade << endl;
    }
    
    // Exemplo: Contagem de frequência
    vector<int> numeros = {1, 2, 2, 3, 3, 3, 4, 4};
    map<int, int> frequencia;
    
    for(int x : numeros) {
        frequencia[x]++;  // Incrementa contador
    }
    
    cout << "\nFrequências:" << endl;
    for(auto &[numero, count] : frequencia) {
        cout << numero << " aparece " << count << " vezes" << endl;
    }
    
    // Remover elemento
    dictionary.erase("alice");
    cout << "\nApós remover alice, tamanho: " << dictionary.size() << endl;
    
    return 0;
}
