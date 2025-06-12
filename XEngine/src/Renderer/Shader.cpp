#include <glad/glad.h>
#include "Shader.h"
#include <stdexcept>

static unsigned int CompileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (!result) {
		char info[512];
		glGetShaderInfoLog(id, 512, nullptr, info);
		throw std::runtime_error(info);
	}
	return id;
}

Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc) {
	unsigned int vertex = CompileShader(GL_VERTEX_SHADER, vertexSrc);
	unsigned int fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertex);
	glAttachShader(m_ID, fragment);
	glLinkProgram(m_ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader() {
	glDeleteProgram(m_ID);
}

void Shader::Bind() const {
	glUseProgram(m_ID);
}

void Shader::Unbind() const {
	glUseProgram(0);
}
