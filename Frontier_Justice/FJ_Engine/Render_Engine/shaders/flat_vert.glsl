#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 tCoord;
layout(location = 2) in vec3 normals;

out vec2 texCoord;
out vec3 vecNorm;
out vec3 fragPos;

uniform mat4 modelMat;
uniform mat4 viewMat;

void main(void)
{
    texCoord = vec2(tCoord.x, 1 - tCoord.y);
    fragPos = vec3(modelMat * vec4(position, 1.0f));
    vecNorm = mat3(transpose(inverse(modelMat))) * normals;
    gl_Position = viewMat * modelMat * vec4(position, 1.0);
}
