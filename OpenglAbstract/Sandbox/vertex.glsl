#version 440 core

out vec2 currentPos;

void main()
{
	const vec4 vertices[] = vec4[](vec4(0.0, 1.0, 1.0, 1.0),
								   vec4(-1.0, -1.0, 1.0, 1.0),
								   vec4(1.0, -1.0, 1.0, 1.0));

	gl_Position = vertices[gl_VertexID];
	currentPos = gl_Position.xy;
}