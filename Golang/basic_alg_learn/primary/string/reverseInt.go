package string

import "math"

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnx13t/
*/

func reverseInt(x int) int {
	if x > math.MaxInt32 || x < math.MinInt32 {
		return 0
	}

	res := 0

	for x != 0 {
		res = res*10 + x%10
		x = x / 10
	}

	if res > math.MaxInt32 || res < math.MinInt32 {
		return 0
	}

	return res
}
