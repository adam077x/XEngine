#pragma once
#include <string>

class Shader {
public:
	Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
	~Shader();
	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_ID;
};
