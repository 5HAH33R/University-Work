#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int target_pos;
int unknown;
int fav_outcome;

void backtrack(int idx, int current_pos) {
    if (idx == unknown) {
        if (current_pos == target_pos) {
            fav_outcome++;
        }
        return;
    }

    backtrack(idx + 1, current_pos + 1);
    backtrack(idx + 1, current_pos - 1);
}

int main() {
    string normal, tocheck;
    cin >> normal;
    cin >> tocheck;

    target_pos = 0;
    for (char c : normal) {
        if (c == '+') {
            target_pos++;
        } else {
            target_pos--;
        }
    }

    int InitDist = 0;
    unknown = 0;
    for (char c : tocheck) {
        if (c == '?') {
            unknown++;
        } else {
            if (c == '+') {
                InitDist++;
            } else {
                InitDist--;
            }
        }
    }

    fav_outcome = 0;
    backtrack(0, InitDist);

    double total_outcomes = pow(2.0, unknown);
    double probability = (double)fav_outcome / total_outcomes;

    cout << fixed << setprecision(12) << probability << endl;
    return 0;
}
