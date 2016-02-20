#include "Program.h"

void Program::addShader(Shader shader)
{
	GLuint shaderID;
	std::string shaderCode;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::badbit);

	try
	{
		shaderFile.open(shader.fileLocation);
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();

		shaderFile.close();

		shaderCode = shaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		char msg[50];
		sprintf_s(msg, "ERROR:SHADER::FILE_NOT_SUCCESFULLY_READ\n");
		OutputDebugStringA(msg);
	}

	const GLchar* shaderSource = shaderCode.c_str();

	shaderID = glCreateShader(shader.shaderType);
	glShaderSource(shaderID, 1, &shaderSource, nullptr);
	glCompileShader(shaderID);

	GLint success;
	GLchar infoLog[512];

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
		sprintf_s(infoLog, "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n %s", infoLog);
		OutputDebugStringA(infoLog);
	};

	glAttachShader(program, shaderID);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		sprintf_s(infoLog, "ERROR::SHADER::PROGRAM::LINKING_FAILED\n %s", infoLog);
		OutputDebugStringA(infoLog);
	}

	glDeleteShader(shaderID);
}