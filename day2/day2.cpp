#include <bits/stdc++.h>
using namespace std;

int main()
{
  // Use also \n instead of endl, because endl flush
  ios::sync_with_stdio(0);
  cin.tie(0);

  ifstream f ("day2.input");
  int x = 0, y = 0;
  string mov;
  int num;
  while(f >> mov >> num){
    char c = mov[0];
    switch(c){
      case 'f': x += num; break;
      case 'd': y += num; break;
      case 'u': y -= num; break;
      default: break;
    }
  }

  cout << (x * y) << endl;

  return 0;
}
