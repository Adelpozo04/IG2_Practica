#version 330 core

in vec2 Vuv0;
in vec4 VvertexCoord;
in vec2 Vpos;

uniform sampler2D TexturaGrano;
uniform int rad;
uniform float colorIntensity;
uniform float yellowZone;

out vec4 fFragColor;

void main(){

    vec4 colorGrano = texture(TexturaGrano, Vuv0);

    
    if(VvertexCoord.x > Vpos.x - rad && VvertexCoord.x < Vpos.x + rad && VvertexCoord.z > Vpos.y - rad && VvertexCoord.z < Vpos.y + rad){

        colorGrano.r += colorIntensity;
    }

    if(VvertexCoord.x > Vpos.x - (rad * yellowZone) && VvertexCoord.x < Vpos.x + (rad * yellowZone) && 
    VvertexCoord.z > Vpos.y - (rad * yellowZone) && VvertexCoord.z < Vpos.y + (rad * yellowZone)){

        colorGrano.g += colorIntensity;
    }
    

    fFragColor = colorGrano;
}