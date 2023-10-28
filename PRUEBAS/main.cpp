#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <MMSystem.h>
#include "glm.h"
#include "Texture.h"
#define FPS 60
#define TO_RADIANS 3.14/180.0

using namespace std;

void camera();
const int width = 16*50;
const int height = 9*50;

///Variables camera --------------------------------

float yaw= 0.0;
int dev_x, x;
//float camX=0.0,camY=55.0,camZ=100.0;
float camX=0.0,camY=15.0,camZ=275.0;

///Sub ventana --------------------------------
int winIdSub;
int winIdSub_2;
int winIdMain;

bool sonido = false, star = false, bandera_1 = false, bandera_2 = false, bandera_3 = false, bandera_4 = false, bandera_5 = false, bandera_6 = false, bandera_7=false;

///Tipografía Sub ventana ---------------------------------------
void drawString (char *s)
{
  unsigned int i;
  for (i = 0; i < strlen (s); i++)
    glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, s[i]);
};

void drawStringBig (char *s)
{
  unsigned int i;
  for (i = 0; i < strlen (s); i++)
    glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, s[i]);
};
///-------------------------------------------------------------

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 10.0f, 10.0f, 10.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

//--------------------------------------------------------
float tx=0,ty=0 ,tz=0, tx1, ty1, tz1,t1x=0,t1y=0,t1z=0,
      t2x=0,t2y=0,t2z=0,ax=0,ay=0,az=0, sx=0,sy=0,sz=0;
//--------------------------------------------------------
float girarhuaco=0,ypoz=0,bandz1=0, tz_1=0,banderaz_1=0,door=0;
bool prin=false, prin2=false,banderita=false;
//--------------------------------------------------------

///Punteros
GLMmodel* punteroM1 = NULL;
GLMmodel* punteroM2 = NULL;
GLMmodel* puerta = NULL;
GLMmodel* marcopuerta = NULL;
///NUBES
GLMmodel* nube = NULL;

///ESCULTURAS
GLMmodel* escultura = NULL;


///CHABITACION---------------------------
GLMmodel* repisach = NULL;
GLMmodel* relojc = NULL;
GLMmodel* estantec = NULL;
GLMmodel* plantac = NULL;
GLMmodel* mesac = NULL;
GLMmodel* mesatvc = NULL;
GLMmodel* tvc = NULL;
GLMmodel* cartelbc = NULL;
GLMmodel* inodoroc = NULL;
GLMmodel* lavamanosc = NULL;
GLMmodel* papelc = NULL;
GLMmodel* mesabanoc = NULL;
GLMmodel* lampc = NULL;
GLMmodel* espejoc = NULL;
GLMmodel* extintorc = NULL;
GLMmodel* cuadrosc = NULL;
///AHABITACION ---------------------------
GLMmodel* escritorioporto2 = NULL;
GLMmodel* escritorio3 = NULL;
GLMmodel* compua = NULL;
GLMmodel* cartelvac = NULL;
GLMmodel* telemer = NULL;
GLMmodel* botiquia = NULL;
GLMmodel* extintora = NULL;
GLMmodel* laptop = NULL;
GLMmodel* soporteimpre = NULL;
GLMmodel* impre = NULL;
GLMmodel* sofaa = NULL;
GLMmodel* planta = NULL;
GLMmodel* sillaa = NULL;
GLMmodel* libross = NULL;
GLMmodel* papelera = NULL;
GLMmodel* cajaelectrica = NULL;
GLMmodel* pinturacuadro = NULL;
GLMmodel* Letrero25 = NULL;
GLMmodel* Palo = NULL;
GLMmodel* Circulo = NULL;
GLMmodel* Letrero = NULL;
GLMmodel* Taxi = NULL;

///-----------------------------------

///JUNTA
GLMmodel* mesa = NULL; //3
GLMmodel* patasmesa = NULL;//4
GLMmodel* silla1 = NULL;//5
GLMmodel* laptop2 = NULL;//6
GLMmodel* estructura = NULL;//63
GLMmodel* ventana = NULL;//64
GLMmodel* piso = NULL;//65
GLMmodel* escritorio = NULL; //99
GLMmodel* silla = NULL ; //98
GLMmodel* planta1 = NULL; //97
GLMmodel* planta2 = NULL; //96
GLMmodel* fuente = NULL;//62
GLMmodel* camillaf = NULL;//66
GLMmodel* puerta1 = NULL;//68


///EXTERIOR
GLMmodel* arbola = NULL;
///--------------------------------------
///-----------------------------------

///CENTRO
GLMmodel* punteroM3 = NULL;
GLMmodel* punteroM5 = NULL;
GLMmodel* punteroM6 = NULL;
GLMmodel* punteroM7 = NULL;
GLMmodel* punteroM8 = NULL;
GLMmodel* punteroM9 = NULL;

GLuint	texture;
Texture	treeTextureAr[150];

struct Motion
{
    bool Forward,Backward,Left,Right, Up, Down,Gira, Reversa;
};

Motion motion = {false,false,false,false, false, false,false,false};

float color(float a)
{
    a=a/255;

    return(a);
}

