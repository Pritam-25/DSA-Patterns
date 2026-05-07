#include<iostream>
using namespace std;

void f(int count, int n) {
    if (n == count) return;
    cout << "pritam" << endl;
    f(count + 1, n);
}

int main() {
    f(0, 5);
    return 0;
}