#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 textureCoordinates;

out vec2 textureCoords;

out vec3 fragNormal;
out vec3 fragPosition;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;

void main(void)
{
    fragNormal = vec3(modelMatrix * vec4(normal, 0));
    fragPosition = vec3(modelMatrix * vec4(position, 1));

    textureCoords.x = textureCoordinates.x;
    textureCoords.y = 1 - textureCoordinates.y;

    gl_Position = viewMatrix * vec4(fragPosition, 1.0);
}
