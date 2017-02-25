attribute vec3 qt_Vertex;

uniform mat4 viewMat;

void main(void)
{
    gl_Position = viewMat * vec4(qt_Vertex, 1.0);
}
