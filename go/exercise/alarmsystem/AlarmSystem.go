package alarmsystem

import (
	"sort"
)

const (
	MAX_ALARM_ID  = 1000
	MAX_HOUR      = 23
	MAX_MINUTE    = 59
	WEEK_DAYS     = 7
	TYPE_STUDY    = 0
	TYPE_EXERCISE = 1
	TYPE_GAME     = 2
)

type AlarmData struct {
	id       int
	hour     int
	minute   int
	typeId   int
	weekdays [7]bool
}

type AlarmSystem struct {
	data map[int]AlarmData
}

func (a *AlarmSystem) AlarmSystemCreate() *AlarmSystem {
	a.data = make(map[int]AlarmData)
	return a
}

func isValid(val, min, max int) bool {
	return ((val) < min) || ((val) > max)
}

func InputValid(id, hour, minute int, weekdays []int, typeId int) bool {
	if isValid(id, 0, MAX_ALARM_ID) ||
		isValid(hour, 0, MAX_HOUR) ||
		isValid(minute, 0, MAX_MINUTE) ||
		isValid(typeId, TYPE_STUDY, TYPE_GAME) ||
		isValid(len(weekdays), 0, WEEK_DAYS) {
		return false
	}

	for _, v := range weekdays {
		if isValid(v, 1, WEEK_DAYS) {
			return false
		}
	}

	return true
}

func (a *AlarmSystem) AlarmSystemAddAlarm(id, hour, minute int, weekdays []int, typeId int) bool {
	if _, exist := a.data[id]; exist {
		return false
	}

	if !InputValid(id, hour, minute, weekdays, typeId) {
		return false
	}

	item := AlarmData{
		id:     id,
		hour:   hour,
		minute: minute,
		typeId: typeId,
	}

	for _, v := range weekdays {
		item.weekdays[v] = true
	}

	a.data[id] = item
	return true
}

func (a *AlarmSystem) AlarmSystemDeleteAlarm(id int) bool {
	if _, exist := a.data[id]; !exist {
		return false
	}

	delete(a.data, id)
	return true
}

func (a *AlarmSystem) isMatch(item AlarmData, weekday, hour, startMinute, endMinute int) bool {
	// week是否满足
	if !item.weekdays[weekday-1] {
		return false
	}

	// hour是否满足
	if item.hour != hour {
		return false
	}

	// minute是否满足
	if (item.minute < startMinute) || item.minute > endMinute {
		return false
	}

	return true
}

func (a *AlarmSystem) AlarmSystemQueryAlarm(weekday, hour, startMinute, endMinute int) []int {
	var temp []AlarmData
	for _, alm := range a.data {
		if !a.isMatch(alm, weekday, hour, startMinute, endMinute) {
			continue
		}

		temp = append(temp, alm)
	}

	if len(temp) == 0 {
		return nil
	}

	sort.Slice(temp, func(i, j int) bool {
		if temp[i].minute < temp[j].minute {
			return true
		}

		if temp[i].minute == temp[j].minute {
			if temp[i].typeId < temp[j].typeId {
				return true
			}

			if temp[i].typeId == temp[j].typeId {
				if temp[i].id < temp[j].id {
					return true
				}
			}
		}

		return false
	})

	var result []int
	for _, v := range temp {
		result = append(result, v.id)
	}

	return result
}

func (a *AlarmSystem) AlarmSystemFree() {
	a.data = nil
}
