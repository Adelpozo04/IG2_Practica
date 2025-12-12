#version 330 core

in vec2 vUv0;

uniform sampler2D TexturaZoom;

out vec4 fFragmentColor;

void main(){
    vec3 color = texture(TexturaZoom, vUv0).rgb;

    fFragmentColor = vec4(color, 1.0);
}