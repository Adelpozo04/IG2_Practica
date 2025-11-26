#version 330 core 

in vec3 vFrontColor; 
in vec3 vBackColor;
in vec2 vUv0; 

uniform sampler2D texturaCorrosionFront;
uniform sampler2D texturaCorrosionBack;
uniform float Flipping;

out vec4 fFragColor; 

void main() 
{ 
    vec3 color;

    bool frontFacing = (Flipping > -1)? gl_FrontFacing : !gl_FrontFacing;

    if(frontFacing){
        color = texture(texturaCorrosionFront, vUv0).rgb; // Acceso a texel

        if(color.r > 0.7){
        discard;
        }

        color = vFrontColor * color;
    }
    else{
        color = texture(texturaCorrosionBack, vUv0).rgb; // Acceso a texel
        color = vBackColor * color;
    }
    
    fFragColor = vec4(color,1.0);
    
}