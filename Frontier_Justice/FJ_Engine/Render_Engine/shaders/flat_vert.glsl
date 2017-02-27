#version 330 core

layout(location = 0) in vec3 qt_Vertex;
layout(location = 1) in vec2 tCoord;

out vec2 texCoord;

uniform mat4 viewMat;

void main(void)
{
    texCoord = vec2(tCoord.x, 1 - tCoord.y);
    gl_Position = viewMat * vec4(qt_Vertex, 1.0);
}
