if not exist bin mkdir bin

gcc -Iinclude src\main.c src\aufgabe1.c src\aufgabe2.c src\aufgabe3.c -o bin\program

cd bin
program