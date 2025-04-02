#include <iostream>
#include <stack>

using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL); 
  ios::sync_with_stdio(false);

  int n;
  int rst=0;
  
  cin >> n;

  for(int i=0; i<n; i++){
    stack<int> s;
    string str;

    cin >> str;

    for(char c: str){
      if(!s.empty()&& s.top() == c) s.pop();
      else s.push(c);
    }

    if(s.empty()) rst++;
  }
  
  cout << rst;

  return 0;
}