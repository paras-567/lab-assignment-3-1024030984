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
 
void revS() { 
    string i; 
cout << "Enter string: "; 
getline(cin, i); 
if (i.empty()) { 
cout << "\nInput empty.\n"; 
return; 
} 
for (char c : i) { 
ps(c); 
} 
string r = ""; 
while (t != -1) { 
r += pp(); 
} 
cout << "Original: " << i << "\n"; 
cout << "Reversed: " << r << "\n"; 
} 
int main() { 
revS(); 
return 0; 
} 
