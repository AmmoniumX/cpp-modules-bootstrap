all: hello

hello: HelloWorld.pcm
	clang++ -std=c++20 \
    -fmodule-file=HelloWorld=HelloWorld.pcm \
    -fmodule-file=HelloWorld:HelloImpl=HelloWorld.HelloImpl.pcm \
    main.cpp Hello.cppm Hello.cpp HelloImpl.cppm -o hello

# Primary module interface
HelloWorld.pcm: Hello.cppm HelloWorld.HelloImpl.pcm
	clang++ -std=c++20 -xc++-module Hello.cppm --precompile -o HelloWorld.pcm

# Internal partition
HelloWorld.HelloImpl.pcm: HelloImpl.cppm
	clang++ -std=c++20 -xc++-module HelloImpl.cppm --precompile -o HelloWorld.HelloImpl.pcm

clean:
	rm hello *.pcm

.PHONY = all clean
