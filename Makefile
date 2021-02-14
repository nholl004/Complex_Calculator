cache: calc.o 
	g++ calc.o -o calc

cache.o: calc.cpp
	g++ -c calc.cpp -o calc.o
	
clean:
	rm -f calc.0