package main

import "time"
import "fmt"
import "strconv"

type stDate struct {
	Index  int
	Year   string
	Month  string
	Day    string
	Hour   int
	Minute int
	Second int
	Week   string
	DateY  string
}

var months_en = [...]string{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
}
var months_ch = [...]string{
	"一月(January)",
	"二月(February)",
	"三月(March)",
	"四月(April)",
	"五月(May)",
	"六月(June)",
	"七月(July)",
	"八月(August)",
	"九月(September)",
	"十月(October)",
	"十一月(November)",
	"十二月(December)",
}

func ConverMonthToChinese(month string) string {
	for v, value := range months_en {
		if month == value {
			return months_ch[v]
		}
	}

	return "Error"
}

var days_en = [...]string{
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
}

var days_ch = [...]string{
	"星期日(Sunday)",
	"星期一(Monday)",
	"星期二(Tuesday)",
	"星期三(Wednesday)",
	"星期四(Thursday)",
	"星期五(Friday)",
	"星期六(Saturday)",
}

func ConverDaysToChinese(Day string) string {
	for v, value := range days_en {
		if Day == value {
			return days_ch[v]
		}
	}

	return "Error"
}

func main() {
	t := time.Now()

	fmt.Println(t)
	fmt.Println(t.Date())
	fmt.Println(t.Year())
	fmt.Println(t.Month())
	fmt.Println(t.Day())
	fmt.Println(t.Hour(), "时")
	fmt.Println(t.Minute(), "分")
	fmt.Println(t.Second(), "秒")
	fmt.Println(t.Year(), "年的第", t.YearDay(), "天")

	m := make(map[int]stDate)
	m[0] = stDate{0, "年", "月", "日", 17, 24, 30, "短日期", "星期"}
	m[1] = stDate{1, "2018", "02", "23", 17, 24, 30, "2018年02月23日", "星期五"}

	var temp stDate
	temp.Index = 2
	temp.Year = strconv.Itoa(t.Year())
	temp.Month = ConverMonthToChinese(t.Month().String())
	temp.Day = strconv.Itoa(t.Day())
	temp.Hour = t.Hour()
	temp.Minute = t.Minute()
	temp.Second = t.Second()
	temp.Week = ConverDaysToChinese(t.Weekday().String())
	temp.DateY = "今年第" + strconv.Itoa(t.YearDay()) + "天"
	m[2] = temp

	for v := range m {
		fmt.Println("map[", v, "]:", m[v])
	}
}
