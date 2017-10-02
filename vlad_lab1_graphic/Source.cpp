#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glu32.lib")
#include <glut.h>
#include <ctime>
#include <stdlib.h>

int KcolorR, KcolorG, KcolorB, McolorR, McolorG, McolorB;
int DKcolorR, DKcolorG, DKcolorB, DMcolorR, DMcolorG, DMcolorB;
int ContKcolorR, ContKcolorG, ContKcolorB, ContMcolorR, ContMcolorG, ContMcolorB;
int DContKcolorR, DContKcolorG, DContKcolorB, DContMcolorR, DContMcolorG, DContMcolorB;
int Kx, Ky, Mx, My;
int DKx, DKy, DMx, DMy;
float angleK, angleM, MEangleK, MEangleM;
bool AutoRotateKleft, AutoRotateKright, AutoRotateMleft, AutoRotateMright;

void UNCircle(float xc, float yc, float radius, int part)
{
	float distance = radius;
	float x, y, dxt;
	long r2, dst, t, s, e, ca, cd, indx;

	r2 = (long)radius * (long)radius;
	dst = 4 * r2;
	dxt = (double)radius / 1.414213562373;
	t = 0;
	s = (-4) * r2 * (long)radius;
	e = (-1)*s / 2. - 3 * r2;
	ca = (-6)*r2;
	cd = (-10)*r2;
	x = 0;
	y = radius;

	float xPre, yPre;
	for (indx = 1; indx <= dxt; indx++)
	{
		x++;
		if (e >= 0)
			e += t + ca;
		else
		{
			y--;
			e += t - s + cd;
			s += dst;
		}
		t -= dst;

		if (indx != 1)
		{

			glBegin(GL_QUADS);
			if (part == 1)
			{
				glVertex2f(xc + xPre, yc + yPre);
				glVertex2f(xc + xPre + distance, yc + yPre);
				glVertex2f(xc + x + distance, yc + y);
				glVertex2f(xc + x, yc + y);

				glVertex2f(xc + yPre, yc + xPre);
				glVertex2f(xc + yPre + distance, yc + xPre);
				glVertex2f(xc + y + distance, yc + x);
				glVertex2f(xc + y, yc + x);
			}
			if (part == 2)
			{
				glVertex2f(xc + yPre, yc - xPre);
				glVertex2f(xc + yPre + distance, yc - xPre);
				glVertex2f(xc + y + distance, yc - x);
				glVertex2f(xc + y, yc - x);

				glVertex2f(xc + xPre, yc - yPre);
				glVertex2f(xc + xPre + distance, yc - yPre);
				glVertex2f(xc + x + distance, yc - y);
				glVertex2f(xc + x, yc - y);
			}
			if (part == 3)
			{
				glVertex2f(xc - xPre, yc - yPre);
				glVertex2f(xc - xPre - distance, yc - yPre);
				glVertex2f(xc - x - distance, yc - y);
				glVertex2f(xc - x, yc - y);

				glVertex2f(xc - yPre, yc - xPre);
				glVertex2f(xc - yPre - distance, yc - xPre);
				glVertex2f(xc - y - distance, yc - x);
				glVertex2f(xc - y, yc - x);
			}
			if (part == 4)
			{
				glVertex2f(xc - yPre, yc + xPre);
				glVertex2f(xc - yPre - distance, yc + xPre);
				glVertex2f(xc - y - distance, yc + x);
				glVertex2f(xc - y, yc + x);

				glVertex2f(xc - xPre, yc + yPre);
				glVertex2f(xc - xPre - distance, yc + yPre);
				glVertex2f(xc - x - distance, yc + y);
				glVertex2f(xc - x, yc + y);
			}
			glEnd();

		}
		xPre = x;
		yPre = y;

	}
	glBegin(GL_QUADS);
	if (part == 1)
	{
		glVertex2f(xc + y, yc + x);
		glVertex2f(xc + y + distance, yc + x);
		glVertex2f(xc + x + distance, yc + y);
		glVertex2f(xc + x, yc + y);
	}
	if (part == 2)
	{
		glVertex2f(xc + x, yc - y);
		glVertex2f(xc + x + distance, yc - y);
		glVertex2f(xc + y + distance, yc - x);
		glVertex2f(xc + y, yc - x);
	}
	if (part == 3)
	{
		glVertex2f(xc - y, yc - x);
		glVertex2f(xc - y - distance, yc - x);
		glVertex2f(xc - x - distance, yc - y);
		glVertex2f(xc - x, yc - y);
	}
	if (part == 4)
	{
		glVertex2f(xc - x, yc + y);
		glVertex2f(xc - x - distance, yc + y);
		glVertex2f(xc - y - distance, yc + x);
		glVertex2f(xc - y, yc + x);
	}
	glEnd();
}

