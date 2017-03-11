#include "frontier_justice.h"

#include <GL/glew.h>

#include <time.h>
#include <stdlib.h>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

float verts[] = {
    -1.0, -1.0, 1.0,
    -1.0, 1.0, 1.0,
    1.0, 1.0, 1.0,
    1.0, 1.0, 1.0,
    1.0, -1.0, 1.0,
    -1.0, -1.0, 1.0,

    -1.0, -1.0, 1.0,
    -1.0, -1.0, -1.0,
    -1.0, 1.0, 1.0,
    -1.0, 1.0, 1.0,
    -1.0, -1.0, -1.0,
    -1.0, 1.0, -1.0,

    1.0, -1.0, -1.0,
    1.0, 1.0, -1.0,
    -1.0, 1.0, -1.0,
    -1.0, 1.0, -1.0,
    -1.0, -1.0, -1.0,
    1.0, -1.0, -1.0,

    1.0, -1.0, 1.0,
    1.0, 1.0, 1.0,
    1.0, 1.0, -1.0,
    1.0, 1.0, -1.0,
    1.0, -1.0, -1.0,
    1.0, -1.0, 1.0,

    -1.0, 1.0, 1.0,
    -1.0, 1.0, -1.0,
    1.0, 1.0, -1.0,
    1.0, 1.0, -1.0,
    1.0, 1.0, 1.0,
    -1.0, 1.0, 1.0,

    -1.0, -1.0, -1.0,
    -1.0, -1.0, 1.0,
    1.0, -1.0, 1.0,
    1.0, -1.0, 1.0,
    1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0
};

float norms[] = {
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 1.0,

    -1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0,

    0.0, 0.0, -1.0,
    0.0, 0.0, -1.0,
    0.0, 0.0, -1.0,
    0.0, 0.0, -1.0,
    0.0, 0.0, -1.0,
    0.0, 0.0, -1.0,

    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0,

    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,

    0.0, -1.0, 0.0,
    0.0, -1.0, 0.0,
    0.0, -1.0, 0.0,
    0.0, -1.0, 0.0,
    0.0, -1.0, 0.0,
    0.0, -1.0, 0.0
};

