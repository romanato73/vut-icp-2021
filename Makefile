all:
	cd src
	qmake -makefile editor.pro
	make Makefile

make doxygen
	doxygen path/to/DoxyFile

make pack
	zipnuť všetko (doc, examples, src, README, Makefile)

make clean
	Vyčistiť všetko čo sa vygenerovalo