void draw_Letter_K(float height)
{
	//контур(большая фигура)
	glColor3ub(ContKcolorR, ContKcolorG, ContKcolorB);
	UNCircle(0 - 1 * height + 0.07*height, height - 0.03*height, height, 2);
	UNCircle(0 - 1 * height - 0.07*height, height + 0.03*height, height, 2);
	UNCircle(3.*height - 1 * height + 0.07*height, height - 0.035*height - 0.03*height, height, 4);
	UNCircle(3.*height - 1 * height - 0.07*height, height - 0.035*height + 0.03*height, height, 4);
	UNCircle(0 - 1 * height - 0.07*height, -height - 0.03*height, height, 1);
	UNCircle(0 - 1 * height + 0.07*height, -height + 0.03*height, height, 1);
	UNCircle(3.*height - 1 * height - 0.07*height, -height + 0.035*height - 0.03*height, height, 3);
	UNCircle(3.*height - 1 * height + 0.07*height, -height + 0.035*height + 0.03*height, height, 3);
	glBegin(GL_POLYGON);
	glVertex2f(0 + height*0.5 - 1 * height + 0.07*height, 2.*height + 0.07*height);
	glVertex2f(-height*0.8 + height*0.5 - 1 * height - 0.07*height, 2.*height + 0.07*height);
	glVertex2f(-height*0.8 + height*0.5 - 1 * height - 0.07*height, -2.*height - 0.07*height);
	glVertex2f(0 + height*0.5 - 1 * height + 0.07*height, -2.*height - 0.07*height);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1.98*height, 2.01*height);
	glVertex2f(0.9*height, 2.01*height);
	glVertex2f(0.9*height, 1.93*height);
	glVertex2f(1.98*height, 1.93*height);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1.98*height, -2.01*height);
	glVertex2f(0.9*height, -2.01*height);
	glVertex2f(0.9*height, -1.93*height);
	glVertex2f(1.98*height, -1.93*height);
	glEnd();


	//меньшая фигура
	glColor3ub(KcolorR, KcolorG, KcolorB);
	UNCircle(0-1*height, height, height, 2);
	UNCircle(3.*height - 1*height, height - 0.035*height, height, 4);
	UNCircle(0 - 1*height, -height, height, 1);
	UNCircle(3.*height - 1*height, -height + 0.035*height, height, 3);
	glBegin(GL_POLYGON);
	glVertex2f(0 + height*0.5 - 1*height, 2.*height);
	glVertex2f(-height*0.8 + height*0.5 - 1*height, 2.*height);
	glVertex2f(-height*0.8 + height*0.5 - 1*height, -2.*height);
	glVertex2f(0 + height*0.5 - 1*height, -2.*height);
	glEnd();


}

