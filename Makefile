GENERATED_FILES= src/*.o src/ui_* src/moc_* src/qrc_* src/.qmake.stash src/Makefile src/editor doc/html doc/latex
ZIP_FILE_NAME=2-xorsza01_xgroma00
ZIP_FILES=./assets/* ./doc/Doxyfile ./examples/* ./Makefile ./README.txt ./src/*

all: clean
	qmake -makefile -o src/Makefile -r src/editor.pro
	make -C src/

run:
	./src/editor

doxygen:
	doxygen ./doc/Doxyfile

clean:
	rm -rf $(ZIP_FILE_NAME).zip
	rm -rf $(GENERATED_FILES)

pack: clean
	zip $(ZIP_FILE_NAME) $(ZIP_FILES)
