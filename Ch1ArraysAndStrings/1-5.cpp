
#include <iostream>
#include <string>

using namespace std;

bool oneAway(string a, string b) {
    if (abs((int) (a.length() - b.length())) > 1)
        return false;

    int aCounts[256] = {0};
    int bCounts[256] = {0};
    
    for (int i = 0; i < a.length(); i++) {
        aCounts[(int) a[i]]++;
    }
    for (int i = 0; i < b.length(); i++) {
        bCounts[(int) b[i]]++;
    }

    int difference = 0;
    for (int i = 0; i < 256; i++) {
        difference += abs((int) (aCounts[i] - bCounts[i]));
    }

    // If strings are the same length, a character change results in 2 differences.
    return (a.length() == b.length() && difference <= 2) || (difference <= 1);
}

int main() {
    string str1 = "pale";
    string str2 = "ple";
    string str3 = "pales";
    string str4 = "bale";
    string str5 = "bake";

    cout << oneAway(str1, str2) << endl;
    cout << oneAway(str3, str1) << endl;
    cout << oneAway(str1, str4) << endl;
    cout << oneAway(str1, str5) << endl;

    return 0;
}
