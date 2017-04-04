#include "shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(){

}

void Shader::operator=(Shader *s){
    this->glID = s->glID;
    this->id = s->id;
}

void Shader::use(){
    glUseProgram(this->glID);
}

void Shader::compile(const char* vertSrc, const char* fragSrc, const char* geoSrc){
    GLuint sVertex, sFragment, gShader;

    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    try
    {
        // Open files
        std::ifstream vertexShaderFile(vertSrc);
        std::ifstream fragmentShaderFile(fragSrc);
        std::stringstream vShaderStream, fShaderStream;
        // Read file's buffer contents into streams
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();
        // close file handlers
        vertexShaderFile.close();
        fragmentShaderFile.close();
        // Convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        // If geometry shader path is present, also load a geometry shader
        if (geoSrc != nullptr)
        {
            std::ifstream geometryShaderFile(geoSrc);
            std::stringstream gShaderStream;
            gShaderStream << geometryShaderFile.rdbuf();
            geometryShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    }
    catch (std::exception e)
    {
        std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }
    const GLchar *vShaderCode = vertexCode.c_str();
    const GLchar *fShaderCode = fragmentCode.c_str();
    const GLchar *gShaderCode = geometryCode.c_str();

    sVertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(sVertex, 1, &vShaderCode, NULL);
    glCompileShader(sVertex);
    checkErrors(sVertex, "VERTEX");

    sFragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sFragment, 1, &fShaderCode, NULL);
    glCompileShader(sFragment);
    checkErrors(sFragment, "FRAGMENT");

    if (gShaderCode != nullptr)
    {
        gShader = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(gShader, 1, &gShaderCode, NULL);
        glCompileShader(gShader);
        checkErrors(gShader, "GEOMETRY");
    }

    this->glID = glCreateProgram();
    glAttachShader(this->glID, sVertex);
    glAttachShader(this->glID, sFragment);
    if (geoSrc != nullptr)
        glAttachShader(this->glID, gShader);
    glLinkProgram(this->glID);
    checkErrors(this->glID, "PROGRAM");


    glDeleteShader(sVertex);
    glDeleteShader(sFragment);
    if (geoSrc != nullptr){
        glDeleteShader(gShader);
    }
}

void Shader::createUniform(std::string name){
    uniforms[name] = glGetUniformLocation(this->glID, name.c_str());
}

void Shader::loadUniform1f(std::string name, float v){
    glUniform1f(uniforms[name], v);
}

void Shader::loadUniform2f(std::string name, float v1, float v2){
    glUniform2f(uniforms[name], v1, v2);
}

void Shader::loadUniform2f(std::string name, vec2 v){
    glUniform2f(uniforms[name], v.x, v.y);
}

void Shader::loadUniform3f(std::string name, float v1, float v2, float v3){
    glUniform3f(uniforms[name], v1, v2, v3);
}

void Shader::loadUniform3f(std::string name, vec3 v){
    glUniform3f(uniforms[name], v.x, v.y, v.z);
}

void Shader::loadUniform4f(std::string name, float v1, float v2, float v3, float v4){
    glUniform4f(uniforms[name], v1, v2, v3, v4);
}

void Shader::loadUniform4f(std::string name, vec4 v){
    glUniform4f(uniforms[name], v.x, v.y, v.z, v.w);
}

void Shader::loadUniform1i(std::string name, int i){
     glUniform1i(uniforms[name], i);
}

void Shader::loadUniformMat3(std::string name, mat3 m){
    glUniformMatrix3fv(uniforms[name], 1, GL_FALSE, value_ptr(m));
}

void Shader::loadUniformMat4(std::string name, mat4 m){
    glUniformMatrix4fv(uniforms[name], 1, GL_FALSE, value_ptr(m));
}

void Shader::checkErrors(GLuint obj, std::string type){
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(obj, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(obj, 1024, NULL, infoLog);
            std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
                << infoLog << "\n -- --------------------------------------------------- -- "
                << std::endl;
        }
    }
    else
    {
        glGetProgramiv(obj, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(obj, 1024, NULL, infoLog);
            std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
                << infoLog << "\n -- --------------------------------------------------- -- "
                << std::endl;
        }
    }
}

