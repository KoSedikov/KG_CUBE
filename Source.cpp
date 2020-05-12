#include <GL/glut.h>



void myDisplay();
GLfloat pos0[] = { 0.0, 0.0, 1.0, 0.0 };
GLfloat pos1[] = { 150.0, 0.0, 600.0, 1.0 };
GLfloat direction[] = { 4.0, 3.0, -50.0 };
GLfloat diffuseColor1[] = { 0.1, 0.2, 0.3, 0.0 };
GLfloat ambientColor0[] = { 0.1, 0.3, 0.3, 0.2 };//Глобальный свет(свет отражения от объектов) 
GLfloat diffuseColor0[] = { 1.4, 0.2, 0.7, 0.7 };//Свет в сферу(освещение сферы)

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GL_DEPTH_BUFFER_BIT);//Для адекватной работы пространства.
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(450, 5);
	glutCreateWindow("Сапронов_Александр_61гр.");
	glClearColor(0.05, 0.1, 0.1, 0.1);// Фон.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);// Главная орта
	glutDisplayFunc(myDisplay);
	glEnable(GL_DEPTH_TEST);//Проверка глубины кадра для адекватного построения изображения.
	glEnable(GL_LIGHTING); //Включаем освещение в целом
	glColor3f(1.0,0.0,0.0);
	glEnable(GL_LIGHT0);//Первый луч вкл.
	glEnable(GL_LIGHT1);//второй луч вкл.
	glutMainLoop(); //Вызывается дисплэй и там все отображается
	glDisable(GL_LIGHT0);//
	glDisable(GL_LIGHT1);//Вырубаем все, что включили
	glDisable(GL_LIGHTING);//
	glDisable(GL_DEPTH_TEST);//
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищение буфера света и буфер глубины
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor0);//
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor0);//
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);		//позиция луча в бесконечности.
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 55.0);// Угол конуса
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 15.0);//Блюр
	
	glPushMatrix(); 			//запоминаем текущую матрицу
		//видовые параметры
	glTranslatef(1.0, 0.0, 0.0);		//начальный сдвиг системы координат
	glRotatef(60.0, 9.0, 8.0, 6.0);		//поворот относительно оси X
	glRotatef(0.0, 0.0, 0.0, 0.0);		//поворот относительно оси Y
	glBegin;
	glutSolidCone(150, 400, 100, 100);	// команды рисования
		glEnd;
	glPopMatrix();
	//(Радиус,разрезка по горизонтали, по вертикали (полигоны)) ///!!! Больше 256 указывать не рекомендую!!!
	
	glFlush();																					/// !!! Возможно появление артифактов     !!!
}