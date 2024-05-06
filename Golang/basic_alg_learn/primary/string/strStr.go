package string

import "strings"

/*
https://leetcode-cn.com/problems/implement-strstr/solution/
*/

func strStr(haystack string, needle string) int {
	if len(needle) == 0 {
		return 0
	}

	if len(haystack) < len(needle) {
		return -1
	}

	for loop := 0; loop < len(haystack); loop++ {
		if haystack[loop] != needle[0] {
			continue
		}

		if strings.HasPrefix(haystack[loop:], needle) {
			return loop
		}
	}

	return -1
}
