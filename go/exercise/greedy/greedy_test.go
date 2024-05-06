package greedy

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCase_maximumSwap(t *testing.T) {
	TestData := [][]int{
		{2736, 7236},
		{9973, 9973},
		{98368, 98863},
	}
	maximumSwap(98368)
	for _, val := range TestData {
		assert.Equal(t, val[1], maximumSwap(val[0]))
	}
}
