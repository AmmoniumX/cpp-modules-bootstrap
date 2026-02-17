all: hello

# Main executable
hello: HelloWorld.pcm
	clang++ -std=c++20 \
    -fmodule-file=HelloWorld=HelloWorld.pcm \
    -fmodule-file=HelloWorld:HelloImpl=HelloWorld.HelloImpl.pcm \
		main.cpp Hello.cppm HelloImpl.cppm -o hello

# Module partition
HelloWorld.HelloImpl.pcm: HelloImpl.cppm
	clang++ -std=c++20 -xc++-module HelloImpl.cppm --precompile -o HelloWorld.HelloImpl.pcm

# Module interface
HelloWorld.pcm: Hello.cppm HelloWorld.HelloImpl.pcm
	clang++ -std=c++20 -xc++-module Hello.cppm \
    -fmodule-file=HelloWorld:HelloImpl=HelloWorld.HelloImpl.pcm \
    --precompile -o HelloWorld.pcm

clean:
	rm *.pcm hello

.PHONY = all clean
