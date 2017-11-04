#ifndef VARS_H
#define VARS_H

//#include <GL\gl.h>
//#include <GL\glu.h>
//#include <windows.h>
#include <GL\glui.h>
#include <GL\glut.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <iostream>

#include "RGBpixmap.h"

// dimensoes e localizacao da janela
#define DIMX 1050
#define DIMY 600
#define INITIALPOS_X 150
#define INITIALPOS_Y 100

using namespace std;

//TRUE - FALSE
const int TRUE  = 1;
const int FALSE = 0;

//checkboxs
int ter[]={TRUE,TRUE,TRUE};
int arv[]={TRUE,TRUE,TRUE,TRUE};
int hol[]={TRUE,TRUE,TRUE,TRUE};
int edi[]={TRUE,TRUE,TRUE,TRUE,TRUE};
int USE_DISPLAY_LISTS=FALSE;
int AXIS=FALSE;
int LUZ=TRUE;
int LET=TRUE;
int FIRST=TRUE;
int EVAL=FALSE;
int BCKG=FALSE;
int AMB=TRUE;

//display lists
GLuint terarv,hospit,helip;

float xy_aspect;
char camara = '1'; //constante para actualizar o numero da camara activa
//declaracoes para a camara 3
int enable_camara_move = FALSE;
int movimento_camara_xx = 0;
int movimento_camara_yy = 0;
int movimento_camara_zz = 0;

//variaveis para criacao de botao de rotacao e de zoom
GLUI_Rotation *view_rot;
GLUI_Translation * trans_z;

// matriz de transf. geometrica utilizada pelo botao esferico
float view_rotate[16] = { 1,0,0,0,
                          0,1,0,0,
                          0,0,1,0,
                          0,0,0,1 };

// vector de posicao utilizado pelo botao de afastamento
float obj_pos[] = { 0.0, 0.0, 0.0 };

// declara��es para os tres eixos (cilindros)
double axis_radius_begin =  0.2;
double axis_radius_end   =  0.0;
double axis_lenght       = 16.0;
int axis_nslices = 8;
int axis_nstacks = 1;

// declaracoes para as paredes
float mat1_shininess[] = {128.0}; 
float mat1_specular[] = {0.3, 0.3, 0.3, 1.0};	/* specular reflection. */
float mat1_diffuse[] =  {0.7, 0.7, 0.7, 1.0};	/* diffuse reflection. */
float mat1_ambient[] =  {0.7, 0.7, 0.7, 1.0};	/* ambient reflection. */

// fonte (global) de luz ambiente 
float light_ambient[] = {0.6, 0.6, 0.6, 1.0}; /* Set the background ambient lighting. */

// declara��es para a fonte de luz LIGHT0;
float light0_position[]  = {0.0, 3.0, 4.0, 1.0}; // nao necessaria...
float light0_ambient[] =   {0.0, 0.0, 0.0, 1.0}; // sem componente ambiente
float light0_diffuse[] =   {10.0, 10.0, 10.0, 1.0};
float light0_specular[] =  {10.0, 10.0, 10.0, 1.0};
float light0_kc = 0.0;
float light0_kl = 1.0;
float light0_kq = 0.0;
/*double light0x = 15.0;
double light0y = 5;
double light0z = 7.0;*/
double light0x = 22.0;
double light0y = 20;
double light0z = -15.0;
double symb_light0_radius = 0.2;
int symb_light0_slices = 8;
int symb_light0_stacks =8;

// declara��es para a fonte de luz dos holofotes;
//Holofote1 = esquerdo-baixo
//Holofote2 = esquerdo-alto
//Holofote3 = direito-baixo
//Holofote4 = direito-alto
float lighth1_position[]  = {0.0, 0.0, 0.0, 1.0};
float lighth2_position[]  = {0.0, 0.0, 0.0, 1.0};
float lighth3_position[]  = {0.0, 0.0, 0.0, 1.0};
float lighth4_position[]  = {0.0, 0.0, 0.0, 1.0};
float lighth_ambient[] =   {0.0, 0.0, 0.0, 1.0};
float lighth_diffuse[] =   {16.0, 16.0, 16.0, 1.0};
float lighth_specular[] =  {16.0, 16.0, 16.0, 1.0};
float lighth_kc = 0.0;
float lighth_kl = 1.0;
float lighth_kq = 0.0;

double lighth1x = 18.0;
double lighth1y = 4.7;
double lighth1z = -3.7;

