/******************************************************************************

给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
题解：
本题的难点在于索引如何去计算寻找，我们每次只需要将每个元素顺时针旋转90°即可，然后确定边界。

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int mulit = 0;
        for(int i = 0; i < matrix.size() / 2; ++i){
            for(int j = i; j < matrix.size() - 1 - i; ++j){
                int temp = matrix[j][matrix.size() - 1 - mulit];
                matrix[j][matrix.size() - 1 - mulit] = matrix[i][j];
                matrix[i][j] = matrix[matrix.size() - 1 - j][i];
                matrix[matrix.size() - 1 - j][i] = matrix[matrix.size() - 1 - mulit][matrix.size() - 1 - j];
                matrix[matrix.size() - 1 - mulit][matrix.size() - 1 - j] = temp;
            }
            mulit++;
        }
    }
};
int main()
{
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    
    return 0;
}