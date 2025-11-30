#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int> line;
    
    // Adicionar elementos (FIFO - First In, First Out)
    line.push(4);
    line.push(7);
    line.push(9);
    // Estado: [4, 7, 9] onde 4 é o front e 9 é o back

    // Acessar elementos (sempre verificar se não está vazia)
    if(!line.empty()) {
        int firstElement = line.front();  // Primeiro elemento (4)
        int lastElement = line.back();    // Último elemento (9)
        int length = line.size();         // Tamanho (3)
        
        cout << "Primeiro: " << firstElement << endl;
        cout << "Último: " << lastElement << endl;
        cout << "Tamanho: " << length << endl;
    }

    // Remover elementos (remove sempre o primeiro)
    if(!line.empty()) {
        line.pop();  // Remove 4, agora front() = 7
        cout << "Após pop, primeiro: " << line.front() << endl;
    }

    // Processar todos os elementos
    cout << "Processando fila: ";
    while(!line.empty()) {
        cout << line.front() << " ";
        line.pop();
    }
    cout << endl;

    return 0;
}