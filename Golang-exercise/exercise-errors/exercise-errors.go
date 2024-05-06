package main

import (
	"fmt"
)

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

func getabs(x float64) float64 {
	if x < 0 {
		return -x
	}

	if x == 0 {
		return 0
	}

	return x
}

func Sqrt(x float64) (float64, error) {
	z := 1.0

	if x < 0 {
		return 0, ErrNegativeSqrt(x)
	} else if x == 0 {
		return x, nil
	} else {
		for getabs(z*z-x) > 1e-6 {
			z = (z + x/z) / 2
		}
		return z, nil
	}
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}
