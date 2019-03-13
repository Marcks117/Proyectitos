//Semestre 2019 - 2
//************* Alumno: López Pérez Marcos Emiliano **********//
//*************	Proyectito 1: Dibujo de lineas ****************//
//*************	Microsoft Visual Studio 2017 *****************//
//************************************************************//
#include "Main.h"

float V0x=0 , V0y=0;
float V1x = 0, V1y = 0;
float V2x = 0, V2y = 0;
float l, h;
float angX = 0.0f;
float angY = 0.0f;
float transZ = -5.0f;
float transX = 0.0;
float transY = 0.0;
int screenW = 0.0;
int screenH = 0.0;
int Sector, Sector2, SectorSum;
float V0eqx=0, V0eqy=0;
float Usup, Ysup, Xsup, Uinf, Yinf, Xinf, Uizq, Xizq, Yizq, Uder, Xder, Yder;

void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)    //Función a la que se transforma para colocar cada cubo
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		glTranslatef(transX, transY, transZ);

//Poner Código Aquí.
		V0eqx = V0x + (l / 2);
		V0eqy = V0y + (h / 2);
	//Linea
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(V1x,V1y , 0.01f);
		glVertex3f(V2x, V2y, 0.01f);
		glEnd();

	//Ventana

		if (l <= 0)
			l = 0;
		if (h <= 0)
			h = 0;

		glColor3f(0.40, 0.40, 1.0);
		glTranslatef(V0eqx, V0eqy,0);//V0x+(l/2), V0y+(h/2), 0); 
		glScalef(l, h, 0);
		prisma();



	/*	glColor3f(1.0, 0.2, 0.60);
		glRotatef(-90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
		glTranslatef(0, 0, -1);
		glScalef(1.70, 0.25, 1.0);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
		prisma();	*/ //Ejemplo transformaciones
  											
  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
			transX -= 0.2f;
			break;
		case 'd':
		case 'D':
			transX += 0.2f;
			break;
		case 'q':
		case 'Q':
			transY -= 0.2f;
			break;
		case 'e':
		case 'E':
			transY += 0.2f;
			break;
		case 'l':
		case 'L':
			l += 0.1f;
			break;
		case 'h':
		case 'H':
			h += 0.1f;
			break;

		case 'g':
		case 'G':
			h -= 0.3f;
			break;
		case 'k':
		case 'K':
			l -= 0.3f;
			break;

		case '1':
			V1x += 0.1f;
			break;
		case '!':
			V1x -= 0.1f;
			break;
		case '2':
			V1y += 0.1f;
			break;
		case '"':
			V1y -= 0.1f;
			break;
		case '3':
			V2x += 0.1f;
			break;
		case '#':
			V2x -= 0.1f;
			break;
		case '4':
			V2y += 0.1f;
			break;
		case '$':
			V2y -= 0.1f;
			break;
		case 'P':
		case 'p':
			printf("\n***** Coordenadas actuales *****\n\n");
			printf("Ventana: \n\nVo : ( %f , %f ) \nLargo= %f \nAlto= %f \n\n", V0x,V0y,l,h);
			printf("Linea: \n\nVertice1: (%f , %f)  \nVertice2: (%f , %f) \n\n ",V1x,V1y,V2x,V2y);
			if (V0eqx <= V1x <= (V0eqx + l) )
			{
				if (V0eqy <= V1y <= (V0eqy + h)) {
					Sector = 0;
				}
			}
			else if (V1x < V0eqx && V0eqy <= V1y <= (V0eqy + h))
			{
				Sector = 2;
			}
			else if (V1x < V0eqx && V1y>(V0eqy + h))
			{
				Sector = 10;
			}
			else if (V1x < V0eqx && V1y < V0eqy)
			{
				Sector = 6;
			}
			else if (V0eqx <= V1x <= (V0eqx + l) && V1y > (V0eqy + h))
			{
				Sector = 8;
			}
			else if (V0eqx <= V1x <= (V0eqx + l) && V1y < V0eqy)
			{
				Sector = 4;
			}
			else if ((V0eqx + l) < V1x  && V0eqy <= V1y <= (V0eqy + h))
			{
				Sector = 1;
			}
			else if ((V0eqx + l) < V1x && (V0eqy + h) < V1y)
			{
				Sector = 9;
			}
			else if ((V0eqx + l) < V1x  && V1y < V0eqy)
			{
				Sector = 5;
			}
