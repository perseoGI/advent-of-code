#include <bits/stdc++.h>
using namespace std;

#define PRINT_ARR(arr, len) for(int i = 0; i < len; ++i)  cout << arr[i] << " "; cout << std::endl;
#define PRINT_MAT(mat, len) for(int i = 0; i < len; ++i) { for(int j = 0; j < len; ++j) cout << mat[i][j]<< ","; cout << endl; }
#define PRINT_VEC(vec) {for(auto elem : vec)  cout << elem << " "; cout << endl;}
#define PRINT_VEC2(vec2) for(auto vec : vec2)  PRINT_VEC(vec);

vector<uint64_t> split(string s, string del=" ") {
    vector<uint64_t> v;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        v.push_back(atoi(s.substr(start, end-start).c_str()));
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back((uint64_t)atoi(s.substr(start, end-start).c_str()));
    return v;
}


int  main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ifstream f("day7.input");
  char sep;

  string line;
  vector<int> input;
  while(getline(f, line)){
      for (auto &n : split(line, ",")){
        input.push_back(n);
      }
  }
  sort(input.begin(), input.end());
  int n = input.size();
  int l = 0;
  int r = n - 1;
  int m = (l+r)>> 1;
  int m0 = input[m], m1 = input[m + 1], m2 = input[m - 1];
  int minSum = min(accumulate(input.begin(), input.end(), 0, [m0](int acc, int curr){ return acc + abs(curr - m0);}),
              min(accumulate(input.begin(), input.end(), 0, [m1](int acc, int curr){ return acc + abs(curr - m1);}),
              accumulate(input.begin(), input.end(), 0, [m2](int acc, int curr){ return acc + abs(curr - m2);} )));

  cout << minSum << endl;
  return 0;
}
