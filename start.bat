if not exist bin mkdir bin

rem gcc -Iinclude src\main.c src\aufgabe1.c src\aufgabe2.c src\aufgabe3.c -o bin\program
gcc src/*.c -o bin\app

cd bin
app