#version 440 core

attribute vec3 coord;
uniform mat4 cameraMatrix;

out vec4 colorfs;

void main(){
	 gl_Position = cameraMatrix * vec4(coord, 1.0f);
	 colorfs = vec4(coord, 1.0f);
}