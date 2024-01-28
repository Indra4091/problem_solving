#include<iostream>
#include<string>
#include<array>
#include<vector>

using namespace std;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  cin >> test;
  for (int t = 0; t < test; t++) {
    string message;
    cin >> message;

    int length = message.size();
    vector<int> table;
    table.push_back(0);
    int count = 0;
    int end = 0;

    for (int r = 1; r < length; ) {
      if (message[r] == message[count]) {
        count++;
        r++;
        table.push_back(count);
      } 
      else {
        if (count != 0) {
          for (int p = 0; p < table.size(); p++) {
            table[p] = 0;
          }
          count = 0;
          end = table.size() - 1;
        } 
        else {
          table.push_back(0);
          end = r;
          r++;
        }
      }
    }

    for (int s = 0; s <= end; s++) {
      cout << message[s];
    }
    cout << "\n";
  }
}