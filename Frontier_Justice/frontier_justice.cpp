#include "frontier_justice.h"

#include <GL/glew.h>

FrontierJustice::FrontierJustice(){

}

bool FrontierJustice::init(){
    if(!FJEngine::init()){
        return false;
    }

    return true;
}

void FrontierJustice::start(){
    GameWindow *window = FJEngine::createGameWindow("Frontier Justice", 0, 0, 800, 600);
    //window->toggleFullScreen();

    Shader light;

    light.compile("../Frontier_Justice/FJ_Engine/Render_Engine/shaders/flat_vert.glsl",
                  "../Frontier_Justice/FJ_Engine/Render_Engine/shaders/flat_frag.glsl");

    light.createUniform("viewMat");
    light.createUniform("modelMat");
    light.createUniform("projMat");

    GLfloat verts[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

    GLuint vao, vbo;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    GLuint lightVAO;
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    Camera cam(vec3(0, 0, -10), vec3(0, 1, 0));
    cam.setPerspective(-75.0f, window->getWidth()/window->getHeight(), 0.0001, 1000);

    long startTime = SDL_GetTicks();
    long endTime = startTime;
    float deltaTime;
    bool quit = false;
    while(!quit){
        deltaTime = endTime - startTime;
        startTime = SDL_GetTicks();

        if(InputManager::keys[InputManager::RIGHT_KEY]){
            cam.yaw = -0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::LEFT_KEY]){
            cam.yaw = 0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::UP_KEY]){
            cam.pitch = 0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::DOWN_KEY]){
            cam.pitch = -0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::Q_KEY]){
            cam.roll = -0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::E_KEY]){
            cam.roll = 0.001 * deltaTime;
        }

        if(InputManager::keys[InputManager::W_KEY]){
            cam.position -= cam.forward * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::S_KEY]){
            cam.position += cam.forward * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::A_KEY]){
            cam.position += cam.right * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::D_KEY]){
            cam.position -= cam.right * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::R_KEY]){
            cam.position -= cam.up * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::F_KEY]){
            cam.position += cam.up * 0.01f * deltaTime;
        }

        FJEngine::update();
        if(InputManager::keys[InputManager::ESC_KEY]){
            quit = true;
        }

        cam.update();
        light.use();
        light.loadUniformMat4("viewMat", cam.viewMatrix);

        glBindVertexArray(vao);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        window->update();
        endTime = SDL_GetTicks();
    }
}
