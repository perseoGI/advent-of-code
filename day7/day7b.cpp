#include <bits/stdc++.h>
#include <climits>
using namespace std;

vector<uint64_t> split(string s, string del = " ") {
    vector<uint64_t> v;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        v.push_back(atoi(s.substr(start, end - start).c_str()));
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back((uint64_t)atoi(s.substr(start, end - start).c_str()));
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream f("day7.input");
    char sep;

    string line;
    vector<uint64_t> input;
    while (getline(f, line)) {
        for (auto &n : split(line, ",")) {
            input.push_back(n);
        }
    }

    auto compute = [](uint64_t n) -> uint64_t { return n * (n + 1) >> 1; };

    uint64_t minSum = INT_MAX;

    for (int m = *min_element(input.begin(), input.end());
         m < *max_element(input.begin(), input.end()); ++m) {

        minSum = min(
            minSum, accumulate(input.begin(), input.end(), (uint64_t)0,
                               [m, compute](uint64_t acc, uint64_t curr) {
                                   return acc + compute(curr > m ? curr - m
                                                                  : m - curr);
                               }));
    }

    cout << minSum << endl;

    return 0;
}
