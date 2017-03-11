#version 330 core

out vec4 finalColor;
uniform vec4 modelColor;

void main(void)
{
    finalColor = modelColor;
}
