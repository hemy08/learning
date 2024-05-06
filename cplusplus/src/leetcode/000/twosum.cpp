//
// Created by z00579768 on 2024/4/8.
//

#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include "leetcode.h"


vector<int> TwoSum::Base(vector<int> &nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

vector<int> TwoSum::WithHash(vector<int> &nums, int target) {
    map<int,int> hash;
    int n = nums.size();
    if (n <= 1) {
        return {};
    }

    for (int i = 0; i < n; i++) {
        auto it = hash.find(target-nums[i]);
        if (it != hash.end()) {
            return {it->second,i};
        }
        hash.insert(make_pair(nums[i],i));
    }
    return {};
}

typedef struct TwoSumModel {
    vector<int> nums;
    int target{};
    vector<int> result;
};

void TestCase_TwoSum_001() {
    map<int, TwoSumModel> testData;
    testData[0] = TwoSumModel{vector<int>{2, 7, 11, 15}, 9,vector<int>{0,1}};
    testData[1] = TwoSumModel{vector<int>{3, 2, 4}, 6,vector<int>{1,2}};
    testData[2] = TwoSumModel{vector<int>{3, 3}, 6,vector<int>{0,1}};
    //testData.insert(make_pair(vector<int> {3, 2, 4}, 6));
    //testData.insert(make_pair(vector<int> {3, 3}, 6));
    //testData.insert(make_pair(vector<int> {2, 7, 11, 15}, 9));
    //testData.insert(make_pair(vector<int> {2, 7, 11, 15}, 9));
    //testData.insert(make_pair(vector<int> {2, 7, 11, 15}, 9));
    //testData.insert(make_pair(vector<int> {2, 7, 11, 15}, 9));
    map<int, TwoSumModel>::iterator it;
    for (it = testData.begin(); it != testData.end(); it++) {
        vector<int> result = TwoSum::WithHash(it->second.nums, it->second.target);
        // 使用std::sort对vector进行排序
        std::sort(result.begin(), result.end());
        if (it->second.result == result) {
            printf("test suit %d success\n", it->first);
        } else {
            printf("test suit %d failed\n", it->first);
        }
    }
}

void writefile()
{

}