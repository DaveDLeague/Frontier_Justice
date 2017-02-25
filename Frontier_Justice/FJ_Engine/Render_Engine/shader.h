#pragma once

#include <string>
#include <map>

#include <GL/glew.h>

#include "../fj_math.h"

class Shader
{
public:
    GLuint ID;

    Shader();
    void use();
    void compile(const char* vertSrc, const char* fragSrc, const char* geoSrc = nullptr);
    void createUniform(std::string name);

    void loadUniform1f(std::string name, float v);
    void loadUniform2f(std::string name, float v1, float v2);
    void loadUniform2f(std::string name, vec2 v);
    void loadUniform3f(std::string name, float v1, float v2, float v3);
    void loadUniform3f(std::string name, vec3 v);
    void loadUniform4f(std::string name, float v1, float v2, float v3, float v4);
    void loadUniform4f(std::string name, vec4 v);
    void loadUniformMat3(std::string name, mat3 m);
    void loadUniformMat4(std::string name, mat4 m);

private:
    void checkErrors(GLuint obj, std::string type);
    std::map<std::string, int> uniforms;
};

