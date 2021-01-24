text-editor : main.o dictionary.o filereader.o
	g++ -o text-editor main.o dictionary.o filereader.o

main.o: main.cpp filereader.h dictionary.h
	g++ -c main.cpp

filereader.o: filereader.cpp filereader.h
	g++ -c filereader.cpp

dictionary.o: dictionary.cpp dictionary.h
        g++ -c dictionary.cpp

clean:
	rm *.o text-editor
