package go_study

import (
	"fmt"
	"testing"
	"time"
)

// 如果说goroutine是Go语音程序的并发体的话，那么channels是它们之间的通信机制
// 对channel的读写是阻塞的，直到读出内容或者写入buffer
// channel的两个功能：传值，同步

// Declaring and initializing
// c := make(chan int) // 创建同步通道
// c1 := make(chan int, 3) // 创建带3个缓冲槽的异步通道

func hello(c chan string) {
	c <- "Hello, world"
}

// 同步通道: 默认为同步模式，需要发送和接受配对。否则会被阻塞，直到另一方准本好后被唤醒
func syncChannel() {
	c := make(chan string)
	go hello(c)
	fmt.Printf("You say:%s\n", <-c)
}

// 异步通道: 异步方式通过判断缓冲区来决定是否阻塞。如果缓冲区已满，发送被阻塞；缓冲区为空，接收被阻塞
func asyncChannel() {
	c := make(chan int, 2)
	go func() {
		// fmt.Printf("You say:%d\n", <-c)
		for i := range c { // 阻塞等待数据
			println("Read", i)
		}
	}()

	for i := 0; i < 4; i++ {
		c <- i // 发送2次后阻塞
		println("Write", i)
	}

	time.Sleep(time.Second)
}

// 多通道SELECT
func NoDefault(in, out chan int) {
	select {
	case <-in:
		println("NoDefault Read")
	case out <- 0:
		println("NoDefault Write")
	}
}

func Default(in, out chan int) {
	select {
	case <-in:
		println("Default Read")
	case out <- 0:
		println("Default Write")
	default:
		println("Default")
	}
}

func multiChannelSelect() {
	in := make(chan int)
	out := make(chan int)
	go NoDefault(in, out) // 选择任一可发送接受分支
	go NoDefault(in, out) // 无发送接受分支，阻塞
	go Default(in, out)   // 无可发送接收分支，执行default
	<-out
}

func Test_Sync_Channel(t *testing.T) {
	println("同步通道 syncChannel: ")
	syncChannel()
}

func Test_Async_Channel(t *testing.T) {
	println("异步通道 asyncChannel: ")
	asyncChannel()
}

func Test_Multi_Channel_Select(t *testing.T) {
	println("多通道Select multiChannelSelect: ")
	multiChannelSelect()
}
