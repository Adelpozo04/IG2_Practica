#version 330 core

in vec4 vertex;
in vec2 uv0;

out vec2 vUv0;

uniform mat4 modelViewProjMat;
uniform float sinTime;

void main(){

    vUv0 = uv0;

    vec4 center = vec4(0,0,0,0);
    float a = 5;
    float b = 3;
    vec4 vertexCoord = vertex;
    float distanceCenter = distance(vertex, center);

    vertexCoord.y += sin(vertexCoord.x + (sinTime*a)) * b + sin(vertexCoord.z + (distanceCenter) + (sinTime*a)) * b;

    gl_Position = modelViewProjMat * vertexCoord;
    
}