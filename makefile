main: main.o

clean:
	git clean -fxdi

compile_commands.json:
	compiledb make -Bn

