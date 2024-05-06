package string

import "sort"

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xn96us/
*/

func isAnagram(s string, t string) bool {
	// 字母异位词长度首先必然是一样的
	ns, nt := len(s), len(t)
	if ns != nt {
		return false
	}

	// map表存储字符以及字符出现的次数
	hasMap := map[int32]int{}
	for _, v := range s {
		if _, has := hasMap[v]; has {
			hasMap[v]++
		} else {
			hasMap[v] = 1
		}
	}

	for _, v := range t {
		if _, has := hasMap[v]; has {
			hasMap[v]--
		} else {
			return false
		}
	}

	for _, v := range hasMap {
		if v != 0 {
			return false
		}
	}

	return true
}

func isAnagramSortComp(s string, t string) bool {
	// 排序
	s1, s2 := []byte(s), []byte(t)
	sort.Slice(s1, func(i, j int) bool {
		return s1[i] < s1[j]
	})
	sort.Slice(s2, func(i, j int) bool {
		return s2[i] < s2[j]
	})

	return string(s1) == string(s2)
}
