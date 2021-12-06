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

  ifstream f("day6.input");
  vector<unsigned int> fishes;
  unsigned int timer;
  char sep;
  while(f >> timer >> sep){
    fishes.push_back(timer);
  }
  fishes.push_back(timer);

  for (int day = 0; day < 80; ++day){
    int currentSize = fishes.size();
    for (int i = 0; i < currentSize; ++i){
      if (--fishes[i] == -1){
        fishes[i] = 6;
        fishes.push_back(8);
      }
    }
  }

  cout << fishes.size() << endl;

  return 0;
}
