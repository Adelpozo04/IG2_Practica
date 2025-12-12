#version 330 core

in vec4 vertex;
in vec2 uv0;

uniform mat4 modelViewProjMat;
uniform vec2 pos;
uniform int rad;
uniform float altura;

out vec2 Vuv0;

void main(){

    Vuv0 = uv0;

    vec4 vertexCoord = vertex;

    if(vertexCoord.x > pos.x - rad && vertexCoord.x < pos.x + rad &&
       vertexCoord.z > pos.y - rad && vertexCoord.z < pos.y + rad){

        float cercania = rad - abs(vertexCoord.x - pos.x);

        float trueAltura = cercania * altura / (float)rad;

        vertexCoord.y += trueAltura;
    }

    gl_Position = modelViewProjMat * vertexCoord;
    
}