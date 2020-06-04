#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
static  GLdouble  viewer[]={0,0,5};
void *currentfont;
float dx=0.5,dy=0.5;
//float angle=0;
void setFont(void *font)
{
	currentfont=font;
}
void drawstring(float x,float y,char *string)
{
	    char *c;
	glRasterPos2f(x,y);

	for(c=string;*c!='\0';c++)
	{	//glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}
void rectmesh()
{float a=0.5,b=0.5,c=1;
int item=1;
char str[10];
char str1[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

            float  i, j;
            for(i=0;i<3.5;i+=dx)
			{
			glColor3f(1,1,1);

			drawstring(i+0.1,2.8,str1[(int)(i*2)]);
			printf(" %d ",(int)(i*2));
			glColor3f(0,0,0);
			glBegin(GL_POLYGON);

			glVertex2f( i, 2.5);
			glVertex2f( i+dx, 2.5);
			glVertex2f( i+dx, 3);
			glVertex2f( i, 3);

			glEnd();
			}
            for(j=2;j>=0;j-=dy)
            for(i=0;i<3.5;i+=dx)
            {
            glColor3f(0,0,0);
            if(item<=31)
            {
            snprintf(str, sizeof(str), "%d", item++);
            drawstring(i+0.2,j+0.2,str);
            }
            }
            for(i=0;i<3.5;i+=dx)
            for(j=0;j<2.5;j+=dy)
            {

            glColor3f(0,0,0);
            glBegin(GL_LINE_LOOP);

            glVertex2f( i, j);
            glVertex2f( i+dx, j);
            glVertex2f( i+dx, j+dy);
            glVertex2f( i, j+dy);

            glEnd();


            glBegin(GL_POLYGON);
            glColor3f(a,b,c*fabs(sin(10*i)));
            glVertex2f( i, j);
            glVertex2f( i+dx, j);
            glVertex2f( i+dx, j+dy);
            glVertex2f( i, j+dy);

            glEnd();

            }


}
void display()
{
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();
            gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
            glTranslated(0,0,5);
  //          glColor3f(0,0,0);
       //     glRotatef(90,0,1,0);
            rectmesh();
            glFlush();
            glutSwapBuffers();
}

void myReshape(int w,int h)
{
            glViewport(0,0,w,h);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0,3.5,0,3,-10,10);
            glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Rectangular Mesh");
glutDisplayFunc(display);
glutReshapeFunc(myReshape);
//glutIdleFunc(idle);
glClearColor(1.0,1.0,1.0,1.0);
glEnable(GL_DEPTH_TEST);
setFont(GLUT_BITMAP_HELVETICA_18);
glutMainLoop();
return 0;
}
