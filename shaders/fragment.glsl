uniform	float lx;
uniform float ly;

void main()
{
	vec2 pos = vec2(gl_FragCoord.x/640.0, gl_FragCoord.y/480.0);
	vec4 color = vec4(0,0,0,1);
	vec2 position[3] = {vec2(0.5, 0.6), vec2(0.25,0.75), vec2(0.75,0.25)};//, vec2(0.4,0.6)};
	position[0].x = lx;
	position[0].y = ly;
	vec3 couleurs[3] = {vec3(1,0.8, 1), vec3(0.1, 0.7, 0.7), vec3(0.2, 0.6, 0.8)};//, vec3(0.57, 0, 0.87),vec3(0.1, 0.26,0.87)};
	float a[3] = {0};
	vec2 dist[3];
	int i;

	for(i=0;i<3;i++) {
		dist[i] = pos - position[i];
		a[i] = 0.02f/(length(dist[i]));
		color += vec4(a[i]*couleurs[i], 0);
	}

	gl_FragColor = color; 
}
