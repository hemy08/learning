package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x248f5/
*/

import "sort"

func containsDuplicate(nums []int) bool {
	sort.Ints(nums)
	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] {
			return true
		}
	}

	return false
}

func containsDuplicateHashMap(nums []int) bool {
	hashMap := map[int]int{}

	for _, v := range nums {
		if _, has := hashMap[v]; has {
			return true
		}
		hashMap[v] = v
	}

	return false
}
