//#ifndef LETTER_H
//#define LETTER_H
//
//#include "includes.h"
//
//class Letter;
//
//class LetterCollector
//{
//private:
//	static LetterCollector* p_instance;
//	LetterCollector() {}
//	LetterCollector(const LetterCollector&);
//	LetterCollector operator=(LetterCollector&);
//
//	int idCurrentLetter;
//	Letter* listOfLetters[2];
//	int continuousTurn[2];
//public:
//	static LetterCollector* getInstance();
//	void ChangeCurrentLetter();
//	void ChangeColorOfLetter(int);
//	void showLetters();
//	void SetCenterAngleOfLatter(int, float);
//	void SetYourselfAngleOfLatter(int, float);
//	void SetContinuousTurn(int, int);
//	void moveCurrentLetter(int, int);
//	void moveAllLetters(int, int);
//	void DefaultPosition();
//	void DefaultColor();
//};
//
//class Letter
//{
//protected:
//
//	int defaultContour_R, defaultContour_G, defaultContour_B;
//	int defaultColor_R, defaultColor_G, defaultColor_B;
//	int defaultdx, defaultdy;
//	int color_R, color_G, color_B;
//	int contour_R, contour_G, contour_B;
//	int dx, dy;
//	float angleOfCenterRotation, angleOfYourselfRotation;
//
//	void UNCircle(float, float, float, int);
//	void Circle(float, float, float, int);
//
//public:
//	Letter(int, int, int, int, int, int, int, int);
//	void move(int, int);
//	void SetAngleOfCenterRotation(float);
//	void SetAngleOfYourselfRotation(float);
//	void changeColor();
//	void setDefaultColor();
//	void setDefaultPosition();
//	virtual void show() = 0;
//};
//
//class Letter_V : public Letter
//{
//private:
//	float radius;
//public:
//	Letter_V(int, int, int, int, int, int, float, int, int);
//	void show();
//};
//
//class Letter_G : public Letter
//{
//private:
//	float radius;
//public:
//	Letter_G(int, int, int, int, int, int, float, int, int);
//	void show();
//};
//
//
//#endif
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////void newCircle(int R)
////{
////	int x = 0;
////	int y = R;
////	int d = 3 - 2 * R;
////	glBegin(GL_POLYGON);
////	while (x <= y)
////	{
////		glVertex2f(x, y);
////		glVertex2f(y, x);
////		glVertex2f(y, -x);
////		glVertex2f(x, -y);
////		glVertex2f(-x, -y);
////		glVertex2f(-y, -x);
////		glVertex2f(-y, x);
////		glVertex2f(-x, y);
////		if (d < 0)
////			d += 4 * x + 6;
////		else
////		{
////			d += 4 * x - 4 * y + 10;
////			y--;
////		}
////		x++;
////	}
////	glEnd();
////}
//
//
//
////void oldB(float radius)
////{
////	float radiusB = radius*1.2;
////	//glLineWidth(radius/10.);
////
////	//������
////	glColor3ub(230, 223, 68);
////	//glColor3ub(0, 0, 0);
////
////		Circle(radius * 0.8, radius, radius*1.05, 1, true);
////		Circle(radiusB * 0.8, -radiusB, radiusB*1.05, 1, true);
////
////		glBegin(GL_POLYGON);
////			glVertex2f(radius * (-1.15), 2.05 * radius);
////			glVertex2f(radius * 0.8, 2.05 * radius);
////			glVertex2f(radius * 0.8, 0);
////			glVertex2f(radius * (-1.), 1.9 * radius);
////			glVertex2f(radius * (-1.15), 1.9 * radius);
////		glEnd();
////		glBegin(GL_POLYGON);
////			glVertex2f(radius * (-1.15), -2.05 * radiusB);
////			glVertex2f(radiusB * 0.8, -2.05 * radiusB);
////			glVertex2f(radiusB * 0.8, 0);
////			glVertex2f(radius * (-1.), -1.91 * radiusB);
////			glVertex2f(radius * (-1.15), -1.91 * radiusB);
////		glEnd();
////
////	//������
////	glColor3ub(/*63, 104, 28*/141, 35, 15);
////
////		Circle(radius * 0.8, radius, radius, 1, true);
////		Circle(radiusB * 0.8, -radiusB, radiusB, 1, true);
////
////		glBegin(GL_QUADS);
////			glVertex2f(radius * (-1.1), 2* radius);
////			glVertex2f(radius * 0.8, 2 * radius);
////			glVertex2f(radius * 0.8, 0);
////			glVertex2f(radius * (-1.1), 0);
////
////			glVertex2f(radius * (-1.1), -2 * radiusB);
////			glVertex2f(radiusB * 0.8, -2 * radiusB);
////			glVertex2f(radiusB * 0.8, 0);
////			glVertex2f(radius * (-1.1), 0);
////		glEnd();
////
////	//������
////	glColor3ub(230, 223, 68);
////	//glColor3ub(0, 0, 0);
////
////		Circle(radius * 0.2, radius - radius*0.05, radius * 0.9, 1, true);
////		Circle(radius * 0.2, -radiusB + radiusB*0.05, radiusB * 0.9, 1, true);
////
////		glBegin(GL_QUADS);
////			glVertex2f(radius * 0.15, radius - radius*0.05 + radius * 0.9);
////			glVertex2f(radius * 0.2, radius - radius*0.05 + radius * 0.9);
////			glVertex2f(radius * 0.2, radius * 0.055);
////			glVertex2f(radius * 0.15, radius * 0.055);
////
////			glVertex2f(radius * 0.15, -radius * 0.06);
////			glVertex2f(radius * 0.2, -radius * 0.06);
////			glVertex2f(radius * 0.2, -radiusB + radiusB*0.05 - radiusB * 0.895);
////			glVertex2f(radius * 0.15, -radiusB + radiusB*0.05 - radiusB * 0.895);
////		glEnd();
////
////	//���������� ���������
////	glColor3f(0.8, 0.8, 0.8);
////
////		Circle(radius * 0.2, radius - radius*0.05, radius * 0.85, 1, true);
////		Circle(radius * 0.2, -radiusB + radiusB*0.05, radiusB * 0.85, 1, true);
////
////	//������
////	glColor3ub(230, 223, 68);
////	//glColor3ub(0, 0, 0);
////
////		Circle(radius * (-1.1), 2 * radius - radius * 0.6, radius * 0.55, 1, true);
////		Circle(radius * (-1.1), -2 * radiusB + radius * 0.6, radius * 0.55, 1, true);
////
////		glBegin(GL_POLYGON);
////			glVertex2f(radius * (-1.1), -2 * radiusB + radius * 0.6);
////			glVertex2f(radius * (-1.1), 2 * radius - radius * 0.6);
////			glVertex2f(radius * (-1.1) + radius * 0.55, 2 * radius - radius * 0.6);
////			glVertex2f(radius * (-1.1) + radius * 0.55, -2 * radiusB + radius * 0.6);
////		glEnd();
////
////	//������ ����� �����
////	glColor3f(0.8, 0.8, 0.8);
////
////		Circle(radius * (-1.1), 2 * radius - radius * 0.6, radius * 0.5, 1, true);
////		Circle(radius * (-1.1), -2 * radiusB + radius * 0.6, radius * 0.5, 1, true);
////
////		glBegin(GL_POLYGON);
////			glVertex2f(radius * (-1.1), -2 * radiusB + radius * 0.6);
////			glVertex2f(radius * (-1.1), 2 * radius - radius * 0.6);
////			glVertex2f(radius * (-1.1) + radius * 0.5, 2 * radius - radius * 0.6);
////			glVertex2f(radius * (-1.1) + radius * 0.5, -2 * radiusB + radius * 0.6);
////		glEnd();
////}