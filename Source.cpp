#include <GL/glut.h>



void myDisplay();
GLfloat pos0[] = { 0.0, 0.0, 1.0, 0.0 };
GLfloat pos1[] = { 150.0, 0.0, 600.0, 1.0 };
GLfloat direction[] = { 4.0, 3.0, -50.0 };
GLfloat diffuseColor1[] = { 0.1, 0.2, 0.3, 0.0 };
GLfloat ambientColor0[] = { 0.1, 0.3, 0.3, 0.2 };//���������� ����(���� ��������� �� ��������) 
GLfloat diffuseColor0[] = { 1.4, 0.2, 0.7, 0.7 };//���� � �����(��������� �����)

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GL_DEPTH_BUFFER_BIT);//��� ���������� ������ ������������.
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(450, 5);
	glutCreateWindow("��������_���������_61��.");
	glClearColor(0.05, 0.1, 0.1, 0.1);// ���.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);// ������� ����
	glutDisplayFunc(myDisplay);
	glEnable(GL_DEPTH_TEST);//�������� ������� ����� ��� ����������� ���������� �����������.
	glEnable(GL_LIGHTING); //�������� ��������� � �����
	glColor3f(1.0,0.0,0.0);
	glEnable(GL_LIGHT0);//������ ��� ���.
	glEnable(GL_LIGHT1);//������ ��� ���.
	glutMainLoop(); //���������� ������� � ��� ��� ������������
	glDisable(GL_LIGHT0);//
	glDisable(GL_LIGHT1);//�������� ���, ��� ��������
	glDisable(GL_LIGHTING);//
	glDisable(GL_DEPTH_TEST);//
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �������� ������ ����� � ����� �������
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor0);//
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor0);//
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);		//������� ���� � �������������.
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 55.0);// ���� ������
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 15.0);//����
	
	glPushMatrix(); 			//���������� ������� �������
		//������� ���������
	glTranslatef(1.0, 0.0, 0.0);		//��������� ����� ������� ���������
	glRotatef(60.0, 9.0, 8.0, 6.0);		//������� ������������ ��� X
	glRotatef(0.0, 0.0, 0.0, 0.0);		//������� ������������ ��� Y
	glBegin;
	glutSolidCone(150, 400, 100, 100);	// ������� ���������
		glEnd;
	glPopMatrix();
	//(������,�������� �� �����������, �� ��������� (��������)) ///!!! ������ 256 ��������� �� ����������!!!
	
	glFlush();																					/// !!! �������� ��������� ����������     !!!
}