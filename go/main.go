package main

import (
	"fmt"
)

func main() {
	newInt := new(int)
	fmt.Printf("new_int type: %T\n", newInt)

	makeSlice := make([]int, 5)
	fmt.Printf("make_slice: %T\n", makeSlice)

	a := 5
	b := 6
	fmt.Printf("a^a is %d\n", a^a)
	fmt.Printf("a^b is %d\n", a^b)
	fmt.Printf("0^b is %d\n", 0^b)
	fmt.Printf("a^b^a is %d\n", a^b^a)
}

/*type BookingSystem struct {

}


func Constructor() BookingSystem {

}


func (bookingSystem *BookingSystem) addLab(labId int, startTime int, endTime int) bool {

}


func (bookingSystem *BookingSystem) bookTime(recordId int, fromTime int, toTime int) int {

}


func (bookingSystem *BookingSystem) cancelBooking(recordId int) bool {

}*/
