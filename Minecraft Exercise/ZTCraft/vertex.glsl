#version 440 core

layout(location = 0) in vec3 position;

uniform mat4 projection;
uniform mat4 lookat;
uniform mat4 model;

out vec4 colorfs;

void main(){
	 gl_Position = projection * lookat * model * vec4(position, 1.0f);
	 colorfs = vec4(position, 1.0f);
}