double lighth2x = 18.0;
double lighth2y = 4.7;
double lighth2z = -11.2;

double lighth3x = 27.0;
double lighth3y = 4.7;
double lighth3z = -3.7;

double lighth4x = 27.0;
double lighth4y = 4.7;
double lighth4z = -11.2;

//float spot_direction1[]  = {0.0, -1.0, 0.0};
float spot_direction1[]  = {1.0, -1, -1};
float spot_direction2[]  = {1.0, -1, 1};
float spot_direction3[]  = {-1.0, -1, -1};
float spot_direction4[]  = {-1.0, -1, 1};

double symb_lighth_radius = 0.2;
int symb_lighth_slices = 8;
int symb_lighth_stacks =8;

// variaveis para a janela
int main_window;
GLUI  *glui2;
GLUquadric* glQ;	// nec. p/ criar sup. quadraticas (cilindros, esferas...)

// declara��es para animacao
unsigned int mili_secs = 10;
double  obj_radius, obj_rotate, delta_radius, delta_rotate;
#define RADIUS_SPEED  0.4  // unidades de comprimento por segundo
#define ANGULAR_SPEED 2  // rotacoes por segundo
int animacao = FALSE;
float MovX1 = 22.5;
float MovY1 = 1;
float MovZ1 = -7.5;
int curva = FALSE;
int vertical_1_up = FALSE;
int vertical_1_down = FALSE;
int vertical_2_down = FALSE;
int horizontal_1 = FALSE;
int vertical_2_up = FALSE;
int paralelo_zz = FALSE;
int paralelo_yy = FALSE;
int acabou_movimento = FALSE;
float VELOCIDADE = 0.01;
float VEL_ROTACAO = 0.1;


double tg = (1/(7.5/15));
double i = 0; //angulo para rodar chopper verticalmente
double o = 0; //angulo para rodar chopper horizontalmente
double x = 0; //angulo para inclinar o chopper de lado

//declaracoes para dimensoes do helicoptero
#define HELI_CABINE_RAIO 2*0.5
#define HELI_PES_RAIO 0.3*0.5
#define HELI_PES_COMPRIMENTO 4*0.5
#define HELI_PERNAS_RAIO_BASE_INF 0.3*0.5
#define HELI_PERNAS_RAIO_BASE_SUP 0.1*0.5
#define HELI_PERNAS_ALTURA 2*0.5
#define HELI_CAUDA_RAIO_BASE 0.7*0.5
#define HELI_CAUDA_COMPRIMENTO 7*0.5
#define HELI_PARAFUSO_HELICES_RAIO 0.2*0.5
#define HELI_PARAFUSO_HELICE_GRANDE_ALTURA 1*0.5
#define HELI_PARAFUSO_HELICE_PEQUENO_ALTURA 0.5*0.5
#define HELI_HELICE_GRANDE_TAMANHO 7*0.5
#define HELI_HELICE_GRANDE_LARGURA 1*0.5
#define HELI_ASAS_TRASEIRAS_ALTURA 1.4*0.5
#define HELI_ASAS_TRASEIRAS_COMPRIMENTO 0.5*0.5
#define HELI_HELICE_PEQUENA_TAMANHO 2*0.5
#define HELI_HELICE_PEQUENA_LARGURA 0.5*0.5

//pontos de controlo do hangar
GLfloat texpts[2][2][2] = {
    {{0.0, 1.0}, {1.0, 1.0}},
    {{0.0, 0.0}, {1.0, 0.0}}
};

GLfloat    ctrlpoints[4][4][3]={
{{9.3,0,0},{9.3,6,0},{0,6,0},{0,0,0}},
{{9.3,0,3.625},{9.3,6,3.625},{0,6,3.625},{0,0,3.625}},
{{9.3,0,7.25},{9.3,6,7.25},{0,6,7.25},{0,0,7.25}},
{{9.3,0,14.5},{9.3,6,14.5},{0,6,14.5},{0,0,14.5}}
};

//pontos para o chao do heliporto
GLfloat ctrlpointsh[4][3] = {	{17.25, 1, -3.75},
								{17.25, 1, -11.25}, 
								{27.75, 1,  -3.75},
								{27.75, 1,  -11.25} };

GLfloat nrmlcompon[4][3] = {	{  0.0, 1.0, 0.0},
								{  0.0, 1.0, 0.0}, 
								{  0.0, 1.0, 0.0},
								{  0.0, 1.0, 0.0} };

