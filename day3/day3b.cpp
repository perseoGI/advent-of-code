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
  vector<long long> nums;
  long long num;
  string line;

  while (f >> line)
    nums.push_back(stoi(line, 0, 2));

  int N = line.size();
  vector<long long> oxygen = nums, co2 = nums;

  for (int b = 0; b < N; ++b){
    auto getOnes = [N,b](const long long &val) -> bool{
      return val >> (N - b - 1) & 1;
    };
    auto getZeros = [N,b](const long long &val) -> bool{
      return !(val >> (N - b - 1) & 1);
    };


    int nOnes = count_if(oxygen.begin(), oxygen.end(), getOnes);
    int nZeros = count_if(co2.begin(), co2.end(), getZeros);

    if (oxygen.size() > 1){
      if (nOnes >= (oxygen.size() - nOnes))
        oxygen.erase(remove_if(oxygen.begin(), oxygen.end(), getZeros), oxygen.end());
      else oxygen.erase(remove_if(oxygen.begin(), oxygen.end(), getOnes), oxygen.end());
    }

    if(co2.size() > 1){
      if (nZeros <= (co2.size() - nZeros))
        co2.erase(remove_if(co2.begin(), co2.end(), getOnes), co2.end());
      else
        co2.erase(remove_if(co2.begin(), co2.end(), getZeros), co2.end());
    }
  }

  cout << (oxygen.front() * co2.front()) << endl;
  return 0;
}
