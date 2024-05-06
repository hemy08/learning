package go_study

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

const (
	a = iota
	b = iota
	c = iota
)

const (
	d, e, f = iota, iota, iota
)

func Test_Const_Iota(t *testing.T) {
	fmt.Println(a, b, c, d, e, f)
	assert.Equal(t, a, 0)
	assert.Equal(t, b, 1)
	assert.Equal(t, c, 2)
	assert.Equal(t, d, 0)
	assert.Equal(t, e, 0)
	assert.Equal(t, f, 0)

}
