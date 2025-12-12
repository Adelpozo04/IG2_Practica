#version 330 core

in vec2 vUv0;

out vec4 fFragColor;

uniform sampler2D TexturaAgua;

void main(){

    vec3 color = texture(TexturaAgua, vUv0).rgb;

    fFragColor = vec4(color, 1.0);
}