#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ifstream f ("day1.input");
  int prev = -1;
  int incCount = 0;
  int num;
  while(f >> num){
    if (prev != -1 && num > prev)
      ++incCount;
    prev = num;
  }
  cout << incCount << endl;
  return 0;
}
