#version 330 core

in vec2 Vuv0;

uniform sampler2D TexturaGrano;

out fFragColor;

void main(){

    vec4 colorGrano = texture(TexturaGrano, Vuv0);

    fFragColor = colorGrano;
}