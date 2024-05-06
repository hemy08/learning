package main

import "code.google.com/p/go-tour/tree"
import "fmt"

// Walk 步进 tree t 将所有的值从 tree 发送到 channel ch。
func Walk(t *tree.Tree, ch chan int) {
	transValue(t, ch)
	close(ch)
}

func transValue(t *tree.Tree, ch chan int) {
	if t != nil {
		transValue(t.Left, ch)
		ch <- t.Value
		transValue(t.Right, ch)
	}
}

// Same 检测树 t1 和 t2 是否含有相同的值。
func Same(t1, t2 *tree.Tree) bool {
	ch1 := make(chan int)
	ch2 := make(chan int)

	go Walk(t1, ch1)
	go Walk(t2, ch2)

	for i := range ch1 {
		if i != <-ch2 {
			return false
		}
	}

	return true
}

func main() {
	ch := make(chan int)
	go Walk(tree.New(1), ch)
	for v := range ch {
		fmt.Println(v)
	}

	//  比较两个tree的value值是否相等
	fmt.Println(Same(tree.New(1), tree.New(1)))
	fmt.Println(Same(tree.New(1), tree.New(2)))

}
