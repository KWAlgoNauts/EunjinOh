#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
  int n;

  cin >> n;

  stack<pair<int, int>> s;
  vector<int> v(n);
  vector<int> result(n);
  int num = 1;

  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  for(int i=0;i<n;i++){
    while(!s.empty() && s.top().first < v[i]){
      s.pop();
    }
    if(s.empty()){
      result[i] = 0;
    }else{
      result[i] = s.top().second;
    }
    s.push({v[i], i+1});
  }

  for(int i = 0; i < n; i++){
    cout << result[i] << ' ';
  }
  
  return 0;
}