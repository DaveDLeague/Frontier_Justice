#include "frontier_justice.h"

#include <GL/glew.h>

#include <time.h>
#include <stdlib.h>

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

float tCoords[] = {
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f
};

float normals[] = {
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,

    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,

    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,
    -1.0f, 0.0f, 0.0f,

    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,

    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,

    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f
};

int sz = 3*6*6;

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
    flat->createUniform("modelMat");
    flat->createUniform("lightPosition");
    flat->createUniform("viewPosition");
    flat->createUniform("lightColor");
    flat->createUniform("objectColor");

    Mesh* m = s.createMesh(verts, sz);
    FJ_Object* box = s.createObject();
    s.addMeshToObject(box, m);
    s.attatchShaderToObject(box, flat);

    Camera cam(vec3(0, 0, -10), vec3(0, 1, 0));
    cam.setPerspective(-75.0f, window->getWidth()/window->getHeight(), 0.0001f, 1000.0f);

    unsigned char col[] = {128, 128, 128};
    Texture* t = s.createTexture();
    t->loadImage("../Frontier_Justice/res/textures/dragon.bmp", true);
    //t->loadData(col, 1, 1, false);
    s.addTextureToMesh(m, t, tCoords, 2*6*6);

    m->addNormalCoordinates(normals, sz);

    FJ_Object* light = s.createObject();
    Mesh* lmesh = s.createMesh(verts, sz);
    s.attatchShaderToObject(light, flat);
    s.addMeshToObject(light, lmesh);

    unsigned char lcolor[] = {255, 255, 255};
    Texture* ltex = s.createTexture();
    ltex->loadData(lcolor, 1, 1, false);
    s.addTextureToMesh(lmesh, ltex, tCoords, 2*6*6);

    vec3 lightPosition(1, 1, 1);

    light->scale = vec3(0.25f, 0.25f, 0.25f);
    light->position = lightPosition;

    long startTime = SDL_GetTicks();
    long endTime = startTime;
    long fpsTime = startTime;
    float deltaTime;
    bool quit = false;
    int fps = 0;

    float rotationSpeed = 0.0005f;
    float movementSpeed = 0.005f;

    flat->loadUniform3f("lightPosition", light->position);
    flat->loadUniform3f("viewPosition", cam.position);
    flat->loadUniform3f("lightColor", vec3(0, 0, 1));
    //flat->loadUniform3f("objectColor", );

    float r = 0, g = 0, b = 0;

    while(!quit){
        FJEngine::update();
        deltaTime = endTime - startTime;
        startTime = SDL_GetTicks();

        if(startTime - fpsTime >= 1000){
            printf("fps: %i\n", fps);
            fps = 0;
            fpsTime = startTime;
        }
        fps++;

        cam.yaw = 0;
        cam.yaw += InputManager::keys[InputManager::RIGHT_KEY] * rotationSpeed * deltaTime;
        cam.yaw -= InputManager::keys[InputManager::LEFT_KEY] * rotationSpeed * deltaTime;

        cam.pitch = 0;
        cam.pitch -= InputManager::keys[InputManager::UP_KEY] * rotationSpeed * deltaTime;
        cam.pitch += InputManager::keys[InputManager::DOWN_KEY] * rotationSpeed * deltaTime;

        cam.roll = 0;
        cam.roll += InputManager::keys[InputManager::Q_KEY] * rotationSpeed * deltaTime;
        cam.roll -= InputManager::keys[InputManager::E_KEY] * rotationSpeed * deltaTime;

        cam.position += cam.forward * movementSpeed * deltaTime * (float)InputManager::keys[InputManager::W_KEY];
        cam.position -= cam.forward * movementSpeed * deltaTime * (float)InputManager::keys[InputManager::S_KEY];
        cam.position -= cam.right * movementSpeed * deltaTime * (float)InputManager::keys[InputManager::A_KEY];
        cam.position += cam.right * movementSpeed * deltaTime * (float)InputManager::keys[InputManager::D_KEY];
        cam.position += cam.up * movementSpeed * deltaTime * (float)InputManager::keys[InputManager::R_KEY];
        cam.position -= cam.up * movementSpeed * deltaTime * (float)InputManager::keys[InputManager::F_KEY];

        quit = InputManager::keys[InputManager::ESC_KEY];


        flat->loadUniform3f("lightPosition", light->position);
        flat->loadUniform3f("viewPosition", cam.position);
        flat->loadUniform3f("lightColor", vec3(0, 0, 1));

        //box->rotation = vec3(0.0001, 0.0001, 0.0001);

        //light->position -= vec3(0.00001, 0, 0);

        flat->loadUniform3f("lightPosition", light->position);
        flat->loadUniform3f("viewPosition", cam.position);
        flat->loadUniform3f("lightColor", vec3(r, g, b));

        r += (float)InputManager::keys[InputManager::F1_KEY] * 0.0001;
        g += (float)InputManager::keys[InputManager::F2_KEY] * 0.0001;
        b += (float)InputManager::keys[InputManager::F3_KEY] * 0.0001;
        r -= (float)InputManager::keys[InputManager::F5_KEY] * 0.0001;
        g -= (float)InputManager::keys[InputManager::F6_KEY] * 0.0001;
        b -= (float)InputManager::keys[InputManager::F7_KEY] * 0.0001;

        cam.update();
        s.update();
        s.render(&cam);
        window->update();

        endTime = SDL_GetTicks();
    }
}
