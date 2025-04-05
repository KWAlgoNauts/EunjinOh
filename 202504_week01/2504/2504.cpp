#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL); 
  ios::sync_with_stdio(false);

  int temp=1;
  int rst=0;
  string str;
  stack<char> s;

  cin >> str;
  
  for(int i=0; i<str.size(); i++){
    if(str[i]=='('){
      s.push(str[i]);
      temp *= 2;
    }
    else if(str[i]=='['){
      s.push(str[i]);
      temp *= 3;
    }
    else if(str[i]==')'){
      if(s.empty() || s.top() != '('){
        cout << 0;
        return 0;
      }
      if(str[i-1] == '('){
        rst += temp;
        temp /= 2;
        
      }else temp/=2;
      s.pop();
    }
    else if(str[i]==']'){
      if(s.empty() || s.top() != '['){
        cout << 0;
        return 0;
      }
      if(str[i-1] == '['){
        rst += temp;
        temp /= 3;
      }
      else temp/=3;
      s.pop();
    }
  }
  
  if(!s.empty()) rst = 0;

  cout << rst;
  return 0;
}