#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ifstream f("day6.input");
  vector<uint64_t> histogram(9, 0);
  uint64_t timer;
  char sep;
  while(f >> timer >> sep){
    ++histogram[timer];
  }
  ++histogram[timer];

  // Solution retrieved from lvrcek
  for (int day = 0; day < 256; ++day){
    vector<uint64_t> tmp (histogram.begin() + 1, histogram.end());
    tmp[6] += histogram[0];
    tmp.push_back(histogram[0]);
    histogram = tmp;
  }

  cout << accumulate(histogram.begin(), histogram.end(), (uint64_t)0) << endl;

  return 0;
}

