#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ifstream f ("day1.input");
  int num;
  int incCount = 1; // first tuple
  vector<int> nums;
  int i = 0;
  int sum = 0;
  while(f >> num){
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



