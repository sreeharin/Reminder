reminder:libreminder
	gcc -g -o bin/reminder main.c -Llib -Iinclude -lreminder `pkg-config --cflags --libs gtk+-3.0`
	rm *.o

libreminder:obj
	ar cr libreminder.a *.o
	mv libreminder.a lib/

obj:
	gcc -c src/*.c -Iinclude `pkg-config --cflags --libs gtk+-3.0`
