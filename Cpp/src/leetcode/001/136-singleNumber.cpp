//
// Created by Administrator on 2024/10/22.
//
#include <algorithm>

#include "vector"

using namespace std;

class Solution {
public:
    int singleNumber_XOR(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result = result ^ num;
        }
        return result;
    }

    int singleNumber_OddEvenDigits(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int numa = 0;
        int numb = 0;
        for (int i = 0; i < nums.size() -1; ++i)
        {
            numa += nums[i];
            numb += nums[i + 1];
            i++;
        }
        numa += nums[nums.size() - 1];
        return numa - numb;
    }
};