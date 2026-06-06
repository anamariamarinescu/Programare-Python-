#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");

    if (!in.is_open() || !out.is_open()) {
        cout << "Unable to open input or output file." << endl;
        return 1;
    }

    int t, k, n;
    in >> t >> k >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        in >> numbers[i];
    }

    int count = 0;
    for (int i = 0; i <= n - k; ++i) {
        bool valid_sequence = true;
        for (int j = i; j < i + k; ++j) {
            if (numbers[j] > t) {
                valid_sequence = false;
                break;
            }
        }
        if (valid_sequence) {
            ++count;
        }
    }

    out << count << endl;

    in.close();
    out.close();

    return 0;
}