//Algoritmo de Recorte V2
			if (V0eqx <= V2x <= (V0eqx + l))
			{
				if (V0eqy <= V2y <= (V0eqy + h))
				{
					Sector2 = 0;
				}
			}
			else if (V2x < V0eqx)
			{
				if (V0eqy <= V2y <= (V0eqy + h))
				{
					Sector2 = 2;
				}
				
			}
			else if (V2x < V0eqx )
			{
				if (V2y > (V0eqy + h))
				{
					Sector2 = 10;
				}
				
			}
			else if (V2x < V0eqx)
			{
				if (V2y < V0eqy) {
					Sector2 = 6;
				}
			}
			else if (V0eqx <= V2x <= (V0eqx + l))
			{
				if (V2y > (V0eqy + h)) {
					Sector2 = 8;
				}
			}
			else if (V0eqx <= V2x <= (V0eqx + l))
			{
				if (V2y < V0eqy)
				{
					Sector2 = 4;
				}
			}
			else if ((V0eqx + l) < V2x)
			{
				if (V0eqy <= V2y <= (V0eqy + h)) {
					Sector2 = 1;
				}
			}
			else if ((V0eqx + l) < V2x )
			{
				if ((V0eqy + h) < V2y) {
						Sector2 = 9;
				}	
			}
			else if ((V0eqx + l) < V2x  )
			{
				if (V2y < V0eqy)
				{
					Sector2 = 5;
				}
				
			}

			SectorSum = Sector + Sector2;
			
			if (Sector = 0)
			{
				if (Sector2 = 1)
				{
					printf("\n\nLa linea se recorta");
					Uder = (V0eqx - V1x) / (V2x - V1x);
					if (0 <= Uder <= 1)
					{
						Yder = V1y + Uder * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				else if(Sector2 = 2){
					printf("\n\nLa linea se recorta");
					Uizq = (V0x - V1x) / (V2x - V1x);
					if (0 <= Uizq <= 1)
					{
						Yizq = V1y + Uizq * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
				}else if (Sector2 = 4) {
					printf("\n\nLa linea se recorta");
					Uinf = (V0y - V1y) / (V2y - V1y);
					if (0 <= Uinf <= 1)
					{
						Xinf = V1x + Uinf * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xinf, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
				}else if (Sector2 = 5) {
					printf("\n\nLa linea se recorta");
					Uder = (V0eqx - V1x) / (V2x - V1x);
					if (0 <= Uder <= 1)
					{
						Yder = V1y + Uder * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
					Uinf = (V0y - V1y) / (V2y - V1y);
					if (0 <= Uinf <= 1)
					{
						Xinf = V1x + Uinf * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xinf, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
				}else if (Sector2 = 6) {
					printf("\n\nLa linea se recorta");
					Uizq = (V0x - V1x) / (V2x - V1x);
					if (0 <= Uizq <= 1)
					{
						Yizq = V1y + Uizq * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
					Uinf = (V0y - V1y) / (V2y - V1y);
					if (0 <= Uinf <= 1)
					{
						Xinf = V1x + Uinf * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xinf, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
				}else if (Sector2 = 8) {
					printf("\n\nLa linea se recorta");

					Usup = (V0eqy - V1y) / (V2y - V1y);
					if (0 <= Usup <= 1)
					{
						Xsup = V1x + Usup * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
				}else if (Sector2 = 9) {
					printf("\n\nLa linea se recorta");
					Uder = (V0eqx - V1x) / (V2x - V1x);
					if (0 <= Uder <= 1)
					{
						Yder = V1y + Uder * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}

					Usup = (V0eqy - V1y) / (V2y - V1y);
					if (0 <= Usup <= 1)
					{
						Xsup = V1x + Usup * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
				}else if (Sector2 = 10) {
					printf("\n\nLa linea se recorta");
					Uizq = (V0x - V1x) / (V2x - V1x);
					if (0 <= Uizq <= 1)
					{
						Yizq = V1y + Uizq * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0y);
					}
					else {
						printf("\nNo hay punto");
					}

					Usup = (V0eqy - V1y) / (V2y - V1y);
					if (0 <= Usup <= 1)
					{
						Xsup = V1x + Usup * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
				}

			}

// Vertice 2 Esta dentro de la ventana

			if (Sector2 = 0)
			{
				if (Sector = 1)
				{
					printf("\n\nLa linea se recorta");
					Uder = (V0eqx - V1x) / (V2x - V1x);
					if (0 <= Uder <= 1)
					{
						Yder = V1y + Uder * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				else if (Sector = 2) {
					printf("\n\nLa linea se recorta");
					Uizq = (V0x - V1x) / (V2x - V1x);
					if (0 <= Uizq <= 1)
					{
						Yizq = V1y + Uizq * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				else if (Sector = 4) {
					printf("\n\nLa linea se recorta");
					Uinf = (V0y - V1y) / (V2y - V1y);
					if (0 <= Uinf <= 1)
					{
						Xinf = V1x + Uinf * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xinf, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				else if (Sector = 5) {
					printf("\n\nLa linea se recorta");
					Uder = (V0eqx - V1x) / (V2x - V1x);
					if (0 <= Uder <= 1)
					{
						Yder = V1y + Uder * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
					Uinf = (V0y - V1y) / (V2y - V1y);
					if (0 <= Uinf <= 1)
					{
						Xinf = V1x + Uinf * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xinf, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				else if (Sector = 6) {
					printf("\n\nLa linea se recorta");
					Uizq = (V0x - V1x) / (V2x - V1x);
					if (0 <= Uizq <= 1)
					{
						Yizq = V1y + Uizq * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
					Uinf = (V0y - V1y) / (V2y - V1y);
					if (0 <= Uinf <= 1)
					{
						Xinf = V1x + Uinf * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xinf, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				else if (Sector = 8) {
					printf("\n\nLa linea se recorta");

					Usup = (V0eqy - V1y) / (V2y - V1y);
					if (0 <= Usup <= 1)
					{
						Xsup = V1x + Usup * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				else if (Sector = 9) {
					printf("\n\nLa linea se recorta");
					Uder = (V0eqx - V1x) / (V2x - V1x);
					if (0 <= Uder <= 1)
					{
						Yder = V1y + Uder * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}

					Usup = (V0eqy - V1y) / (V2y - V1y);
					if (0 <= Usup <= 1)
					{
						Xsup = V1x + Usup * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				else if (Sector = 10) {
					printf("\n\nLa linea se recorta");
					Uizq = (V0x - V1x) / (V2x - V1x);
					if (0 <= Uizq <= 1)
					{
						Yizq = V1y + Uizq * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0y);
					}
					else {
						printf("\nNo hay punto");
					}

					Usup = (V0eqy - V1y) / (V2y - V1y);
					if (0 <= Usup <= 1)
					{
						Xsup = V1x + Usup * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
				}

			} 
else if (SectorSum=0)
			{
				printf("\n\nLa linea se dibuja completa");
			}
			else if (SectorSum == 18)
			{
				printf("\n\nLa linea no se dibuja1");
			}
			else if (SectorSum == 19)
			{
				printf("\n\nLa linea no se dibuja2");
			}
			else if (SectorSum == 10)
			{
				printf("\n\nLa linea no se dibuja3");
			}
			else if (SectorSum == 11)
			{
				printf("\n\nLa linea no se dibuja4");
			}
			else if (SectorSum == 14)
			{
				printf("\n\nLa linea no se dibuja5");
			}
			else if (SectorSum == 12)
			{
				printf("\n\nLa linea no se dibuja6");
			}
			else if (SectorSum == 16)
			{
				printf("\n\nLa linea no se dibuja7");
			}
			else
			{
				printf("\n\nLa linea se Recorta");
				if (true)
				{
					if (SectorSum == 15)
				{
//******************Algoritmo Cohen - Sutherland************************
						Usup = (V0eqy - V1y) / (V2y-V1y);
						if (0<=Usup<=1)
						{
							Xsup = V1x + Usup * (V2x - V1x);
							printf("\n\nPunto de Recorte: (%f , %f)", Xsup,V0eqy);
						}
						else {
							printf("\nNo hay punto");
						}
						Uinf = (V0y - V1y) / (V2y - V1y);
						if (0 <= Uinf <= 1)
						{
							Xinf = V1x + Uinf * (V2x - V1x);
							printf("\n\nPunto de Recorte: (%f , %f)", Xinf, V0y);
						}
						else {
							printf("\nNo hay punto");
						}
						Uizq = (V0x - V1x) / (V2x - V1x);
						if (0 <= Uizq <= 1)
						{
							Yizq = V1y + Uizq * (V2y - V1y);
							printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0y);
						}
						else {
							printf("\nNo hay punto");
						}
						Uder = (V0eqx - V1x) / (V2x - V1x);
						if (0 <= Uder <= 1)
						{
							Yder = V1y + Uder * (V2y - V1y);
							printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
						}
						else {
							printf("\nNo hay punto");
						}
//************************************************************************************
				}
				else if (SectorSum == 3)
				{
					printf("\n\nLa linea se recorta4");
					Uizq = (V0x - V1x) / (V2x - V1x);
					if (0 <= Uizq <= 1)
					{
						Yizq = V1y + Uizq * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
					Uder = (V0eqx - V1x) / (V2x - V1x);
					if (0 <= Uder <= 1)
					{
						Yder = V1y + Uder * (V2y - V1y);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				else if (SectorSum == 12)
				{
					printf("\n\nLa linea se recorta5");
					Usup = (V0eqy - V1y) / (V2y - V1y);
					if (0 <= Usup <= 1)
					{
						Xsup = V1x + Usup * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xsup, V0eqy);
					}
					else {
						printf("\nNo hay punto");
					}
					Uinf = (V0y - V1y) / (V2y - V1y);
					if (0 <= Uinf <= 1)
					{
						Xinf = V1x + Uinf * (V2x - V1x);
						printf("\n\nPunto de Recorte: (%f , %f)", Xinf, V0y);
					}
					else {
						printf("\nNo hay punto");
					}
				}
				}
			}
			
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;     
	/*	case 'R':        // Cuando R es presionado...
		case'r':
			system("CLS");   // Se vuelven a pedir los datos
			break;*/
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}
void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		V0y += 0.1f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		V0y -= 0.1f;
		break;
	case GLUT_KEY_LEFT:
		V0x -= 0.1f;
		break;
	case GLUT_KEY_RIGHT:
		V0x += 0.1f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}
int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (750, 750);	// Tamaño de la Ventana
  glutInitWindowPosition (350, 20);	//Posicion de la Ventana
  glutCreateWindow    ("Recorte y Dibujado de Lineas"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  printf("\n\n*****Datos de la ventana*****\n\n");
  printf("Cordenada del punto inicial, forma (x,y):   ");
  scanf_s("%f,%f", &V0x, &V0y);
  printf("Ancho de la Ventana:   ");
  scanf_s("%f", &l);
  printf("ALto de la ventana:   ");
  scanf_s("%f", &h);
  printf("\n\n*****Datos de la linea*****\n\n");
  printf("Cordenada del vertice 1, forma (x,y):   ");
  scanf_s("%f,%f", &V1x, &V1y);
  printf("Cordenada del vertice 2, forma (x,y):   ");
  scanf_s("%f,%f", &V2x, &V2y);
  
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 
  return 0;
}