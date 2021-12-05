#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ifstream f("day5.input");
  int x1, y1, x2, y2;
  char del;
  map<pair<int,int>,int> vents;
  int counter = 0;
  while (f >> x1 >> del >> y1 >> del >> del >> x2 >> del >> y2){
    if (x1 == x2){
      int start = min(y1, y2);
      int end = max(y1, y2);
      for(int i = start; i <= end; ++i)
        if(++vents[make_pair(x1,i)] == 2)
          ++counter;
    }
    else if (y1 == y2){
      int start = min(x1, x2);
      int end = max(x1, x2);
      for(int i = start; i <= end; ++i)
        if(++vents[make_pair(i,y1)] == 2)
          ++counter;
    }
  }
  cout << counter << endl;

  return 0;
}
