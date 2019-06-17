
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isPermutation(string a, string b) {
    if (a.size() != b.size())
        return false;

    // Also possible to use int[256] for counting instead of maps.
    unordered_map<char, int> aChars;
    unordered_map<char, int> bChars;

    for (int i = 0; i < a.size(); i++) {
        if (aChars.find(a[i]) == aChars.end()) {
            aChars[a[i]] = 1;
        }
        else {
            aChars[a[i]]++;
        }
        if (bChars.find(b[i]) == bChars.end()) {
            bChars[b[i]] = 1;
        }
        else {
            bChars[b[i]]++;
        }
    }

    for (auto element : aChars) {
        if (aChars[element.first] != bChars[element.first])
            return false;
    }

    return true;
}

bool isPermutation2(string a, string b) {
    if (a.size() != b.size())
        return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            return false;
    }

    return true;
}

int main()
{
    cout << isPermutation("abcrderfizzz", "zibczefdazrr") << endl;
    cout << isPermutation("abcrderfizzz", "ziblzefdazrr") << endl;

    cout << isPermutation2("abcrderfizzz", "zibczefdazrr") << endl;
    cout << isPermutation2("abcrderfizzz", "ziblzefdazrr") << endl;

    return 0;
}
