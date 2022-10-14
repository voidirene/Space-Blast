#version 400 //TODO: rename?

layout (location = 0) in vec3 VertexPosition;
layout (location = 2) in vec3 VertexNormal;

out vec3 normal;
uniform mat4 transform;
uniform mat4 m;

//TEXTURE STUFF
attribute vec2 texCoord;
varying vec2 texCoord0;

void main()
{
	normal = mat3(transpose(inverse(m))) * VertexNormal;
	gl_Position = transform * vec4(VertexPosition, 1.0);

	//TEXTURE STUFF
	texCoord0 = texCoord;
}
