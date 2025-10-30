#include <iostream> 
#include <string> 
#include <cctype> 
using namespace std; 
#define SIZE 1000  
char stk[SIZE]; 
int top = -1; 
 
void push(char c) { 
    if (top < SIZE - 1) stk[++top] = c; 
} 
 
char pop() { 
    return (top != -1) ? stk[top--] : '\0'; 
} 
 
char peek() { 
    return (top != -1) ? stk[top] : '\0'; 
} 
 
bool empty() { 
    return top == -1; 
} 
 
int prec(char op) { 
    if (op == '+' || op == '-') return 1; 
    if (op == '*' || op == '/') return 2; 
    if (op == '^') return 3; 
    return 0;  
} 
 
void convert() { 
    string infix; 
    cout << "Enter infix: "; 
    getline(cin, infix); 
 
    string postfix = ""; 
 
    for (char c : infix) { 
        if (isalnum(c)) { 
            postfix += c; 
        } else if (c == '(') { 
            push(c); 
        } else if (c == ')') { 
            while (!empty() && peek() != '(') { 
                postfix += pop(); 
            } 
            if (!empty() && peek() == '(') pop();  
        } else {  
            while (!empty() && prec(c) <= prec(peek())) { 
                postfix += pop(); 
} 
push(c); 
} 
} 
while (!empty()) { 
char op = pop(); 
if (op != '(' && op != ')') { 
postfix += op; 
} 
} 
cout << "Postfix: " << postfix << "\n"; 
} 
int main() { 
convert(); 
return 0; 
} 
