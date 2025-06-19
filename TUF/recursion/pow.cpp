// C++ Example of Head Recursion
#include <iostream>
using namespace std;

void headRecursion(int n) {
    if (n > 0) {
        headRecursion(n - 1);  // Recursive call before processing
        cout << n << " ";  // Processing after recursion
    }
}

int main() {
    headRecursion(5);
    return 0;
}