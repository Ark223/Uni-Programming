#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

void AddToFile(vector<int> a, ofstream &file) {
    stringstream s;
    copy(a.begin(), a.end(), ostream_iterator<int>(s, " "));
    file << s.str() << endl;
}

vector<int> AlmostSorted(vector<int> &a) {
    vector<int> b;
    b.assign(a.begin(), a.end());
    int c = ceil(0.05 * b.size());
    for (int i = 0; i < c; i++) {
        int r1 = rand() % (b.size() - 1) + 1,
            r2 = rand() % (b.size() - 1) + 1;
        int temp = b[r1];
        b[r1] = b[r2];
        b[r2] = temp;
    }
    return b;
}

vector<int> Generate(int n) {
    vector<int> a;
    for (int i = 1; i <= n; i++)
        a.push_back(i);
    return a;
}

void Reverse(vector<int> &a) {
    reverse(a.begin(), a.end());
}

void Shuffle(vector<int> &a) {
    random_shuffle(a.begin(), a.end());
}

template <class T>
string to_string(T t) {
    stringstream s; s << t;
    return s.str();
}

int main() {
    srand(time(NULL));
    int nums[10] = {1000, 2000, 3000, 5000,
        7500, 10000, 20000, 30000, 40000, 50000};
    for (int i = 0; i < 10; i++) {
        ofstream file;
        string path = to_string(nums[i]) + ".txt";
        file.open(path.c_str(), ios_base::app);
        vector<int> a = Generate(nums[i]);
        AddToFile(AlmostSorted(a), file);
        Reverse(a); AddToFile(a, file);
        Shuffle(a); AddToFile(a, file);
        file.close();
    }
    return 0;
}
