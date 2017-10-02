//#include "Letters.h"
//
//LetterCollector* LetterCollector::p_instance = 0;
//
//LetterCollector* LetterCollector::getInstance()
//{
//	if (!p_instance)
//	{
//		p_instance = new LetterCollector();
//		p_instance->listOfLetters[0] = new Letter_G(46, 70, 0, 244, 204, 112, 60, -45, 35);
//		p_instance->listOfLetters[1] = new Letter_V(141, 35, 15, 230, 223, 68, 60, 45, -35);
//		p_instance->idCurrentLetter = 0;
//		for (int i = 0; i < 2; i++)
//			p_instance->continuousTurn[i] = CONTINUOUS_TURN_STOP;
//	}
//	return p_instance;
//}
//void LetterCollector::ChangeCurrentLetter()
//{
//	if (idCurrentLetter == 0)
//		idCurrentLetter = 1;
//	else
//		idCurrentLetter = 0;
//}
//void LetterCollector::ChangeColorOfLetter(int id)
//{
//	p_instance->listOfLetters[id]->changeColor();
//}
//void LetterCollector::showLetters()
//{
//	for (int i = 0; i < 2; i++)
//		if (p_instance->continuousTurn[i] == 1)
//			p_instance->listOfLetters[i]->SetAngleOfYourselfRotation(CONST_ANGLE / 10.);
//		else
//			if (p_instance->continuousTurn[i] == 2)
//				p_instance->listOfLetters[i]->SetAngleOfYourselfRotation(-CONST_ANGLE / 10.);
//
//
//	if (p_instance->idCurrentLetter == 0)
//	{
//		p_instance->listOfLetters[1]->show();
//		p_instance->listOfLetters[0]->show();
//	}
//	else
//	{
//		p_instance->listOfLetters[0]->show();
//		p_instance->listOfLetters[1]->show();
//	}
//}
//void LetterCollector::SetCenterAngleOfLatter(int id, float angle)
//{
//	p_instance->listOfLetters[id]->SetAngleOfCenterRotation(angle);
//}
//void LetterCollector::SetYourselfAngleOfLatter(int id, float angle)
//{
//	p_instance->listOfLetters[id]->SetAngleOfYourselfRotation(angle);
//}
//void LetterCollector::SetContinuousTurn(int id, int mode)
//{
//	if (p_instance->continuousTurn[id] == CONTINUOUS_TURN_STOP)
//		p_instance->continuousTurn[id] = mode;
//	else
//		p_instance->continuousTurn[id] = CONTINUOUS_TURN_STOP;
//}
//void LetterCollector::moveCurrentLetter(int dx, int dy)
//{
//	p_instance->listOfLetters[p_instance->idCurrentLetter]->move(dx, dy);
//}
//void LetterCollector::moveAllLetters(int dx, int dy)
//{
//	for (int i = 0; i < 2; i++)
//		p_instance->listOfLetters[i]->move(dx, dy);
//}
//void LetterCollector::DefaultPosition()
//{
//	for (int i = 0; i < 2; i++)
//		p_instance->listOfLetters[i]->setDefaultPosition();
//}
//void LetterCollector::DefaultColor()
//{
//	for (int i = 0; i < 2; i++)
//		p_instance->listOfLetters[i]->setDefaultColor();
//}
//
//
//
//void Letter::UNCircle(float xc, float yc, float radius, int part)
//{
//	float distance = radius;
//	float x, y, dxt;
//	long r2, dst, t, s, e, ca, cd, indx;
//
//	r2 = (long)radius * (long)radius;
//	dst = 4 * r2;
//	dxt = (double)radius / 1.414213562373;
//	t = 0;
//	s = (-4) * r2 * (long)radius;
//	e = (-1)*s / 2. - 3 * r2;
//	ca = (-6)*r2;
//	cd = (-10)*r2;
//	x = 0;
//	y = radius;
//
//	float xPre, yPre;
//	for (indx = 1; indx <= dxt; indx++)
//	{
//		x++;
//		if (e >= 0)
//			e += t + ca;
//		else
//		{
//			y--;
//			e += t - s + cd;
//			s += dst;
//		}
//		t -= dst;
//
//		if (indx != 1)
//		{
//
//			glBegin(GL_QUADS);
//			if (part == 1)
//			{
//				glVertex2f(xc + xPre, yc + yPre);
//				glVertex2f(xc + distance, yc + yPre);
//				glVertex2f(xc + distance, yc + y);
//				glVertex2f(xc + x, yc + y);
//
//				glVertex2f(xc + yPre, yc + xPre);
//				glVertex2f(xc + distance, yc + xPre);
//				glVertex2f(xc + distance, yc + x);
//				glVertex2f(xc + y, yc + x);
//			}
//			if (part == 2)
//			{
//				glVertex2f(xc + yPre, yc - xPre);
//				glVertex2f(xc + distance, yc - xPre);
//				glVertex2f(xc + distance, yc - x);
//				glVertex2f(xc + y, yc - x);
//
//				glVertex2f(xc + xPre, yc - yPre);
//				glVertex2f(xc + distance, yc - yPre);
//				glVertex2f(xc + distance, yc - y);
//				glVertex2f(xc + x, yc - y);
//			}
//			if (part == 3)
//			{
//				glVertex2f(xc - xPre, yc - yPre);
//				glVertex2f(xc - distance, yc - yPre);
//				glVertex2f(xc - distance, yc - y);
//				glVertex2f(xc - x, yc - y);
//
//				glVertex2f(xc - yPre, yc - xPre);
//				glVertex2f(xc - distance, yc - xPre);
//				glVertex2f(xc - distance, yc - x);
//				glVertex2f(xc - y, yc - x);
//			}
//			if (part == 4)
//			{
//				glVertex2f(xc - yPre, yc + xPre);
//				glVertex2f(xc - distance, yc + xPre);
//				glVertex2f(xc - distance, yc + x);
//				glVertex2f(xc - y, yc + x);
//
//				glVertex2f(xc - xPre, yc + yPre);
//				glVertex2f(xc - distance, yc + yPre);
//				glVertex2f(xc - distance, yc + y);
//				glVertex2f(xc - x, yc + y);
//			}
//			glEnd();
//
//		}
//		xPre = x;
//		yPre = y;
//
//	}
//	glBegin(GL_QUADS);
//	if (part == 1)
//	{
//		glVertex2f(xc + y, yc + x);
//		glVertex2f(xc + distance, yc + x);
//		glVertex2f(xc + distance, yc + y);
//		glVertex2f(xc + x, yc + y);
//	}
//	if (part == 2)
//	{
//		glVertex2f(xc + x, yc - y);
//		glVertex2f(xc + distance, yc - y);
//		glVertex2f(xc + distance, yc - x);
//		glVertex2f(xc + y, yc - x);
//	}
//	if (part == 3)
//	{
//		glVertex2f(xc - y, yc - x);
//		glVertex2f(xc - distance, yc - x);
//		glVertex2f(xc - distance, yc - y);
//		glVertex2f(xc - x, yc - y);
//	}
//	if (part == 4)
//	{
//		glVertex2f(xc - x, yc + y);
//		glVertex2f(xc - distance, yc + y);
//		glVertex2f(xc - distance, yc + x);
//		glVertex2f(xc - y, yc + x);
//	}
//	glEnd();
//}
//void Letter::Circle(float xc, float yc, float radius, int partSemicircle)
//{
//	float x, y, dxt;
//	long r2, dst, t, s, e, ca, cd, indx;
//
//	r2 = (long)radius * (long)radius;
//	dst = 4 * r2;
//	dxt = (double)radius / 1.414213562373;
//	t = 0;
//	s = (-4) * r2 * (long)radius;
//	e = (-1)*s / 2. - 3 * r2;
//	ca = (-6)*r2;
//	cd = (-10)*r2;
//	x = 0;
//	y = radius;
//	glBegin(GL_POLYGON);
//
//	glVertex2f(xc, yc + radius);
//	glVertex2f(xc, yc - radius);
//	if (partSemicircle != 2)
//		glVertex2f(xc + radius, yc);
//	if (partSemicircle != 1)
//		glVertex2f(xc - radius, yc);
//
//	for (indx = 1; indx <= dxt; indx++)
//	{
//		x++;
//		if (e >= 0)
//			e += t + ca;
//		else
//		{
//			y--;
//			e += t - s + cd;
//			s += dst;
//		}
//		t -= dst;
//		if (partSemicircle != 2)
//		{
//			glVertex2f(xc + x, yc + y);
//			glVertex2f(xc + y, yc + x);
//			glVertex2f(xc + y, yc - x);
//			glVertex2f(xc + x, yc - y);
//		}
//		if (partSemicircle != 1)
//		{
//			glVertex2f(xc - x, yc - y);
//			glVertex2f(xc - y, yc - x);
//			glVertex2f(xc - y, yc + x);
//			glVertex2f(xc - x, yc + y);
//		}
//	}
//
//	glEnd();
//}
//Letter::Letter(int col_R, int col_G, int col_B, int con_R, int con_G, int con_B, int dx, int dy)
//{
//	defaultColor_R = color_R = col_R;
//	defaultColor_G = color_G = col_G;
//	defaultColor_B = color_B = col_B;
//	defaultContour_R = contour_R = con_R;
//	defaultContour_G = contour_G = con_G;
//	defaultContour_B = contour_B = con_B;
//	Letter::dx = defaultdx = dx;
//	Letter::dy = defaultdy = dy;
//	angleOfCenterRotation = angleOfYourselfRotation = 0.;
//}
//void Letter::move(int dx, int dy)
//{
//	Letter::dx += dx;
//	Letter::dy += dy;
//}
//void Letter::SetAngleOfCenterRotation(float angle)
//{
//	angleOfCenterRotation += angle;
//	if (angleOfCenterRotation > 360)
//		angleOfCenterRotation -= 360;
//	else
//		if (angleOfCenterRotation < -360)
//			angleOfCenterRotation += 360;
//}
//void Letter::SetAngleOfYourselfRotation(float angle)
//{
//	angleOfYourselfRotation += angle;
//	if (angleOfYourselfRotation > 360)
//		angleOfYourselfRotation -= 360;
//	else
//		if (angleOfYourselfRotation < -360)
//			angleOfYourselfRotation += 360;
//}
//void Letter::changeColor()
//{
//	color_R = rand() % 256;
//	color_G = rand() % 256;
//	color_B = rand() % 256;
//	contour_R = rand() % 256;
//	contour_G = rand() % 256;
//	contour_B = rand() % 256;
//}
//void Letter::setDefaultPosition()
//{
//	dx = defaultdx;
//	dy = defaultdy;
//	angleOfCenterRotation = angleOfYourselfRotation = 0.;
//}
//void Letter::setDefaultColor()
//{
//	color_R = defaultColor_R;
//	color_G = defaultColor_G;
//	color_B = defaultColor_B;
//	contour_R = defaultContour_R;
//	contour_G = defaultContour_G;
//	contour_B = defaultContour_B;
//}
//
//
//Letter_V::Letter_V(int col_R, int col_G, int col_B, int con_R, int con_G, int con_B, float r, int dx, int dy) : Letter::Letter(col_R, col_G, col_B, con_R, con_G, con_B, dx, dy), radius(r) {}
//void Letter_V::show()
//{
//	glLoadIdentity();
//	glRotatef((float)angleOfCenterRotation, 0., 0., 1.);
//	glTranslatef(dx, dy, 0.);
//	glRotatef((float)angleOfYourselfRotation, 0., 0., 1.);
//
//	//������ ������ - ������
//	//������ ������ - ������
//	//-1.35 ... 2.12 (width)
//	//-2.05 ... 2.05 (height)
//	float contourDifference = 0.;
//	for (int i = 0; i < 2; i++)
//	{
//		if (i == 0)
//			glColor3ub(contour_R, contour_G, contour_B);
//		else
//		{
//			glColor3ub(color_R, color_G, color_B);
//			contourDifference = 0.049 * radius;
//		}
//		glBegin(GL_QUADS);
//		//������ (������� �������������)
//		glVertex2f(-1.35 * radius + contourDifference, 2.05 * radius - contourDifference);
//		glVertex2f(0.85 * radius - contourDifference, 2.05 * radius - contourDifference);
//		glVertex2f(0.85 * radius - contourDifference, 1.85  * radius + contourDifference);
//		glVertex2f(-1.35 * radius + contourDifference, 1.85  * radius + contourDifference);
//
//		//������ (������� ������������ �������������)
//		glVertex2f(-0.8  * radius + contourDifference, 2 * radius - contourDifference);
//		glVertex2f(0 - contourDifference, 2 * radius - contourDifference);
//		glVertex2f(0 - contourDifference, -2 * radius + contourDifference);
//		glVertex2f(-0.8  * radius + contourDifference, -2 * radius + contourDifference);
//
//		//������ (������� �������������� �������������)
//		glVertex2f(-0.05 * radius, 0. * radius + contourDifference);
//		glVertex2f(0.95 * radius, 0. * radius + contourDifference);
//		glVertex2f(0.95 * radius, 0.25 * radius - contourDifference);
//		glVertex2f(-0.05 * radius, 0.25* radius - contourDifference);
//
//		//������ (������ �������������)
//		glVertex2f(-1.35 * radius + contourDifference, -2.05 * radius + contourDifference);
//		glVertex2f(1. * radius - contourDifference, -2.05 * radius + contourDifference);
//		glVertex2f(1. * radius - contourDifference, -1.85  * radius - contourDifference);
//		glVertex2f(-1.35 * radius + contourDifference, -1.85  * radius - contourDifference);
//
//
//		//������������ ������� ���� � ������� ������ ���� 
//		glVertex2f(0.75 * radius + 2 * contourDifference, 0.6 * radius + 2 * contourDifference);
//		glVertex2f(0.75 * radius + 2 * contourDifference, 1.5 * radius - 2 * contourDifference);
//		glVertex2f(1. * radius - 2 * contourDifference, 1.5 * radius - 2 * contourDifference);
//		glVertex2f(1. * radius - 2 * contourDifference, 0.6 * radius + 2 * contourDifference);
//
//		glVertex2f(0.9 * radius + 2 * contourDifference, -0.5 * radius - 2 * contourDifference);
//		glVertex2f(0.9 * radius + 2 * contourDifference, -1.4 * radius + 2 * contourDifference);
//		glVertex2f(1.15 * radius - 2 * contourDifference, -1.4 * radius + 2 * contourDifference);
//		glVertex2f(1.15 * radius - 2 * contourDifference, -0.5 * radius - 2 * contourDifference);
//
//
//
//		glEnd();
//
//		//�������� ������� �����
//		UNCircle(-1.35 * radius + contourDifference, 1.3 * radius + contourDifference, 0.55 * radius, 1);
//		//�������� ������ �����
//		UNCircle(-1.35 * radius + contourDifference, -1.3 * radius - contourDifference, 0.55 * radius, 2);
//
//		//���� ������ ������
//		UNCircle(-0.1 * radius + contourDifference, 1. * radius + contourDifference, 0.85 * radius, 1);
//		UNCircle(-0.1 * radius + contourDifference, 1.1 * radius - contourDifference, 0.85 * radius, 2);
//		//���� ������ ������
//		UNCircle(-0.1 * radius + contourDifference, -1. * radius + contourDifference, radius, 1);
//		UNCircle(-0.1 * radius + contourDifference, -0.85 * radius - contourDifference, radius, 2);
//
//		//������ ������� ��������
//		Circle(0.8*radius, 1.1 * radius, 0.95*radius - contourDifference, 1);
//		//������ ������ ��������
//		Circle(0.95*radius, -0.85 * radius, 1.2*radius - contourDifference, 1);
//
//	}
//
//
//	glColor3ub(color_R, color_G, color_B);
//	glBegin(GL_QUADS);
//	//������ (������ �������������)
//	glVertex2f(0.6 * radius, 0 * radius);
//	glVertex2f(0.6 * radius, 0.4 * radius);
//	glVertex2f(1.15 * radius, 0.4* radius);
//	glVertex2f(1.15 * radius, 0 * radius);
//
//	//������ ������ ����� ����� ������� ����������
//	glVertex2f(0.799 * radius, 0.3 * radius);
//	glVertex2f(0.85 * radius, 0.3 * radius);
//	glVertex2f(0.85 * radius, 1.9 * radius);
//	glVertex2f(0.799 * radius, 1.9 * radius);
//
//	//������ ������ ����� ����� ������ ����������
//	glVertex2f(0.949 * radius, 0.1 * radius);
//	glVertex2f(1. * radius, 0.1 * radius);
//	glVertex2f(1. * radius, -1.95 * radius);
//	glVertex2f(0.949 * radius, -1.95 * radius);
//	glEnd();
//}
//
//Letter_G::Letter_G(int col_R, int col_G, int col_B, int con_R, int con_G, int con_B, float r, int dx, int dy) : Letter::Letter(col_R, col_G, col_B, con_R, con_G, con_B, dx, dy), radius(r) {}
//void Letter_G::show()
//{
//	glLoadIdentity();
//	glRotated((float)angleOfCenterRotation, 0., 0., 1.);
//	glTranslated(dx, dy, 0.);
//	glRotated((float)angleOfYourselfRotation, 0., 0., 1.);
//
//
//	//-1.35 ... 1.65 (width)
//	//-2.05 ... 2.05 (height)
//	//������ ������ - ������
//	//������ ������ - ������
//	float contourDifference = 0.;
//	for (int i = 0; i < 2; i++)
//	{
//		if (i == 0)
//			glColor3ub(contour_R, contour_G, contour_B);
//		else
//		{
//			glColor3ub(color_R, color_G, color_B);
//			contourDifference = 0.049 * radius;
//		}
//		glBegin(GL_QUADS);
//		//������ (������� ����� �������������� �������������)
//		glVertex2f(-1.35 * radius + contourDifference, 2.05 * radius - contourDifference);
//		glVertex2f(-0.4 * radius - contourDifference, 2.05 * radius - contourDifference);
//		glVertex2f(-0.4 * radius - contourDifference, 1.85 * radius + contourDifference);
//		glVertex2f(-1.35 * radius + contourDifference, 1.85 * radius + contourDifference);
//
//		//������ (������ ������ �������������� �������������)
//		glVertex2f(-0.5 * radius + contourDifference, 2.05 * radius - contourDifference);
//		glVertex2f(1.65 * radius - contourDifference, 2.05 * radius - contourDifference);
//		glVertex2f(1.65 * radius - contourDifference, 1.65 * radius + contourDifference);
//		glVertex2f(-0.5 * radius + contourDifference, 1.65 * radius + contourDifference);
//
//		//������ (���� ������������ �������������)
//		glVertex2f(1.65  * radius - contourDifference, 2.05 * radius - contourDifference);
//		glVertex2f(1.65  * radius - contourDifference, 0.95 * radius + contourDifference);
//		glVertex2f(1.4   * radius + contourDifference, 0.95 * radius + contourDifference);
//		glVertex2f(1.4   * radius + contourDifference, 2.05 * radius - contourDifference);
//
//		//������ (������� �������������)
//		glVertex2f(-0.8  * radius + contourDifference, 2 * radius - contourDifference);
//		glVertex2f(0 - contourDifference, 2 * radius - contourDifference);
//		glVertex2f(0 - contourDifference, -2 * radius + contourDifference);
//		glVertex2f(-0.8  * radius + contourDifference, -2 * radius + contourDifference);
//
//		//������ (������ �������������)
//		glVertex2f(-1.35 * radius + contourDifference, -2.05 * radius + contourDifference);
//		glVertex2f(0.55 * radius - contourDifference, -2.05 * radius + contourDifference);
//		glVertex2f(0.55 * radius - contourDifference, -1.85  * radius - contourDifference);
//		glVertex2f(-1.35 * radius + contourDifference, -1.85  * radius - contourDifference);
//
//		glEnd();
//
//		//�������� ������� ������
//		UNCircle(0.65 * radius + contourDifference, 0.9   * radius + contourDifference, 0.75 * radius, 1);
//		//�������� ������� �����
//		UNCircle(-1.35 * radius + contourDifference, 2.2 * radius - 0.9 * radius + contourDifference, 0.55 * radius, 1);
//		//�������� ������ �����
//		UNCircle(-1.35 * radius + contourDifference, -1.3 * radius - contourDifference, 0.55 * radius, 2);
//		//�������� ������ ������
//		UNCircle(0.55 * radius - contourDifference, -1.3 * radius - contourDifference, 0.55 * radius, 3);
//	}
//}