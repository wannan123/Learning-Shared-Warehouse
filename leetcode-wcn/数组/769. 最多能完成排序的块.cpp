//题解：当前数组最大值等于数组下表时可以分割一次，因为如果大于数组下标，该最大值右侧肯定还有比它小的数要归并到一个数组里
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum = 0;
        int max = -1;
        for(size_t i = 0; i < arr.size(); ++i){
            if(arr[i] >= max) max = arr[i];
            if(max == i) sum++;
        }
        return sum;
    }
};