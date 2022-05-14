CXX		:=		g++		
DEBUG	:=		-g

fraction: fraction.o main.o
		$(CXX) $(DEBUG) fraction.o main.o -o fraction.exe

fraction.o: fraction.hh fraction.cc
		$(CXX) $(DEBUG) -c fraction.cc

main.o: main.cc fraction.hh
		$(CXX) $(DEBUG) -c main.cc 