#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
  int n, x, rst=0;
  vector<int> v;
  unordered_set<int> s;

  cin >> n;

  v.resize(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
    s.insert(v[i]);
  }

  cin >> x;

  for(int i=0;i<n;i++){
    if(s.find(x-v[i]) != s.end() && s.find(x-v[i]) != s.find(v[i])){
      rst++;
      s.erase(v[i]);       
      s.erase(x - v[i]);
    }
  }
  cout << rst << endl;

  return 0;
  
}