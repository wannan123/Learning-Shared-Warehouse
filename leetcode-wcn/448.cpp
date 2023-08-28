/******************************************************************************

给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
题解：
一开始我想的是在for里面用find函数找哪个不存在，但是这样的复杂度就是O(n^2)所以就采用了另一种题解：原地修改数据
不断遍历nums的元素，判断下标nums是否为正数，如果是正数就讲此下标的value改为负数，这样下次遍历到相同的value，如果是负数就代表出现过一次了。
最后只需要看nums里是否有正数，此下标+1即为所求.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for(auto & num : nums){
            int pos = abs(num) - 1;
            if(nums[pos] > 0){
                nums[pos] = -nums[pos];
            }
        }
        for(size_t i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ret.push_back(i + 1);       
            }
        }
        return ret;
    }
};
int main()
{
    vector<int> v {4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> p = s.findDisappearedNumbers(v);
    for(auto &value : p){
        cout << value <<" ";
    }
    return 0;
}