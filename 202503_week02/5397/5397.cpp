#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main(){
  int n;
  vector<string> v;

  cin >> n;

  while(n>0){
    string s;
    string rst;
    list<char> l;
    list<char>::iterator it;

    cin >> s;
    it = l.begin();

    for(auto c : s){
      if(c == '<'){
          if(it != l.begin()) it--;
      } else if(c == '>'){
          if(it != l.end()) it++;
      } else if(c == '-'){
          if(it != l.begin()){
              it--;
              it = l.erase(it);
          }
      } else {
          it = l.insert(it, c);
          it++;
      }
  }
    
    for(auto c : l){
      rst.push_back(c);
    }

    v.push_back(rst); 

    n--;

  }

  for(auto s : v){
    cout << s << endl;
  }

  return 0;
}