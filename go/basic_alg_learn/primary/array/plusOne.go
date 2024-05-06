package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2cv1c/
*/

func plusOne(digits []int) []int {
	if digits[0] == 0 {
		digits[0] = 1
		return digits
	}

	flag := 0
	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i] == 9 {
			digits[i] = 0
			flag = 1
		} else {
			if i != len(digits)-1 {
				digits[i] = digits[i] + flag
			} else {
				digits[i] = digits[i] + 1
			}
			flag = 0
			break
		}
	}

	if flag == 1 {
		newDig := []int{1}
		newDig = append(newDig, digits...)
		return newDig
	}

	return digits
}

func plusOneCheck(digits []int) []int {
	// 全9
	flag9 := true
	for _, v := range digits {
		if v != 9 {
			flag9 = false
			break
		}
	}

	if flag9 {
		newDig := []int{1}
		for i := range digits {
			digits[i] = 0
		}
		newDig = append(newDig, digits...)
		return newDig
	}

	// 最后一位不是9
	n := len(digits)
	if digits[n-1] != 9 {
		digits[n-1] += 1
		return digits
	}

	// 最后一位是9
	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i] == 9 {
			digits[i] = 0
		} else {
			digits[i] += 1
			break
		}
	}
	return digits
}

func plusOneSimples(digits []int) []int {
	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i] == 9 {
			digits[i] = 0
		} else {
			digits[i] += 1
			return digits
		}
	}

	newDig := []int{1}
	newDig = append(newDig, digits...)
	return newDig
}
