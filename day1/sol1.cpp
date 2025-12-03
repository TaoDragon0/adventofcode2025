#include <bits/stdc++.h>

using namespace std;

int main() {
  
  int dial = 50;
  int turn;
  int res = 0;

  int n;
  cin >> n;
  for (int i = 0;i < n;i++) {
    
    cin >> turn;
    dial += turn; 
    dial %= 100;
    if (dial == 0) {
      res++;
    }
  }
  
  cout << res << "\n";

  return 0;
}
