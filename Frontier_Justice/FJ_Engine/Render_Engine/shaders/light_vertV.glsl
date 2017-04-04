#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;

uniform vec3 lightPosition;
uniform vec3 modelColor;

out vec3 pos;
out vec3 norm;

out vec4 fColor;

void main(void)
{
    pos = vec3(modelMatrix * vec4(position, 1));
    norm = vec3(modelMatrix * vec4(-normal, 0));


    vec3 dVec = normalize(lightPosition - pos);
    float dif = max(dot(dVec, norm), 0.0);

    fColor = vec4(dif * modelColor, 1);

    gl_Position = viewMatrix * vec4(pos, 1);
}
