package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2skh7/
*/

func rotateCopy(nums []int, k int) {
	n := len(nums)

	k = k % n
	if k == 0 {
		return
	}

	arr1 := make([]int, k)
	arr2 := make([]int, n-k)

	// 取出前后两部分
	copy(arr1, nums[n-k:n])
	copy(arr2, nums[0:n-k])

	// 拼接新的数组，然后拷贝给nums
	arr1 = append(arr1, arr2...)
	copy(nums, arr1)
}

func rotateBySlice(nums []int, k int) {
	n := len(nums)

	k = k % n
	if k == 0 {
		return
	}

	arr1 := make([]int, 0)
	arr2 := make([]int, 0)
	arr1 = append(arr1, nums[n-k:n]...)
	arr2 = append(arr2, nums[0:n-k]...)

	for index := k; index < n; index++ {
		nums[index] = arr2[index-k]
	}

	for index := 0; index < k; index++ {
		nums[index] = arr1[index]
	}
}

func rotateByNewNums(nums []int, k int) {
	newNums := make([]int, len(nums))
	for i, v := range nums {
		newNums[(i+k)%len(nums)] = v
	}
	copy(nums, newNums)
}

func rotateRingReplace(nums []int, k int) {
	n := len(nums)

	k = k % n
	if k == 0 {
		return
	}

	for i := 0; i < gcd(k, n); i++ {
		cur := i
		pre := nums[i]
		for ok := true; ok; ok = cur != i {
			next := (cur + k) % n
			nums[next], pre, cur = pre, nums[next], next
		}
	}
}

func gcd(a, b int) int {
	for a != 0 {
		a, b = b%a, a
	}
	return b
}
