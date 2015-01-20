/* Simple shader qui peut servir à dessiner des objets en orbite d'un centre (soleil) 
   les coordnnées et rayons des 4 objets sont à spécifier dans lx,ly et r via glUniform1fv */
uniform	float lx[4];
uniform float ly[4];
uniform float r[4];

void main()
{
	vec2 pos = vec2(gl_FragCoord.x/640.0, gl_FragCoord.y/480.0);
	vec4 color = vec4(0,0,0,1);
	vec2 position[4];
	vec3 couleurs[4] = {vec3(0.8,0.4, 0.3), vec3(0.1, 0.7, 0.4), vec3(0.2, 0.6, 0.8), vec3(0.57, 0.1, 0.87)};//,vec3(0.18, 0.26,0.87)};
	float a[4] = {0};
	vec2 dist[4];
	int i;

	for(i=0;i<4;i++) {
		position[i].x = lx[i];
		position[i].y = ly[i];
		dist[i] = pos - position[i];
		a[i] = r[i]/(20*length(dist[i]));
		color += vec4(a[i]*couleurs[i], 0);
		dist[i] = pos - vec2(0.5f,0.5f);
		a[i] = 0.002f/(abs(length(dist[i]) - r[i]));
		color += vec4(a[i]*couleurs[i], 0);
	}
	// Soleil 
	a[0] = 0.035f/(length(dist[0]) + 0.01f);
	color += vec4(a[0]*vec3(0.87, 0.67, 0.21), 0);

	gl_FragColor = color; 
}
