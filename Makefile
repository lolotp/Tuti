tuti:
	g++ -c utils.cpp -I./libzip
	g++ utils.o GObject.cpp GScene.cpp GRenderingEngine.h GBasicRenderingEngine.cpp GKernel.cpp main.cpp -L/bin -lpng -lzip -lGL -lGLU -lglut