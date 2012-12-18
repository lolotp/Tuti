tuti:
	g++ -c utils.cpp -I./libzip
	g++ utils.o GObject.cpp GScene.cpp GRenderingEngine.h GBasicRenderingEngine.cpp GKernel.cpp main.cpp -lpng -lzip -lGL -lGLU -lglut