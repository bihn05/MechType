#version 330 core
out vec4 FragColor;

uniform float u_tightness; // ubso

void main() {

    float t = (gl_FragCoord.x / 800.0);

    float curve = 4.0 * t * (1.0 - t);

    float half_h = 0.05*(1.0-u_tightness*curve);
    float dist_y = abs((gl_FragCoord.y / 600.0) - 0.5);

    if (dist_y < half_h) {
        FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    } else {
        discard;
    }
}