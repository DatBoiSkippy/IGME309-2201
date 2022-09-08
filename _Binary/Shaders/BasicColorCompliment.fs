#version 330

in vec3 Color;

uniform vec3 SolidColor = vec3(-1,-1,-1);
uniform bool Complimentary = true;

out vec4 Fragment;

void main()
{	
	vec3 temp = Color;
	vec3 base = vec3(1.0f,1.0f,1.0f);
	
	if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0)
		temp = SolidColor;
	if(Complimentary == false)
		temp = base - temp;
		
		Fragment = vec4(temp,1);
	return;
}