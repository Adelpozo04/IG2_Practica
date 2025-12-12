#version 330 core

in vec2 vUv0;

uniform sampler2D TexturaNegativa;
uniform float senotiempo;

out vec4 fFragmentColor;

void main(){
    vec3 color = texture(TexturaNegativa, vUv0).rgb;

    color.r = 1.0 - color.r;
    color.g = 1.0 - color.g;
    color.b = 1.0 - color.b;

    float trueSenTime = 0;

    if(abs(senotiempo) < 0.3){
        trueSenTime = 0.3;
    }
    else{
        trueSenTime = abs(senotiempo);
    }

    vec3 colorChange = vec3(trueSenTime, trueSenTime, trueSenTime);

    color = color * colorChange;

    fFragmentColor = vec4(color, 1.0);
}