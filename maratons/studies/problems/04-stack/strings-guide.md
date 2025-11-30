# Guia Completo de Strings em C++ para Programação Competitiva

## 📚 O que são Strings?

Uma **string** em C++ é uma sequência de caracteres. Em C++ moderno, usamos principalmente a classe `string` da biblioteca padrão, que é muito mais fácil de usar que arrays de `char` do C.

## 🔧 Declaração e Inicialização

### Declaração Básica

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaração vazia
    string s1;
    
    // Inicialização com valor
    string s2 = "Hello";
    string s3("World");
    
    // Inicialização com múltiplas cópias
    string s4(5, 'a');  // "aaaaa"
    
    // Cópia de outra string
    string s5 = s2;  // s5 = "Hello"
    
    return 0;
}
```

### Leitura de Strings

```cpp
string s;

// Lê até encontrar espaço ou quebra de linha
cin >> s;

// Lê linha completa (incluindo espaços)
getline(cin, s);

// Lê linha completa após usar cin (limpa o buffer)
cin.ignore();
getline(cin, s);

// Lê múltiplas linhas até EOF
while (getline(cin, s)) {
    // Processa cada linha
}
```

## 🔍 Operações Básicas

### Acesso a Caracteres

```cpp
string s = "Hello";

// Acesso por índice (como array)
char c1 = s[0];      // 'H'
char c2 = s[1];      // 'e'

// Método at() (com verificação de limites)
char c3 = s.at(0);   // 'H'
// s.at(10);  // Lança exceção se índice inválido

// Primeiro e último caractere
char first = s.front();  // 'H'
char last = s.back();    // 'o'
```

### Tamanho e Capacidade

```cpp
string s = "Hello";

int len = s.length();    // 5
int size = s.size();     // 5 (mesmo que length)
bool empty = s.empty();  // false

// Redimensionar
s.resize(10);           // Aumenta para 10 caracteres
s.resize(3);            // Reduz para 3 caracteres ("Hel")
s.resize(10, 'x');      // Redimensiona preenchendo com 'x'
```

### Concatenação

```cpp
string s1 = "Hello";
string s2 = "World";

// Operador +
string s3 = s1 + " " + s2;  // "Hello World"
s1 += "!";                   // s1 agora é "Hello!"

// Método append()
s1.append(" World");         // "Hello! World"
```

## 🔄 Modificação de Strings

### Inserção e Remoção

```cpp
string s = "Hello";

// Inserir
s.insert(5, " World");      // "Hello World"
s.insert(0, "Say ");        // "Say Hello World"

// Remover
s.erase(0, 4);              // Remove 4 caracteres a partir do índice 0
s.erase(5);                 // Remove do índice 5 até o fim
s.erase(s.begin() + 2);     // Remove caractere no índice 2

// Substituir
s.replace(0, 3, "Hi");      // Substitui 3 caracteres a partir de 0 por "Hi"
```

### Limpar e Resetar

```cpp
string s = "Hello";

s.clear();      // Remove todos os caracteres (s fica vazia)
s = "";         // Mesmo efeito
```

## 🔎 Busca e Encontrar

### Encontrar Substrings

```cpp
string s = "Hello World Hello";

// find() - retorna posição ou string::npos se não encontrar
size_t pos = s.find("World");     // 6
pos = s.find("xyz");              // string::npos (não encontrado)

// Verificar se encontrou
if (pos != string::npos) {
    cout << "Encontrado na posição " << pos << endl;
}

// find() a partir de uma posição
pos = s.find("Hello", 1);         // Procura "Hello" a partir do índice 1

// rfind() - busca da direita para esquerda
pos = s.rfind("Hello");           // 12 (última ocorrência)

// find_first_of() - encontra primeiro caractere que está no conjunto
pos = s.find_first_of("aeiou");   // 1 (primeira vogal 'e')

// find_last_of() - encontra último caractere que está no conjunto
pos = s.find_last_of("aeiou");    // 8 (última vogal 'o')
```

### Contar Ocorrências

```cpp
string s = "Hello World Hello";
string target = "Hello";
int count = 0;
size_t pos = 0;

while ((pos = s.find(target, pos)) != string::npos) {
    count++;
    pos += target.length();
}
cout << count << endl;  // 2
```

## ✂️ Extração de Substrings

```cpp
string s = "Hello World";

// substr() - extrai substring
string sub1 = s.substr(0, 5);     // "Hello" (5 caracteres a partir de 0)
string sub2 = s.substr(6);        // "World" (do índice 6 até o fim)
string sub3 = s.substr(6, 3);     // "Wor" (3 caracteres a partir de 6)
```

## 🔤 Comparação de Strings

```cpp
string s1 = "abc";
string s2 = "abc";
string s3 = "def";

// Operadores de comparação
bool eq = (s1 == s2);      // true
bool ne = (s1 != s3);      // true
bool lt = (s1 < s3);       // true (ordem lexicográfica)
bool gt = (s1 > s3);       // false

// compare() - retorna 0 se iguais, <0 se s1 < s2, >0 se s1 > s2
int result = s1.compare(s2);  // 0
result = s1.compare(s3);      // negativo
result = s1.compare(0, 2, s2, 0, 2);  // Compara substrings
```

## 🔄 Transformações

### Conversão de Case

```cpp
string s = "Hello World";

// Para minúsculas (requer <algorithm>)
transform(s.begin(), s.end(), s.begin(), ::tolower);
// ou manualmente
for (char &c : s) {
    c = tolower(c);
}

