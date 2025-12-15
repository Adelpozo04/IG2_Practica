#version 330 core
in vec2 vUv0;
uniform sampler2D texturaL;
out vec4 fFragColor;

void main() 
{
    vec3 colorL = vec3(texture(texturaL, vUv0));
    fFragColor = vec4(colorL, 1.0);
}
