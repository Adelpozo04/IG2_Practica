#version 330 core

in vec4 vertex;
in vec2 uv0;

uniform mat4 modelViewProjectionMatrix;
uniform float Amplitud;
uniform float senotiempo;

out vec2 vUv0;

void main(){

    vec4 vertexCoord = vertex;
  
    if(vertexCoord.x < senotiempo * 750 + Amplitud && vertexCoord.x > senotiempo * 750 - Amplitud){
        vertexCoord.y += abs(abs(senotiempo * 750 - vertexCoord.x) - Amplitud);
    }
    
    vUv0 = uv0;
    gl_Position = modelViewProjectionMatrix * vertexCoord;
}