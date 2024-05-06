package tendersystem

import (
	"testing"
	"time"

	"github.com/stretchr/testify/assert"
)

func Test_TenderSystem_Case1(t *testing.T) {
	obj := Constructor()
	obj.addTender(1, 1, 10)
	obj.addTender(2, 2, 20)
	obj.addTender(2, 2, 30)
	time.Sleep(time.Millisecond)
	assert.Equal(t, 10, obj.updateTender(1, 1, 40))
	time.Sleep(time.Millisecond)
	assert.Equal(t, -1, obj.updateTender(1, 3, 40))
	assert.Equal(t, 40, obj.removeTender(1, 1))
	assert.Equal(t, -1, obj.removeTender(1, 3))
	obj.addTender(1, 2, 20)
	obj.addTender(3, 2, 10)
	obj.addTender(4, 2, 40)
	assert.Equal(t, 2, obj.queryTender(2, 15))
	assert.Equal(t, -1, obj.queryTender(5, 10))
}

func Test_TenderSystem_Case2(t *testing.T) {
	obj := Constructor()
	obj.addTender(1, 1, 10)
	obj.addTender(2, 1, 20)
	time.Sleep(time.Millisecond)
	assert.Equal(t, 10, obj.updateTender(1, 1, 20))
	assert.Equal(t, 2, obj.queryTender(1, 10))
}
