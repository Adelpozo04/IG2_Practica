#version 330 core

in vec4 vertex;
in vec2 uv0;

uniform mat4 modelViewProjMat;
uniform float ZoomFactor;
uniform float senotiempo;

out vec2 vUv0;

void main(){

    vUv0 = uv0;

    vUv0.s = (vUv0.s - 0.5) * abs(senotiempo) + 0.5;
    vUv0.t = (vUv0.t - 0.5) * abs(senotiempo) + 0.5;

    gl_Position = modelViewProjMat * vertex;

}