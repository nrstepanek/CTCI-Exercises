
#include <iostream>
#include <string>

using namespace std;

string compress(string toCompress) {
    string compressed = "";
    char lastChar = ' ';
    int count = 0;
    
    for (char& c : toCompress) {
        if (c == lastChar)
            count++;
        else {
            if (lastChar != ' ') {
                compressed += lastChar;
                compressed += to_string(count);
            }
            lastChar = c;
            count = 1;
        }
    }

    compressed += lastChar;
    compressed += to_string(count);

    if (compressed.size() < toCompress.size())
        return compressed;
    return toCompress;
}

int main() {
    string ex1 = "aabbbcccccaaa";
    string ex2 = "aabcddhijjjk";
    cout << compress(ex1) << endl;
    cout << compress(ex2) << endl;
    return 0;
}
