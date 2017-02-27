#version 330 core

in vec2 texCoord;

uniform sampler2D tex;

void main(void)
{
    gl_FragColor = texture(tex, texCoord);
}
