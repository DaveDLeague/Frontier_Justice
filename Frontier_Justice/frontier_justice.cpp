#include "frontier_justice.h"

#include <GL/glew.h>

GLfloat verts[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f
    };

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
    //window->setFullScreen(true);
    //window->setVSync(true);

    Scene s;

    Shader* flat = s.createShader();
    flat->compile("../Frontier_Justice/FJ_Engine/Render_Engine/shaders/flat_vert.glsl",
                  "../Frontier_Justice/FJ_Engine/Render_Engine/shaders/flat_frag.glsl");
    flat->createUniform("viewMat");

    FJ_Object* box = s.createObject();
    s.addMeshToObject(box, verts, 6*6*3);
    s.attatchShaderToObject(box, flat);



    Camera cam(vec3(0, 0, -10), vec3(0, 1, 0));
    cam.setPerspective(-75.0f, window->getWidth()/window->getHeight(), 0.0001, 1000);

    long startTime = SDL_GetTicks();
    long endTime = startTime;
    long fpsTime = startTime;
    float deltaTime;
    bool quit = false;
    int fps = 0;

    float v = 0;

    while(!quit){
        deltaTime = endTime - startTime;
        startTime = SDL_GetTicks();

        if(SDL_GetTicks() -fpsTime >= 1000){
            printf("fps: %i\n", fps);
            fps = 0;
            fpsTime = SDL_GetTicks();
        }
        fps++;

        if(InputManager::keys[InputManager::RIGHT_KEY]){
            cam.yaw = +0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::LEFT_KEY]){
            cam.yaw = -0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::UP_KEY]){
            cam.pitch = -0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::DOWN_KEY]){
            cam.pitch = 0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::Q_KEY]){
            cam.roll = 0.001 * deltaTime;
        }
        if(InputManager::keys[InputManager::E_KEY]){
            cam.roll = -0.001 * deltaTime;
        }

        if(InputManager::keys[InputManager::W_KEY]){
            cam.position += cam.forward * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::S_KEY]){
            cam.position -= cam.forward * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::A_KEY]){
            cam.position -= cam.right * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::D_KEY]){
            cam.position += cam.right * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::R_KEY]){
            cam.position += cam.up * 0.01f * deltaTime;
        }
        if(InputManager::keys[InputManager::F_KEY]){
            cam.position -= cam.up * 0.01f * deltaTime;
        }

        FJEngine::update();
        if(InputManager::keys[InputManager::ESC_KEY]){
            quit = true;
        }

        box->modelMatrix = translate(mat4(1), vec3(sin(v), cos(v), v));
        v += 0.001 * deltaTime;

        cam.update();
        s.render(&cam);
        window->update();

        endTime = SDL_GetTicks();
    }
}
