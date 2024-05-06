package string

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnhbqj/
*/

func reverseString(s []byte) {
	l := len(s)
	if l <= 1 {
		return
	}

	n := (l + 1) / 2

	for i := 0; i < n; i++ {
		tmp := s[i]
		s[i] = s[l-1-i]
		s[l-1-i] = tmp
	}
}
