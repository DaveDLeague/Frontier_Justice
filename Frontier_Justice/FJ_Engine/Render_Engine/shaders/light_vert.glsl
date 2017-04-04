#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;

out vec3 pos;
out vec3 norm;

void main(void)
{
    pos = vec3(modelMatrix * vec4(position, 1));
    norm = vec3(modelMatrix * vec4(-normal, 0));
    gl_Position = viewMatrix * vec4(pos, 1);
}
