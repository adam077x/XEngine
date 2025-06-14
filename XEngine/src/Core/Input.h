#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Input {
public:
	static bool IsKeyPressed(int key);
	static glm::vec2 GetMousePosition();
	static void SetWindow(GLFWwindow* window);
private:
	static GLFWwindow* s_Window;
};
