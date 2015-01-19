uniform	float lx;
uniform float ly;

void main()
{
	vec2 dist = vec2(gl_FragCoord.x/640.0 - 0.5f, gl_FragCoord.y/480.0f - 0.5f);
	float a = 0.03f/(abs(length(dist) - 0.11f)+0.01f);
	float a2 = 0.03f/(length(dist)+0.01f);
	vec4 color = vec4((a+a2)*0.25f, (a+a2)*0.35, (a+a2)*0.72, 1);
	gl_FragColor = color; 
}
