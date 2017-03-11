#version 330 core

out vec4 finalColor;

in vec2 texCoords;

uniform sampler2D tex2D;

void main(void)
{
    vec2 newTexCoords = vec2(texCoords.x, 1 - texCoords.y);
    finalColor = texture(tex2D, newTexCoords);
}
