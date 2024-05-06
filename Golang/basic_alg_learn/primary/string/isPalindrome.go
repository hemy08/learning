package string

import "strings"

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xne8id/
*/

func isValid(c byte) bool {
	if c >= '0' && c <= '9' || c >= 'a' && c <= 'z' {
		return true
	}

	return false
}

func isPalindrome(s string) bool {
	tmp := strings.ToLower(s)
	n := len(s)
	for left, right := 0, n-1; left < right; {
		if !isValid(tmp[left]) {
			left++
			continue
		}

		if !isValid(tmp[right]) {
			right--
			continue
		}

		if tmp[left] != tmp[right] {
			return false
		}

		left++
		right--
	}

	return true
}
