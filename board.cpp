#include <iostream>
#include "board.h"
using namespace std;

bool const board::empty() {
  
  return top == nullptr;
  
}
void board::push(int a) {

  node *temp = new node;
  temp->val = a;
  temp->next = nullptr;
  // update the links ...link to the stack
  temp->next = top;
  top = temp;
  
}
int const board::peek() {
  
  return top->val;
  
}
void board::pop() {

  node *temp = top;
  top = top->next; //=temp->next;
  delete temp;
  
}
vector<vector<int>> board::boardUp(vector<vector<int>> m, int s, board b) {

  for(int j = 0; j < s; j++) {
    int idx;
    for(int i = 0; i < s; i++) {
        if(m[i][j] == 2048) {
          if(!b.empty()) {
            b.pop();
          }
        }
        if(m[i][j] != 2048 && m[i][j] != 0) {
          if(b.empty()) {
             b.push(m[i][j]);
             idx = i;
          }
          else if(b.peek() == m[i][j]) {
             m[idx][j] += b.peek();
             m[i][j] = 0;
             b.pop();
          }
          else if(b.peek() != m[i][j]) {
             b.pop();
             b.push(m[i][j]);
             idx = i;
          }
      }
    }
    bool flag = true;
    while(flag) {
      int numTimes = 0;
      for(int i = s - 1; i > 0; i--) {
        if(m[i][j] != 2048 && m[i][j] != 0 && m[i - 1][j] == 0) {
          m[i - 1][j] = m[i][j];
          m[i][j] = 0;
          numTimes++;
        }
      }
     if(numTimes == 0) {
       flag = false;
      }
    }
    while(!b.empty()) {
      b.pop();
    }
  }
  return m;
  
}
vector<vector<int>> board::boardDown(vector<vector<int>> m, int s, board b) {

  for(int j = 0; j < s; j++) {
    int idx;
    for(int i = s - 1; i >= 0; i--) {
        if(m[i][j] == 2048) {
          if(!b.empty()) {
            b.pop();
          }
        }
        if(m[i][j] != 2048 && m[i][j] != 0) {
          if(b.empty()) {
             b.push(m[i][j]);
             idx = i;
          }
          else if(b.peek() == m[i][j]) {
            m[idx][j] += b.peek();
            m[i][j] = 0;
            b.pop();
          }
          else if(b.peek() != m[i][j]) {
            b.pop();
            b.push(m[i][j]);
            idx = i;
         }
      }
    }
    bool flag = true;
    while(flag) {
      int numTimes = 0;
      for(int i = 0; i < s - 1; i++) {
        if(m[i][j] != 2048 && m[i][j] != 0 && m[i + 1][j] == 0) {
          m[i + 1][j] = m[i][j];
          m[i][j] = 0;
          numTimes++;
        }
      }
     if(numTimes == 0) {
       flag = false;
      }
    }
    while(!b.empty()) {
      b.pop();
    }
  }
  return m;
  
}
vector<vector<int>> board::boardLeft(vector<vector<int>> m, int s, board b) {

  for(int i = 0; i < s; i++) {
    int idx;
    for(int j = 0; j < s; j++) {
        if(m[i][j] == 2048) {
          if(!b.empty()) {
            b.pop();
          }
        }
        if(m[i][j] != 2048 && m[i][j] != 0) {
          if(b.empty()) {
             b.push(m[i][j]);
             idx = j;
          }
          else if(b.peek() == m[i][j]) {
            m[i][idx] += b.peek();
            m[i][j] = 0;
            b.pop();
          }
          else if(b.peek() != m[i][j]) {
            b.pop();
            b.push(m[i][j]);
            idx = j;
        }
      }
    }
    bool flag = true;
    while(flag) {
      int numTimes = 0;
      for(int j = s - 1; j > 0; j--) {
        if(m[i][j] != 2048 && m[i][j] != 0 && m[i][j - 1] == 0) {
          m[i][j - 1] = m[i][j];
          m[i][j] = 0;
          numTimes++;
        }
      }
     if(numTimes == 0) {
       flag = false;
      }
    }
    while(!b.empty()) {
      b.pop();
    }
  }
  return m;
  
}
vector<vector<int>> board::boardRight(vector<vector<int>> m, int s, board b) {
  
  for(int i = 0; i < s; i++) {
    int idx;
    for(int j = s - 1; j >= 0; j--) {
        if(m[i][j] == 2048) {
          if(!b.empty()) {
            b.pop();
          }
        }
        if(m[i][j] != 2048 && m[i][j] != 0) {
          if(b.empty()) {
             b.push(m[i][j]);
             idx = j;
          }
          else if(b.peek() == m[i][j]) {
            m[i][idx] += b.peek();
            m[i][j] = 0;
            b.pop();
          }
          else if(b.peek() != m[i][j]) {
            b.pop();
            b.push(m[i][j]);
            idx = j;
          }
      }
    }
    bool flag = true;
    while(flag) {
      int numTimes = 0;
      for(int j = 0; j < s - 1; j++) {
        if(m[i][j] != 2048 && m[i][j] != 0 && m[i][j + 1] == 0) {
          m[i][j + 1] = m[i][j];
          m[i][j] = 0;
          numTimes++;
        }
      }
     if(numTimes == 0) {
       flag = false;
      }
    }
    while(!b.empty()) {
      b.pop();
    }
  }
  return m;
  
}
bool board::check(vector<vector<int>> m, int s) {
  
  int count = 0;
  for(int i = 0; i < s; i++) {
    for(int j = 0; j < s; j++) {
      if(m[i][j] != 0 && m[i][j] != 2048) {
        count++;
      }
    }
  }
  if(count == 1) {
    return true;
  }
  return false;
  
}
void board::solve(vector<vector<int>> mat, vector<vector<int>> co, vector<string> &p, int c, int &m, int s, string str, board b) {

  if(check(mat, s)) {
    m = c;
    if(p.empty()) {
      p.push_back(str);
    } else if(stol(str) < stol(p[0])) {
      p.pop_back();
      p.push_back(str);
    }
    return;
  }
  if(mat == co || c >= m) {
    return;
  }
  vector<vector<int>> m1 = boardUp(mat, s, b);
  vector<vector<int>> m2 = boardRight(mat, s, b);
  vector<vector<int>> m3 = boardDown(mat, s, b);
  vector<vector<int>> m4 = boardLeft(mat, s, b);

  c++;
  solve(m1, mat, p, c, m, s, str + "1", b);
  solve(m2, mat, p, c, m, s, str + "2", b);
  solve(m3, mat, p, c, m, s, str + "3", b);
  solve(m4, mat, p, c, m, s, str + "4", b);
  
}
void board::display(ostream &out, vector<string> s) {

  if(s.empty()) {
    out << "Impossible";
  } else {
    for(int i = 0; i < s.size(); i++) {
      out << s[i];
    }
  }
  
}
