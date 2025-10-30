#include <iostream> 
#include <string> 
 
using namespace std; 
 
#define M 1000  
 
char s[M]; 
int t = -1; 
 
void ps(char c) { 
    if (t < M - 1) { 
        s[++t] = c; 
    } 
} 
 
char pp() { 
    if (t != -1) { 
        return s[t--]; 
    } 
    return '\0'; 
} 
 
bool isM(char c1, char c2) { 
    return (c1 == '(' && c2 == ')') || 
           (c1 == '{' && c2 == '}') || 
           (c1 == '[' && c2 == ']'); 
} 
 
bool isB(const string& e) { 
    for (char c : e) { 
        if (c == '(' || c == '{' || c == '[') { 
            ps(c); 
        } else if (c == ')' || c == '}' || c == ']') { 
            if (t == -1) { 
                return false;  
            } 
            char o = pp(); 
            if (!isM(o, c)) { 
                return false;  
            } 
        } 
    } 
return t == -1;  
} 
int main() { 
  string e; 
  cout << "Enter expression: "; 
  getline(cin, e); 
  if (isB(e)) { 
  cout << "Result: Balanced\n"; 
  } else { 
  cout << "Result: Not Balanced\n"; 
  } 
  return 0; 
}
