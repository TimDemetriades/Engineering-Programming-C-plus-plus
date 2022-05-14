DEBUG   :=  -g
CXX :=  g++ $(DEBUG)

complex: main.o complex.o
    $(CXX) main.o complex.o -o complex

main.o: main.cc complex.hh
    $(CXX) -c $<

complex.o: complex.cc Complex.hh
    $(CXX) -c $<

clean:
    rm *.o complex