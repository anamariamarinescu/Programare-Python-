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

    int n;
    in >> n;
    
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        in >> numbers[i];
    }

    int max_length = 0;
    int start_index = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (numbers[i] % 2 != numbers[i+1] % 2) {
            int length = 1;
            int j = i;
            while (j < n - 1 && numbers[j] % 2 != numbers[j+1] % 2) {
                ++length;
                ++j;
            }
            if (length > max_length) {
                max_length = length;
                start_index = i;
            }
        }
    }

    for (int i = start_index; i < start_index + max_length; ++i) {
        out << numbers[i] << " ";
    }
    out << endl;

    in.close();
    out.close();

    return 0;
}
