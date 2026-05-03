all:
	make document
	gcc -o build/bin/lesson0 src/c/lesson0.c

document:
	mkdir -p build/doc/
	pdflatex -output-directory=build/doc/ -jobname=i2c4p src/tex/lesson0.tex
	pdflatex -output-directory=build/doc/ -jobname=i2c4p src/tex/lesson0.tex

clean:
	rm -rf build/bin/*
	rm -rf build/doc/*
