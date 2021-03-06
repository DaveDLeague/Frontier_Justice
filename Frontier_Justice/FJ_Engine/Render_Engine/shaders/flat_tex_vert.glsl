#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 textureCoordinates;

out vec2 texCoords;

uniform mat4 modelMat;
uniform mat4 viewMat;

void main(void)
{
    texCoords = textureCoordinates;
    gl_Position = viewMat * modelMat * vec4(position, 1.0);
}
