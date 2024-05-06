package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2gy9m/
*/

func removeDuplicates(nums []int) int {
	numLen := len(nums)
	if numLen == 0 || numLen == 1 {
		return numLen
	}

	count := 0
	for _, num := range nums {
		if nums[count] != num {
			count++
			nums[count] = num
		}
	}

	return count + 1
}

func removeDuplicatesDoublePoint(nums []int) int {
	numLen := len(nums)
	if numLen == 0 || numLen == 1 {
		return numLen
	}

	low := 0
	for fast := 1; fast < numLen; fast++ {
		if nums[fast] != nums[low] {
			low++
			nums[low] = nums[fast]
		}
	}

	return low + 1
}
