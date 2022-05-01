#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int val;
    node* next;
};

class board
{
private:
      node* top;
public:
      board(){top = nullptr;}
      bool const empty();
      void push(int);
    int const peek();
      void pop();
    vector<vector<int>> boardUp(vector<vector<int>> m, int, board);
    vector<vector<int>> boardDown(vector<vector<int>> m, int, board);
    vector<vector<int>> boardLeft(vector<vector<int>> m, int, board);
    vector<vector<int>> boardRight(vector<vector<int>> m, int, board);
    bool check(vector<vector<int>> m, int);
    void solve(vector<vector<int>> mat, vector<vector<int>> c,            vector<string> &s, int, int &m, int, string, board);
    void display(ostream &o, vector<string> s);
};
