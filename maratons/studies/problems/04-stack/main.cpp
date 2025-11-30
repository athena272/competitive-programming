#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> s;
    
    // Adicionar elementos (LIFO - Last In, First Out)
    s.push(10);
    s.push(20);
    s.push(30);
    // Estado: [10, 20, 30] onde 30 é o topo

    // Acessar elementos (sempre verificar se não está vazia)
    if(!s.empty()) {
        int topo = s.top();        // Elemento do topo (30)
        int tamanho = s.size();    // Tamanho (3)
        
        cout << "Topo: " << topo << endl;
        cout << "Tamanho: " << tamanho << endl;
    }

    // Remover elementos (remove sempre do topo)
    if(!s.empty()) {
        s.pop();  // Remove 30, agora top() = 20
        cout << "Após pop, topo: " << s.top() << endl;
    }

    // Processar todos os elementos (ordem reversa - do topo para base)
    cout << "Processando pilha (do topo para base): ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    // Exemplo: Verificar parênteses balanceados
    string expr = "((()))";
    stack<char> paren;
    bool balanced = true;
    
    for(char c : expr) {
        if(c == '(') {
            paren.push(c);
        }
        else if(c == ')') {
            if(paren.empty()) {
                balanced = false;
                break;
            }
            paren.pop();
        }
    }
    
    if(balanced && paren.empty()) {
        cout << "Expressão balanceada!" << endl;
    }
    else {
        cout << "Expressão não balanceada!" << endl;
    }

    return 0;
}

