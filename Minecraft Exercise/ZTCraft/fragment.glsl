#version 440 core

in vec4 colorfs;
out vec4 color;

void main(){
	 color = colorfs;
	 //color = vec4(0.2f, 0.6f, 0.7f, 1.0f);
}