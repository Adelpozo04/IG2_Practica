#version 330 core 

in vec3 vNormals;
in vec3 vNormal;
in vec2 vUv0; 

uniform sampler2D texturaCorrosionFront;
uniform sampler2D texturaCorrosionBack;
uniform float Flipping;

uniform vec3 lightDiffuse;
uniform vec4 lightDirection;

uniform vec3 materialDiffuse;

out vec4 fFragColor; 

float diff(vec3 cNormal){
    vec3 lightDir = lightDirection.xyz;
    return max(dot(cNormal, normalize(-lightDir)), 0.0); 

}

void main() 
{ 
    vec3 color;

    bool frontFacing = (Flipping > -1)? gl_FrontFacing : !gl_FrontFacing;

    if(frontFacing){
        color = texture(texturaCorrosionFront, vUv0).rgb; // Acceso a texel

        if(color.r > 0.7){
        discard;
        }

        color = diff(vNormals) * lightDiffuse * materialDiffuse * color;
    }
    else{
        color = abs(vNormal.rgb);
        color = diff(-vNormals) * lightDiffuse * materialDiffuse * color;
    }
    
    fFragColor = vec4(color,1.0);
    
}