package alarmsystem

import "testing"

func Test_AlarmSystem_Case1(t *testing.T) {
	var obj AlarmSystem
	obj.AlarmSystemCreate()
	_ = obj.AlarmSystemAddAlarm(7, 22, 30, []int{3, 2, 6}, 0)
	_ = obj.AlarmSystemAddAlarm(2, 22, 30, []int{1, 2}, 2)
	_ = obj.AlarmSystemAddAlarm(3, 22, 30, []int{1, 2}, 1)
	_ = obj.AlarmSystemAddAlarm(4, 22, 30, []int{1, 2}, 0)

	res := obj.AlarmSystemQueryAlarm(2, 22, 0, 59)
	for i, v := range res {
		println("res [", i, "] ", v)
	}
}
