package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x21ib6/
*/

import (
	"sort"
)

func singleNumber(nums []int) int {
	stack := map[int]int{}
	for _, v := range nums {
		stack[v]++
	}

	for key, val := range stack {
		if val != 2 {
			return key
		}
	}
	return 0
}

func singleNumberArr(nums []int) int {
	n := len(nums)

	if n%2 == 0 {
		return 0
	}

	sort.Ints(nums)

	for index := 0; index < n; index++ {
		// 奇数，并且前面都匹配上了
		if index+1 >= n && n%2 != 0 {
			return nums[index]
		}

		if nums[index] != nums[index+1] {
			return nums[index]
		}
		index++
	}
	return 0
}

func singleNumberArr2(nums []int) int {
	n := len(nums)

	if n%2 == 0 {
		return 0
	}

	sort.Ints(nums)

	sumA, sumB := 0, 0
	for index := 0; index < n-1; index++ {
		sumA += nums[index]
		sumB += nums[index+1]
		index++
	}
	sumA += nums[n-1]

	return sumA - sumB
}

func singleNumberBitwise(nums []int) int {
	result := 0
	for _, v := range nums {
		result = result ^ v
	}
	return result
}
