#include <bits/stdc++.h>
using namespace std;

#define PRINT_ARR(arr, len) for(int i = 0; i < len; ++i)  cout << arr[i] << " "; cout << std::endl;
#define PRINT_MAT(mat, len) for(int i = 0; i < len; ++i) { for(int j = 0; j < len; ++j) cout << mat[i][j]<< ","; cout << endl; }
#define PRINT_VEC(vec) {for(auto elem : vec)  cout << elem << " "; cout << endl;}
#define PRINT_VEC2(vec2) for(auto vec : vec2)  PRINT_VEC(vec);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ifstream f("day3.input");
  string line;
  f >> line;
  int N = line.size();
  vector<int> arr(N);
  do {
    for (int b = 0; b < N; ++b)
      arr[b] += (line[b] == '0'? -1 : 1);
  } while(f >> line);

  int gamma = 0, epsilon = 0;
  for (int b = 0; b < N; ++b){
    if (arr[b] > 0)
      gamma |= 1 << (N - b - 1);
    else
      epsilon |= 1 << (N - b - 1);
  }
  cout << (gamma * epsilon) << endl;

  return 0;
}
