#version 330 core

out vec4 finalColor;

in vec3 pos;
in vec3 norm;
in vec4 fColor;
void main(void)
{
    finalColor = fColor;
}