bool LoadTreeTextures()
{
	int i;

	if (LoadTGA(&treeTextureAr[0], "modelos/MuseoFirme_baseColorTexture.tga")
     && LoadTGA(&treeTextureAr[1], "modelos/2.tga")
     && LoadTGA(&treeTextureAr[2], "modelos/nube.tga")
     ///JUNTA
     ///---------------------------------------------------------
     && LoadTGA(&treeTextureAr[3], "modelos/nuevo/tmesa.tga")
     && LoadTGA(&treeTextureAr[4], "modelos/nuevo/tpata.tga")
     && LoadTGA(&treeTextureAr[5], "modelos/nuevo/tsilla.tga")
     && LoadTGA(&treeTextureAr[6], "modelos/nuevo/laptop.tga")

     && LoadTGA(&treeTextureAr[63], "modelos/nuevo/pared.tga")
     && LoadTGA(&treeTextureAr[64], "modelos/nuevo/fierro.tga")
     && LoadTGA(&treeTextureAr[65], "modelos/nuevo/piso.tga")
     && LoadTGA(&treeTextureAr[96], "modelos/oficina/maceta.tga")
     && LoadTGA(&treeTextureAr[97], "modelos/oficina/hojas.tga")
     && LoadTGA(&treeTextureAr[98], "modelos/oficina/10239_Office_Chair_v1_Diffuse.tga")
     && LoadTGA(&treeTextureAr[99], "modelos/oficina/texturaescritorio1.tga")
    //&& LoadTGA(&treeTextureAr[62], "modelos/oficina/Fuente_rec_ret.tga")
    && LoadTGA(&treeTextureAr[66], "modelos/oficina/camilla.tga")
    && LoadTGA(&treeTextureAr[67], "modelos/oficina/carteldecamilla.tga")
    && LoadTGA(&treeTextureAr[68], "modelos/nuevo/otro.tga")
    && LoadTGA(&treeTextureAr[69], "modelos/oficina/cartelpuerta.tga")
     ///---------------------------

    && LoadTGA(&treeTextureAr[8], "modelos/nuevo/rojo2.tga")
    && LoadTGA(&treeTextureAr[9], "modelos/nuevo/extintor.tga")
    && LoadTGA(&treeTextureAr[10], "modelos/nuevo/emergencia.tga")//3
    && LoadTGA(&treeTextureAr[11],"modelos/nuevo/emergencia2.tga")//4
    && LoadTGA(&treeTextureAr[12], "modelos/nuevo/madera3.tga") //51
    && LoadTGA(&treeTextureAr[13], "modelos/avatar2.tga") //50


    ///CHABITA------------------------------------------------------------------------
    && LoadTGA(&treeTextureAr[30], "modelos/chabita/colocolumna.tga")
    && LoadTGA(&treeTextureAr[31], "modelos/chabita/respisa_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[32], "modelos/chabita/relooj_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[33], "modelos/chabita/estante_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[34], "modelos/chabita/planta_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[35], "modelos/chabita/mesa_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[36], "modelos/chabita/mesatv_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[37], "modelos/chabita/tvc_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[38], "modelos/chabita/cartelvaczonasegura.tga")
    && LoadTGA(&treeTextureAr[39], "modelos/chabita/cartelvacsalida.tga")
    && LoadTGA(&treeTextureAr[40], "modelos/chabita/carextintor.tga")
    && LoadTGA(&treeTextureAr[41], "modelos/chabita/sshhcar.tga")
    && LoadTGA(&treeTextureAr[42], "modelos/chabita/cartelvacsalidadere.tga")
    && LoadTGA(&treeTextureAr[43], "modelos/chabita/colorinodoro.tga")
    && LoadTGA(&treeTextureAr[44], "modelos/chabita/papelc.tga")
    && LoadTGA(&treeTextureAr[45], "modelos/chabita/mesabano_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[46], "modelos/chabita/lampc_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[47], "modelos/chabita/espejobano_baseColorTexture.tga")
    && LoadTGA(&treeTextureAr[48], "modelos/chabita/extintor.tga")
    && LoadTGA(&treeTextureAr[49], "modelos/chabita/pinturacuadroa.tga")
    && LoadTGA(&treeTextureAr[50], "modelos/chabita/pinturacuadrob.tga")
///Ahabita---------------------------------------------------------------------------
     &&LoadTGA(&treeTextureAr[71], "modelos/Ahabita/escritorioporto2.tga")
     &&LoadTGA(&treeTextureAr[72], "modelos/Ahabita/compua.tga")
     &&LoadTGA(&treeTextureAr[73], "modelos/Ahabita/cartelvaczonasegura.tga")
     &&LoadTGA(&treeTextureAr[74], "modelos/Ahabita/cartelvacsalida.tga")
     &&LoadTGA(&treeTextureAr[75], "modelos/Ahabita/telemer.tga")
     &&LoadTGA(&treeTextureAr[76], "modelos/Ahabita/carttele.tga")
     &&LoadTGA(&treeTextureAr[77], "modelos/Ahabita/botiquin.tga")
     &&LoadTGA(&treeTextureAr[78], "modelos/Ahabita/extintor.tga")
     &&LoadTGA(&treeTextureAr[79], "modelos/Ahabita/carextintor.tga")
     &&LoadTGA(&treeTextureAr[80], "modelos/Ahabita/carbotiquin.tga")
     &&LoadTGA(&treeTextureAr[81], "modelos/Ahabita/laptop.tga")
     &&LoadTGA(&treeTextureAr[82], "modelos/Ahabita/soporteimpre.tga")
     &&LoadTGA(&treeTextureAr[83], "modelos/Ahabita/impre.tga")
     &&LoadTGA(&treeTextureAr[84], "modelos/Ahabita/sofa.tga")
     &&LoadTGA(&treeTextureAr[85], "modelos/Ahabita/planta.tga")
     &&LoadTGA(&treeTextureAr[86], "modelos/Ahabita/silla.tga")
     &&LoadTGA(&treeTextureAr[87], "modelos/Ahabita/libross.tga")
     &&LoadTGA(&treeTextureAr[88], "modelos/Ahabita/papelera.tga")
     &&LoadTGA(&treeTextureAr[89], "modelos/Ahabita/cajaelectrica.tga")
     &&LoadTGA(&treeTextureAr[90], "modelos/Ahabita/carriesgoelect.tga")
     &&LoadTGA(&treeTextureAr[91], "modelos/Ahabita/pinturacuadro1.tga")
     &&LoadTGA(&treeTextureAr[92], "modelos/Ahabita/pinturacuadro2.tga")
     &&LoadTGA(&treeTextureAr[100], "modelos/Ahabita/punto_reunion.tga")
     &&LoadTGA(&treeTextureAr[101], "modelos/Ahabita/letrero25.tga")
     &&LoadTGA(&treeTextureAr[102], "modelos/Ahabita/circulo.tga")
     &&LoadTGA(&treeTextureAr[103], "modelos/Ahabita/taxi_baseColorTexture.tga")

    ///--------------------------------------------------------------------------
    ///EXTERIOR
    &&LoadTGA(&treeTextureAr[120], "modelos/exteriora/arbol1_baseColorTexture.tga")



     )
	{
		for (i = 0; i<150; i++){
			glGenTextures(1, &treeTextureAr[i].texID);
			glBindTexture(GL_TEXTURE_2D, treeTextureAr[i].texID);
			glTexImage2D(GL_TEXTURE_2D, 0, treeTextureAr[i].bpp / 8, treeTextureAr[i].width, treeTextureAr[i].height, 0, treeTextureAr[i].type, GL_UNSIGNED_BYTE, treeTextureAr[i].imageData);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			if (treeTextureAr[i].imageData)
			{
				free(treeTextureAr[i].imageData);
			}
		}
		return true;
	}
	else{
		return false;
	}
}

void init(void)
{
	glClearColor(0.73,0.9,0.91, 0.0);
	LoadTreeTextures();
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glDepthFunc(GL_LEQUAL);
}

void abrirpuerta(int i){

	if (door<90)
        door+= 0.5;
	glutPostRedisplay();
	glutTimerFunc(1,abrirpuerta, 2);
}


void graficar(void)
{
	glutSetWindow (winIdMain); //Acciona ventana principal

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();

    ///------------------------------------------------------


    ///CHABITACION------------------------------------------------------------------------------
    glPushMatrix();
        glTranslated(-75,18.2,61.5);
        glRotated(90,0,0,1);
        glScalef(4.7,0.5,0.3);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[30].texID);
        glutSolidCube(8);            ///columna 1
    glPopMatrix();
    glPushMatrix();
        glTranslated(-75,18.2,-2);
        glRotated(90,0,0,1);
        glScalef(4.7,0.5,0.3);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[30].texID);
        glutSolidCube(8);            ///columna 2
    glPopMatrix();
    glPushMatrix();
        glTranslated(-77,18.2,8);
        glRotated(270,1,0,0);
        glRotated(90,0,0,1);
        glScalef(22,22,22);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[31].texID);
        glmDraw(repisach, GLM_SMOOTH | GLM_TEXTURE);///repisalibro mas arriba
    glPopMatrix();
    glPushMatrix();
        glTranslated(-77,10,51);
        glRotated(270,1,0,0);
        glRotated(90,0,0,1);
        glScalef(22,22,22);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[31].texID);
        glmDraw(repisach, GLM_SMOOTH | GLM_TEXTURE);///repisalibro mas abajo
    glPopMatrix();
    glPushMatrix();
        glTranslated(-75.8,25,51);
        glScalef(12,12,12);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(90,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[32].texID);
        glmDraw(relojc, GLM_SMOOTH | GLM_TEXTURE);///reloj
    glPopMatrix();
    glPushMatrix();
        glTranslated(-73,0,12);
        glScalef(32,32,32);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(90,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[33].texID);
        glmDraw(estantec, GLM_SMOOTH | GLM_TEXTURE);///estante ventana
    glPopMatrix();
    glPushMatrix();
        glTranslated(-25,0,12);
        glScalef(32,32,32);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(90,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[34].texID);
        glmDraw(plantac, GLM_SMOOTH | GLM_TEXTURE);///planta esquina puerta
    glPopMatrix();
     glPushMatrix();
        glTranslated(-25,0,55);
        glScalef(32,32,32);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(90,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[34].texID);
        glmDraw(plantac, GLM_SMOOTH | GLM_TEXTURE);///planta entrada
    glPopMatrix();
     glPushMatrix();
        glTranslated(-50,0.5,32);
        glScalef(60,60,60);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(90,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[35].texID);
        glmDraw(mesac, GLM_SMOOTH | GLM_TEXTURE);///mesacentral
    glPopMatrix();
    glPushMatrix();
        glTranslated(-50,0.5,58);
        glScalef(32,32,32);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(180,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[33].texID);
        glmDraw(estantec, GLM_SMOOTH | GLM_TEXTURE);///estante
    glPopMatrix();
    glPushMatrix();
        glTranslated(-25,0,35);
        glScalef(32,52,32);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(90,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[36].texID);
        glmDraw(mesatvc, GLM_SMOOTH | GLM_TEXTURE);///mesatv
    glPopMatrix();
    glPushMatrix();
        glTranslated(-25,12,35);
        glScalef(22,22,22);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(270,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[37].texID);
        glmDraw(tvc, GLM_SMOOTH | GLM_TEXTURE);///tv
    glPopMatrix();
    glPushMatrix();
        glTranslated(-74.6,18,60.3);
        glRotated(-180,0,1,0);
        glScaled(3,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[38].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);///columnanetrada
    glPopMatrix();
    glPushMatrix();
        glTranslated(-73,18,-2);
        glRotated(-180,0,1,0);
        glRotated(-90,0,1,0);
        glScaled(2,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[38].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);///columnafondo
    glPopMatrix();
    glPushMatrix();
        glTranslated(-22,10,2);
        glRotated(-180,0,1,0);
        glRotated(90,0,1,0);
        glScaled(2,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[40].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);///cartelextintor
    glPopMatrix();
    glPushMatrix();
        glTranslated(-22.1,10,2);
        glRotated(-90,1,0,0);
        glRotated(270,0,0,1);
        glScaled(9,7,7);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[48].texID);
        glmDraw(extintorc, GLM_SMOOTH | GLM_TEXTURE);///extinror
    glPopMatrix();
    glPushMatrix();
        glTranslated(-23,10,-4);
        glRotated(360,0,1,0);
        glScaled(2,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[38].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);///zonaseguracercabaño
    glPopMatrix();
    glPushMatrix();
        glTranslated(-60,10,-3.5);
        glRotated(360,0,1,0);
        glScaled(2,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[41].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);///servicios higinicso
    glPopMatrix();
     glPushMatrix();
        glTranslated(-40.5,10,-4);
        glRotated(360,0,1,0);
        glScaled(2,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[42].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);///cartelsalidaflechaderecha
    glPopMatrix();
    glPushMatrix();
        glTranslated(-70,0,-25);
        glRotated(270,0,0,1);
        glRotated(-90,0,1,0);
        glScalef(2,2,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[43].texID);
        glmDraw(inodoroc, GLM_SMOOTH | GLM_TEXTURE);///inodoro
    glPopMatrix();
    glPushMatrix();
        glTranslated(-70,0,-8);
        glRotated(270,0,0,1);
        glRotated(-90,0,1,0);
        glRotated(-90,0,0,1);
        glScalef(8,8,8);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[43].texID);
        glmDraw(lavamanosc, GLM_SMOOTH | GLM_TEXTURE);///lavamanos
    glPopMatrix();
    glPushMatrix();
        glTranslated(-74,5,-22);
        glRotated(-90,0,1,0);
        glRotated(270,0,0,1);
        glScalef(0.05,0.05,0.05);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[44].texID);
        glmDraw(papelc, GLM_SMOOTH | GLM_TEXTURE);///papel higienico
    glPopMatrix();
    glPushMatrix();
        glTranslated(-55,0.5,-25);
        glRotated(270,0,0,1);
        glRotated(-90,0,1,0);
        glRotated(270,0,0,1);
        glRotated(-180,0,0,1);
        glScalef(10,10,15);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[45].texID);
        glmDraw(mesabanoc, GLM_SMOOTH | GLM_TEXTURE);///mesabano 1
    glPopMatrix();
    glPushMatrix();
        glTranslated(-48,0.5,-25);
        glRotated(270,0,0,1);
        glRotated(-90,0,1,0);
        glRotated(270,0,0,1);
        glRotated(-180,0,0,1);
        glScalef(10,10,15);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[45].texID);
        glmDraw(mesabanoc, GLM_SMOOTH | GLM_TEXTURE);///mesabano 2
    glPopMatrix();
    glPushMatrix();
        glTranslated(-40,0.5,-10);
        glScalef(22,22,22);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(90,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[34].texID);
        glmDraw(plantac, GLM_SMOOTH | GLM_TEXTURE);///planta pasadizo
    glPopMatrix();
    glPushMatrix();
        glTranslated(-47,0.5,-10);
        glScalef(22,22,22);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(90,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[34].texID);
        glmDraw(plantac, GLM_SMOOTH | GLM_TEXTURE);///planta esquina puerta bano
    glPopMatrix();
    glPushMatrix();
        glTranslated(-60,0.5,-8);
        glScalef(15,25,15);
        glRotated(-180,1,0,0);
        glRotated(90,1,0,0);
        glRotated(90,0,0,1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[46].texID);
        glmDraw(lampc, GLM_SMOOTH | GLM_TEXTURE);///lamparabano
    glPopMatrix();
    glPushMatrix();
        glTranslated(-43.5,10,-18);
        glRotated(-180,0,1,0);
        glRotated(90,0,1,0);
        glScaled(2,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[42].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);///cartelsalidabano
    glPopMatrix();
    glPushMatrix();
        glTranslated(-70,15,-6);
        glRotated(270,0,0,1);
        glRotated(-90,0,1,0);
        glRotated(-90,0,0,1);
        glScalef(15,15,15);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[47].texID);
        glmDraw(espejoc, GLM_SMOOTH | GLM_TEXTURE);///espejobano
    glPopMatrix();
   /* glPushMatrix();
        glTranslated(-55,10,-25);
        glRotated(-360,0,1,0);
        glRotated(90,0,0,1);
        glRotated(90,0,1,0);
        glRotated(-90,0,0,1);
        glScaled(0.009,0.007,0.008); ///ancho, fondo, alto
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[49].texID);
        glmDraw(cuadrosc, GLM_SMOOTH | GLM_TEXTURE);///cuadrobano*
    glPopMatrix();
    glPushMatrix();
        glTranslated(-65,5,-3.2);
        glRotated(-360,0,1,0);
        glRotated(90,0,0,1);
        glRotated(90,0,1,0);
        glRotated(-90,0,0,1);
        glScaled(0.009,0.007,0.008); ///ancho, fondo, alto
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[50].texID);
        glmDraw(cuadrosc, GLM_SMOOTH | GLM_TEXTURE);///cuadroadelantesshh
    glPopMatrix();*/
