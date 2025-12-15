#version 330 core
out vec4 fFragColor;
in vec2 vUv0;
uniform sampler2D texturaL; 

void main(void) {
    vec3 color = texture(texturaL, vUv0).rgb;
    fFragColor = vec4(color , 1.0);
}
