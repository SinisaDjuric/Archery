all:  player score gui main build

.PHONY: player score gui main build

player:
	$(MAKE) -C player all

score:
	$(MAKE) -C score all

gui:
	$(MAKE) -C gui all

main:
	$(MAKE) -C main all

build:
	$(MAKE) -C build all