// As cores a atribuir a cada ponto de controlo
GLfloat colorpoints[4][4] = {	{ 0.0, 0.2, 0.2, 0},
								{ 0.0, 0.0, 0.2, 0}, 
								{ 0.0, 0.2, 0.0, 0},
								{ 0.2, 0.0, 0.0, 0} };

GLfloat textpoints[4][2] = {	{ 0.0, 0.0},
								{ 0.0, 1.0}, 
								{ 1.0, 0.0},
								{ 1.0, 1.0} };


//plano para cortar sphere
GLdouble eqn[4] = {0.0,1.0,0.0,0.0};

//variavel para texturas
RGBpixmap pixmap;

//variaveis para materiais
GLfloat mat_ambient[12][4] ={{ 0.7, 0.7, 0.7, 1.0 },
							 { 0.2, 0.9, 0.2, 1.0 },
							 { 1.0, 1.0, 1.0, 0.0 },
							 { 0.9, 0.5, 0.0, 1.0 },
                             { 1.0, 1.0, 1.0, 1.0 },
							 { 0.7, 0.7, 0.7, 1.0 },
                             { 0.0, 0.5, 0.7, 0.5 },
							 { 0.0, 0.5, 0.0, 1.0 },
                             { 0.5, 0.5, 0.5, 0.5 },
                             { 0.5, 0.2, 0.0, 1.0 },
							 { 0.1, 0.5, 0.7, 0.5 },
							 { 0.3, 0.3, 0.3, 0.5 }};

GLfloat mat_diffuse[12][4] ={{ 0.7, 0.7, 0.7, 1.0 },
							 { 0.4, 0.4, 0.4, 1.0 },
							 { 0.4, 0.4, 0.4, 1.0 },
							 { 0.7, 0.7, 0.7, 1.0 },
                             { 0.4, 0.4, 0.4, 1.0 },
						   	 { 0.7, 0.7, 0.7, 1.0 },
							 { 0.5, 0.5, 0.5, 0.5 },
                             { 0.0, 0.0, 0.0, 1.0 },
							 { 0.5, 0.5, 0.5, 1.0 },
							 { 0.4, 0.4, 0.4, 1.0 },
							 { 0.3, 0.3, 0.3, 0.5 },
							 { 0.2, 0.2, 0.2, 0.5 }};

GLfloat mat_specular[12][4]={{ 0.3, 0.3, 0.3, 1.0 },
							 { 0.3, 0.3, 0.3, 1.0 },
							 { 0.3, 0.3, 0.3, 1.0 },
							 { 0.3, 0.3, 0.3, 1.0 },
							 { 0.3, 0.3, 0.3, 1.0 },
							 { 0.5, 0.5, 0.5, 1.0 },
							 { 1.0, 1.0, 1.0, 0.5 },
							 { 0.0, 0.0, 0.0, 1.0 },
							 { 0.5, 0.5, 0.5, 1.0 },
							 { 0.3, 0.3, 0.3, 1.0 },
							 { 0.8, 0.8, 0.8, 0.5 },
							 { 0.2, 0.2, 0.2, 0.5 }};

GLfloat mat_emission[12][4]={{ 0.0, 0.0, 0.0, 0.0},
							 { 0.0, 0.0, 0.0, 0.0},
							 { 0.0, 0.0, 0.0, 0.0},
							 { 0.0, 0.0, 0.0, 0.0},
							 { 0.0, 0.0, 0.0, 0.0},
							 { 0.0, 0.0, 0.0, 0.0},
							 { 0.0, 0.0, 0.0, 0.0},
				             { 0.0, 1.0, 0.0, 1.0},
						     { 0.0, 0.0, 0.0, 0.0},
							 { 0.0, 0.0, 0.0, 0.0},
							 { 0.7, 0.7, 0.7, 0.5},
							 { 0.0, 0.0, 0.0, 0.0}};

GLfloat mat_shininess[12][1] ={{128.0},{0.0},{0.0},{0.0},{64.0},{10.0},{128.0},{100.0},{10.0},{10.0},{0.0},{10.0}};

enum mat_enum{DEFAULT,RELVA,TRANSPARENTE,TELHA,PAREDE,
			  CHAO,VIDRO,NEON,FERRO,MADEIRA,CABINE,FERROB};

#endif
