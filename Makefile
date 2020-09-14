CC=gcc
CXX=g++
RM=rm -f


CPPFLAGS=-std=c++11 -O3 -msse3 -mavx -I.
LDFLAGS=-std=c++11 -O3  -pthread
LDLIBS=
#LDLIBS=-lboost_thread -lboost_system -lboost_program_options -lboost_regex

#BRANCH=more_valarray
PROGRAM=sse
#PROGRAM2=blockfinder

SRCS=sse2.cpp 

OBJS=$(subst .cpp,.o,$(SRCS))
ASMS=$(subst .cpp,.asm,$(SRCS))

all: $(PROGRAM)

asm: $(ASMS)

%.asm: %.cpp
	$(CXX) $(LDFLAGS) $(LDLIBS) -S -o $@ $< $(LDLIBS)

$(PROGRAM): $(OBJS)
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $(PROGRAM) $(OBJS) $(LDLIBS)

clean:
	rm -rf $(OBJS) $(PROGRAM)
