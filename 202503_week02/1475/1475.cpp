#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  vector<int> v(10, 0);

  cin >> n;

  while(n>0){
    v[n%10]++;
    n /= 10;
  }

  v[6] = (v[6] + v[9] + 1) / 2;
  v[9] = 0;

  sort(v.begin(), v.end(), greater<int>());

  cout << v[0] << endl;
  
  return 0;
}