void draw_Letter_M(float height)
{
	//контур(большая фигура)
	glColor3ub(ContMcolorR, ContMcolorG, ContMcolorB);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0 - 0.1*height);
	glVertex2f(2.*height +0.07*height, 2.*height - 0.03*height);
	glVertex2f(2.*height + 0.07*height, 3.*height + 0.17*height);
	glVertex2f(0, height + 0.1*height);
	glVertex2f(-2.*height- 0.07*height, 3.*height + 0.17*height);
	glVertex2f(-2.*height - 0.07*height, 2.*height - 0.03*height);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-height + 0.07*height, 2 * height);
	glVertex2f(-height - height - 0.07*height, 2 * height);
	glVertex2f(-height - height - 0.07*height, -height - 0.07*height);
	glVertex2f(-height + 0.07*height, -height - 0.07*height);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(height - 0.07*height, 2 * height);
	glVertex2f(height + height + 0.07*height, 2 * height);
	glVertex2f(2 * height + 0.07*height, -height - 0.07*height);
	glVertex2f(height - 0.07*height, -height - 0.07*height);
	glEnd();

	UNCircle(-3 * height + 0.07*height, -height + 0.021*height - 0.03*height, height, 2);
	UNCircle(-3 * height - 0.07*height, -height + 0.021*height + 0.03*height, height, 2);
	UNCircle(3 * height + 0.07*height, -height + 0.021*height + 0.03*height, height, 3);
	UNCircle(3 * height - 0.07*height, -height + 0.021*height - 0.03*height, height, 3);

	glBegin(GL_POLYGON);
	glVertex2f(2.98*height, -2.03*height);
	glVertex2f(1.9*height, -2.03*height);
	glVertex2f(1.9*height, -1.95*height);
	glVertex2f(2.98*height, -1.95*height);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-2.98*height, -2.03*height);
	glVertex2f(-1.9*height, -2.03*height);
	glVertex2f(-1.9*height, -1.95*height);
	glVertex2f(-2.98*height, -1.95*height);
	glEnd();


	//меньшая фигура
	glColor3ub(McolorR, McolorG, McolorB);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(2.*height, 2.*height);
	glVertex2f(2.*height, 3.*height);
	glVertex2f(0, height);
	glVertex2f(-2.*height, 3.*height);
	glVertex2f(-2.*height , 2.*height );
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-height, 2*height);
	glVertex2f(-height  - height, 2*height);
	glVertex2f(-height  - height, - height);
	glVertex2f(-height, - height);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(height, 2 * height);
	glVertex2f(height + height, 2 * height);
	glVertex2f(2*height, - height);
	glVertex2f(height, - height);
	glEnd();

	UNCircle(-3 * height, -height + 0.021*height, height, 2);
	UNCircle(3 * height, -height + 0.021*height, height, 3);

}

