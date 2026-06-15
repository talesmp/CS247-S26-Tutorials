CXX = g++
CXXFLAGS = -std=c++17 -Wall -g     # -g embeds the debug info that gdb & valgrind need

buggy: buggy.cpp
	$(CXX) $(CXXFLAGS) buggy.cpp -o buggy

.PHONY: clean
clean:
	rm -rf buggy buggy.dSYM     # buggy.dSYM only appears on macOS; harmless on Linux
