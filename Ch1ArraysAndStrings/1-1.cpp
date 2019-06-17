
#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isUnique(string toCheck) {
    unordered_map<char, int> chars;
    for (char& c : toCheck) {
        if (chars.find(c) != chars.end())
            return false;
        chars[c] = 0;
    }

    return true;
}

bool isUnique2(string toCheck) {
    bitset<256> chars;
    for (char& c : toCheck) {
        int bit = c;
        if (chars[bit])
            return false;
        chars.set(bit);
    }

    return true;
}

int main()
{
    string good = "asdf;lkjqwerpoiuzxcvnm";
    string bad = "asdf;lkjqwerpoiuzxcvsmn";
    cout << isUnique2(good) << endl;
    cout << isUnique2(bad) << endl;
}
