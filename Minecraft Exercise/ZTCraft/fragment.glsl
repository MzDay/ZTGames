#version 440 core

in vec4 colorfs;
out vec4 color;

void main(){
	 color = normalize(colorfs*colorfs.y);
}