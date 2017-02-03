#include "render_utility.h"

RenderUtility::RenderUtility(){

}

void RenderUtility::clearScreen(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderUtility::init(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE | GL_DEPTH_TEST | GL_FRAMEBUFFER_SRGB);
}
