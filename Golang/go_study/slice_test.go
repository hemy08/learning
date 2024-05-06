package go_study

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_IntSlice(t *testing.T) {
	intSlice := []int{1, 2, 3}
	intSlice2 := intSlice[1:3]
	fmt.Println("1=== after init:", intSlice, intSlice2)

	intSlice[1] = 0
	fmt.Println("2=== after intSlice[1] = 0:", intSlice, intSlice2)

	intSlice2 = append(intSlice2, 4)
	fmt.Println("3=== after append:", intSlice, intSlice2)

	intSlice2[1] = 6
	fmt.Println("4=== after intSlice2[1]=6:", intSlice, intSlice2)

	fmt.Println(intSlice, intSlice2)
	assert.Equal(t, intSlice, []int{1, 0, 3})
	assert.Equal(t, intSlice2, []int{0, 6, 4})

	s := "hello你好"
	fmt.Println(len(s), len([]rune(s)))
}
