#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
int flag = -1;
int keyflag=-999;
int enter = 0;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1200, 0, 700);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void keys(unsigned char key, int x, int y)
{
	if (key == '1') keyflag = 1;
	else if (key == '2') keyflag = 2;
	else if (key == '3') keyflag = 3;
	else if (key == '4') keyflag = 4;
	else if (key == '5') keyflag = 5;
	else if (key == '6') keyflag = 6;
	else if (key == '7') keyflag = 7;
	else if (key == '8') keyflag = 8;
	else if (key == '9') keyflag = 9;
	else keyflag = 0;
}


void renderBitmapString(float x, float y, float z, void* font, const char* string)
{
	const char* c;
	glColor3f(1, 0, 0);
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void xrenderBitmapString(float x, float y, float z, void* font, const char* string, float r, float g, float b)
{
	const char* c;
	glColor3f(r, g, b);
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void Circle_theta(float r, float xc, float yc)
{
	float theta, x, y;
	//glColor3f(0.613, 0.902, 0.789);
	glColor3f(0, 1, 0);
	glBegin(GL_LINE_STRIP);
	for (theta = 0; theta <= 360; theta++)
	{
		x = r * cos(theta);
		y = r * sin(theta);
		glVertex2f(x + xc, y + yc);
	}
	glEnd();
}

void fill_Circle_theta(float r, float xc, float yc)
{
	float theta, x, y;
	//glColor3f(0.613, 0.902, 0.789);
	glColor3f(0, 0.5, 0);
	glBegin(GL_POLYGON);
	for (theta = 0; theta <= 360; theta++)
	{
		x = r * cos(theta);
		y = r * sin(theta);
		glVertex2f(x + xc, y + yc);
	}
	glEnd();
}

void void_Circle_theta(float r, float xc, float yc)
{
	float theta, x, y;
	//glColor3f(0.613, 0.902, 0.789);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (theta = 0; theta <= 360; theta++)
	{
		x = r * cos(theta);
		y = r * sin(theta);
		glVertex2f(x + xc, y + yc);
	}
	glEnd();
}

//void rectangle(float x, float y)
//{
//	glColor3f(1, 0.7, 0);
//	glBegin(GL_LINE_LOOP);
//	glVertex2f(x + 75, y + 75);
//	glVertex2f(x - 75, y + 75);
//	glVertex2f(x - 75, y - 75);
//	glVertex2f(x + 75, y - 75);
//	glEnd();
//	glFlush();
//}

void mini_rectangle(float x, float y)
{
	glColor3f(1, 0.7, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x ,y);
	glVertex2f(x+70, y);
	glVertex2f(x+70, y-35);
	glVertex2f(x, y-35);
	glEnd();
	glLineWidth(0.0);
	glFlush();
}

void display(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	if (flag == -1)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.0, 0.5, 0.7);
		xrenderBitmapString(400, 585, 0, GLUT_BITMAP_TIMES_ROMAN_24, "RNS INSTITUTE OF TECHNOLOGY",1,0.64,0);
		xrenderBitmapString(330, 520, 0, GLUT_BITMAP_TIMES_ROMAN_24, "HOW CONVOLUTIONAL NEURAL NETWORK ",1, 0,0);
		xrenderBitmapString(360, 350, 0, GLUT_BITMAP_TIMES_ROMAN_24, "1RN18CS048 " , 0.7 , 0.7, 0);
		xrenderBitmapString(360, 400, 0, GLUT_BITMAP_TIMES_ROMAN_24, "HRITHIK K ", 0 , 0.3 ,0.7);
		xrenderBitmapString(670, 350, 0, GLUT_BITMAP_TIMES_ROMAN_24, "1RN18CS037 ", 0.7, 0.7, 0);
		xrenderBitmapString(670, 400, 0, GLUT_BITMAP_TIMES_ROMAN_24, "DHANUSH V ", 0, 0.3, 0.7);
		enter = 1;
		
		xrenderBitmapString(520, 150, 0, GLUT_BITMAP_TIMES_ROMAN_24, "click here ", 1, 0, 0);
		glColor3f(1.0, 1.0, 1.0);
		/*renderStrokeString(30,365, 0, GLUT_STROKE_ROMAN, "HOW CONVOLUTIONAL NEURAL NETWORK WORKS");*/
		glFlush();
	}
	else
	{
		glPointSize(4);
		//rectangle(100, 600);
		//Circle_theta(50, 100, 600);//main circle
		glutKeyboardFunc(keys);
		renderBitmapString(315, 15, 0, GLUT_BITMAP_HELVETICA_18, "Input layer");
		renderBitmapString(575, 50, 0, GLUT_BITMAP_HELVETICA_18, "hidden layer 1");
		renderBitmapString(825, 50, 0, GLUT_BITMAP_HELVETICA_18, "hidden layer 2");
		renderBitmapString(1000, 130, 0, GLUT_BITMAP_HELVETICA_18, "Output layer");
		printf("%d", keyflag);
		glLineWidth(0);
		renderBitmapString(100, 600, 0, GLUT_BITMAP_HELVETICA_18, "Enter the number");
		if(keyflag==0)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "0", 1, 1, 0);
		else if (keyflag == 1)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "1", 1, 1, 0);
		else if (keyflag == 2)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "2", 1, 1, 0);
		else if (keyflag == 3)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "3", 1, 1, 0);
		else if (keyflag == 4)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "4", 1, 1, 0);
		else if (keyflag == 5)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "5", 1, 1, 0);
		else if (keyflag == 6)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "6", 1, 1, 0);
		else if (keyflag == 7)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "7", 1, 1, 0);
		else if (keyflag == 8)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "8", 1, 1, 0);
		else if (keyflag == 9)
			xrenderBitmapString(150, 570, 0, GLUT_BITMAP_TIMES_ROMAN_24, "9", 1, 1, 0);
		
		//connect lines from first row to second row
		for (int i = 650; i >= 55; i = i - 35)
		{
			for (int j = 615; j >= 90; j = j - 35)
			{
				if (i < 405 && i > 300)
					continue;
				glLineWidth(0);
				glColor3f(1, 1, 1);
				glBegin(GL_LINES);
				glVertex2i(350, i);
				glVertex2i(625, j);
				glEnd();
			}
		}

		//connect lines from second row to third row
		for (int i = 615; i >= 90; i = i - 35)
		{
			for (int j = 615; j >= 90; j = j - 35)
			{
				glLineWidth(0);
				glBegin(GL_LINES);
				glVertex2i(625, i);
				glVertex2i(875, j);
				glEnd();
			}
		}

		//connect lines from third row to fourth row
		for (int i = 615; i >= 90; i = i - 35)
		{
			for (int j = 490; j >= 160; j = j - 35)
			{
				glLineWidth(0);
				glBegin(GL_LINES);
				glVertex2i(875, i);
				glVertex2i(1050, j);
				glEnd();
			}
		}

		//first row
		//nodes start from here
		for (int i = 650; i >= 55; i = i - 35)
		{
			if (i < 405 && i > 300)
				continue;
			Circle_theta(13, 350, i);
			void_Circle_theta(11, 350, i);
		}

		//for dotted lines
		glColor3f(0, 1, 0);
		glBegin(GL_POINTS);
		glVertex2i(350, 370);
		glVertex2i(350, 352);
		glVertex2i(350, 335);
		glEnd();

		//second row
		for (int i = 615; i >= 90; i = i - 35)
		{
			Circle_theta(13, 625, i);
			void_Circle_theta(11, 625, i);
		}

		//third row
		for (int i = 615; i >= 90; i = i - 35)
		{
			Circle_theta(13, 875, i);
			void_Circle_theta(11, 875, i);
		}

		//fourth row
		for (int i = 490; i >= 160; i = i - 35)
		{
			Circle_theta(13, 1050, i);
			void_Circle_theta(11, 1050, i);
		}

		//to put the numbers
		renderBitmapString(1075, 480, 0, GLUT_BITMAP_TIMES_ROMAN_24, "0");
		renderBitmapString(1075, 445, 0, GLUT_BITMAP_TIMES_ROMAN_24, "1");
		renderBitmapString(1075, 410, 0, GLUT_BITMAP_TIMES_ROMAN_24, "2");
		renderBitmapString(1075, 375, 0, GLUT_BITMAP_TIMES_ROMAN_24, "3");
		renderBitmapString(1075, 340, 0, GLUT_BITMAP_TIMES_ROMAN_24, "4");
		renderBitmapString(1075, 305, 0, GLUT_BITMAP_TIMES_ROMAN_24, "5");
		renderBitmapString(1075, 270, 0, GLUT_BITMAP_TIMES_ROMAN_24, "6");
		renderBitmapString(1075, 235, 0, GLUT_BITMAP_TIMES_ROMAN_24, "7");
		renderBitmapString(1075, 200, 0, GLUT_BITMAP_TIMES_ROMAN_24, "8");
		renderBitmapString(1075, 165, 0, GLUT_BITMAP_TIMES_ROMAN_24, "9");

		//for big left line
		glColor3f(1, 0, 0);
		glBegin(GL_LINES);
		glVertex2i(320, 640);
		glVertex2i(320, 365);
		glVertex2i(320, 330);
		glVertex2i(320, 65);
		glVertex2i(320, 640);
		glVertex2i(330, 655);
		glVertex2i(320, 65);
		glVertex2i(330, 50);
		glEnd();

		//for small arrow
		glBegin(GL_LINES);
			glVertex2i(320, 365);
			glVertex2i(305, 347);
			glVertex2i(305, 347);
			glVertex2i(320, 330);
		glEnd();
		renderBitmapString(260, 344, 0, GLUT_BITMAP_TIMES_ROMAN_24, "784");
		renderBitmapString(243, 324, 0, GLUT_BITMAP_TIMES_ROMAN_24, "nodes");

		glLineWidth(0);
		/*glBegin(GL_LINES);
		glVertex2i(118, 620);
		glVertex2i(83, 560);
		glEnd();*/
		if (flag >= 1 && (keyflag >= 0 && keyflag <= 9))
		{
				fill_Circle_theta(11, 350, 615);
				fill_Circle_theta(11, 350, 580);
				fill_Circle_theta(11, 350, 545);
				fill_Circle_theta(11, 350, 510);
				fill_Circle_theta(11, 350, 475);
				fill_Circle_theta(11, 350, 440);
				fill_Circle_theta(11, 350, 405);
				fill_Circle_theta(11, 350, 300);
				fill_Circle_theta(11, 350, 265);
				fill_Circle_theta(11, 350, 230);
				fill_Circle_theta(11, 350, 195);
				fill_Circle_theta(11, 350, 160);

		}

		if (flag >= 2 && (keyflag >= 0 && keyflag <= 9))
		{
			for (int i = 650; i >= 55; i = i - 35)
			{
				for (int j = 615; j >= 90; j = j - 35)
				{
					if ((i == 580 || i == 545 || i == 510 || i == 475 || i == 440 || i == 405 || i == 300 || i == 265 || i == 230 || i == 195 || i == 160) && (j == 545 || j == 475 || j == 335 || j == 195 || j == 160 || j == 125))
					{
						glLineWidth(0);
						glColor3f(1,1,0);
						glBegin(GL_LINES);
						glVertex2i(350, i);
						glVertex2i(625, j);
						glEnd();
					}
				}
			}
			//for previous rows
			fill_Circle_theta(11, 350, 615);
			fill_Circle_theta(11, 350, 580);
			fill_Circle_theta(11, 350, 545);
			fill_Circle_theta(11, 350, 510);
			fill_Circle_theta(11, 350, 475);
			fill_Circle_theta(11, 350, 440);
			fill_Circle_theta(11, 350, 405);
			fill_Circle_theta(11, 350, 300);
			fill_Circle_theta(11, 350, 265);
			fill_Circle_theta(11, 350, 230);
			fill_Circle_theta(11, 350, 195);
			fill_Circle_theta(11, 350, 160);

			//for current rows
			fill_Circle_theta(11, 625, 545);
			fill_Circle_theta(11, 625, 475);
			fill_Circle_theta(11, 625, 335);
			fill_Circle_theta(11, 625, 195);
			fill_Circle_theta(11, 625, 160);
			fill_Circle_theta(11, 625, 125);
		}

		if (flag >= 3 && (keyflag >= 0 && keyflag <= 9))
		{

			for (int i = 615; i >= 90; i = i - 35)
			{
				for (int j = 615; j >= 90; j = j - 35)
				{
					if ((i == 545 || i == 475 || i == 335 || i == 195 || i == 160 || i == 125) && (j == 510 || j == 475 || j == 335 || j == 300 || j == 125 || j == 90 || j == 405))
					{
						glLineWidth(0);
						glColor3f(1 ,1 , 0);
						glBegin(GL_LINES);
						glVertex2i(625, i);
						glVertex2i(875, j);
						glEnd();
					}
				}
			}
			//for previous rows
			fill_Circle_theta(11, 625, 545);
			fill_Circle_theta(11, 625, 475);
			fill_Circle_theta(11, 625, 335);
			fill_Circle_theta(11, 625, 195);
			fill_Circle_theta(11, 625, 160);
			fill_Circle_theta(11, 625, 125);

			//for current rows
			fill_Circle_theta(11, 875, 510);
			fill_Circle_theta(11, 875, 475);
			fill_Circle_theta(11, 875, 405);
			fill_Circle_theta(11, 875, 335);
			fill_Circle_theta(11, 875, 300);
			fill_Circle_theta(11, 875, 125);
			fill_Circle_theta(11, 875, 90);
		}
		
		if (flag >= 4 && (keyflag >= 0 && keyflag <= 9))
		{

			if (keyflag == 0)
			{
				for (int i = 615; i >= 90; i = i - 35)
				{
					for (int j = 490; j >= 160; j = j - 35)
					{
						if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 490))
						{
							glLineWidth(0);
							glColor3f(1, 1, 0);
							glBegin(GL_LINES);
							glVertex2i(875, i);
							glVertex2i(1050, j);
							glEnd();
						}
					}
				}
				mini_rectangle(1028, 507);
				fill_Circle_theta(11, 1050, 490);
			}


			else if (keyflag == 1)
			{
				for (int i = 615; i >= 90; i = i - 35)
				{
					for (int j = 490; j >= 160; j = j - 35)
					{
						if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 455))
						{
							glLineWidth(0);
							glColor3f(1, 1, 0);
							glBegin(GL_LINES);
							glVertex2i(875, i);
							glVertex2i(1050, j);
							glEnd();
						}
					}
				}
				mini_rectangle(1028, 472);
				fill_Circle_theta(11, 1050, 455);
			}


			else if (keyflag == 2)
			{
				for (int i = 615; i >= 90; i = i - 35)
				{
					for (int j = 490; j >= 160; j = j - 35)
					{
						if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 420))
						{
							glLineWidth(0);
							glColor3f(1, 1, 0);
							glBegin(GL_LINES);
							glVertex2i(875, i);
							glVertex2i(1050, j);
							glEnd();
						}
					}
				}
				mini_rectangle(1028, 437);
				fill_Circle_theta(11, 1050, 420);
			}


			else if (keyflag == 3)
			{
				for (int i = 615; i >= 90; i = i - 35)
				{
					for (int j = 490; j >= 160; j = j - 35)
					{
						if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 385))
						{
							glLineWidth(0);
							glColor3f(1, 1, 0);
							glBegin(GL_LINES);
							glVertex2i(875, i);
							glVertex2i(1050, j);
							glEnd();
						}
					}
				}
				mini_rectangle(1028, 402);
				fill_Circle_theta(11, 1050, 385);
			}


			else if (keyflag == 4)
			{
				for (int i = 615; i >= 90; i = i - 35)
				{
					for (int j = 490; j >= 160; j = j - 35)
					{
						if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 350))
						{
							glLineWidth(0);
							glColor3f(1, 1, 0);
							glBegin(GL_LINES);
							glVertex2i(875, i);
							glVertex2i(1050, j);
							glEnd();
						}
					}
				}
				mini_rectangle(1028, 367);
				fill_Circle_theta(11, 1050, 350);
			}


			else if (keyflag == 5)
			{
				for (int i = 615; i >= 90; i = i - 35)
				{
					for (int j = 490; j >= 160; j = j - 35)
					{
						if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 315))
						{
							glLineWidth(0);
							glColor3f(1, 1, 0);
							glBegin(GL_LINES);
							glVertex2i(875, i);
							glVertex2i(1050, j);
							glEnd();
						}
					}
				}
				mini_rectangle(1028, 332);
				fill_Circle_theta(11, 1050, 315);
			}


			else if (keyflag == 6)
			{
			for (int i = 615; i >= 90; i = i - 35)
			{
				for (int j = 490; j >= 160; j = j - 35)
				{
					if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 280))
					{
						glLineWidth(0);
						glColor3f(1, 1, 0);
						glBegin(GL_LINES);
						glVertex2i(875, i);
						glVertex2i(1050, j);
						glEnd();
					}
				}
			}
			mini_rectangle(1028, 297);
			fill_Circle_theta(11, 1050, 280);
			}


			else if (keyflag == 7)
			{
			for (int i = 615; i >= 90; i = i - 35)
			{
				for (int j = 490; j >= 160; j = j - 35)
				{
					if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 245))
					{
						glLineWidth(0);
						glColor3f(1, 1, 0);
						glBegin(GL_LINES);
						glVertex2i(875, i);
						glVertex2i(1050, j);
						glEnd();
					}
				}
			}
			mini_rectangle(1028, 262);
			fill_Circle_theta(11, 1050, 245);
			}


			else if (keyflag == 8)
			{
			for (int i = 615; i >= 90; i = i - 35)
			{
				for (int j = 490; j >= 160; j = j - 35)
				{
					if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 210))
					{
						glLineWidth(0);
						glColor3f(1, 1, 0);
						glBegin(GL_LINES);
						glVertex2i(875, i);
						glVertex2i(1050, j);
						glEnd();
					}
				}
			}
			mini_rectangle(1028, 227);
			fill_Circle_theta(11, 1050, 210);
			}


			else
			{
			for (int i = 615; i >= 90; i = i - 35)
			{
				for (int j = 490; j >= 160; j = j - 35)
				{
					if ((i == 510 || i == 475 || i == 335 || i == 300 || i == 125 || i == 90 || i == 405) && (j == 175))
					{
						glLineWidth(0);
						glColor3f(1, 1, 0);
						glBegin(GL_LINES);
						glVertex2i(875, i);
						glVertex2i(1050, j);
						glEnd();
					}
				}
			}
			mini_rectangle(1028, 192);
			fill_Circle_theta(11, 1050, 175);
			}

			//for previous rows
			fill_Circle_theta(11, 875, 510);
			fill_Circle_theta(11, 875, 475);
			fill_Circle_theta(11, 875, 405);
			fill_Circle_theta(11, 875, 335);
			fill_Circle_theta(11, 875, 300);
			fill_Circle_theta(11, 875, 125);
			fill_Circle_theta(11, 875, 90);
		}


		glFlush();
		glLineWidth(0);
	}
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			glutPostRedisplay();
			if (enter == 1)
			{
				flag++;
				enter--;
			}
			else if(flag<4 && (keyflag>=0 && keyflag<=9))
			flag++;
		}
		else if (state == GLUT_UP)
			glutPostRedisplay();
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{
			if(flag>0)
			flag--;
			glutPostRedisplay();
		}
		break;
	default: break;
	}
}


int main(int argc,char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(175, 75);
	glutInitWindowSize(1200, 700);
	glutCreateWindow("CONVOLUTIONAL NEURAL NETWORK");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}