package go_study

import (
	"bytes"
	"os/exec"
	"sync/atomic"
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_os_exec_Command(t *testing.T) {
	cmd := exec.Command("go", "test", "-v", "-race", "-run", "Test_Const_Iota", "-failfast")
	var out bytes.Buffer
	cmd.Stdout = &out
	t.Log("Running go test -v -race -run TestFailfastSuite -failfast")
	err := cmd.Run()
	t.Log(out.String())
	if err != nil {
		t.Log(err)
		t.Fail()
	}
}

func Test_sync_atomic_pkg(t *testing.T) {
	n := int32(100)
	println("init:", n)

	atomic.AddInt32(&n, 1)
	assert.Equal(t, n, int32(101))
	println("AddInt32 delta > 0:", n)

	atomic.AddInt32(&n, -1)
	assert.Equal(t, n, int32(100))
	println("AddInt32 delta < 0:", n)

	m := uint32(100)
	println("init:", m)

	atomic.AddUint32(&m, 1)
	assert.Equal(t, m, uint32(101))
	println("AddUint32 delta > 0:", m)

	atomic.AddUint32(&m, ^uint32(0))
	assert.Equal(t, m, uint32(100))
	println("AddUint32 delta < 0:", m)
}
