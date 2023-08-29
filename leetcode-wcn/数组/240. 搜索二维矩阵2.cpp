/******************************************************************************

题解：本体可以采用二叉搜索树的思想，我们观察矩阵找出特点，一开始从左上角开始搜索，如果小于
则列减1，如果大于则行+1；

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        if(row == 0){
            return false;
        }
        int i = 0;
        int j = col -1;
        for(int n = 0; n < row + col; ++n){
            if(j < 0 || i >= row){
                break;
            }
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                --j;
            }else{
                ++i;
            }
    
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> vector {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    Solution s;
    bool b = s.searchMatrix(vector,5);
    bool x = true;
    cout << x << endl;
    std::cout << b << std::endl;
    return 0;
}