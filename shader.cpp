#include "shader.h"

#include <iostream>
#include <fstream>

static string parseShader(string fileName) {
    ifstream file(fileName.c_str());
    string shaderStr = "";
    string line = "";

    if (file.is_open()) {
        while (getline(file, line)) {
            shaderStr += line;
            shaderStr += '\n';
            //cout << line << '\n';
        }
        file.close();
    } else {
        cout << "unable to open file " << fileName << endl;
    }

    return shaderStr;
}

Shader::Shader(){

}

Shader::~Shader() {
    glDeleteProgram(program);
}

void Shader::createProgram(string vertexFile, string fragmentFile){
    string vs = parseShader(vertexFile);
    string fs = parseShader(fragmentFile);

    const GLchar* vertexShaderSource = vs.c_str();
    const GLchar* fragmentShaderSource = fs.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog
                << std::endl;
    }


    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog
                << std::endl;
    }

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog
                << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::useProgram(){
    glUseProgram(program);
}

void Shader::setUniform1f(int loc, float v){
    glUniform1f((GLuint)loc, v);
}

void Shader::setUniform2f(int loc, float v1, float v2){
    glUniform2f((GLuint)loc, v1, v2);
}

void Shader::setUniform3f(int loc, float v1, float v2, float v3){
    glUniform3f((GLuint)loc, v1, v2, v3);
}

void Shader::setUniform4f(int loc, float v1, float v2, float v3, float v4){
    glUniform4f((GLuint)loc, v1, v2, v3, v4);
}

void Shader::setUniform1i(int loc, int v){
    glUniform1i((GLuint)loc, (GLint)v);
}

void Shader::setUniform2i(int loc, int v1, int v2){
    glUniform2i((GLuint)loc, (GLint)v1, (GLint)v2);
}

void Shader::setUniform3i(int loc, int v1, int v2, int v3){
    glUniform3i((GLuint)loc, (GLint)v1, (GLint)v2, (GLint)v3);
}

void Shader::setUniform4i(int loc, int v1, int v2, int v3, int v4){
    glUniform4i((GLuint)loc, (GLint)v1, (GLint)v2, (GLint)v3, (GLint)v4);
}

void Shader::setUniform2f(int loc, int count, Vec2f &v){
    float f[2] = {v.x, v.y};
    glUniform2fv((GLuint)loc, (GLsizei)count, f);
}

void Shader::setUniform3f(int loc, int count, Vec3f &v){
    float f[3] = {v.x, v.y, v.z};
    glUniform3fv((GLuint)loc, (GLsizei)count, f);
}

void Shader::setUniform4f(int loc, int count, Vec4f &v){
    float f[4] = {v.x, v.y, v.z, v.w};
    glUniform4fv((GLuint)loc, (GLsizei)count, f);
}

void Shader::setUniformMat4(int loc, Mat4f &v){
   float m[16];

   int ctr = 0;
   for(int i = 0; i < 4; i++){
       for(int j = 0; j < 4; j++){
           m[ctr++] = v.matrix[i][j];
       }
   }

   glUniformMatrix4fv((GLuint)loc, 1, GL_TRUE, (GLfloat*)m);
}

int Shader::getUniformLocation(string name){
    GLuint loc = glGetUniformLocation(program, (GLchar*) name.c_str());
    uniformLocations.push_back(loc);
    return loc;
}
