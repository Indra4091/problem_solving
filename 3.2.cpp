#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//global variables
int digit[10] = { 0 };
int result[15] = { 0 };     //return value saved here
int save = 0;

int findSmaller(int t) {
    for (int r = 0; r < 10; r++) {
        if (digit[9 - r] == 1 && 9 - r < t) {
            return 9 - r;
        }
    }
    return -1;
}

void optimizedFunction(int ma, int mi, int length, string main) {
    int pointer = 0;
    bool resolved = true;

    for (int r = 0; r < length; r++) {
        int current = int(main[r] - '0');
        if (digit[current] == 0) {
            resolved = false;
            break;
        }
        result[r] = current;
        pointer = r;
    }

    save = pointer;
    for (int r = pointer; r >= 0; r--) {
        int current = int(main[r] - '0');

        if (resolved == false) {
            if (current <= mi) {
                resolved = false;
                if (r == 0) {
                    result[r] = -1;
                }
                else {
                    result[r] = ma;
                }
            }
            else {
                int s = findSmaller(current);
                resolved = true;
                result[r] = s;
                break;
            }
        }
    }
    return;
}

int main() {
    int test;
    cin >> test;
    for (int t = 0; t < test; t++) {
        for (int r = 0; r < 10; r++) {
            digit[r] = 0;
        }

        int length = 0;             //length of the limit
        int minimum = 10;           //smallest digit
        int maximum = -1;           //biggest digit
        string main;
        cin >> main;
        length = main.size();

        main[length - 1] = main[length - 1] - '1';

        int count;
        cin >> count;

        for (int r = 0; r < count; r++) {
            int digits;
            cin >> digits;
            digit[digits] = 1;
            minimum = min(digits, minimum);
            maximum = max(digits, maximum);
        }

        optimizedFunction(maximum, minimum, length, main);
        for (int siz = 0; siz <= save; siz++) {
            if (result[siz] == -1) {
                continue;
            }
            cout << result[siz];
        }
        for (int siz = save + 1; siz < length; siz++) {
            cout << maximum;
        }
        cout << "\n";
    }
}




