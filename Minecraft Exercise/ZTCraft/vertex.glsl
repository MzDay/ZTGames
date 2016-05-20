#version 440 core

layout(location = 0) in vec3 coord;

uniform mat4 cameraMatrix;
uniform mat4 model;

out vec4 colorfs;

void main(){
	 gl_Position = cameraMatrix * model * vec4(coord.xyz, 1.0f);
	 colorfs = gl_Position;
}