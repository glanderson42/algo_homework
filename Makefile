COMPILER=g++
CPPFLAGS=-Wall -Wextra -std=c++14 -lstdc++fs

default:
	$(COMPILER) -o homework main.cpp $(CPPFLAGS)
