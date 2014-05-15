
PROJECTDIR=.
SUBDIR=.

include config.mk

.PHONY: all clean midi midi-clean driver driver-clean test test-clean

default: all

all: midikit test
midikit: midi driver
clean: midi-clean driver-clean test-clean

documentation: midi driver
	rm -r documentation/xml
	rm -r documentation/html
	rm -r documentation/wiki
	doxygen
	cd documentation && ./generate_wikidoc.sh

midi: midi/.make
midi-clean: midi/.make-clean
driver: driver/.make
driver-clean: driver/.make-clean
test: test/.make
test-clean: test/.make-clean

driver/.make: midi
test/.make: midi driver

%/.make:
	cd $$(dirname $@) && $(MAKE)

%/.make-clean:
	cd $$(dirname $@) && $(MAKE) clean


