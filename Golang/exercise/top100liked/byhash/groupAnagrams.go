package byhash

import "sort"

// GroupAnagrams 字母异位词
// https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked
// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
func GroupAnagrams(strs []string) [][]string {
	res := map[string][]string{}
	for _, str := range strs {
		s := []byte(str)
		sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
		sortedStr := string(s)
		res[sortedStr] = append(res[sortedStr], str)
	}

	ans := make([][]string, 0, len(res))
	for _, v := range res {
		ans = append(ans, v)
	}
	return ans
}
