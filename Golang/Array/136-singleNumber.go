package Array

import "sort"

func singleNumber_XOR(nums []int) int {
	result := 0
	for _, num := range nums {
		result = result ^ num
	}
	return result
}

func singleNumber_OddEvenDigits(nums []int) int {
	if len(nums)%2 == 0 {
		return 0
	}

	sort.Ints(nums)
	numa := 0
	numb := 0
	println(numa, numb, len(nums))
	for i := 0; i < len(nums); i++ {
		numa += nums[i]
		numb += nums[i+1]
		i += 1
	}
	numa += nums[len(nums)-1]
	return numa - numb
}
