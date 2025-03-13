#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int a, b, c;
  int rst;
  string str;
  vector<int> v(10, 0);

  cin >> a >> b >> c;

  rst = a * b * c;
  str = to_string(rst);
  
  for(int i=0; i<str.length(); i++) {
    v[str[i] - '0']++;
  }

  for(int i=0; i<v.size(); i++) {
    cout << v[i] << endl;
  }
}
