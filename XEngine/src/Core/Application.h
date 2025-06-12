#pragma once
#include "Window.h"

class Application {
public:
	Application(int width, int height, const std::string& title);
	void Run();

private:
	Window m_Window;
	void OnUpdate();
};
