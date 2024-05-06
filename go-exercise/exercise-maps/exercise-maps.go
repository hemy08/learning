package main

import (
	"strings"

	"code.google.com/p/go-tour/wc"
)

func WordCount(s string) map[string]int {
	//return map[string]int{"x": 1}
	m := make(map[string]int) // map对象
	c := strings.Fields(s)    // []byte
	for _, v := range c {
		m[v] += 1 //没有k，v就添加  有的话就修改v
	}
	return m
}

func main() {
	wc.Test(WordCount)
}
