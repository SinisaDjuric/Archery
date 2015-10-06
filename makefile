all:  player main build score

.PHONY: player main build score

player:
	$(MAKE) -C player all

main:
	$(MAKE) -C main all

build:
	$(MAKE) -C build all

score:
	$(MAKE) -C score all


