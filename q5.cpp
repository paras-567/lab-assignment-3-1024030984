#include <iostream> 
#include <string> 
#include <cmath>  
#include <cctype> 
using namespace std; 
 
#define SIZE 1000  
 
double stk[SIZE]; 
int top = -1; 
 
void push(double v) { 
    if (top < SIZE - 1) stk[++top] = v; 
} 
 
double pop() { 
    return (top != -1) ? stk[top--] : 0.0; 
} 
 
bool empty() { 
    return top == -1; 
} 
 
double applyOp(double op2, double op1, char op) { 
    switch (op) { 
        case '+': return op1 + op2; 
        case '-': return op1 - op2; 
        case '*': return op1 * op2; 
        case '/':  
            if (op2 == 0) { 
                cout << "Error: Div by zero\n"; 
                exit(1); 
            } 
            return op1 / op2; 
        case '^': return pow(op1, op2); 
        default: return 0.0; 
    } 
} 
 
void evaluate() { 
    string postfix; 
    cout << "Enter postfix (single digits): "; 
    getline(cin, postfix); 
 
    for (char c : postfix) { 
        if (isdigit(c)) { 
            push(c - '0');  
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') { 
            if (empty()) { 
                cout << "Error: Too many ops\n"; 
                return; 
            } 
            double op2 = pop(); 
            if (empty()) { 
            cout << "Error: Too many ops\n"; 
            return; 
            } 
            double op1 = pop(); 
            push(applyOp(op2, op1, c)); 
      } 
  } 
  if (!empty() && top == 0) { 
  cout << "Result: " << pop() << "\n"; 
  } else { 
  cout << "Error: Too many operands\n"; 
  } 
} 
int main() { 
  evaluate(); 
  return 0; 
}
