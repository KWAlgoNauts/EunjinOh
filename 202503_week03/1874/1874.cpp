#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
  int n;

  cin >> n;

  vector<int> v(n);
  stack<int> s;
  vector<char> result;
  int num = 1;

  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  for(int i=0;i<n;i++){
    while(num <= v[i]){
      s.push(num);
      result.push_back('+');
      num++;
    }
    if(s.top() == v[i]){
      s.pop();
      result.push_back('-');
    }else{
      cout << "NO" << endl;
      return 0;
    }   
  }

  for(int i = 0; i < result.size(); i++){
    cout << result[i] << '\n';
  }
  
  return 0;
}