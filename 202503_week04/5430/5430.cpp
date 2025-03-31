#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL); 
  ios::sync_with_stdio(false);

  int n;
  
  //vector<string> arr;

  cin >> n;

  while(n>0){
    string s;
    string arr;
    int m;
    deque<int> dq;
    bool isError = false;
    bool isReverse = false;
    
    cin >> s;
    cin >> m;
    cin >> arr;

    
    if (m > 0) {
      arr.pop_back(); arr.erase(arr.begin()); // [] 제거
      stringstream ss(arr);
      string token;
      while (getline(ss, token, ',')) {
          dq.push_back(stoi(token));
      }
  }
    for (char cmd : s) {
      if (cmd == 'R') {
          isReverse = !isReverse;
      } else if (cmd == 'D') {
          if (dq.empty()) {
              isError = true;
              break;
          }
          if (isReverse) dq.pop_back();
          else dq.pop_front();
      }
  }

    if (isError) {
      cout << "error\n";
  } else {
    string output = "[";
      if (isReverse) {
        for (int i = dq.size() - 1; i >= 0; i--) {
            output += to_string(dq[i]);
            if (i != 0) output += ",";
        }
        output += "]\n";
      }
      else{ 
        
        for (int i = 0; i < dq.size(); i++) {
            output += to_string(dq[i]);
            if (i != dq.size() - 1) output += ",";
        }
        output += "]\n";
        }

      cout << output;
  }

    n--;
  }

  return 0;
}