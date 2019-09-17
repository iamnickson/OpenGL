#include <windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>
#include <cmath>
 
int screenheight = 600;
int screenwidth = 800;
bool flag = true;

double angle = 10;

//The angle for the rotation (in degrees)

typedef struct{
    float x;
    float y;
}Point2D;

Point2D p1,p2,p3,p4;

void DrawLineSegment(Point2D pt1, Point2D pt2, Point2D pt3, Point2D pt4){

       glPointSize(1.0);
       glBegin(GL_QUADS);
       glVertex2i(pt1.x, pt1.y);
       glVertex2i(pt2.x, pt2.y);
	   glVertex2i(pt3.x, pt3.y);
       glVertex2i(pt4.x, pt4.y);
       glEnd();
       glFlush();

}

Point2D translate(Point2D p, float tx, float ty){
	   Point2D ptemp;
       ptemp.x =p.x + tx; //.....wite the equations for translation 
       ptemp.y = p.y + ty; //.....wite the equations for translation
       return ptemp;
}

Point2D scale(Point2D p, float dx, float dy){
	Point2D ptemp;
	ptemp.x = p.x*dx;
	ptemp.y = p.y*dy;
	return ptemp;

}

Point2D  rotate(Point2D p, float ang){
    ang = ang * 3.14 / 180.0;                                 //angle in radians
    Point2D ptemp;
    ptemp.x = p.x * cos(ang) - p.y * sin(ang);
    ptemp.y = p.x * sin(ang) + p.y * cos(ang);
	return ptemp;
}

