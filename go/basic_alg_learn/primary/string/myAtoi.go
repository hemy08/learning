package string

import "math"

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnoilh/
*/

// myAtoi 字符串转换成数字
func myAtoi(s string) int {
	signedFlag := 1

	// 跳过前导空格以及符号位
	begin, end := 0, len(s)-1
	for begin < end {
		if s[begin] == ' ' {
			begin++
			continue
		}

		if s[begin] == '-' {
			begin++
			signedFlag = -1
			break
		}

		if s[begin] == '+' {
			begin++
		}
		break
	}

	sum := 0
	for begin <= end {
		if s[begin] < '0' || s[begin] > '9' {
			return sum * signedFlag
		}

		sum = sum*10 + int(s[begin]-'0')
		begin++
		if signedFlag == 1 && sum > math.MaxInt32 {
			return math.MaxInt32
		}

		if signedFlag == -1 && sum > math.MaxInt32+1 {
			return math.MinInt32
		}
	}
	return sum * signedFlag
}
