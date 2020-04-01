#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int getNum(string a, char b, vector<int> &c, int *max) {
    int ptr, tmp_int, a_size = a.size();
    stringstream ss;
    string tmp_str;
    for (ptr = 0; ptr < a_size; ptr++) {
        tmp_str += a[ptr];
        if (a[ptr] == b) {
            ss << tmp_str;
            ss >> tmp_int;
            if (tmp_int > *max) *max = tmp_int;  // ###
            c.push_back(tmp_int);
            tmp_str = "";
            ss.clear();
        }
    }
    ss << tmp_str;
    ss >> tmp_int;
    if (tmp_int > *max) *max = tmp_int;  // ###
    c.push_back(tmp_int);
}

int main() {
    int n;
    string input;
    vector<int> grade_arr;

    stringstream ss;
	getline(cin, input);
	ss << input;
    ss >> n;
    // cin >> n;
    // cin.ignore();
    int *ans = new int[n]();

	// cout << n << endl;

    for (int i = 0, max = 0, adjustment; i < n;
         i++, max = 0, grade_arr.clear()) {
        getline(cin, input);
        getNum(input, ' ', grade_arr, &max);
        max = max < 95 ? 95 - max : 0;
        for (int j = 0; j < grade_arr.size(); j++) {
            adjustment = grade_arr.at(j) + max;
            if (adjustment >= 55 && adjustment <= 59) *(ans + i) += 1;
        }
        // cout << *(ans + i) << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << *(ans + i) << endl;
    }

    return 0;
}
