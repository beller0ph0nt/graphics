#include "Shader.h"

Shader::Shader(Type type, std::string&& source)
	: m_type(type),
	  m_source(move(source)) {
	m_id = glCreateShader(static_cast<GLenum>(m_type));
	std::clog << "Shader::ctor id=" << m_id << std::endl;
	const char* src = m_source.c_str();
	glShaderSource(m_id, 1, &src, NULL);
	glCompileShader(m_id);
	GLint success;
	glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLint len;
		glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &len);
		auto log = std::make_unique<char[]>(len);
		glGetShaderInfoLog(m_id, len, NULL, log.get());
		throw std::exception(log.get());
	}
}

Shader::Shader(Type type, fs::path&& filepath)
	: Shader(type, std::move(File::ReadAll(std::move(filepath))))
{}

Shader::Shader(Shader&& shader) {
	Shader::operator=(std::move(shader));
}

void Shader::operator=(Shader&& shader) {
	m_id = shader.m_id;
	m_type = shader.m_type;
	m_source = shader.m_source;
	shader.m_id = 0;
	shader.m_type = Type::Unknown;
	shader.m_source = "";
}

Shader::~Shader() {
	std::clog << "~Shader::dtor id=" << m_id << std::endl;
	glDeleteShader(m_id);
}

GLuint Shader::GetId() const { 
	return m_id; 
}
