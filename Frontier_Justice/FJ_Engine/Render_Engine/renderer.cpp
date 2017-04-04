#include "renderer.h"

Renderer::Renderer(){

}

void Renderer::setShader(Shader s){
    this->shader = s;
}

void Renderer::loadShader(const char* vShader, const char* fShader, const char* gShader){
    shader.compile(vShader, fShader, gShader);
    shader.createUniform("viewMat");
    shader.createUniform("modelMat");
    shader.createUniform("modelColor");
}

void Renderer::render(GameObject* objects, Camera* camera){
    int endIndex = startingIndex + totalObjects;

    shader.use();
    for(int i = startingIndex; i < endIndex; i++){
        glBindVertexArray(objects[i].mesh->vao);
        shader.loadUniformMat4("viewMat", camera->viewMatrix);
        shader.loadUniformMat4("modelMat", objects[i].modelMatrix);
        shader.loadUniform4f("modelColor", vec4(0.0, 1.0, 0.0, 1.0));
        glDrawArrays(GL_TRIANGLES, 0, (objects[i].mesh->vertexCount / 3));

    }
}
