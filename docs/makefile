all: class-diag.svg

%.svg: %.puml
	plantuml -tsvg $<

clean:
	git clean -fxdi

