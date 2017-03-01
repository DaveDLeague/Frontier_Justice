#version 330 core

out vec4 finalColor;

in vec2 texCoord;
in vec3 vecNorm;
in vec3 fragPos;

uniform vec3 lightPosition;
uniform vec3 viewPosition;
uniform vec3 lightColor;
uniform vec3 objectColor;

uniform sampler2D tex;

void main(void)
{
    //ambient
    float ambientStrength = 0.001f;
    vec3 ambient = ambientStrength * lightColor;

    //diffuse
    vec3 norm = normalize(vecNorm);
    vec3 lightDir = normalize(lightPosition - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    //specular
    float specStrength = 0.5;
    vec3 viewDir = normalize(viewPosition - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specStrength * spec * lightDir;

    vec4 img = texture(tex, texCoord);

    vec3 result = (ambient + diffuse + specular) * img.xyz;

    finalColor = vec4(result, img.w);
}
