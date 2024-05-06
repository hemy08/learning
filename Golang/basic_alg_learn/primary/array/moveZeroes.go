package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2ba4i/
*/

func moveZeroes(nums []int) {
	n := len(nums)
	// 遍历，找到0，和后面的交换
	for i := 0; i < n; i++ {
		if nums[i] == 0 {
			for j := i + 1; j < n; j++ {
				if nums[j] != 0 {
					nums[i] = nums[j]
					nums[j] = 0
					break
				}
			}
		}
	}
}
