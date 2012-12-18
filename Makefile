tuti:
	g++ -c utils.cpp -I./libzip
	g++ -c GObject.cpp
	g++ -c GScene.cpp
	g++ -c GBasicRenderingEngine.cpp
	g++ -c GKernel.cpp
	g++ utils.o GObject.o GScene.o GBasicRenderingEngine.o GKernel.o main.cpp -lpng -lzip -lGL -lGLU -lglut