#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  string str;
  list<int> lst;
  list<int>::iterator iter;
  
  for(int i = 1; i <= n; i++){
    lst.push_back(i);
  }

  iter = lst.begin();

  str += "<";

  while(lst.empty() == false){
    for(int i = 0; i < k-1; i++){
      iter++;
      if(iter == lst.end()){
        iter = lst.begin();
      }
    }
    str += to_string(*iter) + ", ";
    iter = lst.erase(iter);
    if(iter == lst.end()){
      iter = lst.begin();
    }
  }
  
  str.pop_back();
  str.pop_back();
  str += ">";
  cout<<str<<endl;


  return 0;
}