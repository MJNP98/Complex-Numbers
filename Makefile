CXX = g++
CPPVERSION = 23
DVPMT = Yes
ifeq ($(DVPMT), Yes)
	CXXFLAGS = -std=c++$(CPPVERSION) -g -Wall -O0 -Wpedantic -D_GLIBCXX_DEBUG -Wextra -Werror -Wconversion \
		   	   -Wshadow=compatible-local -fbounds-check -Wunused-variable -pedantic-errors
else
	CXXFLAGS = -std=c++$(CPPVERSION) -Wall -O3 -march=native -DNDEBUG
endif
#  -O -Os -Wno-error -pedantic
# -pthread -ltbb pour parallelisation
# -Weffc++

EXEC = bin/main_complex.exe

all: $(EXEC)

bin/main_complex.exe: lib/main_complex.o
	$(CXX) $+ -o $@

lib/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@echo "Cleaning up..."
	@rm --force --verbose $(EXEC) include/*~ src/*~ lib/*.o

ar:
	@echo "Archiving files..."
	@ar -rsc -v lib/libMatrix.a lib/*.o

tar: clean
	tar zcvf ../codesMatrix.tar.gz *