void myMouse(int button, int state, int x, int y) {
	
	//rotate  the rectangle with respect to its centre (25,15). 
	if(button == GLUT_LEFT_BUTTON) 
	{
		if (state == GLUT_DOWN) {
			glClear(GL_COLOR_BUFFER_BIT);
			Point2D p5;
			p5.x = x;
			p5.y = screenheight - y;

			float tan_p3 = (float) p3.y/ (float) p3.x;
			float tan_p5 = (float) p5.y/ (float) p5.x;

			if(tan_p3 > tan_p5)
			{
				Point2D Rotated_p1 = rotate(p1,-angle);
				Point2D Rotated_p2 = rotate(p2,-angle);
				Point2D Rotated_p3 = rotate(p3,-angle);
				Point2D Rotated_p4 = rotate(p4,-angle);
								
				DrawLineSegment(Rotated_p1,Rotated_p2,Rotated_p3,Rotated_p4 );
			}
			else{
				Point2D Rotated_p1 = rotate(p1,angle);
				Point2D Rotated_p2 = rotate(p2,angle);
				Point2D Rotated_p3 = rotate(p3,angle);
				Point2D Rotated_p4 = rotate(p4,angle);
								
				DrawLineSegment(Rotated_p1,Rotated_p2,Rotated_p3,Rotated_p4 );
			}
				
		}

	}

	//rotate the rectangle with respect to origin through an angle, say 10o
	else if (button == GLUT_RIGHT_BUTTON) {
		if(state == GLUT_DOWN) {
			glClear(GL_COLOR_BUFFER_BIT);
			Point2D p5;
			p5.x = x;
			p5.y = screenheight - y;

			float tan_p3 = (float) p3.y/ (float) p3.x;
			float tan_p5 = (float) p5.y/ (float) p5.x;

			if(tan_p3 > tan_p5)
			{
				Point2D translate_p1 = translate(p1,-25, -15);
				Point2D translate_p2 = translate(p2,-25, -15);					
				Point2D translate_p3 = translate(p3,-25, -15);
				Point2D translate_p4 = translate(p4,-25, -15);

				Point2D Rotated_p1 = rotate(translate_p1,-angle);
				Point2D Rotated_p2 = rotate(translate_p2,-angle);
				Point2D Rotated_p3 = rotate(translate_p3,-angle);
				Point2D Rotated_p4 = rotate(translate_p4,-angle);

				Point2D translate_p11 = translate(Rotated_p1,25, 15);
				Point2D translate_p22 = translate(Rotated_p2,25, 15);
				Point2D translate_p33 = translate(Rotated_p3,25, 15);
				Point2D translate_p44 = translate(Rotated_p4,25, 15);					
								
				DrawLineSegment(translate_p11,translate_p22,translate_p33,translate_p44 );
			}
			else{
									
				Point2D translate_p1 = translate(p1,-25, -15);
				Point2D translate_p2 = translate(p2,-25, -15);
				Point2D translate_p3 = translate(p3,-25, -15);
				Point2D translate_p4 = translate(p4,-25, -15);

				Point2D Rotated_p1 = rotate(translate_p1,angle);
				Point2D Rotated_p2 = rotate(translate_p2,angle);
				Point2D Rotated_p3 = rotate(translate_p3,angle);
				Point2D Rotated_p4 = rotate(translate_p4,angle);

				Point2D translate_p11 = translate(Rotated_p1,25, 15);
				Point2D translate_p22 = translate(Rotated_p2,25, 15);
				Point2D translate_p33 = translate(Rotated_p3,25, 15);
				Point2D translate_p44 = translate(Rotated_p4,25, 15);
								
				DrawLineSegment(translate_p11,translate_p22,translate_p33,translate_p44 );
			}
				
		}
     
	}
}
void keyboard(unsigned char key, int x, int y)
{
   
	if (key == 'q' || key == 'Q')
        exit(0);
	else if (key == 'e' || key == 'E'){
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}

	//zoom-in and zoom-out the rectangle with respect to its centre (25,15)
	else if (key == '+' ){
		glClear(GL_COLOR_BUFFER_BIT);
		Point2D scale_p1 = scale(p1,2,2);
		Point2D scale_p2 = scale(p2,2,2);
		Point2D scale_p3 = scale(p3,2,2);
		Point2D scale_p4 = scale(p4,2,2);
		DrawLineSegment(scale_p1, scale_p2, scale_p3, scale_p4);
				
	}
	else if (key == '-' ){
		glClear(GL_COLOR_BUFFER_BIT);
		Point2D scale_p1 = scale(p1,0.5,0.5);
		Point2D scale_p2 = scale(p2,0.5,0.5);
		Point2D scale_p3 = scale(p3,0.5,0.5);
		Point2D scale_p4 = scale(p4,0.5,0.5);
		DrawLineSegment(scale_p1, scale_p2, scale_p3, scale_p4);		
				
	}

	//zoom-in and zoom-out the rectangle with respect to origin
	else if (key == '*' ){
		glClear(GL_COLOR_BUFFER_BIT);
		Point2D translate_p1 = translate(p1,-25, -15);
		Point2D translate_p2 = translate(p2,-25, -15);					
		Point2D translate_p3 = translate(p3,-25, -15);
		Point2D translate_p4 = translate(p4,-25, -15);

		Point2D scale_p1 = scale(translate_p1,2,2);
		Point2D scale_p2 = scale(translate_p2,2,2);
		Point2D scale_p3 = scale(translate_p3,2,2);
		Point2D scale_p4 = scale(translate_p4,2,2);

		Point2D translate_p11 = translate(scale_p1,25, 15);
		Point2D translate_p22 = translate(scale_p2,25, 15);
		Point2D translate_p33 = translate(scale_p3,25, 15);
		Point2D translate_p44 = translate(scale_p4,25, 15);

		DrawLineSegment(translate_p11,translate_p22,translate_p33,translate_p44 );
				
	}
	else if (key == '/' ){
		glClear(GL_COLOR_BUFFER_BIT);
		Point2D translate_p1 = translate(p1,-25, -15);
		Point2D translate_p2 = translate(p2,-25, -15);					
		Point2D translate_p3 = translate(p3,-25, -15);
		Point2D translate_p4 = translate(p4,-25, -15);

		Point2D scale_p1 = scale(translate_p1,0.5,0.5);
		Point2D scale_p2 = scale(translate_p2,0.5,0.5);
		Point2D scale_p3 = scale(translate_p3,0.5,0.5);
		Point2D scale_p4 = scale(translate_p4,0.5,0.5);

		Point2D translate_p11 = translate(scale_p1,25, 15);
		Point2D translate_p22 = translate(scale_p2,25, 15);
		Point2D translate_p33 = translate(scale_p3,25, 15);
		Point2D translate_p44 = translate(scale_p4,25, 15);

		DrawLineSegment(translate_p11,translate_p22,translate_p33,translate_p44 );		
				
	}
	
}




void myDisplay(){
       glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
       glClear(GL_COLOR_BUFFER_BIT);
	   glPointSize(1.0);
       glBegin(GL_QUADS);
	   glColor3f(0.0, 0.0, 0.0);
	    p1.x = 0 ;
		p1.y = 0 ;
		p2.x = 50 ;
		p2.y = 0 ;
		p3.x = 50;
		p3.y = 30;
		p4.x = 0 ;
		p4.y = 30 ;
       glVertex2i(p1.x,p1.y);
       glVertex2i(p2.x,p2.y);
	   glVertex2i(p3.x,p3.y);
       glVertex2i(p4.x, p4.y);
       glEnd();
       glFlush();
       glColor3f(0.0f, 0.0f, 0.0f);
}
 
int main( int argc, char ** argv ) {
       glutInit( &argc, argv );
       glutInitWindowPosition( 0, 0 );
       glutInitWindowSize( 800, 600 );
       glutCreateWindow( "My Drawing Screen" );
	   glMatrixMode( GL_PROJECTION );
       glLoadIdentity();
       gluOrtho2D( 0, 800, 0, 600 );
       glViewport(0, 0, 800, 600);

       glutMouseFunc( myMouse );
	   glutKeyboardFunc(keyboard); 
       glutDisplayFunc( myDisplay );
	   
       glutMainLoop();
       return( 0 );
}