///-----------------------------------------------------------------------------------------------------
    ///Ahabitacion --------------------------------------
/*
 glPushMatrix();
    glTranslated(-135,0,-80);
    glScalef(20,20,20);
    //Letrero Punto reu
    glPushMatrix();
    glTranslatef(1.4,-0.4,5.8);
    glScalef(0.7,0.7,0.7);
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[100].texID);
        glTranslatef(1.5,1.2,2.46);
        glRotatef(0,0,1,0);
        glScalef(0.3,0.5,0.1);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    //Palo
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[101].texID);
        glTranslatef(1.5,0.4,2.45);
        //glRotatef(90,0,1,0);
        glScalef(1,1,1);
        glmDraw(Palo, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPopMatrix();
    //Circulo
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[102].texID);
        glTranslatef(0.5,0.2,4);
        glRotatef(90,0,1,0);
        glRotatef(-8,1,0,0);
        glScalef(1,1,1);
        glmDraw(Circulo, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    //Circulo
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[102].texID);
        glTranslatef(0.5,0.39,6.4);
        glRotatef(90,0,1,0);
        glRotatef(-5,1,0,0);
        glScalef(1,1,1);
        glmDraw(Circulo, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    //Taxi
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[103].texID);
        glTranslatef(-2,1.3,2.1);
        glRotatef(90,0,1,0);
        glRotatef(-90,1,0,0);
        glScalef(1.6,1.6,1.6);
        glmDraw(Taxi, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    //--*/
    ///Escritorio
    glPushMatrix();
        glTranslated(-65,0,-80);
        glRotated(180,0,1,0);
        glScaled(3.5,3.5,3.5);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[71].texID);
        glmDraw(escritorio3, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Computadora
    glPushMatrix();
        glTranslated(-65,8.5,-90);
        glRotated(-90,1,0,0);
        glScaled(16,16,16);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[72].texID);
        glmDraw(compua, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Laptop
    glPushMatrix();
        glTranslated(-60,8.5,-80);
        glRotated(-90,1,0,0);
        glRotated(-90,0,0,1);
        glRotated(20,0,0,1);
        glScaled(7,7,7);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[81].texID);
        glmDraw(laptop, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///N°1 SISMO
    glPushMatrix();
        glTranslated(-24.1,12,-91);
        glScaled(3,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[73].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///N°2 SISMO
    glPushMatrix();
        glTranslated(-23.3,12,-31.3);
        glRotated(-180,0,1,0);
        glScaled(2.7,5.8,2); ///Ancho, Alto, fondo
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[73].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///N°21 SISMO
    glPushMatrix();
        glTranslated(-75,12,-34.5);
        glRotated(-180,0,1,0);
        glScaled(2.7,5.8,2); ///Ancho, Alto, fondo
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[73].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///N°3 SALIDA
    glPushMatrix();
        glTranslated(-43,12,-32);
        glRotated(-180,0,1,0);
        glScaled(3,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[74].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///N°4 TELEFONOEMERGENCIA
    glPushMatrix();
        glTranslated(-21.8,17.5,-40);
        glRotated(-180,0,1,0);
        glRotated(270,0,0,1);
        glRotated(-90,1,0,0);
        glScaled(1.5,4.2,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[76].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///TELEFONO
    glPushMatrix();
        glTranslated(-22,13,-35);
        glRotated(-90,0,1,0);
        glRotated(-90,1,0,0);
        glScaled(0.07,0.07,0.07);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[75].texID);
        glmDraw(telemer, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///N°5 BOTIQUIN
    glPushMatrix();
        glTranslated(-21.8,10.8,-45);
        glRotated(-90,0,1,0);
        glScaled(2.7,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[80].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///BOTIQUIN
    glPushMatrix();
        glTranslated(-21.8,13,-46);
        glRotated(-90,0,0,1);
        glScaled(350,360,360);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[77].texID);
        glmDraw(botiquia, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///N°5 EXTINTOR
    glPushMatrix();
        glTranslated(-21.8,11.8,-40);
        glRotated(-90,0,1,0);
        glScaled(2.7,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[79].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///EXTINTOR
    glPushMatrix();
        glTranslated(-22.3,10,-40);
        glRotated(-90,1,0,0);
        glRotated(270,0,0,1);
        glScaled(9,7,7);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[78].texID);
        glmDraw(extintora, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Soporte
    glPushMatrix();
        glTranslated(-63,16,-38.8);
        glRotated(-90,1,0,0);
        glRotated(180,0,0,1);
        glScaled(10,11,10);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[82].texID);
        glmDraw(soporteimpre, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Impresora
    glPushMatrix();
        glTranslated(-65,7,-35);
        glRotated(-180,1,0,0);
        glScaled(11,5.5,11);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[83].texID);
        glmDraw(impre, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Sofa
    glPushMatrix();
        glTranslated(-27,1,-70);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glScaled(40,40,40);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[84].texID);
        glmDraw(sofaa, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Planta1
    glPushMatrix();
        glTranslated(-35,0.4,-95);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[85].texID);
        glmDraw(planta, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Planta2
    glPushMatrix();
        glTranslated(-25,0.4,-55);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[85].texID);
        glmDraw(planta, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Planta3
    glPushMatrix();
        glTranslated(-70,0.4,-50);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[85].texID);
        glmDraw(planta, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Papelera
    glPushMatrix();
        glTranslated(-75,0.4,-60);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glRotated(-180,0,0,1);
        glScaled(10,10,10);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[88].texID);
        glmDraw(papelera, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Libros
    glPushMatrix();
        glTranslated(-60,8.5,-70);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glScaled(5,5,5);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[87].texID);
        glmDraw(libross, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Silla
    glPushMatrix();
        glTranslated(-70,0.5,-80);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glRotated(180,0,0,1);
        glScaled(20,20,23);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[86].texID);
        glmDraw(sillaa, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Riesgo Electrico
    glPushMatrix();
        glTranslated(-40.5,9,-18);
        glRotated(-180,0,1,0);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glScaled(1.5,1.5,1.5);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[89].texID);
        glmDraw(cajaelectrica, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Cartel Riesgo Electrico
    glPushMatrix();
        glTranslated(-40.8,11,-18);
        glRotated(-180,0,1,0);
        glRotated(-90,0,1,0);
        glScaled(2.7,5.8,2); ///Ancho, Alto, fondo
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[90].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Cuadro1
     /*  glPushMatrix();
        glTranslated(-76,11,-43);
        glRotated(-360,0,1,0);
        glRotated(90,0,0,1);
        glRotated(90,0,1,0);
        glScaled(0.009,0.007,0.008); //ancho, fondo, alto
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[91].texID);
        glmDraw(pinturacuadro, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///Cuadro2
    glPushMatrix();
        glTranslated(-22,10,-72);
        glRotated(-90,0,0,1);
        glRotated(270,0,1,0);
        glScaled(0.013,0.007,0.010); //ancho, fondo, alto
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[92].texID);
        glmDraw(pinturacuadro, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();*/
    ///Muro o Columna Esquina1
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslated(-24.1,12,-95);
        glRotated(90,1,0,0);
        glScalef(0.3,0.5,1.5);
        glutSolidCube(16); ///tamaño pared
    glPopMatrix();
    ///Muro o Columna Esquina2
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslated(-75,11,-33);
        glRotated(90,1,0,0);
        glScalef(0.3,0.2,1.5);
        glutSolidCube(16); ///tamaño pared
    glPopMatrix();

    ///-------------------------------------------------------------------------------------------------
    ///junta
    ///---------------------------------------------------------------------
    glPushMatrix();
        glTranslatef(-5,0,-40);
        glRotated(-90,1,0,0);
        glScaled(10,10,10);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[63].texID);
        glmDraw(estructura, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[64].texID);
        glmDraw(ventana, GLM_SMOOTH | GLM_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[65].texID);
        glmDraw(piso, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///ESCRITORIO
    glPushMatrix();
       glTranslatef(65,0,-76);
        glScaled(3,3,3);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[99].texID);
        glmDraw(escritorio, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///SILLA
     glPushMatrix();
       glTranslatef(73,0,-86);
        glRotated(-90,1,0,0);
        glScaled(0.1,0.1,0.1);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[98].texID);
        glmDraw(silla, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///PLANTA
     glPushMatrix();
       glTranslatef(49,0.4,-88);
        //glRotated(-90,1,0,0);
        glScaled(15,15,15);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[97].texID);
        glmDraw(planta1, GLM_SMOOTH | GLM_TEXTURE);
         glBindTexture(GL_TEXTURE_2D, treeTextureAr[96].texID);
        glmDraw(planta2, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///
     glPushMatrix();
        glTranslatef(70,0,20);
        glScaled(3,3,3);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[3].texID);
        glmDraw(mesa, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(70,0,20);
        glScaled(3,3,3);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[4].texID);
        glmDraw(patasmesa, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(80,0,20);
        glScaled(3,3,3);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[4].texID);
        glmDraw(patasmesa, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(90,0,20);
        glScaled(3,3,3);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[4].texID);
        glmDraw(patasmesa, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(95,0.5,20);
        glRotatef(270,0,1,0);
        glScaled(12,12,12);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
        glmDraw(silla1, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(48,0.5,20);
        glRotatef(90,0,1,0);
        glScaled(12,12,12);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
        glmDraw(silla1, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(60,0.5,5);
        glScaled(12,12,12);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
        glmDraw(silla1, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(70,0.5,5);
        glScaled(12,12,12);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
        glmDraw(silla1, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(80,0.5,5);
        glScaled(12,12,12);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
        glmDraw(silla1, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(60,0.5,35);
        glRotatef(180,0,1,0);
        glScaled(12,12,12);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
        glmDraw(silla1, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(70,0.5,35);
        glRotatef(180,0,1,0);
        glScaled(12,12,12);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
        glmDraw(silla1, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(80,0.5,35);
        glRotatef(180,0,1,0);
        glScaled(12,12,12);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
        glmDraw(silla1, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(60,10,27);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[6].texID);
        glmDraw(laptop2, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(70,10,27);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[6].texID);
        glmDraw(laptop2, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(80,10,27);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[6].texID);
        glmDraw(laptop2, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(60,10,15);
        glRotatef(180,0,1,0);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[6].texID);
        glmDraw(laptop2, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(70,10,15);
        glRotatef(180,0,1,0);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[6].texID);
        glmDraw(laptop2, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(80,10,15);
        glRotatef(180,0,1,0);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[6].texID);
        glmDraw(laptop2, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    ///---------------------------------------------------------------------


    ///EXTERIOR-----------------------------------------------------------------
    glPushMatrix();
        glTranslated(-60,0,75);
        glRotated(90,0,1,0);
        glRotated(-90,1,0,0);
        glScalef(48,48,48);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[120].texID);
        glmDraw(arbola, GLM_SMOOTH | GLM_TEXTURE);            ///ARBOL
    glPopMatrix();
    glPushMatrix();
        glTranslated(-45,0,75);
        glRotated(90,0,1,0);
        glRotated(-90,1,0,0);
        glScalef(48,48,48);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[120].texID);
        glmDraw(arbola, GLM_SMOOTH | GLM_TEXTURE);            ///ARBOL
    glPopMatrix();
     glPushMatrix();
        glTranslated(-30,0,75);
        glRotated(90,0,1,0);
        glRotated(-90,1,0,0);
        glScalef(48,48,48);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[120].texID);
        glmDraw(arbola, GLM_SMOOTH | GLM_TEXTURE);            ///ARBOL
    glPopMatrix();
    glPushMatrix();
        glTranslated(45,0,75);
        glRotated(90,0,1,0);
        glRotated(-90,1,0,0);
        glScalef(48,48,48);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[120].texID);
        glmDraw(arbola, GLM_SMOOTH | GLM_TEXTURE);            ///ARBOL
    glPopMatrix();
    glPushMatrix();
        glTranslated(60,0,75);
        glRotated(90,0,1,0);
        glRotated(-90,1,0,0);
        glScalef(48,48,48);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[120].texID);
        glmDraw(arbola, GLM_SMOOTH | GLM_TEXTURE);            ///ARBOL
    glPopMatrix();
    glPushMatrix();
        glTranslated(75,0,75);
        glRotated(90,0,1,0);
        glRotated(-90,1,0,0);
        glScalef(48,48,48);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[120].texID);
        glmDraw(arbola, GLM_SMOOTH | GLM_TEXTURE);            ///ARBOL
    glPopMatrix();
    glPushMatrix();
        glTranslated(90,0,75);
        glRotated(90,0,1,0);
        glRotated(-90,1,0,0);
        glScalef(48,48,48);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[120].texID);
        glmDraw(arbola, GLM_SMOOTH | GLM_TEXTURE);            ///ARBOL
    glPopMatrix();

    ///PUERTA
    glPushMatrix();
        glTranslatef(-5,0,-40);
        glRotated(-90,1,0,0);
        glScaled(10,10,10);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[68].texID);
        glmDraw(puerta1, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
 ///CAMILLA
     glPushMatrix();
       glTranslatef(-18.75,10,24);
        glRotated(-90,0,0,1);
        glScaled(13,13,13);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[66].texID);
        glmDraw(camillaf, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///CARTEL CAMILLA
     glPushMatrix();
       glTranslatef(-18.75,10,24);
        glRotated(90,0,1,0);
              glScaled(2.7,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[67].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
     ///CARTEL PUERTA SOCORRO
     glPushMatrix();
       glTranslatef(-15,10,-76);
        //glRotated(90,0,1,0);
        glScaled(2.7,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[69].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    glPushMatrix();
        glTranslated(63,6.9,-82);
        glRotated(-90,1,0,0);
        glRotated(90,0,0,1);
        glScaled(16,16,16);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[72].texID);
        glmDraw(compua, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///-------------------------------------------------------------------------
    glPushMatrix();
        glTranslated(-18.7,10,4);
        glRotated(-180,0,1,0);
        glRotated(-90,0,1,0);
        glScaled(2.7,5.8,2); ///Ancho, Alto, fondo
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[11].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();
        glTranslated(41.7,23,-31.7);
        glRotated(-180,0,1,0);
        glRotated(180,0,1,0);
        glRotated(180,0,0,1);
        glScaled(2,5,2); ///Ancho, Alto, fondo
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[10].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-13,0,-50);
        glScaled(9,9,9);
        //glRotated(90,1,0,0);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[13].texID);
        glmDraw(punteroM7, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();
        glTranslated(20,0,-80);
        glScaled(2,2,2);
        //glRotated(90,1,0,0);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[12].texID);
        glmDraw(punteroM5, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();
        glTranslated(5,2,25);
        glScaled(12,12,12);
        //glRotated(90,1,0,0);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[12].texID);
        glmDraw(punteroM6, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    ///extintor obj
    glPushMatrix();
        glTranslated(-22,8,-28);
        glRotated(-90,1,0,0);
        glRotated(360,0,0,1);
        glScaled(9,7,7);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[48].texID);
        glmDraw(extintorc, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    ///extintor
    glPushMatrix();
        glTranslated(-22,10,-28.7);
        glRotated(-180,0,1,0);
        glRotated(-180,0,1,0);
        glScaled(2.7,5.8,2); ///Ancho, Alto, fondo
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[79].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();



    ///extintor obj
    glPushMatrix();
        glTranslated(41.7,10,-11.85);
        glRotated(-90,1,0,0);
        glRotated(180,0,0,1);
        glScaled(9,7,7);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[48].texID);
        glmDraw(extintorc, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    ///extintor
    glPushMatrix();
        glTranslated(41.7,10,-11.2);
        glRotated(-180,0,1,0);
        glRotated(0,0,1,0);
        glScaled(2,5,2); ///Ancho, Alto, fondo
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[79].texID);
        glmDraw(cartelbc, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    ///cartel botiquin medio
    glPushMatrix();
        glTranslated(40.5,10.8,-5);
        glRotated(-90,0,1,0);
        glScaled(2.7,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[80].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    ///botiquin medio
    glPushMatrix();
        glTranslated(40,13,-6.3);
        glRotated(-90,0,0,1);
        glScaled(350,360,360);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[77].texID);
        glmDraw(botiquia, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();


    ///cartel botiquin medio
    glPushMatrix();
        glTranslated(40.5,10.8,-65);
        glRotated(-90,0,1,0);
        glScaled(2.7,5.8,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[80].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    ///botiquin medio
    glPushMatrix();
        glTranslated(40,13,-66.3);
        glRotated(-90,0,0,1);
        glScaled(350,360,360);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[77].texID);
        glmDraw(botiquia, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();


    glPushMatrix();
        glTranslated(40.5,17.5,-55);
        glRotated(-180,0,1,0);
        glRotated(270,0,0,1);
        glRotated(-90,1,0,0);
        glScaled(1.5,4.2,2);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[76].texID);
        glmDraw(cartelvac, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///TELEFONO
    glPushMatrix();
        glTranslated(40,13,-50.3);
        glRotated(-90,0,1,0);
        glRotated(-90,1,0,0);
        glScaled(0.07,0.07,0.07);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[75].texID);
        glmDraw(telemer, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    ///planta medio 1
     glPushMatrix();
        glTranslated(38,0.4,-95);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[85].texID);
        glmDraw(planta, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    ///planta medio 2
     glPushMatrix();
        glTranslated(38,0.4,-35);
        glRotated(-90,0,0,1);
        glRotated(-90,0,1,0);
        glScaled(20,20,20);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[85].texID);
        glmDraw(planta, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-60,-11.5,0);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[1].texID);
        glmDraw(punteroM2, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
    ///NUBES


  	glutSwapBuffers();
}

void redimensionar(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 500.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();

    ///Subventana 1
    glutSetWindow (winIdSub);
    glutPositionWindow (1000,530);
    glutSetWindow (winIdMain);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(10/FPS,timer,0);
}

void camera()
{
    if(motion.Forward)
    {
        camX += cos((90)*TO_RADIANS)/5.0;
        camZ -= sin((90)*TO_RADIANS)/5.0;
        camY += cos((90)*TO_RADIANS)/5.0;
    }
    if(motion.Backward)
    {
        camX += cos((90+180)*TO_RADIANS)/5.0;
        camZ -= sin((90+180)*TO_RADIANS)/5.0;
        camY += cos((90+180)*TO_RADIANS)/5.0;
    }
    if(motion.Left)
    {
        camX += cos((90+90)*TO_RADIANS)/5.0;
        camZ -= sin((90+90)*TO_RADIANS)/5.0;
        camY += sin((90+90)*TO_RADIANS)/5.0;
    }
    if(motion.Right)
    {
        camX += cos((90-90)*TO_RADIANS)/5.0;
        camZ -= sin((90-90)*TO_RADIANS)/5.0;
        camY += sin((90-90)*TO_RADIANS)/5.0;
    }

    if(motion.Up)
    {
        camX += cos((90)*TO_RADIANS)/5.0;
        camZ += sin((90-90)*TO_RADIANS)/5.0;
        camY += cos((90-90)*TO_RADIANS)/5.0;
    }
    if(motion.Down)
    {
        camX += cos((90)*TO_RADIANS)/5.0;
        camZ += sin((90+90)*TO_RADIANS)/5.0;
        camY += cos((90+90)*TO_RADIANS)/5.0;
    }

    if(motion.Gira)
    {
        dev_x = (width/10)-camX;
        yaw= yaw + (float)dev_x/100.0;
    }
     if(motion.Reversa)
    {
        dev_x = (width/10)-camX;
        yaw= yaw - (float)dev_x/100.0;
    }

    if (bandera_1) ///Ir a entrada
    {
        camX = 0.0;
        camY = 15.0;
        camZ = 175.0;
        yaw = 0.0;
        bandera_1 = false;
    }

    if (bandera_2) ///Ir a primer espacio izquierda
    {
        camX = -30;
        camY = 13;
        camZ = 40;
        yaw = 40;
        bandera_2 = false;
    }

    if (bandera_3) ///Ir baño
    {
        camX = -45;
        camY = 10;
        camZ = -8;
        yaw = 60;
        bandera_3 = false;
    }

    if (bandera_4) ///Ir a oficina al fondo
    {
        camX = -32;
        camY = 14;
        camZ = -34;
        yaw = 40;
        bandera_4 = false;
    }

    if (bandera_5) ///Ir al centro
    {  ///GIRAR B SE OBESERVA TODO EL CENTRO
        camX = -5;
        camY = 14;
        camZ = -10;
        yaw = 100;
        bandera_5 = false;
    }

    if (bandera_6) ///Ir a junta
    {
        camX = 85;
        camY = 18;
        camZ = 48;
        yaw = 10;
        bandera_6 = false;
    }

    if (bandera_7) ///Ir a oficina al fondo
    {
        camX = 53;
        camY = 10;
        camZ = -45;
        yaw = -30;
        bandera_7 = false;
    }

    glTranslatef(-camX,-camY,-camZ);

    glTranslatef(camX,camY,camZ);
        glRotatef(-yaw,0.0,1.0,0.0);
    glTranslatef(-camX,-camY,-camZ);
}
void keyboard(unsigned char key,int x,int y)
{
    static int info_banner = 1;
    switch(key)
    {
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'I':
    case 'i':
        motion.Up = true;
        break;
    case 'O':
    case 'o':
        motion.Down = true;
        break;
    case 'G':
    case 'g':
        motion.Gira = true;
        break;
    case 'B':
    case 'b':
        motion.Reversa = true;
        break;
    ///Oculta y aparece sub-ventana
    case 'y':
    case 'Y':
        if (info_banner)
        {
            glutSetWindow (winIdSub);
            glutHideWindow ();
        }
        else
        {
            glutSetWindow (winIdSub);
            glutShowWindow ();
        };
        info_banner = !info_banner;
        break;
    case 'E':
    case 'e':
        sonido = true;
        if (sonido == true)
            sndPlaySound("condor_pasa.wav",SND_ASYNC);
        break;
    case 'N':
    case 'n':
        sonido = false;
            sndPlaySound(".wav",SND_ASYNC);
        break;
    case '1':
        bandera_1 = true;
        break;
    case '2':
        bandera_2 = true;
        break;
    case '3':
        bandera_3 = true;
        break;
    case '4':
        bandera_4 = true;
        break;
    case '5':
        bandera_5 = true;
        break;
    case '6':
        bandera_6 = true;
        break;
    case '7':
        bandera_7 = true;
        break;
    }
}

void keyboard_up(unsigned char key,int x,int y)
{
    switch(key)
    {
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'I':
    case 'i':
        motion.Up = false;
        break;
    case 'O':
    case 'o':
        motion.Down = false;
        break;
    case 'G':
    case 'g':
        motion.Gira = false;
        break;
    case 'B':
    case 'b':
        motion.Reversa = false;
        break;
    }
}

void subDisplay()
{
    // Establece el color de la ventana
    glutSetWindow (winIdSub);
    //glClearColor (0.25, 0.25, 0.25, 0.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Dibuja borde ventana
    glColor3f (0.0F, 1.0F, 0.0F);

    glBegin (GL_LINE_LOOP);
        glVertex2f (-0.99F, -0.99F); //inferior izquierdo
        glVertex2f (-0.99F, 0.99F); //superior izquierdo
        glVertex2f (1.0F, 0.99F); //superior derecho
        glVertex2f (1.0F, -1.0F);
    glEnd ();

    if (star==false)
    {
        glColor3f (1.0F, 1.0F, 1.0F);
        glRasterPos2f (-0.85, 0.65);
        drawStringBig("Edificacion con senales de seguridad");
        glRasterPos2f (-0.3, 0.45);
        drawString(" Bienvenid@ \n");
        glRasterPos2f (-0.6, 0.25);
        drawString("\n E: Activar audio     N: Desactivar Audio\n");

        glRasterPos2f (-0.9, 0.1);
        drawString("\n 1. Ir a entrada \n ");
        glRasterPos2f (0.1, 0.1);
        drawString("\n 2. Ir a Sala de Recreacion \n");

        glRasterPos2f (-0.9, -0.05);
        drawString("\n 3. Ir a SS.HH. \n ");
        glRasterPos2f (0.1, -0.05);
        drawString("\n 4. Ir a Oficina Central\n ");

        glRasterPos2f (-0.9, -0.2);
        drawString("\n 5. Ir Sala de espera \n");
        glRasterPos2f (0.1, -0.2);
        drawString("\n 6. Ir a Sala de juntas \n");
        glRasterPos2f (-0.9, -0.35);
        drawString("\n 7. Ir a la Oficina de Gerencia \n");

        glRasterPos2f (-0.2, -0.6);
        drawString("\n Navegacion \n");
        glRasterPos2f (-0.9, -0.75);
        drawString(" A - D : Derecha, Izquierda ");
        glRasterPos2f (0.1, -0.75);
        drawString(" W - S : Atras, Adelante ");
        glRasterPos2f (-0.9, -0.89);
        drawString(" I - O : Arriba, Abajo");
        glRasterPos2f (0.1, -0.89);
        drawString(" G - B : Gira ");
    }

    if (star==true)
    {
        glColor3f (1.0F, 1.0F, 1.0F);
        glRasterPos2f (-0.8, 0.5);
        drawStringBig("Museo de\n ");
    }

   glutSwapBuffers ();
};

void subDisplay_2()
{
    // Establece el color de la ventana
    glutSetWindow (winIdSub_2);
    glClearColor ( color(83), color(107), color(141), 0.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Dibuja borde ventana
    //glColor3f (0.0F, 1.0F, 0.0F);

    glBegin (GL_LINE_LOOP);
        glVertex2f (-0.99F, -0.99F); //inferior izquierdo
        glVertex2f (-0.99F, 0.99F); //superior izquierdo
        glVertex2f (1.0F, 0.99F); //superior derecho
        glVertex2f (1.0F, -1.0F);
    glEnd ();

    glutSwapBuffers ();
};

void subReshape (int w, int h)
{
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    glMatrixMode(GL_MODELVIEW);
};

void subReshape_2 (int w, int h)
{
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    glMatrixMode(GL_MODELVIEW);
};

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1800, 1000);
	glutInitWindowPosition(100, 0);

	winIdMain = glutCreateWindow("Simulación");
	init();

	///Punteros
	punteroM1 = glmReadOBJ("modelos/museofirme3.obj");
	marcopuerta = glmReadOBJ("modelos/marcopuerta.obj");
	punteroM2 = glmReadOBJ("modelos/grass.obj");
	puerta = glmReadOBJ("modelos/puerta.obj");
	nube = glmReadOBJ("modelos/nubes.obj");

    punteroM3 = glmReadOBJ("modelos/letrero1.obj");
    punteroM5 = glmReadOBJ("modelos/desk.obj");
    punteroM6 = glmReadOBJ("modelos/mesa.obj");
    punteroM7 = glmReadOBJ("modelos/muebles2.obj");
    punteroM8 = glmReadOBJ("modelos/extintor.obj");
    punteroM9 = glmReadOBJ("modelos/letrero2.obj");
 	///----------------------------------------------------------
	///SALA DE JUNTAS
	mesa = glmReadOBJ("modelos/nuevo/mesa.obj");
	patasmesa = glmReadOBJ("modelos/nuevo/patasmesa.obj");
	silla1 = glmReadOBJ("modelos/nuevo/silla.obj");
    laptop2 = glmReadOBJ("modelos/nuevo/laptop.obj");
    estructura = glmReadOBJ("modelos/nuevo/pared.obj");
	ventana = glmReadOBJ("modelos/nuevo/ventana.obj");
	piso = glmReadOBJ("modelos/nuevo/piso.obj");
	escritorio = glmReadOBJ("modelos/oficina/escritorio1.obj");
	silla = glmReadOBJ("modelos/oficina/10239_Office_Chair_v1_L3.obj");
	planta1 = glmReadOBJ("modelos/oficina/hojas.obj");
	planta2 = glmReadOBJ("modelos/oficina/maceta.obj");
	camillaf = glmReadOBJ("modelos/oficina/fondocamilla.obj");
	puerta1 = glmReadOBJ("modelos/oficina/puerta.obj");

 ///CHabitacion
    repisach = glmReadOBJ("modelos/chabita/repisa.obj");
    relojc = glmReadOBJ("modelos/chabita/reloj.obj");
    estantec = glmReadOBJ("modelos/chabita/estantec.obj");
    plantac = glmReadOBJ("modelos/chabita/plantac.obj");
    mesac = glmReadOBJ("modelos/chabita/mesac.obj");
    mesatvc = glmReadOBJ("modelos/chabita/mesatv.obj");
    tvc = glmReadOBJ("modelos/chabita/tvc.obj");
    cartelbc = glmReadOBJ("modelos/chabita/cartelvac.obj");
    inodoroc = glmReadOBJ("modelos/chabita/inodoroc.obj");
    lavamanosc = glmReadOBJ("modelos/chabita/lavamanosc.obj");
    papelc = glmReadOBJ("modelos/chabita/papelc.obj");
    mesabanoc = glmReadOBJ("modelos/chabita/mesabano.obj");
    lampc = glmReadOBJ("modelos/chabita/lampc.obj");
    espejoc = glmReadOBJ("modelos/chabita/espejoc.obj");
    extintorc = glmReadOBJ("modelos/chabita/extintorobj.obj");
    cuadrosc = glmReadOBJ("modelos/chabita/pinturacuadro.obj");
    ///Ahabitacion --------------------------------------------------
	escritorioporto2 = glmReadOBJ("modelos/Ahabita/escritorioporto2.obj");
    escritorio3 = glmReadOBJ("modelos/Ahabita/escritorio3.obj");
    compua = glmReadOBJ("modelos/Ahabita/compua.obj");
    cartelvac = glmReadOBJ("modelos/Ahabita/cartelvac.obj");
    telemer = glmReadOBJ("modelos/Ahabita/telemer.obj");
    botiquia = glmReadOBJ("modelos/Ahabita/botiquin.obj");
    extintora = glmReadOBJ("modelos/Ahabita/extintorobj.obj");
    laptop = glmReadOBJ("modelos/Ahabita/compu.obj");
    soporteimpre = glmReadOBJ("modelos/Ahabita/soporteimpre.obj");
    impre = glmReadOBJ("modelos/Ahabita/impre.obj");
    sofaa = glmReadOBJ("modelos/Ahabita/sofaa.obj");
    planta = glmReadOBJ("modelos/Ahabita/planta.obj");
    sillaa = glmReadOBJ("modelos/Ahabita/sillaa.obj");
    libross = glmReadOBJ("modelos/Ahabita/libross.obj");
    papelera = glmReadOBJ("modelos/Ahabita/papelera.obj");
    cajaelectrica = glmReadOBJ("modelos/Ahabita/cajaelectrica.obj");
    pinturacuadro = glmReadOBJ("modelos/Ahabita/pinturacuadro.obj");
    Palo = glmReadOBJ("modelos/Ahabita/palo.obj");
    Circulo = glmReadOBJ("modelos/Ahabita/circulo.obj");
    Taxi = glmReadOBJ("modelos/Ahabita/taxi.obj");
	///----------------------------------------------------------
     ///Exterior --------------------------------------------------
    arbola = glmReadOBJ("modelos/exteriora/arbol1.obj");


	glutDisplayFunc(graficar);
	glutReshapeFunc(redimensionar);
    glutTimerFunc(0,timer,0);
    glutTimerFunc(2,abrirpuerta, 4);


    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    ///Creación: Sub - Ventana 1 - Menú
    winIdSub = glutCreateSubWindow (winIdMain,1000,530,400,200);
        glutDisplayFunc (subDisplay);
        glutReshapeFunc (subReshape);

    ///Instrucciones y Autores
    cout << "\n |   Simulacion  |";
    cout << "\n\n\n Creadores - Autores:";
    cout << "\n . Aliaga Cerbajal Paulo";
    cout << "\n . Mendez Cruz Angely";
    cout << "\n . Mendez Cruz Ciara";
    cout << "\n . Padilla Leyva Valentina";
    cout << "\n . Recalde Monzon Angie";
    cout << "\n . Senmache Ly Sebastian";

    cout << "\n\n Presione Y o y : para ocultar la subventana";

	glutMainLoop();
	return 0;
}
