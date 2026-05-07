#include<iostream>
using namespace std;

bool checkPalindrome(int l, int r, const string& s) {
    if (l >= r) return true;
    if (tolower(s[l]) != tolower(s[r])) return false;

    return checkPalindrome(l + 1, r - 1, s);
}

int main() {
    string s = "nMADAM";
    int n = s.length();
    bool isPalindrome = checkPalindrome(0, n - 1, s);
    isPalindrome ? cout << s << " is palindrome" << endl : cout << s << " is not a palindrome" << endl;
    return 0;
}