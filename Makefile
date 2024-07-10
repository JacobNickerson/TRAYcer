com:
	g++ -I include/ src/*.cpp main.cpp -o build/main
	build/main > build/images/image.ppm
	feh build/images/image.ppm

debug:
	g++ -g -I include/ src/*.cpp main.cpp -o build/main
	gdb build/main 