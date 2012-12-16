class GKernel {
private:
	GScene* activeScene;
public:
	void initGameLoop();
	void setActiveScene(GScene* scene);
};