#include "Application.h"

Application::Application(int width, int height, const std::string& title) : m_Window(width, height, title) {}

void Application::Run() {
	while (!m_Window.ShouldClose()) {
		OnUpdate();
		m_Window.SwapBuffers();
		m_Window.PollEvents();
	}
}

void Application::OnUpdate() {
	glClear(GL_COLOR_BUFFER_BIT);
}