void RenderScene(void)
{
	glClearColor(1, 0.82, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (AutoRotateKleft)
		MEangleK += 1;
	if (AutoRotateKright)
		MEangleK -= 1;
	if (AutoRotateMleft)
		MEangleM += 1;
	if (AutoRotateMright)
		MEangleM -= 1;

	glLoadIdentity();
	glRotatef(angleM, 0., 0., 1.);
	glTranslatef(Mx, My, 0);
	glRotatef(MEangleM, 0., 0., 1.);
	draw_Letter_M(48.);

	glLoadIdentity();
	glRotatef(angleK, 0., 0., 1.);
	glTranslatef(Kx, Ky, 0);
	glRotatef(MEangleK, 0., 0., 1.);
	draw_Letter_K(60.);

	glutSwapBuffers();
}

void ChangeWindowSize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void DetectKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w': {
		Ky += 10;
		break;
	}
	case 's': {
		Ky -= 10;
		break;
	}
	case 'a': {
		Kx -= 10;
		break;
	}
	case 'd': {
		Kx += 10;
		break;
	}
	case 'i': {
		My += 10;
		break;
	}
	case 'k': {
		My -= 10;
		break;
	}
	case 'j': {
		Mx -= 10;
		break;
	}
	case 'l': {
		Mx += 10;
		break;
	}
	case 'z': {
		KcolorR = rand() % 256;
		KcolorG = rand() % 256;
		KcolorB = rand() % 256;
		ContKcolorR = rand() % 256;
		ContKcolorG = rand() % 256;
		ContKcolorB = rand() % 256;
		break;
	}
	case 'x': {
		McolorR = rand() % 256;
		McolorG = rand() % 256;
		McolorB = rand() % 256;
		ContMcolorR = rand() % 256;
		ContMcolorG = rand() % 256;
		ContMcolorB = rand() % 256;
		break;
	}
	case 'c': {
		KcolorR = DKcolorR;
		KcolorG = DKcolorG;
		KcolorB = DKcolorB;
		ContKcolorR = DContKcolorR;
		ContKcolorG = DContKcolorG;
		ContKcolorB = DContKcolorB;
		McolorR = DMcolorR;
		McolorG = DMcolorG;
		McolorB = DMcolorB;
		ContMcolorR = DContMcolorR;
		ContMcolorG = DContMcolorG;
		ContMcolorB = DContMcolorB;
		break;
	}
	}
}
void DetectSpecKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: {
		Ky += 10;
		My += 10;
		break;
	}
	case GLUT_KEY_DOWN: {
		Ky -= 10;
		My -= 10;
		break;
	}
	case GLUT_KEY_LEFT: {
		Kx -= 10;
		Mx -= 10;
		break;
	}
	case GLUT_KEY_RIGHT: {
		Kx += 10;
		Mx += 10;
		break;
	}
	case GLUT_KEY_PAGE_UP: {
		angleK += 10;
		angleM += 10;
		if (angleK > 360)
			angleK -= 360;
		if (angleK < -360)
			angleK += 360;

		if (angleM > 360)
			angleM -= 360;
		if (angleM < -360)
			angleM += 360;
		break;
	}
	case GLUT_KEY_PAGE_DOWN: {
		angleK -= 10;
		angleM -= 10;
		if (angleK > 360)
			angleK -= 360;
		if (angleK < -360)
			angleK += 360;

		if (angleM > 360)
			angleM -= 360;
		if (angleM < -360)
			angleM += 360;
		break;
	}
	case GLUT_KEY_F1: {
		MEangleK += 10;
		if (MEangleK > 360)
			MEangleK -= 360;
		if (MEangleK < -360)
			MEangleK += 360;
		break;
	}
	case GLUT_KEY_F2: {
		MEangleK -= 10;
		if (MEangleK > 360)
			MEangleK -= 360;
		if (MEangleK < -360)
			MEangleK += 360;
		break;
	}
	case GLUT_KEY_F11: {
		MEangleM += 10;
		if (MEangleK > 360)
			MEangleK -= 360;
		if (MEangleK < -360)
			MEangleK += 360;
		break;
	}
	case GLUT_KEY_F12: {
		MEangleM -= 10;
		if (MEangleK > 360)
			MEangleK -= 360;
		if (MEangleK < -360)
			MEangleK += 360;
		break;
	}
	case GLUT_KEY_HOME: {
		Kx = DKx;
		Ky = DKy;
		Mx = DMx;
		My = DMy;
		angleK = 0.;
		angleM = 0.;
		MEangleK = 0.;
		MEangleM = 0.;
		break;
	}
	case GLUT_KEY_F6: {
		if (AutoRotateKleft)
			AutoRotateKleft = false;
		else
			AutoRotateKleft = true;

		if (AutoRotateMleft)
			AutoRotateMleft = false;
		else
			AutoRotateMleft = true;
		break;
	}
	case GLUT_KEY_F7: {
		if (AutoRotateKright)
			AutoRotateKright = false;
		else
			AutoRotateKright = true;

		if (AutoRotateMright)
			AutoRotateMright = false;
		else
			AutoRotateMright = true;
		break;
	}
	case GLUT_KEY_F8: {
		if (AutoRotateKleft)
			AutoRotateKleft = false;
		else
			AutoRotateKleft = true;

		if (AutoRotateMright)
			AutoRotateMright = false;
		else
			AutoRotateMright = true;
		break;
	}
	}
}

int main(int argc, char* argv[])
{
	srand(time(0));
	ContKcolorR = DContKcolorR = 1;
	ContKcolorG = DContKcolorG = 1;
	ContKcolorB = DContKcolorB = 100;
	KcolorR = DKcolorR = 100;
	KcolorG = DKcolorG = 1;
	KcolorB = DKcolorB = 1;

	ContMcolorR = DContMcolorR = 1;
	ContMcolorG = DContMcolorG = 1;
	ContMcolorB = DContMcolorB = 1;
	McolorR = DMcolorR = 1;
	McolorG = DMcolorG = 100;
	McolorB = DMcolorB = 1;

	Kx = DKx = -70;
	Ky = DKy = 50;
	Mx = DMx = 70;
	My = DMy = -50;
	angleK = angleM = MEangleK = MEangleM = 0.;
	AutoRotateKleft = AutoRotateKright = AutoRotateMleft = AutoRotateMright = false;



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Кацай ПК-15-1");


	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);
	glutReshapeFunc(ChangeWindowSize);
	glutSpecialFunc(DetectSpecKeys);
	glutKeyboardFunc(DetectKeys);
	glutMainLoop();

	return 0;
}