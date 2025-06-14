#include <glad/glad.h>
#include "Application.h"
#include "../Renderer/VertexArray.h"
#include "../Renderer/VertexBuffer.h"
#include "../Renderer/Shader.h"
#include <memory>

Application::Application(int width, int height, const std::string& title) : m_Window(width, height, title) {}

void Application::Run() {
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	std::unique_ptr<VertexArray> m_VAO = std::make_unique<VertexArray>();
	std::unique_ptr<VertexBuffer> m_VBO = std::make_unique<VertexBuffer>(vertices, sizeof(vertices));

	m_VAO->Bind();
	m_VBO->Bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	const std::string vertexSrc = R"(
		#version 440 core
		layout (location = 0) in vec3 aPos;
		void main() {
			gl_Position = vec4(aPos, 1.0);
		}
	)";

	const std::string fragmentSrc = R"(
		#version 440 core
		out vec4 FragColor;
		void main() {
			FragColor = vec4(1.0, 0.5, 0.2, 1.0);
		}
	)";

	std::unique_ptr<Shader> m_Shader = std::make_unique<Shader>(vertexSrc, fragmentSrc);

	while (!m_Window.ShouldClose()) {
		OnUpdate();

		m_Shader->Bind();
		m_VAO->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);

		m_Window.SwapBuffers();
		m_Window.PollEvents();
	}
}

void Application::OnUpdate() {
	glClear(GL_COLOR_BUFFER_BIT);
}
