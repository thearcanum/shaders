#include <shader.h>
#include <SDL/SDL.h>


int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *scr = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
	glOrtho(0, 1, 0, 1,-1, 1);
	SDL_WM_SetCaption("Arcanum Shaders", NULL);
	SDL_Event e;
	GLint lxloc, lyloc;
	float lx = 0.5f;
	float ly = 0.3f;
	int r = 1;
	
	if(argc > 2) {
		shader(argv[1], argv[2]);
	} else {
		shader("shaders/vertex.glsl", "shaders/fragment.glsl");
	}
	
	shaderUse();
	lxloc = glGetUniformLocation(programId, "lx");
	lyloc = glGetUniformLocation(programId, "ly");
	
	printf("%d\n", lxloc);
	
	while(r)
   	{
   		SDL_PollEvent(&e);
   		if(e.type == SDL_QUIT)
   			r = 0;
   		if(e.type == SDL_KEYDOWN) {
   			switch(e.key.keysym.sym) {
   			default:break;
   			case SDLK_LEFT: lx -= 0.01f; break;
   			case SDLK_RIGHT: lx += 0.01f; break;
   			case SDLK_UP: ly += 0.01f; break;
   			case SDLK_DOWN: ly -= 0.01f; break;
   			}
   		}
   			
   		SDL_GL_SwapBuffers();
   		glClear(GL_COLOR_BUFFER_BIT);
   		
   		glUniform1fv(lxloc,1, &lx);
   		glUniform1fv(lyloc,1, &ly);
   		
   		glBegin(GL_QUADS);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
			glVertex2f(1, 1);
			glVertex2f(0, 1);
		glEnd();

		SDL_Delay(20);
   	}

   	SDL_Quit();
	return 0;
}
