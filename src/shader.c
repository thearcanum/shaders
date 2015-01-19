#include <shader.h>


unsigned long get_flen(FILE *f)
{
    unsigned long s = 0;
    fseek(f, 0, SEEK_END);
    s = ftell(f);
    fseek(f, 0, SEEK_SET);
    return s;
}

const char *fload(const char *filename)
{
	char c;
	int i = 0;
	char *v;
	FILE *f;
	f = fopen(filename, "r");
	if(!f)
		return NULL;
	
	v = malloc(get_flen(f) + 1);
	if(!v)
		return NULL;
		
	while((c = fgetc(f)) != EOF) {
		v[i] = c;
		i++;
	}
	v[i] = 0;
	
	fclose(f);
	return (const char*)v;

}


int shader(const char *vFileName, const char *sFileName)
{
	
	const char* VertexShaderSource;
	const char* FragmentShaderSource;
	GLint compiled = 0;

	vertexShader 	= glCreateShader(GL_VERTEX_SHADER);
	fragmentShader 	= glCreateShader(GL_FRAGMENT_SHADER);
	
	VertexShaderSource = fload(vFileName);
	FragmentShaderSource = fload(sFileName);
	
	if(!VertexShaderSource || !FragmentShaderSource) {
		printf("Impossible de charger les fichiers sources...\n");
		return -1;
	}
	
	printf("Vertex Shader Source : \n%s\n", VertexShaderSource);
	printf("Fragment Shader Source : \n%s\n", FragmentShaderSource);
	
	glShaderSource(vertexShader, 1, &VertexShaderSource, NULL);
	glShaderSource(fragmentShader, 1, &FragmentShaderSource, NULL);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);
	
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compiled);
	printf("Vertex Shader status : %d\n", compiled);
	if(!compiled) {
		printf("Impossible de compiler le Vertex Shader !\n");
		return -1;
	}
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compiled);
	printf("Fragment Shader status : %d\n", compiled);
	if(!compiled) {
		printf("Impossible de compiler le Fragment Shader !\n");
		return -1;
	}
	
	programId= glCreateProgram();
	
	glAttachShader(programId, vertexShader) ;
	glAttachShader(programId, fragmentShader) ;

	glLinkProgram (programId); 
	
	
	return 0;
}

void shaderUse()
{
	glUseProgram(programId);
}
