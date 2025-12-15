#version 330 core
in vec4 vertex;
in vec2 uv0;
uniform mat4 modelViewProjMat;
out vec2 vUv0;
uniform float sintime;
uniform float radio;
uniform vec2 centro;
uniform float altura;


void main() {
    vUv0 = uv0;

    vec4 vertexCord = vertex;

    if(vertexCord.x < centro.x + radio && vertexCord.x > centro.x - radio
    && vertexCord.z < centro.y + radio && vertexCord.z > centro.y - radio)
    {
        float distX = radio - abs(vertexCord.x - centro.x);
        float altX = distX * altura / radio;

        float distZ = radio - abs(vertexCord.z - centro.y);
        float altZ = distZ * altura / radio;

        vertexCord.y += abs(sintime * altX) + abs(sintime * altZ);
    }


    gl_Position = modelViewProjMat * vertexCord;
}