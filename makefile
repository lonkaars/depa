# this makefile transparently forwards all `make` calls to `redo` for convenience

.PHONY: FORCE

all: FORCE
	@redo $(MAKECMDGOALS)

$(MAKECMDGOALS): all
