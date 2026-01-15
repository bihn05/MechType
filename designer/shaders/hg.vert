#version 330 core

layout (location = 0) in vec3 aPos;
out vec2 TexCoords;

void main() {
    gl_Position = vec4(aPos, 1.0);
    float t=(aPos.x-(-0.7))/1.4;
    float v=aPos.y / 0.1;
    TexCoords=vec2(t,v);
}