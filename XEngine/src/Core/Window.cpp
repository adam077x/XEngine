#include <glad/glad.h>
#include "Window.h"
#include "Input.h"
#include <stdexcept>

Window::Window(int width, int height, const std::string& title)
{
	if (!glfwInit())
		throw std::runtime_error("Failed to initialize GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

	m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!m_Window) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(m_Window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLAD");
	}

	Input::SetWindow(m_Window);
}

Window::~Window() {
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void Window::PollEvents() const {
	glfwPollEvents();
}

void Window::SwapBuffers() const {
	glfwSwapBuffers(m_Window);
}

bool Window::ShouldClose() const {
	return glfwWindowShouldClose(m_Window);
}
