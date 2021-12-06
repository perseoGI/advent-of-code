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

  ifstream f("");
  uint64_t timer;
  char sep;

  string line;
  while(getline(f, line)){
      for (auto &n : split(line, ",")){

      }
  }

  return 0;
}
