
#include <iostream>

using namespace std;

char* urlify(char toEncode[], int length) {
    int numSpaces = 0;
    for (int i = 0; i < length; i++) {
        if (toEncode[i] == ' ')
            numSpaces++;
    }

    int newLength = length + 2 * numSpaces;
    char* encoded = new char[newLength];
    int oldI = 0;

    for (int i = 0; i < newLength; i++) {
        if (toEncode[oldI] != ' ') {
            encoded[i] = toEncode[oldI];
        }
        else {
            encoded[i++] = '%';
            encoded[i++] = '2';
            encoded[i] = '0';
        }

        oldI++;
    }

    return encoded;
}

int main() {
    char ex1[] = "asdf werl lkdo ";
    char ex2[] = "ow wje   woek  w ";
    char *ans1 = urlify(ex1, 15);
    char *ans2 = urlify(ex2, 17);
    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}
