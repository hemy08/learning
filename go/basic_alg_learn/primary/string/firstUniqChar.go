package string

import "strings"

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xn5z8r/
*/

func firstUniqChar(s string) int {
	// 首位
	if v := strings.IndexByte(s[1:], s[0]); v == -1 {
		return 0
	}

	// 分割为两个子串进行处理
	for i := 1; i < len(s); i++ {
		// 当前位置往前是否出现过
		v1st := strings.IndexByte(s[:i], s[i])
		// 当前位置往后的子串中是否存在
		vFlow := strings.IndexByte(s[i+1:], s[i])

		// 当前位置是第一次出现，并且往后没有再出现，则返回
		if v1st == -1 && vFlow == -1 {
			return i
		}
	}

	return -1
}
