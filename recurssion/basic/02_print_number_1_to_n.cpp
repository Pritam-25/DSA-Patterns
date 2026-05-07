#include<iostream>
using namespace std;

void f(int count, int n) {
    if (n == count)return;
    cout << count + 1 << endl;
    f(count + 1, n);
}

void f_Reverse(int count, int n) {
    if (n == count)return;
    f_Reverse(count + 1, n);
    cout << count + 1 << endl;
}



int main() {
    f(0, 5);
    cout << "---------------------" << endl;
    f_Reverse(0, 5);
    return 0;
}