tuti:
	g++ -c utils.cpp -I./libzip
	g++ -c GObject.cpp
	g++ -c GEvent.cpp
	g++ -c GAction.cpp
	g++ -c GScene.cpp
	g++ -c GBasicRenderingEngine.cpp    
	g++ -c GBasicInteractionEngine.cpp
	g++ -c GKernel.cpp
	g++ utils.o GObject.o GEvent.o GAction.o GScene.o GBasicRenderingEngine.o GBasicInteractionEngine.o GKernel.o main.cpp -lpng -lzip -lGL -lGLU -lglut