
#include <iostream>
#include <string>

using namespace std;

bool isRotation(string s1, string s2) {
    string combined = s2 + s2;
    if (combined.find(s1) != string::npos) {
        return true;
    }

    return false;
}

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    string s3 = "erbottlezat";

    cout << isRotation(s1, s2) << endl;
    cout << isRotation(s1, s3) << endl;

    return 0;
}
