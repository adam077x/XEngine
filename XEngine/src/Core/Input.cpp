#include <glad/glad.h>
#include "Input.h"
#include <stdexcept>

GLFWwindow* Input::s_Window = nullptr;

bool Input::IsKeyPressed(int key) {
	return glfwGetKey(s_Window, key) == GLFW_PRESS;
}

glm::vec2 Input::GetMousePosition() {
	double xpos, ypos;
	glfwGetCursorPos(s_Window, &xpos, &ypos);
	return { (float)xpos, (float)ypos };
}

void Input::SetWindow(GLFWwindow* window) {
	s_Window = window;
}
