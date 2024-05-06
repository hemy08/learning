package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2jrse/
*/

// twoSum 暴力解法
func twoSum(nums []int, target int) []int {
	n := len(nums)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return nil
}

// twoSum hash表
func twoSumHashMap(nums []int, target int) []int {
	hashMap := map[int]int{}
	for i, v := range nums {
		num2 := target - v
		if _, has := hashMap[num2]; has {
			return []int{i, hashMap[num2]}
		}
		hashMap[v] = i
	}
	return nil
}
