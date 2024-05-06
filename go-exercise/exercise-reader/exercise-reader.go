package main

import "code.google.com/p/go-tour/reader"

type MyReader struct{}

// TODO: Add a Read(byte) (int, error) method to MyReader.

func (v MyReader) Read(b []byte) (int, error) {
	b[0] = 'A'
	b[1] = 'A'
	b[2] = 'A'
	b[3] = 'A'
	return 4, nil
}

func main() {
	reader.Validate(MyReader{})
}
