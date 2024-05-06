package string

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnpvdm/
*/

func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}

	res := countAndSay(n - 1)
	begin, num := 0, len(res)
	result := make([]byte, 0)
	for begin < num {
		count := 0
		for i := begin; i < num; i++ {
			if res[begin] != res[i] {
				break
			}
			count++
		}
		result = append(result, byte(count+'0'))
		result = append(result, res[begin])
		begin += count
	}

	return string(result)
}
