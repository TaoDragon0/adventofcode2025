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
    
    while (turn >= 100) {
      turn -= 100;
      res++;
    }
    
    while (turn <= -100) {
      turn += 100;
      res++;
    }

    // res is now in [-99, 99]

    if (dial == 0) {
      dial += turn;
      if (dial < 0) {
        dial += 100;
      }
    } else {
      dial += turn;
      if (dial < 0) {
        res++;
        dial += 100;
      } else if (dial == 0) {
        res++;
      } else if (dial >= 100) {
        res++;
        dial -= 100;
      }
    }

    cout << dial << " ";
    cout << res << "\n";
  }
  
  cout << "\n" << res << "\n";

  return 0;
}
