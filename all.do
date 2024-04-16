DEPS="main.o"
redo-ifchange $DEPS
gcc -o "$3" $DEPS
