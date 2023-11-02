#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
    : ShaderProgram(std::move(VertexShader()), std::move(FragmentShader()))
{
}

ShaderProgram::ShaderProgram(VertexShader&& vertexShader)
    : ShaderProgram(std::move(vertexShader), std::move(FragmentShader()))
{
}

ShaderProgram::ShaderProgram(FragmentShader&& fragmentShader)
    : ShaderProgram(std::move(VertexShader()), std::move(fragmentShader))
{
}

ShaderProgram::ShaderProgram(
    VertexShader&& vertexShader, FragmentShader&& fragmentShader
)
{
    std::vector<Shader> shaders;
    shaders.push_back(std::move(vertexShader));
    shaders.push_back(std::move(fragmentShader));
    ShaderProgram(std::move(shaders));
}

ShaderProgram::ShaderProgram(std::vector<Shader>&& shaders)
{
    m_id = glCreateProgram();
    std::clog << "ShaderProgram::ctor id=" << m_id << std::endl;
    for (int i = 0; i < shaders.size(); ++i) {
        glAttachShader(m_id, shaders[i].GetId());
    }
    glLinkProgram(m_id);
    GLint success;
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if (!success) {
        GLint len;
        glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &len);
        auto log = std::make_unique<char[]>(len);
        glGetProgramInfoLog(m_id, len, NULL, log.get());
        throw std::exception(log.get());
    }
}

ShaderProgram::~ShaderProgram()
{
    std::clog << "~ShaderProgram::dtor id=" << m_id << std::endl;
    glDeleteProgram(m_id);
}

GLuint ShaderProgram::GetId() const { return m_id; }

void ShaderProgram::Use() const { glUseProgram(m_id); }
