package main

import (
	"image"

	"code.google.com/p/go-tour/pic"
)

type Image struct{}

func main() {
	m := Image{}
	pic.ShowImage(m)
}