bool load_mesh (const char* file_name, GLuint* vao, int* point_count) {
    const aiScene* scene = aiImportFile (file_name, aiProcess_Triangulate);
    if (!scene) {
        fprintf (stderr, "ERROR: reading mesh %s\n", file_name);
        return false;
    }
    printf ("  %i animations\n", scene->mNumAnimations);
    printf ("  %i cameras\n", scene->mNumCameras);
    printf ("  %i lights\n", scene->mNumLights);
    printf ("  %i materials\n", scene->mNumMaterials);
    printf ("  %i meshes\n", scene->mNumMeshes);
    printf ("  %i textures\n", scene->mNumTextures);

    /* get first mesh in file only */
    const aiMesh* mesh = scene->mMeshes[0];
    printf ("    %i vertices in mesh[0]\n", mesh->mNumVertices);

    /* pass back number of vertex points in mesh */
    *point_count = mesh->mNumVertices;

    /* generate a VAO, using the pass-by-reference parameter that we give to the
    function */
    glGenVertexArrays (1, vao);
    glBindVertexArray (*vao);

    /* we really need to copy out all the data from AssImp's funny little data
    structures into pure contiguous arrays before we copy it into data buffers
    because assimp's texture coordinates are not really contiguous in memory.
    i allocate some dynamic memory to do this. */
    GLfloat* points = NULL; // array of vertex points
    GLfloat* normals = NULL; // array of vertex normals
    GLfloat* texcoords = NULL; // array of texture coordinates
    if (mesh->HasPositions ()) {
        points = (GLfloat*)malloc (*point_count * 3 * sizeof (GLfloat));
        for (int i = 0; i < *point_count; i++) {
            const aiVector3D* vp = &(mesh->mVertices[i]);
            points[i * 3] = (GLfloat)vp->x;
            points[i * 3 + 1] = (GLfloat)vp->y;
            points[i * 3 + 2] = (GLfloat)vp->z;
        }
    }
    if (mesh->HasNormals ()) {
        normals = (GLfloat*)malloc (*point_count * 3 * sizeof (GLfloat));
        for (int i = 0; i < *point_count; i++) {
            const aiVector3D* vn = &(mesh->mNormals[i]);
            normals[i * 3] = (GLfloat)vn->x;
            normals[i * 3 + 1] = (GLfloat)vn->y;
            normals[i * 3 + 2] = (GLfloat)vn->z;
        }
    }
    if (mesh->HasTextureCoords (0)) {
        texcoords = (GLfloat*)malloc (*point_count * 2 * sizeof (GLfloat));
        for (int i = 0; i < *point_count; i++) {
            const aiVector3D* vt = &(mesh->mTextureCoords[0][i]);
            texcoords[i * 2] = (GLfloat)vt->x;
            texcoords[i * 2 + 1] = (GLfloat)vt->y;
        }
    }

    /* copy mesh data into VBOs */
    if (mesh->HasPositions ()) {
        GLuint vbo;
        glGenBuffers (1, &vbo);
        glBindBuffer (GL_ARRAY_BUFFER, vbo);
        glBufferData (
            GL_ARRAY_BUFFER,
            3 * *point_count * sizeof (GLfloat),
            points,
            GL_STATIC_DRAW
        );
        glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray (0);
        free (points);
    }
    if (mesh->HasNormals ()) {
        GLuint vbo;
        glGenBuffers (1, &vbo);
        glBindBuffer (GL_ARRAY_BUFFER, vbo);
        glBufferData (
            GL_ARRAY_BUFFER,
            3 * *point_count * sizeof (GLfloat),
            normals,
            GL_STATIC_DRAW
        );
        glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray (1);
        free (normals);
    }
    if (mesh->HasTextureCoords (0)) {
        GLuint vbo;
        glGenBuffers (1, &vbo);
        glBindBuffer (GL_ARRAY_BUFFER, vbo);
        glBufferData (
            GL_ARRAY_BUFFER,
            2 * *point_count * sizeof (GLfloat),
            texcoords,
            GL_STATIC_DRAW
        );
        glVertexAttribPointer (2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray (2);
        free (texcoords);
    }
    if (mesh->HasTangentsAndBitangents ()) {
        // NB: could store/print tangents here
    }

    aiReleaseImport (scene);
    printf ("mesh loaded\n");

    return true;
}

void calcModelMat(GameObject* o){
    o->modelMatrix = mat4(1);
    quat qyaw = angleAxis(o->rotation.y, vec3(0, 1, 0));
    quat qpitch = angleAxis(o->rotation.x, vec3(1, 0, 0));
    quat qroll = angleAxis(o->rotation.z, vec3(0, 0, 1));
    o->rotQuat = qroll * qyaw * qpitch * o->rotQuat;
    o->modelMatrix = translate(o->modelMatrix, o->position);
    o->modelMatrix = o->modelMatrix * mat4_cast(o->rotQuat);
    o->modelMatrix = scale(o->modelMatrix, o->scale);
}

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

    Camera cam(vec3(0, 0, -10), vec3(0, 1, 0));
    cam.setPerspective(-75.0f, window->getWidth()/window->getHeight(), 0.0001f, 1000.0f);
    cam.position.z = -30;


    Shader shad;
    shad.compile("../Frontier_Justice/FJ_Engine/Render_Engine/shaders/light_vert.glsl",
                 "../Frontier_Justice/FJ_Engine/Render_Engine/shaders/light_frag.glsl");
    shad.createUniform("modelMatrix");
    shad.createUniform("viewMatrix");
    shad.createUniform("lightPosition");

    Shader fshad;
    fshad.compile("../Frontier_Justice/FJ_Engine/Render_Engine/shaders/flat_vert.glsl",
                 "../Frontier_Justice/FJ_Engine/Render_Engine/shaders/flat_frag.glsl");
    fshad.createUniform("modelMatrix");
    fshad.createUniform("viewMatrix");
    fshad.createUniform("modelColor");



    int size = 3*6*6;

    Mesh tri;
    tri.addVertices(verts, size);
    tri.addNormalCoordinates(norms, size);

    GameObject o;
    Mesh m;
    load_mesh("../Frontier_Justice/res/models/monkey2.obj", &m.vao, &m.vertexCount);
    o.mesh = &tri;

    GameObject l;
    l.mesh = &m;

    long startTime = SDL_GetTicks();
    long endTime = startTime;
    long fpsTime = startTime;
    float deltaTime;
    bool quit = false;
    int fps = 0;

    float rotationSpeed = 0.0005f;
    float movementSpeed = 0.005f;

    vec3 lightPosition = vec3(5, 5, 5);

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

        cam.update();

        shad.use();
        glBindVertexArray(o.mesh->vao);

        o.rotation.y = 0.0001;

        calcModelMat(&o);
        shad.loadUniformMat4("modelMatrix", o.modelMatrix);
        shad.loadUniformMat4("viewMatrix", cam.viewMatrix);
        shad.loadUniform3f("lightPosition", lightPosition);

        glDrawArrays(GL_TRIANGLES, 0, o.mesh->vertexCount / 3);

        l.position = lightPosition;
        l.scale.x = 0.25;
        l.scale.y = 0.25;
        l.scale.z = 0.25;

        calcModelMat(&l);
        fshad.use();
        glBindVertexArray(l.mesh->vao);
        fshad.loadUniformMat4("modelMatrix", l.modelMatrix);
        fshad.loadUniformMat4("viewMatrix", cam.viewMatrix);
        fshad.loadUniform4f("modelColor", vec4(1, 1, 1, 1));
        glDrawArrays(GL_TRIANGLES, 0, l.mesh->vertexCount);

        //lightPosition.x -= 0.00001;
        lightPosition.y -= 0.00001;

        window->update();
        endTime = SDL_GetTicks();
    }
}
