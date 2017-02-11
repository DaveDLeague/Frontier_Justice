#include <iostream>

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "ResourceManager.h"
#include "maths_funcs.h"

int main(int argc, char *argv[])
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Frontier Justice", 0, 0, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    glewInit();
    glClearColor(1, 1, 0, 0);
    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LESS);

    GLfloat points[] = {
             0.0f,	0.5f,	0.0f,
             0.5f, -0.5f,	0.0f,
            -0.5f, -0.5f,	0.0f
        };

    float normals[] = {
            0.0f, 0.0f,  1.0f,
            0.0f, 0.0f,  1.0f,
            0.0f, 0.0f,  1.0f,
        };

    GLuint pointsVBO;
    GLuint normalsVBO;

    glGenBuffers(1, &pointsVBO);
    glGenBuffers(1, &normalsVBO);

    glBindBuffer(GL_ARRAY_BUFFER, pointsVBO);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), points, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, normalsVBO);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), normals, GL_STATIC_DRAW);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, pointsVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glBindBuffer(GL_ARRAY_BUFFER, normalsVBO);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    Shader s = ResourceManager::loadShader("../Frontier_Justice/phong_vs.glsl", "../Frontier_Justice/phong_fs.glsl", NULL, "phong");

    #define ONE_DEG_IN_RAD (2.0 * M_PI) / 360.0 // 0.017444444
    // input variables
    float near = 0.1f; // clipping plane
    float far = 100.0f; // clipping plane
    float fov = 67.0f * ONE_DEG_IN_RAD; // convert 67 degrees to radians
    float aspect = (float)640 / (float)480; // aspect ratio
    // matrix components
    float range = tan (fov * 0.5f) * near;
    float Sx = (2.0f * near) / (range * aspect + range * aspect);
    float Sy = near / range;
    float Sz = -(far + near) / (far - near);
    float Pz = -(2.0f * far * near) / (far - near);
    GLfloat proj_mat[] = {
        Sx, 0.0f, 0.0f, 0.0f,
        0.0f, Sy, 0.0f, 0.0f,
        0.0f, 0.0f, Sz, -1.0f,
        0.0f, 0.0f, Pz, 0.0f
    };

    float cam_pos[] = {0.0f, 0.0f, 2.0f}; // don't start at zero, or we will be too close
        float cam_yaw = 0.0f; // y-rotation in degrees
        mat4 T = translate(identity_mat4(), vec3(-cam_pos[0], -cam_pos[1], -cam_pos[2]));
        mat4 R = rotate_y_deg(identity_mat4 (), -cam_yaw);
        mat4 view_mat = R * T;

        mat4 model_mat = identity_mat4 ();

        s.setMatrix4f("view_mat", view_mat.m, true);
        s.setMatrix4f("projection_mat", proj_mat, true);
        s.setMatrix4f("model_mat", model_mat.m, true);


        glEnable (GL_CULL_FACE); // cull face
        glCullFace (GL_BACK); // cull back face
        glFrontFace (GL_CW); // GL_CCW for counter clock-wise

    bool quit = false;
    SDL_Event event;
    float val = 0;
    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.key.keysym.sym == SDLK_ESCAPE || event.type == SDL_QUIT){
                quit = true;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport (0, 0, 640, 480);
        s.use();

        model_mat.m[12] = sinf (val);
        val += 0.01;
        s.setMatrix4f("model_mat", model_mat.m, true);

        glBindVertexArray (vao);

        glDrawArrays (GL_TRIANGLES, 0, 3);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
