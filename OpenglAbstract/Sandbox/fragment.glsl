#version 440 core

uniform vec2 pos;
uniform vec4 color;
out vec4 color_out;
in vec2 currentPos;

void main()
{
	//float intens = 25.0 / length(gl_FragCoord.xy - pos.xy);
	//color_out = color * intens;
	float intens = 0.05 / length(currentPos - pos);
	color_out = color * intens;
}