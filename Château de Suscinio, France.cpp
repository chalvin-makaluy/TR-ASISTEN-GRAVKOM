#include<windows.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <stdarg.h>
#include <math.h>


int i = 0;

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

GLuint texture[35];

int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float zrot = 0.0f;
float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;


void init(void)
{
	glClearColor(0.1, 0.1, 0.1, 0.50);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(5.0f);

}

void kotak(float x1, float y1, float z1, float x2, float y2, float z2)
{
	//depan
	glTexCoord2f(0.0, 0.0);
	glVertex3f(x1, y1, z1);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(x2, y1, z1);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(x2, y2, z1);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(x1, y2, z1);
	//atas
	glTexCoord2f(0.0, 0.0);
	glVertex3f(x1, y2, z1);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(x2, y2, z1);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(x2, y2, z2);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(x1, y2, z2);
	//belakang
	glTexCoord2f(0.0, 0.0);
	glVertex3f(x1, y2, z2);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(x2, y2, z2);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(x2, y1, z2);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(x1, y1, z2);
	//bawah
	glTexCoord2f(0.0, 0.0);
	glVertex3f(x1, y1, z2);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(x2, y1, z2);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(x2, y1, z1);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(x1, y1, z1);
	//samping kiri
	glTexCoord2f(0.0, 0.0);
	glVertex3f(x1, y1, z1);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(x1, y2, z1);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(x1, y2, z2);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(x1, y1, z2);
	//samping kanan
	glTexCoord2f(0.0, 0.0);
	glVertex3f(x2, y1, z1);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(x2, y2, z1);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(x2, y2, z2);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(x2, y1, z2);
}


void tampil(void)
{
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);



	//lt
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(70, -40.00, 100);
	glVertex3f(-70, -40.00, 100);
	glVertex3f(-70, -40.00, -70);
	glVertex3f(70, -40.00, -70);
	glEnd();

	//rumah belakang
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	kotak(-30, -39.9, -60, 60, -5, -45);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	kotak(-50, -39.9, -60, -30, -20, -55);
	glEnd();
	glPopMatrix();



	//rumah depan
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	kotak(30, -39.9, 60, -50, 0, 45);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	kotak(60, -39.9, 60, 30, -20, 45);
	glEnd();
	glPopMatrix();


	//kiri panjang
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	kotak(-65, -39.9, -20, -60, -20, 30);
	glEnd();
	glPopMatrix();

	// KANAN
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0.5);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	kotak(65, -39.9, 60, 60, -20, -60);
	glEnd();
	glPopMatrix();

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	glTranslatef(xmov, ymov, zmov);
	tampil();
	glFlush();
	glutSwapBuffers();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		zmov += 10;
		break;
	case 'd':
	case 'D':
		xmov += 10;
		break;
	case 's':
	case 'S':
		zmov -= 10;
		break;
	case 'a':
	case 'A':
		xmov -= 10;
		break;
	case '7':
		ymov += 10;
		break;
	case '9':
		ymov -= 10;
		break;
	case '2':
		xrot += 10;
		break;
	case '8':
		xrot -= 10;
		break;
	case '6':
		yrot += 10;
		break;
	case '4':
		yrot -= 10;
		break;
	case '1':
		zrot += 10;
		break;
	case '3':
		zrot -= 10;
		break;
	case '5':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
	}
	glutPostRedisplay();
}


void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -250.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(150, 80);
	glutCreateWindow("TR");
	glutDisplayFunc(display);
	glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(display);
	init();
	glutMainLoop();
	return 0;
}