void main()
{	
	vec2 pos = vec2(gl_FragCoord.x/640.0f, gl_FragCoord.y/480.0f);
	vec4 color = (0, 0, 0, 1);
	vec2 dist = pos - vec2(0.5,0.5);
	float a,t;
	
	t = acos(dist.x/length(dist));
	
	a = 2*exp(-8*length(dist));
	color = vec4(a*vec3(0, 0.6, 0.8), 0);
	
	a = 0.02f/(abs(length(dist)-(0.2f+0.1f*cos(10*t))));
	color += vec4(a*vec3(0.1, 0.8*pos.y, 0.56*(pos.x+pos.y)), 0);
	
	gl_FragColor = color;
}
