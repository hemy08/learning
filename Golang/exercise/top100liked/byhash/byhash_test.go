package byhash

import (
	"fmt"
	"testing"
)

func TestCase_longestConsecutive(t *testing.T) {
	fmt.Printf("result %v \n", longestConsecutive([]int{100, 4, 200, 1, 3, 2}))
	fmt.Printf("result %v \n", longestConsecutive([]int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}))
	fmt.Printf("result %v \n", longestConsecutive([]int{1, 0, -1}))
	fmt.Printf("result %v \n", longestConsecutive([]int{7, 2, -2, 9, 6, 9, -7, 2, 1, -3, -1, -7, -5}))
	fmt.Printf("result %v \n", longestConsecutiveOfficially([]int{100, 4, 200, 1, 3, 2}))
	fmt.Printf("result %v \n", longestConsecutiveOfficially([]int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}))
	fmt.Printf("result %v \n", longestConsecutiveOfficially([]int{1, 0, -1}))
	fmt.Printf("result %v \n", longestConsecutiveOfficially([]int{7, 2, -2, 9, 6, 9, -7, 2, 1, -3, -1, -7, -5}))
	fmt.Printf("result %v \n", longestConsecutiveMutated([]int{100, 4, 200, 1, 3, 2}))
	fmt.Printf("result %v \n", longestConsecutiveMutated([]int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}))
	fmt.Printf("result %v \n", longestConsecutiveMutated([]int{1, 0, -1}))
	fmt.Printf("result %v \n", longestConsecutiveMutated([]int{7, 2, -2, 9, 6, 9, -7, 2, 1, -3, -1, -7, -5}))
}