// Para maiúsculas
transform(s.begin(), s.end(), s.begin(), ::toupper);
// ou manualmente
for (char &c : s) {
    c = toupper(c);
}
```

### Reverter String

```cpp
string s = "Hello";

reverse(s.begin(), s.end());  // s agora é "olleH"
```

### Ordenar Caracteres

```cpp
string s = "hello";

sort(s.begin(), s.end());  // "ehllo"
```

## 🔢 Conversões

### String para Número

```cpp
string s = "123";

// stoi() - string para int
int num = stoi(s);

// stol() - string para long
long l = stol(s);

// stoll() - string para long long
long long ll = stoll(s);

// stof() - string para float
float f = stof("3.14");

// stod() - string para double
double d = stod("3.14159");

// Com base (ex: binário)
int binary = stoi("1010", nullptr, 2);  // 10
```

### Número para String

```cpp
int num = 123;

// to_string()
string s = to_string(num);  // "123"

// Com formatação (usando stringstream)
#include <sstream>
stringstream ss;
ss << fixed << setprecision(2) << 3.14159;
string s = ss.str();  // "3.14"
```

## 🔍 Iteração sobre Strings

```cpp
string s = "Hello";

// Loop tradicional
for (int i = 0; i < s.length(); i++) {
    cout << s[i];
}

// Range-based for loop (C++11)
for (char c : s) {
    cout << c;
}

// Com referência (para modificar)
for (char &c : s) {
    c = toupper(c);
}

// Iteradores
for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it;
}
```

## 🧹 Limpeza e Processamento

### Remover Espaços

```cpp
string s = "  Hello World  ";

// Remover espaços do início e fim
s.erase(0, s.find_first_not_of(" \t"));
s.erase(s.find_last_not_of(" \t") + 1);

// Remover todos os espaços
s.erase(remove(s.begin(), s.end(), ' '), s.end());
```

### Dividir String (Split)

```cpp
string s = "Hello,World,Test";
vector<string> tokens;
stringstream ss(s);
string token;

while (getline(ss, token, ',')) {
    tokens.push_back(token);
}
// tokens = {"Hello", "World", "Test"}
```

### Remover Caracteres Específicos

```cpp
string s = "Hello123World";

// Remover dígitos
s.erase(remove_if(s.begin(), s.end(), ::isdigit), s.end());
// s = "HelloWorld"

// Remover não-alfanuméricos
s.erase(remove_if(s.begin(), s.end(), 
    [](char c) { return !isalnum(c); }), s.end());
```

## 📊 Operações Úteis para Competição

### Verificar se é Palíndromo

```cpp
string s = "racecar";
string reversed = s;
reverse(reversed.begin(), reversed.end());
bool isPalindrome = (s == reversed);
```

### Contar Caracteres

```cpp
string s = "hello";
map<char, int> count;

for (char c : s) {
    count[c]++;
}
// count['h'] = 1, count['e'] = 1, count['l'] = 2, etc.
```

### Verificar Prefixo/Sufixo

```cpp
string s = "Hello World";

// Verificar prefixo
bool hasPrefix = (s.substr(0, 5) == "Hello");

// Verificar sufixo
bool hasSuffix = (s.substr(s.length() - 5) == "World");

// Usando compare()
bool hasPrefix2 = (s.compare(0, 5, "Hello") == 0);
```

## 🎯 Exemplos Práticos

### Exemplo 1: Processar Múltiplas Linhas

```cpp
string line;
while (getline(cin, line)) {
    // Processa cada linha
    cout << "Linha: " << line << endl;
}
```

### Exemplo 2: Contar Palavras

```cpp
string s = "Hello World Test";
stringstream ss(s);
string word;
int count = 0;

while (ss >> word) {
    count++;
}
cout << count << endl;  // 3
```

### Exemplo 3: Substituir Todas as Ocorrências

```cpp
string s = "Hello Hello World";
string oldStr = "Hello";
string newStr = "Hi";
size_t pos = 0;

while ((pos = s.find(oldStr, pos)) != string::npos) {
    s.replace(pos, oldStr.length(), newStr);
    pos += newStr.length();
}
// s = "Hi Hi World"
```

### Exemplo 4: Verificar se String Contém Apenas Dígitos

```cpp
string s = "12345";
bool isNumeric = all_of(s.begin(), s.end(), ::isdigit);
```

## ⚠️ Dicas Importantes

1. **string::npos**: É o maior valor possível para `size_t`, usado para indicar "não encontrado"
2. **Índices**: Sempre verifique se o índice é válido antes de acessar
3. **Performance**: `string` é eficiente para a maioria dos casos, mas para operações muito frequentes, considere usar `string_view` (C++17)
4. **Espaços**: `cin >> s` para na primeira espaço, use `getline()` para ler linha completa
5. **Buffer**: Após usar `cin >>`, use `cin.ignore()` antes de `getline()` para limpar o buffer

## 📚 Referência Rápida

| Operação | Sintaxe |
|----------|---------|
| Tamanho | `s.length()` ou `s.size()` |
| Vazia? | `s.empty()` |
| Acesso | `s[i]` ou `s.at(i)` |
| Concatenação | `s1 + s2` ou `s1 += s2` |
| Buscar | `s.find("sub")` |
| Substring | `s.substr(pos, len)` |
| Inserir | `s.insert(pos, "text")` |
| Remover | `s.erase(pos, len)` |
| Substituir | `s.replace(pos, len, "new")` |
| Reverter | `reverse(s.begin(), s.end())` |
| Ordenar | `sort(s.begin(), s.end())` |
