#pragma once

#include <string>
#include <map>

#include <GL/glew.h>

#include "../math_util.h"

class Shader
{
public:
    int id;

    Shader();
    void operator=(Shader* s);

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
    void loadUniform1i(std::string name, int i);
    void loadUniformMat3(std::string name, mat3 m);
    void loadUniformMat4(std::string name, mat4 m);

private:
    GLuint glID;
    void checkErrors(GLuint obj, std::string type);
    std::map<std::string, int> uniforms;
};

