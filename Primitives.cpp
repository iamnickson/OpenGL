#include <GL/glut.h>

void init()
{
	glClearColor (0.0, 0.0, 0.0, 1.0); //RGB+transparency
	glColor3f(1.0, 0.5, 0.5); 

	glMatrixMode (GL_PROJECTION);    
	glLoadIdentity ();    
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  
}


void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT); //specify background colour
	glPointSize (50);
	glLineWidth(50);
	glBegin(GL_POLYGON);   //polygon, points, line, .. primitive type
	
	//glBegin(GL_LINES);
	//glBegin(GL_LINE_LOOP);
	//glBegin(GL_TRIANGLE_STRIP);
	//glBegin(GL_QUADS);
	//GL_QUADS	//glLineWidth(5);
	//glBegin(GL_POINTS);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.75, -0.25);
		glVertex2f(-0.5, 0.5);        
		glVertex2f(0.5, 0.5);  
		glVertex2f(0.1, -0.25); 
		glVertex2f(0.5, -0.5);    //specify the co-ordinates
	glEnd();
	glFlush(); 
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowSize(500,500);	//
	glutInitWindowPosition(100,100);
	glutCreateWindow("simple");     //define window properties
	glutDisplayFunc(mydisplay);  //rendering callback
	init();  //set Open GL state
	glutMainLoop(); //enter event loop
}
