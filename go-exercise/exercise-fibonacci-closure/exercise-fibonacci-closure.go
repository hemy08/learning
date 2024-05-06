package main

import "fmt"

// 单纯的两个数字相加的函数
func add(x, y int) int {
	return x + y
}

// fibonacci 函数会返回一个返回 int 的函数。
func fibonacci(s1, s2 int) func() int {
	fmt.Println("fibonacci start with ", s1, " and ", s2)
	// 初始化需要记忆住的变量left和right，这部分只会被调用一次
	left := s1
	right := s2
	return func() int {
		// 这部分开始会被调用多次，只要外部调用方调用一次f函数，这里就会被执行一次
		next := add(left, right)
		// 更新需要记忆住的变量left和right
		left = right
		right = next
		// 返回每一次f被调用的结果
		return next
	}
}

func main() {
	// 调用一次闭包函数来得到f函数，又可称为闭包函数的初始化
	f := fibonacci(0, 1)
	for i := 0; i < 10; i++ {
		// 反复不断的调用f得到结果
		fmt.Println("next value: ", f())
	}
}