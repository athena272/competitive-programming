#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    string expressao;
    
    // Lê cada linha até o fim do arquivo (EOF)
    while (getline(cin, expressao)) {
        stack<char> stack_abre;
        stack<char> stack_fecha;
        
        for (int i = 0; i < expressao.size(); i++)
        {
            char ch = expressao[i];
            if (tolower(ch) == '(')
            {
                stack_abre.push('(');
            }
            else if (tolower(ch) == ')')
            {
                stack_fecha.push(')');
               if(!stack_abre.empty())
               {
                    stack_abre.pop();
                    stack_fecha.pop();
               }
            }
        }

        if(stack_abre.empty() && stack_fecha.empty())
        {
            cout << "correct" << endl;
        }
        else
        {
            cout << "incorrect" << endl;
        }
    }
    
    return 0;
}

