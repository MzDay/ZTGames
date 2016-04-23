#version 440 core

attribute vec4 coord;
uniform mat4 cameraMatrix;

out vec4 colorfs;

void main(){
	 gl_Position = cameraMatrix * vec4(coord.xyz, 1.0f);
	 colorfs = vec4(coord.xyz, 1.0f);
}