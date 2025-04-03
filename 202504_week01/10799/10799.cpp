#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  stack<char> stk;
  bool isPipe = false;
  int rst = 0;
  string str;

  cin >> str;

  for(char c : str){

    if(c == '('){
      stk.push(c);
      isPipe = false;
    }
    else if(c == ')'){
      if(isPipe){
        stk.pop();
        rst+=1;
      }
      else{
        stk.pop();
        rst += stk.size();
        isPipe = true;
      }
    }
  }

  cout<< rst;

  return 0;
}