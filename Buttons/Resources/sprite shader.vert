#version 330

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 texCoord;

out vec2 fragTexCoord;

uniform mat3 viewProj;

void main() {
  gl_Position = vec4(viewProj * vec3(pos, 1.0), 1.0);
  fragTexCoord = texCoord;
}
