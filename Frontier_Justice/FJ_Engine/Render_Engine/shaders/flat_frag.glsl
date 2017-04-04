#version 330 core

out vec4 finalColor;

in vec2 textureCoords;

in vec3 fragNormal;
in vec3 fragPosition;

uniform vec3 lightPosition;

uniform sampler2D textureSampler;
uniform sampler2D normalSampler;

void main(void)
{
     vec4 tex = texture(textureSampler, textureCoords);
     vec4 norm = texture(normalSampler, textureCoords);
     norm = normalize(norm * 2.0 - 1.0);

    vec3 diffuseVec = normalize(lightPosition - fragPosition);
    float diffuse = max(dot(diffuseVec, fragNormal - norm.xyz), 0.0);

    vec3 outColor = diffuse * tex.xyz;

    finalColor = vec4(outColor, tex.w);
}
