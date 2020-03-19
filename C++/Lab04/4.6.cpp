#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string multiplyers = "13791379131";

int main() {
    vector<int> nums;
    int a, b, c;
    cout << "Podaj pesel: " << endl;
    cin >> a;
    b = a;
    while (b > 0) {
        nums.push_back(b % 10);
        b /= 10;
    }
    reverse(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
        c += nums[i] * (int)multiplyers[i];
    int res = c % 10;
    cout << "Podany pesel" << ((res != 0) ?
        " nie" : "") << " jest prawidlowy";
    return 0;
}
