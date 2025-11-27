#version 330 core

in vec4 vertex;
in vec3 normal;
in vec2 uv0;

uniform mat4 modelViewMat;
uniform mat4 modelViewProjMat;
uniform mat4 normalMat;

uniform vec3 lightDiffuse;
uniform vec4 lightPosition;

uniform vec3 materialDiffuse;

out vec2 vUv0;
out vec3 vFrontColor;
out vec3 vBackColor;

float diff(vec3 cVertex, vec3 cNormal){
    vec3 lightDir = lightPosition.xyz;
    return max(dot(cNormal, normalize(lightDir)), 0.0); 

}

void main(){

    vec3 viewVertex = vec3(modelViewMat * vertex);
    vec3 viewNormal = normalize( (normalMat * vec4(normal, 0.0)).xyz );
    
    vFrontColor = diff(viewVertex, viewNormal) * lightDiffuse * materialDiffuse;
    vBackColor = diff(viewVertex,-viewNormal) * lightDiffuse * materialDiffuse;

    vUv0 = uv0;

    gl_Position = modelViewProjMat * vertex;
    
}


