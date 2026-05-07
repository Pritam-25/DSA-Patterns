#include <iostream>
using namespace std;

// Parameterized recursion
void sumParameterized(int n, int sum) {
    if (n == 0) {
        cout << "Sum using parameterized recursion: " << sum << endl;
        return;
    }
    sumParameterized(n - 1, sum + n);
}

// Functional recursion
int sumFunctional(int n) {
    if (n == 0) return 0;
    return n + sumFunctional(n - 1);
}

int main() {
    int n = 5;

    sumParameterized(n, 0);

    int result = sumFunctional(n);
    cout << "Sum using functional recursion: " << result << endl;

    return 0;
}