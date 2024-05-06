package main

import (
	"bytes"
	"encoding/base64"
	"fmt"
	"image"
	"image/png"
	"io"
	"math"
	"os"
)

type alg_type int8

const (
	meanType alg_type = iota
	multiType
	powType
	myType1
)

func Show(dx, dy int, etype alg_type, file io.Writer) {
	data := Pic(dx, dy, etype)

	m := image.NewNRGBA(image.Rect(0, 0, dx, dy))

	for y := 0; y < dy; y++ {
		for x := 0; x < dx; x++ {
			v := data[y][x]
			i := y*m.Stride + x*4
			m.Pix[i] = v
			m.Pix[i+1] = v
			m.Pix[i+2] = 255
			m.Pix[i+3] = 255
		}
	}

	err := png.Encode(file, m)
	if err != nil {
		fmt.Println(err)
		panic(err)
	}

	ShowImage(m)
}

func ShowImage(m image.Image) {
	var buf bytes.Buffer

	err := png.Encode(&buf, m)
	if err != nil {
		panic(err)
	}
	enc := base64.StdEncoding.EncodeToString(buf.Bytes())
	fmt.Println("IMAGE:" + enc)
}

func Pic(dx, dy int, etype alg_type) [][]uint8 {
	var slTemp [][]uint8

	slTemp = make([][]uint8, dy)
	for ix := range slTemp {
		slTemp[ix] = make([]uint8, dx)
	}

	slx := slTemp
	for ix := range slx {
		sly := slx[ix]
		for iy := range sly {
			switch etype {
			case meanType:
				sly[iy] = uint8((ix*ix + iy*iy) / 2)
			case multiType:
				sly[iy] = uint8(ix * iy)
			case powType:
				sly[iy] = uint8(math.Pow(float64(ix), float64(iy)))
			case myType1:
				sly[iy] = uint8(ix * (iy + 1))
			default:
				sly[iy] = uint8(ix * (iy - 1))
			}
		}
		slx[ix] = sly
	}

	return slTemp
}

func getFileName(t alg_type) string {
	switch t {
	case meanType:
		return "mean.png"
	case multiType:
		return "multi.png"
	case powType:
		return "pow.png"
	case myType1:
		return "my1.png"
	default:
		return "test.png"
	}

}

func main() {
	const (
		dx = 256
		dy = 256
	)

	file, err := os.Create(getFileName(meanType))
	if err != nil {
		fmt.Println(err)
	}
	defer file.Close()
	Show(dx, dy, meanType, file)
}
