#include <bits/stdc++.h>
using namespace std;

#define PRINT_ARR(arr, len) for(int i = 0; i < len; ++i)  cout << arr[i] << " "; cout << std::endl;
#define PRINT_MAT(mat, len) for(int i = 0; i < len; ++i) { for(int j = 0; j < len; ++j) cout << mat[i][j]<< ","; cout << endl; }
#define PRINT_VEC(vec) {for(auto elem : vec)  cout << elem << " "; cout << endl;}
#define PRINT_VEC2(vec2) for(auto vec : vec2)  PRINT_VEC(vec);

#define F(n) for(int i = 0; i < (n); ++i)
#define FI(i,a,n) for(int i=(a);i<=(n);++i)
#define FD(i,a,b) for(int i=(a);i>=(b);--i)

#define LL long long
#define Ldouble long double
#define PI 3.1415926535897932384626

#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define fi first
#define se second

int main()
{
  // Use also \n instead of endl, because endl flush
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  int incCount = 0;
  vector<int> nums;
  int i = 0;
  int sum = 0;
  while(cin >> num){
    nums.push_back(num);
    if (i > 3){
      int newSum = sum - nums[i - 3] + num;
      if (newSum > sum)
        ++incCount;
      sum = newSum;
    }
    else
      sum += num;
    ++i;
  }

  cout << incCount << endl;

  return 0;
}



