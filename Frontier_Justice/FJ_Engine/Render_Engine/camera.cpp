#include "camera.h"

Camera::Camera(vec3 location, vec3 up){
    this->yaw = -0.0f;
    this->pitch = 0.0f;
    this->roll = 0.0f;
    this->position = location;
    this->worldUp = up;
    this->up = up;
    this->forward = vec3(0, 0, 1);
    this->right = vec3(1, 0, 0);

    this->id = mat4();
    this->viewMatrix = id;
    this->translation = id;
    this->rotation = id;
    this->projection = id;

    this->rotQuat = quat();
}

void Camera::update(){
    quat qyaw = angleAxis(yaw, vec3(up.x, up.y, up.z));
    quat qpitch = angleAxis(pitch, vec3(right.x, right.y, right.z));
    quat qroll = angleAxis(roll, vec3(forward.x, forward.y, forward.z));

    rotQuat = qroll * qyaw * qpitch * rotQuat;
    rotation = mat4_cast(rotQuat);
    forward = (vec3)(rotation * vec4(0.0f, 0.0f, -1.0f, 0.0f));
    up = (vec3)(rotation * vec4(0.0f, 1.0f, 0.0f, 0.0f));
    right = (vec3)(rotation * vec4(1.0f, 0.0f, 0.0f, 0.0f));

    translation = translate(id, position);
    viewMatrix = projection * inverse(rotation) * translation;

    yaw = 0;
    pitch = 0;
    roll = 0;
}

void Camera::setPerspective(float fov, float aspect, float znear, float zfar){
    projection = perspective(fov, aspect, znear, zfar);
}
