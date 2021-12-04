#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int prev = -1;
  int incCount = 0;
  int num;
  while(cin >> num){
    if (prev != -1 && num > prev)
      ++incCount;
    prev = num;
  }
  cout << incCount << endl;
  return 0;
}
