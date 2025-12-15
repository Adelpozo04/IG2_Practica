#version 330 core

in vec4 vertex;
in vec2 uv0;

uniform mat4 modelViewProjMat;
uniform vec2 pos;
uniform int rad;
uniform float altura;
uniform float senotiempo;

out vec2 Vuv0;
out vec4 VvertexCoord;
out vec2 Vpos;

void main(){

    vec4 vertexCoord = vertex;

    Vuv0 = uv0;
    VvertexCoord = vertexCoord;
    Vpos = pos;
    
    if(vertexCoord.x > pos.x - rad && vertexCoord.x < pos.x + rad && vertexCoord.z > pos.y - rad && vertexCoord.z < pos.y + rad){

        float cercania = rad - abs(vertexCoord.x - pos.x);

        float trueAltura = (cercania * altura) / rad;

        float cercaniaZ = rad - abs(vertexCoord.z - pos.y);

        float trueAlturaZ = (cercaniaZ * altura) / rad;

        vertexCoord.y = vertexCoord.y + (trueAltura * abs(senotiempo)) + (trueAlturaZ * abs(senotiempo) );
    }
    
    gl_Position = modelViewProjMat * vertexCoord;
    
}