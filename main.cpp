#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ArgumentManager.h"
#include "board.h"
using namespace std;
 
int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    string ifile = am.get("input"); //get the filename of argument name "input"
    string ofile = am.get("output"); //get the filename of argument name "output"
    ifstream input(ifile);
    ofstream output(ofile);

    board b;
    int size, max, total = 0;
    int val;
    vector<vector<int>> matrix; //this 2d vector will be the numbers in the board
    vector<vector<int>> combinations;
    vector<string> puzzle; // this vector will be used to solve the puzzle
    bool flag;
    string str;
    
    input >> size;
    cout << size << endl;

    for(int i = 0; i < size; i++) {
        vector<int> nums;
        for(int j = 0; j < size; j++) {
            input >> val;
            nums.push_back(val);
        }
        matrix.push_back(nums);
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            total += matrix[i][j];
            cout << matrix[i][j] << " ";
        }
      cout << endl;
    }
    cout << "The total is " << total << endl;
    if(size >= 20) {
      max = 8;
    } else {
      max = 12;
    }
    if(total % 2 != 0) {
      output << "Impossible";
    } else if(b.check(matrix, size)) {
      output << "0";
    } else {
      b.solve(matrix, combinations, puzzle, 0, max, size, str, b);
      b.display(output, puzzle);
    }
    return 0;
}
