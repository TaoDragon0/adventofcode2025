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

long long genfactor(int n, int power) {
  // generates a factor with n and power
  // for example genfactor(3, 3) will return 1001001.
  long long factor = 1;
  long long tenpower = llpow(10, power);
  for (int i = 1; i < n; i++) {
    factor *= tenpower;
    factor += 1;
  }
  return factor;
}

long long p1soln (int n, string stranges) {
  
  cout << "\n" << n << "\n";


  long long res = 0;
  while (stranges != "") {
    string strange = stranges.substr(0, stranges.find(",")); //getting the first range, will return whole string if no ,
    long long min = stoll( strange.substr(0,stranges.find("-")) );
    strange = strange.erase(0, strange.find("-") + 1);
    long long max = stoll( strange );
    int maxpower = (int) ( log((double) max) / (n * log(10.0)) ) + 1;
    
    cout << "found range: " << min << "-" << max << "\n";

    int minpower = (int) ( log((double) min) / (n * log(10.0)) ) + 1;
    long long factor = genfactor(n, minpower);
    while (minpower <= maxpower) {

      //voodoo magic
      long long minmin = llpow(10, minpower - 1);
      long long maxmax = llpow(10, minpower) - 1;
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

      minpower += 1;
      factor = genfactor(n, minpower);
    }

    if (stranges.find(',') != string::npos) {
      stranges = stranges.erase(0, stranges.find(',') + 1);
    } else {
      stranges = "";
    }
    //stranges = "";
  }
  
  return res;
}

int main () {

  string stranges;
  cin >> stranges;
  
  
  // ITS PIE TIME
  // the max n we have to account for is 10, so our primes are 2, 3, 5, 7
  // this means we have 16 iterations to go through
  
  long long res = 0;
  // technically i only needs 4 bits
  for (int i = 0; i < 16; i++) {
    int n = 1; // our n!!!!
    int sign = -1; // if we will add or subtract the value
    
    // time for the processing. since we only have 4 primes, writing them all out improves readability
    if ((i & 1) == 1) {
      n *= 2;
      sign *= -1;
    }  
    if (((i >> 1) & 1) == 1) {
      n *= 3;
      sign *= -1;
    }
    if (((i >> 2) & 1) == 1) {
      n *= 5;
      sign *= -1;
    }
    if (((i >> 3) & 1) == 1) {
      n *= 7;
      sign *= -1;
    }

    cout << n;
    // max of 12 for extra room
    // n=1 counts valid codes
    if (1 < n && n <= 12) {
      res += sign*p1soln(n, stranges);
    }
  }

  cout << "\n" << "\n" << res;
  

  //cout << p1soln(2, stranges);
  return 0;
}
