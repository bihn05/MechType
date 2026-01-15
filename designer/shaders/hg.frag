#version 330 core
out vec4 FragColor;
in vec2 TexCoords;

uniform float u_tightness; // ubso

void main() {

    float t = TexCoords.x;
    float v = TexCoords.y;

    float curve = 4.0 * t * (1.0 - t);

    float limit = 1.0 - u_tightness * curve;

    if (abs(v) < limit) {
        FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    } else {
        discard;
    }
}