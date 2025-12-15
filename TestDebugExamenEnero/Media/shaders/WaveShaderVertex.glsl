#version 330 core
in vec4 vertex;
in vec2 uv0;
out vec2 vUv0;

uniform mat4 modelViewProjMat;
uniform float sintime;
uniform float a;
void main() {
    vec4 pos = vertex;
    
    if(pos.x < sintime*750 + a && pos.x > sintime*750 - a)
        pos.y += abs(abs(sintime * 750 - pos.x) - a);
    
    vUv0 = uv0;
    gl_Position = modelViewProjMat * pos;
}
