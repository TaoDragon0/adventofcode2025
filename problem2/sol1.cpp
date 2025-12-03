#include <bits/stdc++.h>

using namespace std;

long long llpow(long long base, unsigned int exp) {
  //simple ll integer power operation
  //base cases
  if (exp == 0) return (long long) 1;
  if (exp == 1) return (long long) base;

  //log(n) branching thing
  long long tmp = llpow(base, exp>>1);
  if(exp % 2 ==0) return tmp * tmp;
  return base * tmp * tmp;

  //i probably dont need this bc the highest power im going to is 8 but idc
}


int main () {
  
  // parsing the input into 
  // stranges means str ranges
  string stranges;
  cin >> stranges;

  long long res = 0;
  while (stranges != "") {
    string strange = stranges.substr(0, stranges.find(",")); //getting the first range, will return whole string if no ,
    long long min = stoll( strange.substr(0,stranges.find("-")) );
    strange = strange.erase(0, strange.find("-") + 1);
    long long max = stoll( strange );
    
    cout << "found range: " << min << "-" << max << "\n";

    int minpower = (int) ( log((double) min) / log(100.0) ) + 1;
    long long factor = llpow(10, minpower) + 1;
    while (factor <= max) {

      //voodoo magic
      long long minmin = (factor - 1) / 10;
      long long maxmax = factor - 2;
      long long mindfactor = ((min-1) / factor) + 1;
      if (mindfactor < minmin) mindfactor = minmin;
      long long maxdfactor = max / factor;
      if (maxdfactor > maxmax) maxdfactor = maxmax;
      
      //docs
      cout << " min " << mindfactor << " | max " << maxdfactor << "\n";

      if (mindfactor <= maxdfactor) {
        long long addthis = factor * ((mindfactor + maxdfactor)*(maxdfactor - mindfactor + 1)) / 2;
        cout << "adding " << addthis << "\n";
        res += addthis;
      }

      factor -= 1;
      factor *= 10;
      factor += 1;
    }

    if (stranges.find(',') != string::npos) {
      stranges = stranges.erase(0, stranges.find(',') + 1);
    } else {
      stranges = "";
    }
    //stranges = "";
  }
  
  cout << res << "\n";
  return 0;
}
