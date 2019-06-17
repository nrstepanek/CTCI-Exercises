
#include <bitset>
#include <iostream>
#include <locale>
#include <string>

using namespace std;

// Only handles alpha-numeric and spaces, could be extended for more.
bool permPalindrome(string s) {
    int counts[256] = {0};
    int actualLength = 0;
    for (char& c : s) {
        if (c != ' ') {
            counts[(int) tolower(c)]++;
            actualLength++;
        }
    }

    int oddCount = 0;
    for (int count : counts) {
        if (count % 2 == 1)
            oddCount++;
    }

    return actualLength % 2 == oddCount;
}

// Uses a bitset instead of an array of ints.
bool permPalindrome2(string s) {
    bitset<256> bits;
    int actualLength = 0;
    for (char& c : s) {
        if (c != ' ') {
            bits.flip((int) tolower(c));
            actualLength++;
        }
    }

    return bits.count() == actualLength % 2;
}

int main() {
    cout << permPalindrome("tact coa") << endl;
    cout << permPalindrome2("tact coa") << endl;

    return 0;
}
