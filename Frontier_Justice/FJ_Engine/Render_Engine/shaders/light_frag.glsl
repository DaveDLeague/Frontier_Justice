#version 330 core

out vec4 finalColor;

in vec3 pos;
in vec3 norm;

uniform vec3 lightPosition;
uniform vec3 modelColor;

void main(void)
{
    vec3 dVec = normalize(lightPosition - pos);
    float dif = max(dot(dVec, norm), 0.0);

    vec4 fColor = vec4(dif * modelColor, 1);
    finalColor = fColor;
}
