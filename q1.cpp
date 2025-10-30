#include <iostream> 
 
#define S 5  
 
int st[S]; 
int t = -1; 
 
void push(int v) { 
    if (t < S - 1) { 
        st[++t] = v; 
        std::cout << "\nPushed: " << v << "\n"; 
    } else { 
        std::cout << "\nError: Stack full\n"; 
    } 
} 
 
bool isE() { 
    return t == -1; 
} 
 
int pop() { 
    if (!isE()) { 
        int v = st[t--]; 
        std::cout << "\nPopped: " << v << "\n"; 
        return v; 
    } else { 
        std::cout << "\nError: Stack empty\n"; 
        return -1;  
    } 
} 
 
bool isF() { 
    return t == S - 1; 
} 
 
void disp() { 
    if (isE()) { 
        std::cout << "\nStack is empty\n"; 
        return; 
    } 
    std::cout << "\nStack elements (Top -> Bottom):\n"; 
    for (int i = t; i >= 0; i--) { 
        std::cout << "| " << st[i] << " |\n"; 
    } 
    std::cout << "-------\n"; 
} 
 
int peek() { 
    if (!isE()) { 
        int v = st[t]; 
        std::cout << "\nPeek (Top element): " << v << "\n"; 
        return v; 
    } else { 
        std::cout << "\nError: Stack empty\n"; 
        return -1;  
    } 
} 
 
int main() { 
    int o; 
    int v; 
 
    while (true) { 
        std::cout << "\n--- Stack Menu ---\n"; 
        std::cout << "1. Push\n"; 
        std::cout << "2. Pop\n"; 
        std::cout << "3. Check Empty\n"; 
        std::cout << "4. Check Full\n"; 
        std::cout << "5. Display\n"; 
        std::cout << "6. Peek\n"; 
        std::cout << "0. Exit\n"; 
        std::cout << "Enter option: "; 
 
        if (!(std::cin >> o)) { 
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            o = -1; 
        } 
 
        if (o == 1) { 
            std::cout << "Enter value to push: "; 
            if (std::cin >> v) { 
                push(v); 
            } else { 
                std::cin.clear(); 
                std::cin.ignore(10000, '\n'); 
                std::cout << "\nInvalid input\n"; 
            } 
        } 
        else if (o == 2) { 
            pop(); 
        } 
        else if (o == 3) { 
            if (isE()) { 
                std::cout << "\nStack is Empty (True)\n"; 
            } else { 
                std::cout << "\nStack is Not Empty (False)\n"; 
            } 
        } 
        else if (o == 4) { 
            if (isF()) { 
                std::cout << "\nStack is Full (True)\n"; 
            } else { 
                std::cout << "\nStack is Not Full (False)\n"; 
            } 
        } 
        else if (o == 5) { 
            disp(); 
        } 
        else if (o == 6) { 
            peek(); 
        } 
        else if (o == 0) { 
            std::cout << "\nExiting program.\n"; 
            break; 
        } 
        else { 
            std::cout << "\nInvalid option. Try again.\n"; 
        } 
    } 
    return 0; 
} 
