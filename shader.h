#pragma once

#include <string>
#include <vector>

#include <GL/glew.h>

#include "game_math.h"

using namespace std;

class Shader {
public:
    Shader();
    ~Shader();

    inline GLuint getProgram() const {
        return program;
    }

    void createProgram(string vertexFile, string fragmentFile);
    void useProgram();
    void setUniform1f(int loc, float v);
    void setUniform2f(int loc, float v1, float v2);
    void setUniform3f(int loc, float v1, float v2, float v3);
    void setUniform4f(int loc, float v1, float v2, float v3, float v4);
    void setUniform1i(int loc, int v);
    void setUniform2i(int loc, int v1, int v2);
    void setUniform3i(int loc, int v1, int v2, int v3);
    void setUniform4i(int loc, int v1, int v2, int v3, int v4);
    void setUniform1ui(int loc, unsigned int v);
    void setUniform2ui(int loc, unsigned int v1, unsigned int v2);
    void setUniform3ui(int loc, unsigned int v1, unsigned int v2, unsigned int v3);
    void setUniform4ui(int loc, unsigned int v1, unsigned int v2, unsigned int v3, unsigned int v4);


    void setUniform2f(int loc, int count, Vec2f &v);
    void setUniform3f(int loc, int count, Vec3f &v);
    void setUniform4f(int loc, int count, Vec4f &v);
    void setUniform1fi(int loc, int count, int *v);
    void setUniform2fi(int loc, int count, int *v);
    void setUniform3fi(int loc, int count, int *v);
    void setUniform4f(int loc, int count, int *v);
    void setUniform1fui(int loc, int count, unsigned int *v);
    void setUniform2fui(int loc, int count, unsigned int *v);
    void setUniform3fui(int loc, int count, unsigned int *v);
    void setUniform4fui(int loc, int count, unsigned int *v);

    void setUniformMat4(int loc, Mat4f &v);


    int getUniformLocation(string name);

private:

    GLuint program;
    vector<GLuint> uniformLocations;
};
