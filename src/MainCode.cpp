#include "vars.h"

void draweixos() {
	// cilindro representativo do eixo X
	glColor3f(1.0,0.0,0.0);		// vermelho
	glPushMatrix();
	glRotated(90.0, 0.0,1.0,0.0 );
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	glPopMatrix();

	// cilindro representativo do eixo Y
	glColor3f(0.0,1.0,0.0);		// verde
	glPushMatrix();
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	glPopMatrix();
	
	// cilindro representativo do eixo Z
	glColor3f(0.0,0.0,1.0);		// azul
	glPushMatrix();
	// nao necessita rotacao... glRotated(...);
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	glPopMatrix();
}

void luzes() {
	// Actualizacao da posicao das fontes de luz...
	light0_position[0] = light0x;	// por razoes de eficiencia, os restantes 
	light0_position[1] = light0y;	// parametros _invariaveis_ da LIGHT0 mantem os valores
	light0_position[2] = light0z;	// definidos na funcao de inicializacao
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0f);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	// ... e das esfera que as simbolizam
	glColor3f(1.0,1.0,0.0);		// cor amarela
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(light0x,light0y,light0z);
	gluSphere(glQ, symb_light0_radius, symb_light0_slices, symb_light0_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);

	//luz 1
	lighth1_position[0] = lighth1x;	
	lighth1_position[1] = lighth1y;	
	lighth1_position[2] = lighth1z;
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 40.0f);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction1);
	glLightfv(GL_LIGHT1, GL_POSITION, lighth1_position);

	glColor3f(1.0,1.0,0.0);		
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(lighth1x,lighth1y,lighth1z);
	gluSphere(glQ, symb_lighth_radius, symb_lighth_slices, symb_lighth_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);

	//luz 2
	lighth2_position[0] = lighth2x;	
	lighth2_position[1] = lighth2y;	
	lighth2_position[2] = lighth2z;
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 40.0f);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction2);
	glLightfv(GL_LIGHT2, GL_POSITION, lighth2_position);

	glColor3f(1.0,1.0,0.0);		
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(lighth2x,lighth2y,lighth2z);
	gluSphere(glQ, symb_lighth_radius, symb_lighth_slices, symb_lighth_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);

	//luz 3
	lighth3_position[0] = lighth3x;	
	lighth3_position[1] = lighth3y;	
	lighth3_position[2] = lighth3z;
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 40.0f);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction3);
	glLightfv(GL_LIGHT3, GL_POSITION, lighth3_position);

	glColor3f(1.0,1.0,0.0);		
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(lighth3x,lighth3y,lighth3z);
	gluSphere(glQ, symb_lighth_radius, symb_lighth_slices, symb_lighth_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);

	//luz 4
	lighth4_position[0] = lighth4x;	
	lighth4_position[1] = lighth4y;	
	lighth4_position[2] = lighth4z;
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 40.0f);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction4);
	glLightfv(GL_LIGHT4, GL_POSITION, lighth4_position);
	
	glColor3f(1.0,1.0,0.0);		
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(lighth4x,lighth4y,lighth4z);
	gluSphere(glQ, symb_lighth_radius, symb_lighth_slices, symb_lighth_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);
}

void myTexturas() {
	pixmap.readBMPFile("feup.bmp");
	pixmap.setTexture(1);

	pixmap.readBMPFile("tile.bmp");
	pixmap.setTexture(2);

	pixmap.readBMPFile("clamp.bmp");
	pixmap.setTexture(3);

	pixmap.readBMPFile("mandril.bmp");
	pixmap.setTexture(4);

	pixmap.readBMPFile("janela.bmp");
	pixmap.setTexture(5);

	pixmap.readBMPFile("heliporto.bmp");
	pixmap.setTexture(6);

	pixmap.readBMPFile("relva.bmp");
	pixmap.setTexture(7);

	pixmap.readBMPFile("passeio.bmp");
	pixmap.setTexture(8);

	pixmap.readBMPFile("pista.bmp");
	pixmap.setTexture(9);

	pixmap.readBMPFile("madeira.bmp");
	pixmap.setTexture(10);

	pixmap.readBMPFile("telhas.bmp");
	pixmap.setTexture(11);

	pixmap.readBMPFile("fcp.bmp");
	pixmap.setTexture(12);

	pixmap.readBMPFile("ferro.bmp");
	pixmap.setTexture(13);

	pixmap.readBMPFile("cameo.bmp");
	pixmap.setTexture(14);

	pixmap.readBMPFile("cruz.bmp");
	pixmap.setTexture(15);
}

void myMaterial(int mat){
	glDisable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient[mat]);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse[mat]);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular[mat]); 
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,mat_emission[mat]); 
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess[mat]);
}

void myInitTransforms()
{
    delta_rotate = (double) mili_secs/1000.0 * ANGULAR_SPEED *360.0;
    delta_radius = (double) mili_secs/1000.0 * RADIUS_SPEED;
}

void myUpdateTransforms(int dummy)
{
    obj_rotate += delta_rotate;
    obj_radius += delta_radius;

    glutTimerFunc(mili_secs, myUpdateTransforms, 0);
}

void myObjectTransforms()
{
    glRotated(obj_rotate, 0,1,0);
    glTranslated(obj_radius,0.0,0.0);
}

void myObjectDraw()
{
    glPushMatrix();
    glTranslated(2.0, 0.0, 0.0);
    glRotated(-90.0, 1,0,0);
    glTranslated(0.0, 2.0, 0.0);
    glNormal3d(0.0,0.0,1.0);
    glRectd(-1.0,-2.0, 1.0,2.0);
    glBegin(GL_TRIANGLES);
        glVertex2d( 2.0, 2.0);
        glVertex2d( 0.0, 3.0);
        glVertex2d(-2.0, 2.0);
    glEnd();
    glPopMatrix();
}

//funcao para criar cilindro especificando quantas e quais faces estarao fechadas
void gluCylinder_closed(GLUquadric * glQ,GLdouble raio_ini,GLdouble raio_final,GLdouble altura,GLint slices,GLint stacks,int cima,int baixo)
{
    //criar cilindro
    gluCylinder(glQ, raio_ini,raio_final,altura,slices,stacks);
    //fechar cilindro
    if(cima==TRUE){
        glPushMatrix();
            glTranslatef(0,0,altura);
            gluDisk(glQ, 0, raio_final, slices, 4);
        glPopMatrix();
    }
    if(baixo==TRUE){
        glPushMatrix();
            gluQuadricOrientation(glQ, GLU_INSIDE);
            glTranslatef(0,0,0);
            gluDisk(glQ, 0, raio_final, slices, 4);
        glPopMatrix();
    }
}



//desenhar - TRUE ou FALSE como parametros para cada um dos objectos
void chao(int c1, int c2, int c3) {
	glEnable(GL_TEXTURE_2D);

	if (c1==TRUE) {
	// 1� rectangulo (esquerdo)
	glBindTexture(GL_TEXTURE_2D, 7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(RELVA);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(0, 0, 0);
		glTexCoord2f(8.0,0.0); glVertex3d(15, 0,  0);
		glTexCoord2f(8.0,8.0); glVertex3d(15, 0,  -30);
		glTexCoord2f(0.0,8.0);  glVertex3d(0, 0, -30);
	glEnd();
	}

	if (c2==TRUE) {
	// 2� rectangulo (centro)
	glBindTexture(GL_TEXTURE_2D, 8);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(CHAO);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(15, 0, 0);
		glTexCoord2f(8.0,0.0); glVertex3d(30, 0,  0);
		glTexCoord2f(8.0,8.0); glVertex3d(30, 0,  -30);
		glTexCoord2f(0.0,8.0);  glVertex3d(15, 0, -30);
	glEnd();
	}

	if (c3==TRUE) {
	// 3� rectangulo (direito)
	glBindTexture(GL_TEXTURE_2D, 9);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(CHAO);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(30, 0, 0);
		glTexCoord2f(8.0,0.0); glVertex3d(45, 0,  0);
		glTexCoord2f(8.0,8.0); glVertex3d(45, 0,  -30);
		glTexCoord2f(0.0,8.0);  glVertex3d(30, 0, -30);
	glEnd();
	}
	glDisable(GL_TEXTURE_2D);
	myMaterial(DEFAULT);
}

void arvores(int a1, int a2, int a3, int a4) {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S); 
    glEnable(GL_TEXTURE_GEN_T); 
	//desenhar arvores

	if (a1==TRUE) {
	//arvore grande
	glBindTexture(GL_TEXTURE_2D, 10);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glColor3f(0.0,1.0,0.0);
	myMaterial(MADEIRA);
	glPushMatrix();
	glTranslatef(10,0,-25);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, 0.4, 0,7, axis_nslices, axis_nstacks);  
	glPopMatrix();
	//folhas da arvore grande vista de um lado
	glBindTexture(GL_TEXTURE_2D, 7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(RELVA);
	glDisable(GL_CULL_FACE);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0); 
		glTexCoord2f(0.0,0.0);  glVertex3d(8, 3,-25);	
		glTexCoord2f(0.0,2); glVertex3d(12, 3,-25);
		glTexCoord2f(1.0,2); glVertex3d(10, 7,-25);	
	glEnd();
	glBegin(GL_POLYGON);
		glNormal3d(1.0,0.0,0.0); 
		glTexCoord2f(0.0,0.0);  glVertex3d(10, 3,-27);	
		glTexCoord2f(0.0,2); glVertex3d(10, 3,-23);	
		glTexCoord2f(1.0,2); glVertex3d(10, 7,-25);	
	glEnd();
	glEnable(GL_CULL_FACE);
	}

	if (a2==TRUE) {
	//arvore pequena
	glBindTexture(GL_TEXTURE_2D, 10);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glColor3f(0.0,1.0,0.0);
	myMaterial(MADEIRA);
	glPushMatrix();
	glTranslatef(3,0,-17);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, 0.2, 0,5, axis_nslices, axis_nstacks);
	glPopMatrix();
	//folhas da arvore grande vista de um lado
	glBindTexture(GL_TEXTURE_2D, 7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(RELVA);
	glDisable(GL_CULL_FACE);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(2, 2,-17);
		glTexCoord2f(0.0,2); glVertex3d(4, 2,-17);
		glTexCoord2f(1.0,2); glVertex3d(3, 5,-17);
	glEnd();
	glBegin(GL_POLYGON);
		glNormal3d(1.0,0.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(3, 2,-18);
		glTexCoord2f(0.0,2); glVertex3d(3, 2,-16);
		glTexCoord2f(1.0,2); glVertex3d(3, 5,-17);
	glEnd();
	glEnable(GL_CULL_FACE);
	}

	//arvores redondas
	if (a3==TRUE) {
	//arvore 1
	glBindTexture(GL_TEXTURE_2D, 10);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(MADEIRA);
	//glColor3f(1.0,1.0,1.0);		
	glPushMatrix();
	glTranslatef(8,0,-16);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, 0.6, 0,3.5, axis_nslices, axis_nstacks);   
	glPopMatrix();
	}
	if (a4==TRUE) {
	//arvore 2
	glBindTexture(GL_TEXTURE_2D, 10);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(MADEIRA);
	//glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glTranslatef(3,0,-27);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, 0.6, 0,3.5, axis_nslices, axis_nstacks);
	glPopMatrix();
	}
	//folhas das arvores redondas
	if (a4==TRUE) {
	//arvore 1
	glBindTexture(GL_TEXTURE_2D, 7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(RELVA);
	//glColor3f(1.0,1.0,1.0);		
	glPushMatrix();
	glTranslatef(3,3.5,-27);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, 2, 0,2.5, axis_nslices, axis_nstacks);   
	glPopMatrix();
	}
	if (a3==TRUE) {
	//arvore 2
	glBindTexture(GL_TEXTURE_2D, 7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(RELVA);
	//glColor3f(1.0,1.0,1.0);		
	glPushMatrix();
	glTranslatef(8,3.5,-16);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, 2, 0,2.5, axis_nslices, axis_nstacks);   
	glPopMatrix();
	}
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_GEN_S); 
    glDisable(GL_TEXTURE_GEN_T); 
	myMaterial(DEFAULT);
}

void hospital(int h, int l) {
	glEnable(GL_TEXTURE_2D);

	//paredes do hospital (frente, direita, tras, esquerda)
	if (h==TRUE) {
	glBindTexture(GL_TEXTURE_2D, 5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(PAREDE);
	//frente
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(16.75, 0, -19);
		glTexCoord2f(3.0,0); glVertex3d(28.25, 0,  -19);
		glTexCoord2f(3.0,3); glVertex3d(28.25, 11.5,  -19);	
		glTexCoord2f(0.0,3.0);  glVertex3d(16.75, 11.5, -19);
	glEnd();

	//direita
	glBegin(GL_POLYGON);
		glNormal3d(1.0,0.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(28.25, 0, -19);
		glTexCoord2f(2.0,0); glVertex3d(28.25, 0,  -26);
		glTexCoord2f(2.0,3); glVertex3d(28.25, 11.5,  -26);	
		glTexCoord2f(0.0,3.0);  glVertex3d(28.25, 11.5, -19);
	glEnd();

	//tras
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,-1.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(28.25, 0, -26);
		glTexCoord2f(3.0,0); glVertex3d(16.75, 0,  -26);
		glTexCoord2f(3.0,3); glVertex3d(16.75, 11.5,  -26);	
		glTexCoord2f(0.0,3.0);  glVertex3d(28.25, 11.5, -26);
	glEnd();

	//esquerda
	glBegin(GL_POLYGON);
		glNormal3d(-1.0,0.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(16.75, 0, -26);
		glTexCoord2f(2.0,0); glVertex3d(16.75, 0,  -19);
		glTexCoord2f(2.0,3); glVertex3d(16.75, 11.5,  -19);	
		glTexCoord2f(0.0,3.0);  glVertex3d(16.75, 11.5, -26);
	glEnd();

	//chao do hospital
	myMaterial(CHAO);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(16.75, 0, -19);
		glTexCoord2f(0.0,2); glVertex3d(28.25, 0,  -19);
		glTexCoord2f(1.0,2); glVertex3d(28.25, 0,  -26);	
		glTexCoord2f(1.0,0.0);  glVertex3d(16.75, 0, -26);
	glEnd();

	//tecto do hospital
	myMaterial(TELHA);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(16.75, 11.5, -19);
		glTexCoord2f(0.0,2); glVertex3d(28.25, 11.5,  -19);
		glTexCoord2f(1.0,2); glVertex3d(28.25, 11.5,  -26);	
		glTexCoord2f(1.0,0.0);  glVertex3d(16.75, 11.5, -26);
	glEnd();

	//telhado do hospital
	glBindTexture(GL_TEXTURE_2D, 11);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//base
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(16, 11.5, -18.25);
		glTexCoord2f(0.0,2); glVertex3d(29, 11.5,  -18.25);
		glTexCoord2f(1.0,2); glVertex3d(29, 11.5,  -26.75);	
		glTexCoord2f(1.0,0.0);  glVertex3d(16, 11.5, -26.75);
	glEnd();

	//triangulos
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(16, 11.5, -18.25);
		glTexCoord2f(0.0,2); glVertex3d(19.25, 12.5,  -22.50);
		glTexCoord2f(1.0,2); glVertex3d(16, 11.5,  -26.75);
	glEnd();
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(29, 11.5, -18.25);
		glTexCoord2f(0.0,2); glVertex3d(29, 11.5,  -26.75);
		glTexCoord2f(1.0,2); glVertex3d(25.75, 12.5,  -22.50);
	glEnd();

	//quadrilateros 
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(16, 11.5, -18.25);
		glTexCoord2f(0.0,2); glVertex3d(29, 11.5,  -18.25);
		glTexCoord2f(1.0,2); glVertex3d(25.75, 12.5, -22.50);	
		glTexCoord2f(1.0,0.0);  glVertex3d(19.25, 12.5, -22.50);
	glEnd();
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glTexCoord2f(0.0,0.0);  glVertex3d(29, 11.5, -26.75);
		glTexCoord2f(0.0,2); glVertex3d(16, 11.5,  -26.75);
		glTexCoord2f(1.0,2); glVertex3d(19.25, 12.5, -22.50);	
		glTexCoord2f(1.0,0.0);  glVertex3d(25.75, 12.5, -22.50);
	glEnd();

	//Porta
	myMaterial(PAREDE);
	glBindTexture(GL_TEXTURE_2D, 10);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_POLYGON);
	//glColor3f(1.0,0.5,0.0);
		glNormal3d(0.0,0.0,1.0);
		glVertex3d(21.0, 0, -18.95);
		glVertex3d(24.0, 0,  -18.95);
		glVertex3d(24.0, 3.2, -18.95);	
		glVertex3d(21.0, 3.2, -18.95);
	glEnd();
	}

	if (l==TRUE) {
	//Nome
	glDisable(GL_TEXTURE_2D);
	/*glBindTexture(GL_TEXTURE_2D, 7);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);*/
	myMaterial(NEON);
	glPushMatrix();
	glTranslatef(19,12,-19);
	glScalef(0.03, 0.03, 0.03);
	//glColor3f(0.0,1.0,0.0);
    glLineWidth(4.0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, 'H');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, 'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, 'J');
	glPopMatrix();
	}
	glDisable(GL_TEXTURE_2D);
	myMaterial(DEFAULT);
}

void heliporto(int hp) {
	glEnable(GL_TEXTURE_2D);

	if (hp==TRUE) {
	//chao do heliporto
	glBindTexture(GL_TEXTURE_2D, 6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(CHAO);

	glPushMatrix();
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &ctrlpointsh[0][0]);
	glMap2f(GL_MAP2_NORMAL,   0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &nrmlcompon[0][0]);
	//glMap2f(GL_MAP2_COLOR_4,  0.0, 1.0, 4, 2,  0.0, 1.0, 8, 2,  &colorpoints[0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &textpoints[0][0]);

	// os interpoladores activam-se:
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_NORMAL);
	//glEnable(GL_MAP2_COLOR_4);
	glEnable(GL_MAP2_TEXTURE_COORD_2);

	glMapGrid2f(40, 0.0,1.0, 60, 0.0,1.0); 

	if (EVAL) {
		//com evaluators
		glEvalMesh2(GL_FILL, 0,40, 0,60);		// GL_POINT, GL_LINE, GL_FILL
	} else {
		//sem evaluators
		glBegin(GL_POLYGON);
			glNormal3d(0.0,1.0,0.0);
			glTexCoord2f(0.0,0.0);  glVertex3d(17.25, 1, -3.75);
			glTexCoord2f(1.0,0); glVertex3d(27.75, 1,  -3.75);
			glTexCoord2f(1.0,1); glVertex3d(27.75, 1,  -11.25);
			glTexCoord2f(0.0,1.0);  glVertex3d(17.25, 1, -11.25);
		glEnd();
	}

	glPopMatrix();

	//4 lados
	glBindTexture(GL_TEXTURE_2D, 13);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	myMaterial(CHAO);
    glBegin(GL_POLYGON);
        glNormal3d(0.0,1.0,0.0);
        glTexCoord2f(0.0,0.0);  glVertex3d(17.25, 0, -3.75);
        glTexCoord2f(1.0,0); glVertex3d(27.75, 0,  -3.75);
        glTexCoord2f(1.0,1); glVertex3d(27.75, 1,  -3.75);
        glTexCoord2f(0.0,1.0);  glVertex3d(17.25, 1, -3.75);
    glEnd();
    glBegin(GL_POLYGON);
        glNormal3d(0.0,1.0,0.0);
        glTexCoord2f(1.0,0); glVertex3d(27.75, 0,-11.25);
        glTexCoord2f(0.0,0.0);  glVertex3d(17.25, 0,-11.25);
        glTexCoord2f(0.0,1.0);  glVertex3d(17.25, 1, -11.25);
        glTexCoord2f(1.0,1); glVertex3d(27.75, 1,  -11.25);
    glEnd();
    glBegin(GL_POLYGON);
        glNormal3d(0.0,1.0,0.0);
        glTexCoord2f(0.0,0.0);  glVertex3d(17.25, 0, -11.25);
        glTexCoord2f(1.0,0); glVertex3d(17.25, 0,  -3.75);
        glTexCoord2f(1.0,1); glVertex3d(17.25, 1,  -3.75);
        glTexCoord2f(0.0,1.0);  glVertex3d(17.25, 1, -11.25);
    glEnd();
    glBegin(GL_POLYGON);
        glNormal3d(0.0,1.0,0.0);
        glTexCoord2f(1.0,0); glVertex3d(27.75, 0,  -3.75);
        glTexCoord2f(0.0,0.0);  glVertex3d(27.75, 0, -11.25);
        glTexCoord2f(0.0,1.0);  glVertex3d(27.75, 1, -11.25);
        glTexCoord2f(1.0,1); glVertex3d(27.75, 1,  -3.75);
    glEnd();
	}

	glDisable(GL_TEXTURE_2D);
	myMaterial(DEFAULT);
}

void holofotes(int h1,int h2,int h3,int h4) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 13);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//postes
	if (h1==TRUE) {
	myMaterial(FERRO);
	//esquerdo-baixo
	glPushMatrix();
	glTranslatef(17.25,0,-3.75);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ,0.3, 0.3, 4.7, 8, axis_nstacks);
	glPopMatrix();
	}

	if (h2==TRUE) {
	myMaterial(FERRO);
	//direito-baixo
	glPushMatrix();
	glTranslatef(27.75,0,-3.75);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ,0.3, 0.3, 4.7, 8, axis_nstacks);
	glPopMatrix();
	}

	if (h3==TRUE) {
	myMaterial(FERRO);
	//direito-alto
	glPushMatrix();
	glTranslatef(27.75,0,-11.25);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ,0.3, 0.3, 4.7, 8, axis_nstacks);
	glPopMatrix();
	}

	if (h4==TRUE) {
	myMaterial(FERRO);
	//esquerdo-alto
	glPushMatrix();
	glTranslatef(17.25,0,-11.25);
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ,0.3, 0.3, 4.7, 8, axis_nstacks);
	glPopMatrix();
	}

	glDisable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, 10);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	if (h1==TRUE) {
	//desenhar lampada de holofote esquerdo-baixo
	myMaterial(MADEIRA);
	glPushMatrix();
	glTranslatef(18,4.5,-3.7);
	glRotated(-45.0,0.0,0.0,1.0 );
	glRotated(-90.0, 1.0,0.0,0.0 );
	glRotated(-90.0,0.0,1.0,0.0 );
	gluCylinder(glQ, 1.3, 0.7,0.7, axis_nslices, axis_nstacks);
	glPopMatrix();

	//fechar caixa holofote
	glPushMatrix();
	glTranslatef(17.5,5.0,-3.7);
	glRotated(-45.0,0.0,0.0,1.0 );
	glRotated(-90.0,0.0,1.0,0.0 );
	gluDisk(glQ, 0, 0.7, axis_nslices, 4);
	glPopMatrix();
	}

	if (h4==TRUE) {
	//desenhar lampada de holofote esquerdo-alto
	myMaterial(MADEIRA);
	glPushMatrix();
	glTranslatef(18,4.5,-11.2);
	glRotated(-45.0,0.0,0.0,1.0 );
	glRotated(-90.0, 1.0,0.0,0.0 );
	glRotated(-90.0,0.0,1.0,0.0 );
	gluCylinder(glQ, 1.3, 0.7,0.7, axis_nslices, axis_nstacks);
	glPopMatrix();

	//fechar caixa holofote
	glPushMatrix();
	glTranslatef(17.5,5.0,-11.2);
	glRotated(-45.0,0.0,0.0,1.0 );
	glRotated(-90.0,0.0,1.0,0.0 );
	gluDisk(glQ, 0, 0.7, axis_nslices, 4);
	glPopMatrix();
	}

	if (h2==TRUE) {
	//desenhar lampada de holofote direito-baixo
	myMaterial(MADEIRA);
	glPushMatrix();
	glTranslatef(27.0,4.5,-3.7);
	glRotated(-45.0,0.0,0.0,1.0 );
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, 1.3, 0.7,0.7, axis_nslices, axis_nstacks);
	glPopMatrix();

	//fechar caixa holofote
	glPushMatrix();
	glTranslatef(27.5,5.0,-3.7);
	glRotated(-45.0,0.0,0.0,1.0 );
	glRotated(-90.0,0.0,1.0,0.0 );
	glRotated(-90.0,1.0,0.0,0.0 );
	gluDisk(glQ, 0, 0.7, axis_nslices, 4);
	glPopMatrix();
	}

	if (h3==TRUE) {
	//desenhar lampada de holofote direito-alto
	myMaterial(MADEIRA);
	glPushMatrix();
	glTranslatef(27,4.5,-11.2);
	glRotated(-45.0,0.0,0.0,1.0 );
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, 1.3, 0.7,0.7, axis_nslices, axis_nstacks);
	glPopMatrix();

	//fechar caixa holofote
	glPushMatrix();
	glTranslatef(27.5,5.0,-11.2);
	glRotated(-45.0,0.0,0.0,1.0 );
	glRotated(-90.0,0.0,1.0,0.0 );
	glRotated(-90.0,1.0,0.0,0.0 );
	gluDisk(glQ, 0, 0.7, axis_nslices, 4);
	glPopMatrix();
	}
	
	glEnable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_2D);
	myMaterial(DEFAULT);
}

void torre(int tow) {

	myMaterial(CHAO);
	if (tow==TRUE) {
	//base da torre
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S); 
    glEnable(GL_TEXTURE_GEN_T); 
	glBindTexture(GL_TEXTURE_2D, 8);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	myMaterial(FERRO);
    glPushMatrix();
    glTranslatef(43,0,-25);
    glRotated(-90.0, 1.0,0.0,0.0 );
    gluCylinder(glQ,1.25,1.25,9.5,16,axis_nstacks);
    glPopMatrix();

    //plataforma cilindrica da torre
    glPushMatrix();
        glTranslatef(43,9.5,-25);
        glRotated(-90.0, 1.0,0.0,0.0 );
        gluCylinder_closed(glQ,4.5,4.5,0.7,16,axis_nstacks,TRUE,TRUE);
    glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_GEN_S); 
    glDisable(GL_TEXTURE_GEN_T); 

	myMaterial(VIDRO);
    //cupula da torre (sphere clipada e com blend)
    glPushMatrix();
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        //glColor3f(0,0.5,1);
        glPushMatrix();
        glTranslatef(43,9.5,-25);
        gluQuadricOrientation( glQ, GLU_OUTSIDE);
        glClipPlane(GL_CLIP_PLANE0,eqn);
        glEnable(GL_CLIP_PLANE0);
        gluSphere(glQ, 4.5, 16, 8);
        glDisable(GL_CLIP_PLANE0);
        glPopMatrix();
    glDisable(GL_BLEND);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
	}
	myMaterial(DEFAULT);
}

void hangar(int hang) {
	myMaterial(DEFAULT);
	if (hang==TRUE) {
		//Definicoes para o uso dos evaluators
		glMap2f(GL_MAP2_VERTEX_3,0, 1, 3, 4, 0, 1, 12,4,&ctrlpoints[0][0][0]);
		glMap2f(GL_MAP2_TEXTURE_COORD_2, 0, 1, 2, 2,0, 1, 4, 2, &texpts[0][0][0]);
		glEnable(GL_MAP2_TEXTURE_COORD_2);
		glEnable(GL_MAP2_VERTEX_3);
		glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
		glPushMatrix();
        glDisable(GL_CULL_FACE);
            //glShadeModel(GL_FLAT);
            glTranslatef(31,0,-27);
            glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, 12);
                glEvalMesh2(GL_FILL, 0,20, 0,20);
            glDisable(GL_TEXTURE_2D);
        glEnable(GL_CULL_FACE);
		glPopMatrix();
	}
}
//funcao para construir helicoptero
//Nao foi construido na origem por questoes de visualizacao durante a construcao
void constroihelicoptero(GLUquadric * glQ){
    //cabine piloto
	myMaterial(CABINE);
    glPushMatrix();
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    //tornar cabine transparente a tudo menos aos proprios componentes do helicoptero
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glColor3f(0,0.5,1);
        gluQuadricOrientation( glQ, GLU_OUTSIDE);
        gluSphere(glQ,HELI_CABINE_RAIO,24,24);
    glDisable(GL_BLEND);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
    
    glDisable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_GEN_S); 
		glEnable(GL_TEXTURE_GEN_T); 

		glBindTexture(GL_TEXTURE_2D, 14);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //pernas do helicoptero
	myMaterial(FERROB);
        glPushMatrix();
        glTranslatef(-(HELI_CABINE_RAIO*0.5),-HELI_CABINE_RAIO-(HELI_PERNAS_ALTURA*0.5),0);
        glRotatef(-90,1,0,0);
        gluCylinder_closed(glQ,HELI_PERNAS_RAIO_BASE_INF,HELI_PERNAS_RAIO_BASE_SUP,HELI_PERNAS_ALTURA,16,8,TRUE,TRUE);
        glPopMatrix();
        glPushMatrix();
        glTranslatef((HELI_CABINE_RAIO*0.5),-HELI_CABINE_RAIO-(HELI_PERNAS_ALTURA*0.5),0);
        glRotatef(-90,1,0,0);
        gluCylinder_closed(glQ,HELI_PERNAS_RAIO_BASE_INF,HELI_PERNAS_RAIO_BASE_SUP,HELI_PERNAS_ALTURA,16,8,TRUE,TRUE);
        glPopMatrix();
    //pes do helicoptero
		glBindTexture(GL_TEXTURE_2D, 13);
        glPushMatrix();
        glTranslatef(-(HELI_CABINE_RAIO*0.5),-HELI_CABINE_RAIO-(HELI_PERNAS_ALTURA*0.5),-(HELI_PES_COMPRIMENTO*0.5));
        gluCylinder_closed(glQ,HELI_PES_RAIO,HELI_PES_RAIO,HELI_PES_COMPRIMENTO,16,8,TRUE,TRUE);
        glPopMatrix();
        glPushMatrix();
        glTranslatef((HELI_CABINE_RAIO*0.5),-HELI_CABINE_RAIO-(HELI_PERNAS_ALTURA*0.5),-(HELI_PES_COMPRIMENTO*0.5));
        gluCylinder_closed(glQ,HELI_PES_RAIO,HELI_PES_RAIO,HELI_PES_COMPRIMENTO,16,8,TRUE,TRUE);
        glPopMatrix();
    //cauda do helicoptero
		glBindTexture(GL_TEXTURE_2D, 14);
        glPushMatrix();
        glTranslatef(0,0,-HELI_CABINE_RAIO*0.25);
        glRotatef(180,0,1,0);
        gluCylinder_closed(glQ,HELI_CAUDA_RAIO_BASE,0,HELI_CAUDA_COMPRIMENTO,16,8,TRUE,TRUE);
        glPopMatrix();
    
        
        //"parafuso" helice grande
		glBindTexture(GL_TEXTURE_2D, 14);
        glPushMatrix();
        glRotatef(obj_rotate,0,1,0);
        glPushMatrix();
        
        glTranslatef(0,HELI_CABINE_RAIO-(HELI_PARAFUSO_HELICE_GRANDE_ALTURA*0.5),0);
        glRotatef(-90,1,0,0);
        gluCylinder_closed(glQ,HELI_PARAFUSO_HELICES_RAIO,HELI_PARAFUSO_HELICES_RAIO,HELI_PARAFUSO_HELICE_GRANDE_ALTURA,16,8,TRUE,TRUE);
        glPopMatrix();
        //helices grandes
        //helice 1
        glBindTexture(GL_TEXTURE_2D, 13);
        glPushMatrix();
        glTranslatef(0,HELI_CABINE_RAIO+(HELI_PARAFUSO_HELICE_GRANDE_ALTURA*0.25),0);
        glBegin(GL_POLYGON);
            glNormal3d(0.0,1.0,0.0);
            glTexCoord2f(0.0,0.0);  glVertex3d(0, 0, 0);
            glTexCoord2f(1.0,0.0); glVertex3d(HELI_HELICE_GRANDE_TAMANHO, 0,  HELI_HELICE_GRANDE_LARGURA*0.5);
            glTexCoord2f(1.0,1.0); glVertex3d(HELI_HELICE_GRANDE_TAMANHO, 0, -HELI_HELICE_GRANDE_LARGURA*0.5);
        glEnd();
        glPopMatrix();
        //helice 2
        glPushMatrix();
        glTranslatef(0,HELI_CABINE_RAIO+(HELI_PARAFUSO_HELICE_GRANDE_ALTURA*0.25),0);
        glRotatef(120,0,1,0);
        glBegin(GL_POLYGON);
            glNormal3d(0.0,1.0,0.0);
            glTexCoord2f(0.0,0.0); glVertex3d(0, 0, 0);
            glTexCoord2f(1.0,0.0); glVertex3d(HELI_HELICE_GRANDE_TAMANHO, 0,  HELI_HELICE_GRANDE_LARGURA*0.5);
            glTexCoord2f(1.0,1.0); glVertex3d(HELI_HELICE_GRANDE_TAMANHO, 0,  -HELI_HELICE_GRANDE_LARGURA*0.5);
        glEnd();
        glPopMatrix();
        //helice 3
        glPushMatrix();
        glTranslatef(0,HELI_CABINE_RAIO+(HELI_PARAFUSO_HELICE_GRANDE_ALTURA*0.25),0);
        glRotatef(240,0,1,0);
        glBegin(GL_POLYGON);
            glNormal3d(0.0,1.0,0.0);
            glTexCoord2f(0.0,0.0);  glVertex3d(0, 0, 0);
            glTexCoord2f(1.0,0.0); glVertex3d(HELI_HELICE_GRANDE_TAMANHO, 0,  HELI_HELICE_GRANDE_LARGURA*0.5);
            glTexCoord2f(1.0,1.0); glVertex3d(HELI_HELICE_GRANDE_TAMANHO, 0,  -HELI_HELICE_GRANDE_LARGURA*0.5);
        glEnd();
        glPopMatrix();
        glPopMatrix();
        //asas traseiras
        //cima
		glDisable(GL_TEXTURE_GEN_S); 
		glDisable(GL_TEXTURE_GEN_T); 
        glBindTexture(GL_TEXTURE_2D, 15);
        glPushMatrix();
        glTranslatef(0,0,-HELI_CABINE_RAIO*0.25-HELI_CAUDA_COMPRIMENTO+(HELI_CAUDA_COMPRIMENTO/5.6)-(HELI_ASAS_TRASEIRAS_COMPRIMENTO*0.5));
        glBegin(GL_POLYGON);
            glNormal3d(0.0,1.0,0.0);
            glTexCoord2f(0.0,0.0);  glVertex3d(0,0,0);
            glTexCoord2f(1.0,0.0); glVertex3d(0,0,HELI_ASAS_TRASEIRAS_COMPRIMENTO);
            glTexCoord2f(1.0,1.0); glVertex3d(0, HELI_ASAS_TRASEIRAS_ALTURA,  -0.1);
            glTexCoord2f(0.0,1.0);  glVertex3d(0, HELI_ASAS_TRASEIRAS_ALTURA, -0.1-HELI_ASAS_TRASEIRAS_COMPRIMENTO);
        glEnd();
        glPopMatrix();
        //baixo
		//glBindTexture(GL_TEXTURE_2D, 13);
        glPushMatrix();
        glTranslatef(0,0,-HELI_CABINE_RAIO*0.25-HELI_CAUDA_COMPRIMENTO+(HELI_CAUDA_COMPRIMENTO/5.6)-(HELI_ASAS_TRASEIRAS_COMPRIMENTO*0.5));
        glBegin(GL_POLYGON);
            glNormal3d(0.0,1.0,0.0);
            glTexCoord2f(0.0,0.0); glVertex3d(0,0,0);
            glTexCoord2f(1.0,0.0);  glVertex3d(0,0, HELI_ASAS_TRASEIRAS_COMPRIMENTO);
            glTexCoord2f(1.0,1.0); glVertex3d(0, -HELI_ASAS_TRASEIRAS_ALTURA,  -0.1);
            glTexCoord2f(0.0,1.0);  glVertex3d(0,-HELI_ASAS_TRASEIRAS_ALTURA, -0.1-HELI_ASAS_TRASEIRAS_COMPRIMENTO);
        glEnd();
        glPopMatrix();
        //"parafuso" helice pequena
		glEnable(GL_TEXTURE_GEN_S); 
		glEnable(GL_TEXTURE_GEN_T); 
		glBindTexture(GL_TEXTURE_2D, 14);
        glPushMatrix();
        glTranslatef(0,0,-HELI_CABINE_RAIO*0.25-HELI_CAUDA_COMPRIMENTO+(HELI_CAUDA_COMPRIMENTO/5.6));
        glRotatef(obj_rotate,1,0,0);
        glTranslatef(0,0,-(-HELI_CABINE_RAIO*0.25-HELI_CAUDA_COMPRIMENTO+(HELI_CAUDA_COMPRIMENTO/5.6)));

        glPushMatrix();
        glTranslatef(0,0,-HELI_CABINE_RAIO*0.25-HELI_CAUDA_COMPRIMENTO+(HELI_CAUDA_COMPRIMENTO/5.6));
        glRotatef(-90,0,1,0);
        gluCylinder_closed(glQ,HELI_PARAFUSO_HELICES_RAIO,HELI_PARAFUSO_HELICES_RAIO,HELI_PARAFUSO_HELICE_PEQUENO_ALTURA,16,8,TRUE,TRUE);
        glPopMatrix();
        //helices pequenas
        //helice 1
        glBindTexture(GL_TEXTURE_2D, 13);
        glPushMatrix();
        glTranslatef(-(HELI_PARAFUSO_HELICE_PEQUENO_ALTURA*0.5),0,-HELI_CABINE_RAIO*0.25-HELI_CAUDA_COMPRIMENTO+(HELI_CAUDA_COMPRIMENTO/5.6));
        glBegin(GL_POLYGON);
            glNormal3d(0.0,1.0,0.0);
            glTexCoord2f(0.0,0.0);  glVertex3d(0, 0, 0);
            glTexCoord2f(1.0,0.0); glVertex3d(0, HELI_HELICE_PEQUENA_TAMANHO,  HELI_HELICE_PEQUENA_LARGURA*0.5);
            glTexCoord2f(1.0,1.0); glVertex3d(0, HELI_HELICE_PEQUENA_TAMANHO,  -HELI_HELICE_PEQUENA_LARGURA*0.5);
        glEnd();
        glPopMatrix();
        //helice 2
        glPushMatrix();
        glTranslatef(-(HELI_PARAFUSO_HELICE_PEQUENO_ALTURA*0.5),0,-HELI_CABINE_RAIO*0.25-HELI_CAUDA_COMPRIMENTO+(HELI_CAUDA_COMPRIMENTO/5.6));
        glRotatef(120,1,0,0);
        glBegin(GL_POLYGON);
            glNormal3d(0.0,1.0,0.0);
            glTexCoord2f(0.0,0.0);  glVertex3d(0, 0, 0);
            glTexCoord2f(1.0,0.0); glVertex3d(0, HELI_HELICE_PEQUENA_TAMANHO,  HELI_HELICE_PEQUENA_LARGURA*0.5);
            glTexCoord2f(1.0,1.0); glVertex3d(0, HELI_HELICE_PEQUENA_TAMANHO,  -HELI_HELICE_PEQUENA_LARGURA*0.5);
        glEnd();
        glPopMatrix();
        //helice 3
        glPushMatrix();
        glTranslatef(-(HELI_PARAFUSO_HELICE_PEQUENO_ALTURA*0.5),0,-HELI_CABINE_RAIO*0.25-HELI_CAUDA_COMPRIMENTO+(HELI_CAUDA_COMPRIMENTO/5.6));
        glRotatef(240,1,0,0);
        glBegin(GL_POLYGON);
            glNormal3d(0.0,1.0,0.0);
            glTexCoord2f(0.0,0.0);  glVertex3d(0, 0, 0);
            glTexCoord2f(1.0,0.0); glVertex3d(0, HELI_HELICE_PEQUENA_TAMANHO,  HELI_HELICE_PEQUENA_LARGURA*0.5);
            glTexCoord2f(1.0,1.0); glVertex3d(0, HELI_HELICE_PEQUENA_TAMANHO,  -HELI_HELICE_PEQUENA_LARGURA*0.5);
        glEnd();
        glPopMatrix();
        glPopMatrix();
    glDisable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_GEN_S); 
    glDisable(GL_TEXTURE_GEN_T); 

    glEnable(GL_CULL_FACE);
	myMaterial(DEFAULT);
}

void helichopper() {
	glTranslatef(MovX1,MovY1,MovZ1);
		glTranslatef(0,HELI_CABINE_RAIO+(HELI_PERNAS_ALTURA*0.5)+HELI_PES_RAIO,0);
		if(curva == FALSE){ //se nao esta a fazer a curva
			glRotatef(o,0,1,0);
			glRotatef(i,0,0,1);
		}else{              //se est� a fazer a curva
			glTranslatef(7.5,0,0);
			glRotatef(o,0,1,0);
			glRotatef(i,0,0,1);
			glRotatef(x,1,0,0);
			glTranslatef(0,0,-7.5);
		}

	glPushMatrix();
	if(animacao == TRUE){ //ja foi carregado enter? se sim, comeca a animacao
		//desenhar helicoptero
		//sobe na trajectoria verde
			if(vertical_1_up == FALSE){ //movimento vertical ja foi realizado? nao, entao vai ser feito
				if( i > -10 ){			//inclina o helicoptero em relacao a z levantando a cauda atras e baixando o bico a frente
						i -= 1;
				}
				if(o > -27){			//roda o helicoptero por forma a ficar virado de frente para a sua trajectoria
						o-=VEL_ROTACAO;			//27 � o angulo para a diagonal (calculado aritmeticamente)
				}
				if(MovY1>13)			//ja chegou � altura que � suposto chegar neste tro�o de movimento? 
					vertical_1_up = TRUE; //se sim, ent�o o movimento vertical j� foi realizado
				MovY1 += VELOCIDADE;
			}
			//diagonal na trajectoria verde
			if(vertical_1_up == TRUE){		//movimento vertical j� foi realizado? se sim, vamos ver se o movimento diagonal ja foi realizado
				if(horizontal_1 == FALSE){	//movimento diagonal ja foi realizado? e n�o, realiza-se agora, sen�o, salta para o proximo movimento
					if( i < 10 ){					
						i += VEL_ROTACAO;
					}
				
					if( MovX1 > 7.5){
						MovX1 -= 2*VELOCIDADE; //anda 2 casas na horizontal para 1 na vertical para fazer a diagonal
					}
					if(MovZ1 > -15){
						MovZ1 -= VELOCIDADE;
					}else{
						horizontal_1 = TRUE;	//movimento diagonal concluido
					}
				}
			}
			//desce na trajectoria verde
			if(horizontal_1 == TRUE){
				if(vertical_1_down == FALSE){
					if( i > -10 ){					
						i -= VEL_ROTACAO;
					}
					if(o < 90){
						o+=2*VEL_ROTACAO;
					}
					if(MovY1<9)
						vertical_1_down = TRUE;
					MovY1 -= VELOCIDADE;
				}
			}
			//sobe na trajectoria vermelha
			if(vertical_1_down == TRUE){
				if( i < 10 && paralelo_yy == FALSE){					
						i += VEL_ROTACAO;
				}
				if(o < 90 && paralelo_yy == FALSE){
					o+=2*VEL_ROTACAO;
				}
				if(paralelo_zz == FALSE){
				
					if(MovY1>13)
						paralelo_zz = TRUE;
					MovY1 += VELOCIDADE;
				}
			}
			/*//anda paralelo aos zz na trajectoria vermelha
			if(paralelo_zz == TRUE){
				if(paralelo_yy == FALSE){
					if(MovZ1 > -7.5){
						paralelo_yy = TRUE;
					}
					MovZ1 += VELOCIDADE;
				}
			}

			*/
			if(paralelo_zz == TRUE){		//faz a curva
				if(paralelo_yy == FALSE){
					curva = TRUE;			//esta variavel serve para escolher quais as translaccoes e rotacoes que vao ser feitas)
					if(o>180){
						paralelo_yy = TRUE;
						curva = FALSE;
						MovZ1 = -7.5; //actualiza as posicoes para seguir
						MovX1 += 7.5; //no local certo depois da curva
					}
					if(o < 135){
						if(x < 10){
							x += VEL_ROTACAO*(VEL_ROTACAO*3); //roda para o helicoptero ficar inclinado de lado
						}
					}else{
						if(x > 0){
							x -= VEL_ROTACAO*(VEL_ROTACAO*3); //roda para o helicoptero voltar a inclinacao lateral inicial ( ou seja, 0)
						}
					}
					o += VEL_ROTACAO;
				}
			}

			//anda paralelo aos yy na trajectoria vermelha
			if(paralelo_yy == TRUE){
				if(vertical_2_down == FALSE){
					if(o < 180){
						o+=VEL_ROTACAO;
					}
					if(MovX1 > 22.5){
						vertical_2_down = TRUE;
					}
					MovX1 += VELOCIDADE;
				}
			}

			//desce ate ao heliporto
			if(vertical_2_down == TRUE){
				if(acabou_movimento == FALSE){
					if(MovY1 > 6.5){
						if( i > -10 ){					
							i -= VEL_ROTACAO;
						}
					}else{
							if( i < 0 ){
								i += VEL_ROTACAO;
							}
						}
					if(o > 0){
						o-=2*VEL_ROTACAO;
					}
					if(MovY1 < 1){					//o movimento acabou, portanto, reiniciar todas as vars para poder fazer outra vez o mesmo
						acabou_movimento = TRUE;	//sem ter de estar a voltar a correr o programa todo
						vertical_1_up = FALSE;
						vertical_1_down = FALSE;
						vertical_2_down = FALSE;
						horizontal_1 = FALSE;
						vertical_2_up = FALSE;
						paralelo_zz = FALSE;
						paralelo_yy = FALSE;
						acabou_movimento = FALSE;
						animacao = FALSE;
						curva = FALSE;
					}
					MovY1 -= VELOCIDADE;
				}
			}
		}
			glRotatef(-90,0,1,0); //originalmente, o helicoptero esta colocado com a frente orientada pelo eixo dos zz. 
			constroihelicoptero(glQ); //Muda-se para comecar orientado pelo eixo dos xx (virado para a parte negativa dos mesmos)
		glPopMatrix();
}
//Gerar Display Lists
void myDLists() {
	terarv = glGenLists (1);
		glNewList(terarv, GL_COMPILE);
		chao(ter[0],ter[1],ter[2]);
		arvores(arv[0],arv[1],arv[2],arv[3]);
		glEndList();
   
	hospit = glGenLists (2);
		glNewList(hospit, GL_COMPILE);
		hospital(edi[0], edi[1]);
		glEndList();
	   
	helip = glGenLists (3);
		glNewList(helip, GL_COMPILE);
		heliporto(edi[2]);
		holofotes(TRUE,TRUE,TRUE,TRUE);
		glEndList();
	cout << "Display Lists geradas" << endl;
}
//funcao das checkboxs
void callback_checkbox(int id){
	int i=0;
	switch (id){
		case 1:
			if (hol[0]) {
				glEnable(GL_LIGHT1);
			} else {
				glDisable(GL_LIGHT1);
			}
			break;
		case 2:
			if (hol[1]) {
				glEnable(GL_LIGHT2);
			} else {
				glDisable(GL_LIGHT2);
			}
			break;
		case 3:
			if (hol[2]) {
				glEnable(GL_LIGHT3);
			} else {
				glDisable(GL_LIGHT3);
			}
			break;
		case 4:
			if (hol[3]) {
				glEnable(GL_LIGHT4);
			} else {
				glDisable(GL_LIGHT4);
			}
			break;
		case 5:
			if (LUZ) {
				//luz_on
				glEnable(GL_LIGHT0);
			}
			else {
				//luz_off
				glDisable(GL_LIGHT0);
			}
			break;
		case 6:
			if (LET) {
				mat_emission[7][1]=1.0;
			} else {
				mat_emission[7][1]=0.0;
			}
			break;
		case 20:
			if (BCKG) {
				glClearColor(0.4,0.7,1.0,1.0);
			} else {
				glClearColor(0.0,0.0,0.0,1.0); 
			}
			break;
		case 21:
			if (AMB) {
				for (i=0;i<3;i++)
					light_ambient[i] = 0.6;
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);
			} else {
				for (i=0;i<3;i++)
					light_ambient[i] = 0.0;
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);
			}
			break;
		default: FIRST=TRUE;
			break;
	}
	FIRST=TRUE;
}

void display(void)
{
	// ****** declaracoes internas a funcao display() ******
	float temp;
	// ****** fim de todas as declaracoes da funcao display() ******

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	// inicializacoes da matriz de visualizacao
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum( -xy_aspect*.04, xy_aspect*.04, -.04, .04, .1, 150.0 );
    //reposiciona o centro da camara
    //glTranslatef(-22,-5,-10);

    //inicializacoes da matriz de transformacoes geometricas
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //condicoes para se saber qual a camara que foi activada pelo teclado
    if(camara == '1'){
        gluLookAt(22.5,20,30,22.5,0,-15,0,1,0);
        // roda a cena de acordo com o botao (esfera) de rotacao
        glTranslatef( obj_pos[0], obj_pos[1], -obj_pos[2]-25 );
        glMultMatrixf( view_rotate );
    } else if(camara == '2'){
        gluLookAt(22.5,50,-15,22.5,0,-15.1,0,1,0);
    } else if (camara = '3'){
        gluLookAt(movimento_camara_xx,movimento_camara_yy,movimento_camara_zz,22.5,1,-7.5,0,1,0);
    }
	
	/*// afasta a cena de 25 unidades mais a dist�ncia que...
	// ...decorre da utilizacao do botao de afastamento (pseudo-zoom)
    glTranslatef( obj_pos[0], obj_pos[1], -obj_pos[2]-25 );
		// tambem se poderia ter feito:
		//glTranslated(0.0,0.0,-25.0);
		//glTranslatef( obj_pos[0], obj_pos[1], -obj_pos[2] );

	// roda a cena para ficar em perspectiva
	//glRotated( 20.0, 1.0,0.0,0.0 );		// 20 graus em torno de X
	//glRotated(-45.0, 0.0,1.0,0.0 );		//-45 graus em torno de Y
	*/

	// roda a cena de acordo com o botao (esfera) de rotacao
	//glMultMatrixf( view_rotate );
	
	// permissao de atribuicao directa de cores
	// para objectos que nao tem material atribuido, como
	// e' o caso dos eixos e da esfera que simboliza a fonte de luz...
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	//eixos
	if (AXIS)
		draweixos();
	
	// Actualizacao da posicao das fontes de luz e das esfera que as simbolizam
	luzes();

	// SEGUEM-SE ALGUNS EXEMPLOS DE UTILIZACAO DE OPENGL (GL, GLU, GLUT)

	// GLU: funcoes para desenhar Quadraticas
	//   Permitem desenhar alguns objectos: disco, cilindro/cone, esfera
	//   O parametro do tipo GLUquadric (variavel glQ, declarada acima) passa,
	//   em argumento da funcao de desenho respectiva, algumas propriedades
	//   que esta tem em conta durante o desenho (estilo de desenho, calculo e
	//   orientacao de normais, mapeamento de texturas...

	// Funcoes para definicao dessas propriedades em glQ
	gluQuadricDrawStyle(glQ, GLU_LINE);		// GLU_FILL, GLU_LINE, GLU_SILHOUETTE, GLU_POINT
	gluQuadricNormals(glQ, GLU_SMOOTH);		// GLU_NONE, GLU_FLAT, GLU_SMOOTH
	gluQuadricOrientation(glQ, GLU_OUTSIDE);	// GLU_OUTSIDE, GLU_INSIDE
	gluQuadricTexture(glQ, GL_FALSE);		// GL_TRUE, GL_FALSE
	//gluQuadricCallback(glQ, GLU_ERROR, <CallBackFunc>);

	// Funcoes de desenho de quadraticas
	// gluDisk(GLUquadric* quad, GLdouble inner, GLdouble outer,
	//			GLint slices, GLint loops )
	// gluPartialDisk(GLUquadric* quad, GLdouble inner, GLdouble outer,
	//			GLint slices, GLint loops, GLdouble start, GLdouble sweep )
	// gluCylinder(GLUquadric * quad, GLdouble base, GLdouble top, GLdouble height,
	//			GLint slices, GLint stacks );
	// gluSphere(GLUquadric* quad, GLdouble radius, GLint slices, GLint stacks )

	// Solidos, na GLUT: nao fazem mapeamento de texturas (excepto o Teapot)
	// glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
	// glutSolidCube(GLdouble size);
	// glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
	// glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings);
	// glutSolidDodecahedron(void);
	// glutSolidOctahedron(void);
	// glutSolidTetrahedron(void);
	// glutSolidIcosahedron(void);
	// glutSolidTeapot(GLdouble size);

	// Texto 3D, GLUT
	// void glutStrokeCharacter(void *font, int character);	// GLUT_STROKE_ROMAN
	// int glutStrokeWidth(GLUTstrokeFont font, int character);

	// Texto BitMap, GLUT
	// glRasterPos3f(x,y,z);
	// void glutBitmapCharacter(void *font, int character);	// valores varios...
	// int glutBitmapWidth(GLUTbitmapFont font, int character);

	// inibicao de atribuicao directa de cores; os objectos que se seguem DEVEM
	// possuir materiais associados
	glDisable(GL_COLOR_MATERIAL);

	// Definicao de material a usar daqui em diante (valores declarados acima)
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat1_shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat1_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat1_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat1_ambient);

	gluQuadricDrawStyle(glQ, GLU_FILL);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_NORMALIZE);
	//glDisable(GL_AUTO_NORMAL);
	glEnable(GL_DEPTH_TEST);

	//Poligno teste
	//enum mat_enum{TRANSPARENTE,TELHA,PAREDE,CHAO,VIDRO,NEON,FERRO,PNEU,AMARELO,VERDE,CIANO,AZUL,MAGENTA,ROSA,VERMELHO};
	/*myMaterial(MADEIRA);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);
		glVertex3d(10.0, 0, 5);
		glVertex3d(20.0, 0,  5);
		glVertex3d(20.0, 10, 5);	
		glVertex3d(10.0, 10, 5);
	glEnd();*/

	if (USE_DISPLAY_LISTS) {
		//se algum objecto for escondido ou mostrado volta a gerar as display lists
		if (FIRST) {
			myDLists();
			FIRST=FALSE;
		}
		//Display Lists
		glCallList(terarv);
		glCallList(hospit);
		glCallList(helip);
	} else
	{
	//---Rect�ngulo/ch�o Dividido em 3 partes iguais---
	chao(ter[0],ter[1],ter[2]);
	//---Rect�ngulo/ch�o Dividido em 3 partes iguais---

	//---Zona da esquerda (floresta)---
	//arvores
	arvores(arv[0],arv[1],arv[2],arv[3]);
	//---Zona da esquerda (floresta)---

	//---Zona central (�rea hospitalar)---
	//-Hospital
	hospital(edi[0], edi[1]);
	//-Heliporto
	heliporto(edi[2]);
	//-Holofotes
	holofotes(TRUE,TRUE,TRUE,TRUE);
	//---Zona central (�rea hospitalar)---
	}

	//---Zona da direita---
	//torre
	torre(edi[3]);
	//hangar
	glEnable(GL_AUTO_NORMAL);
	hangar(edi[4]);
	glDisable(GL_AUTO_NORMAL);
	//desenha helicoptero
	helichopper();
	//---Zona da direita---

	//reiniciam-se as projeccoes e define-se um plano 2d para se trabalhar sobre a janela,
    //com as dimensoes da janela e ai acrescentase as letras
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,DIMX,0,DIMY);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    glPushMatrix();
        glColor3f(1.0,1.0,0);
        glRasterPos2d(5,DIMY-30);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'c');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'a');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'm');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'a');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'r');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'a');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ':');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, camara);
    glPopMatrix();
    glDisable(GL_COLOR_MATERIAL);

	// swapping the buffers causes the rendering above to be shown
	glutSwapBuffers();
	glFlush();
}


/* Mouse handling */
void processMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{	 
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{	
	}
	
	glutPostRedisplay();
	
}

void processMouseMoved(int x, int y)
{
	
	// pedido de refrescamento da janela
	glutPostRedisplay();				

}

void processPassiveMouseMoved(int x, int y)
{

	// pedido de refrescamento da janela
	glutPostRedisplay();				
}

void reshape(int w, int h)
{
	int tx, ty, tw, th;

	GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
	glViewport( tx, ty, tw, th );
	xy_aspect = (float)tw / (float)th;

	glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
        case '1':
            enable_camara_move = FALSE;
            camara = '1';
            //reset rotacao
            view_rot->reset();
            //reset zoom
            obj_pos[0] = 0;
            obj_pos[1] = 0;
            obj_pos[2] = 0;
            view_rot->enable();
            trans_z->enable();
            break;
        case '2':
            enable_camara_move = FALSE;
            camara = '2';
            //desliga botao rotacao e zoom
            trans_z->disable();
            view_rot->disable();
            break;
        case '3':
            camara = '3';
            enable_camara_move = TRUE;
            //desliga botao rotacao e zoom
            trans_z->disable();
            view_rot->disable();
            break;
        case 'j':
            if(enable_camara_move == TRUE){
                movimento_camara_xx-=1;
            }
            break;
        case 'l':
            if(enable_camara_move == TRUE){
                movimento_camara_xx+=1;
            }
            break;
        case 'i':
            if(enable_camara_move == TRUE){
                movimento_camara_yy+=1;
            }
            break;
        case 'k':
            if(enable_camara_move == TRUE){
                movimento_camara_yy-=1;
            }
            break;
        case 'q':
            if(enable_camara_move == TRUE){
                movimento_camara_zz-=1;
            }
            break;
        case 'a':
            if(enable_camara_move == TRUE){
                movimento_camara_zz+=1;
            }
            break;

        case 13:
            animacao = TRUE;
            break;
        
        case 27:        // tecla de escape termina o programa
            exit(0);
            break;
		default:
			break;
   }
}


void myGlutIdle( void )
{
  /* According to the GLUT specification, the current window is 
     undefined during an idle callback.  So we need to explicitly change
     it if necessary */
  if ( glutGetWindow() != main_window ) 
    glutSetWindow(main_window);  


  glutPostRedisplay();

}

void inicializacao()
{
	glQ = gluNewQuadric();

	glFrontFace(GL_CCW);		// Front faces defined using a counterclockwise rotation
	glDepthFunc(GL_LEQUAL);		// Por defeito e GL_LESS
	glEnable(GL_DEPTH_TEST);	// Use a depth (z) buffer to draw only visible objects

	// Face Culling para aumentar a velocidade
	glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);		// GL_FRONT, GL_BACK, GL_FRONT_AND_BACK


	// Define que modelo de iluminacao utilizar; consultar o manual de referencia
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);  // define luz ambiente
	glLightModelf (GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModeli (GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	
	// por defeito a cor de fundo e o preto
	glClearColor(0.0,0.0,0.0,1.0);    // cor de fundo

	// declaracoes para a fonte luz GL_LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,  light0_kc);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION,    light0_kl);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, light0_kq);

	// NOTA: a direccao e a posicao de GL_LIGHT0 estao na rotina display(), pelo
	//       que as instrucoes seguntes nao sao necessarias
	//glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90.0);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	//glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	// declaracoes para a fonte luz GL_LIGHT1
	glLightfv(GL_LIGHT1, GL_AMBIENT, lighth_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lighth_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lighth_specular);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION,  lighth_kc);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION,    lighth_kl);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, lighth_kq);

	// declaracoes para a fonte luz GL_LIGHT2
	glLightfv(GL_LIGHT2, GL_AMBIENT, lighth_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lighth_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lighth_specular);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION,  lighth_kc);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION,    lighth_kl);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, lighth_kq);

	// declaracoes para a fonte luz GL_LIGHT3
	glLightfv(GL_LIGHT3, GL_AMBIENT, lighth_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, lighth_diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, lighth_specular);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION,  lighth_kc);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION,    lighth_kl);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, lighth_kq);

	// declaracoes para a fonte luz GL_LIGHT4
	glLightfv(GL_LIGHT4, GL_AMBIENT, lighth_ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, lighth_diffuse);
	glLightfv(GL_LIGHT4, GL_SPECULAR, lighth_specular);
	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION,  lighth_kc);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION,    lighth_kl);
	glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, lighth_kq);

	// Permitir calculos de iluminacao
	glEnable(GL_LIGHTING);
	// "Acender" as fontes de luz
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);

	// Declaracoe para shading
	glShadeModel(GL_SMOOTH);			// GL_FLAT / GL_SMOOTH
	glPolygonMode(GL_FRONT, GL_FILL);	// preence a face da frente dos poligonos
	//glPolygonMode(GL_FRONT, GL_LINE);	// desenha arestas dos poligonos

	// Texturas a utilizar (ver classe RGBpixmap)
	myTexturas();
	
	//glClearColor (0.0, 0.0, 0.0, 0.0);

	//inicializa transf. geom. da animacao.
	myInitTransforms();
	myDLists();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize (DIMX, DIMY);
    glutInitWindowPosition (INITIALPOS_X, INITIALPOS_Y);
    //titulo da janela definido como "LAIG projecto 1"
    main_window = glutCreateWindow ("LAIG projecto 1");
    
    glutDisplayFunc(display);
    GLUI_Master.set_glutReshapeFunc(reshape);
    GLUI_Master.set_glutKeyboardFunc (keyboard);
    GLUI_Master.set_glutMouseFunc(processMouse);
    glutMotionFunc(processMouseMoved);
    glutPassiveMotionFunc(processPassiveMouseMoved);
    GLUI_Master.set_glutSpecialFunc( NULL );
   
    glutTimerFunc(mili_secs, myUpdateTransforms, 0);

    /*** Create the bottom subwindow ***/
    glui2 = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_BOTTOM );
    glui2->set_main_gfx_window( main_window );

    view_rot = glui2->add_rotation( "Rotacao", view_rotate );
    view_rot->set_spin( 1.0 );
    
    glui2->add_column( false );
    trans_z = glui2->add_translation( "Zoom", GLUI_TRANSLATION_Z, &obj_pos[2] );
    trans_z->set_speed( .02 );

	glui2->add_column( false );
	GLUI_Panel *panel_main = glui2->add_panel ("Main");
	glui2->add_checkbox_to_panel(panel_main,"Eixos",&AXIS,0,callback_checkbox);
	glui2->add_checkbox_to_panel(panel_main,"Display Lists",&USE_DISPLAY_LISTS,7,callback_checkbox);
	glui2->add_checkbox_to_panel(panel_main,"Evaluators",&EVAL,22,callback_checkbox);
	glui2->add_checkbox_to_panel(panel_main,"BackGround",&BCKG,20,callback_checkbox);

	glui2->add_column( false );
	GLUI_Panel *panel = glui2->add_panel ("Luzes");
	glui2->add_checkbox_to_panel(panel,"Holofote 1",&hol[0],1,callback_checkbox);
	glui2->add_checkbox_to_panel(panel,"Holofote 2",&hol[1],2,callback_checkbox);
	glui2->add_checkbox_to_panel(panel,"Holofote 3",&hol[2],3,callback_checkbox);
	glui2->add_checkbox_to_panel(panel,"Holofote 4",&hol[3],4,callback_checkbox);
	glui2->add_column_to_panel(panel, false );
	glui2->add_checkbox_to_panel(panel,"Letreiro",&LET,6,callback_checkbox);
	glui2->add_checkbox_to_panel(panel,"Global",&LUZ,5,callback_checkbox);
	glui2->add_checkbox_to_panel(panel,"Ambiente",&AMB,21,callback_checkbox);

	glui2->add_column( false );
	GLUI_Panel *panel2 = glui2->add_panel ("Terrenos");
	glui2->add_checkbox_to_panel(panel2,"Floresta",&ter[0],8,callback_checkbox);
	glui2->add_checkbox_to_panel(panel2,"Area Hospitalar",&ter[1],9,callback_checkbox);
	glui2->add_checkbox_to_panel(panel2,"Pista",&ter[2],10,callback_checkbox);

	glui2->add_column( false );
	GLUI_Panel *panel3 = glui2->add_panel ("Arvores");
	glui2->add_checkbox_to_panel(panel3,"Triangular 1",&arv[0],11,callback_checkbox);
	glui2->add_checkbox_to_panel(panel3,"Triangular 2",&arv[1],12,callback_checkbox);
	glui2->add_checkbox_to_panel(panel3,"Redonda 1",&arv[2],13,callback_checkbox);
	glui2->add_checkbox_to_panel(panel3,"Redonda 2",&arv[3],14,callback_checkbox);

	glui2->add_column( false );
	GLUI_Panel *panel4 = glui2->add_panel ("Edificios");
	glui2->add_checkbox_to_panel(panel4,"Hospital",&edi[0],15,callback_checkbox);
	glui2->add_checkbox_to_panel(panel4,"Letreiro",&edi[1],16,callback_checkbox);
	glui2->add_checkbox_to_panel(panel4,"Heliporto",&edi[2],17,callback_checkbox);
	glui2->add_column_to_panel(panel4, false );
	glui2->add_checkbox_to_panel(panel4,"Torre",&edi[3],18,callback_checkbox);
	glui2->add_checkbox_to_panel(panel4,"Hangar",&edi[4],19,callback_checkbox);

	glui2->add_column( false );
	glui2->add_statictext("Teclas de Atalho Activas");
	glui2->add_statictext("Camaras Disponiveis: 1, 2, 3");
	glui2->add_statictext("Pressione ENTER para");
	glui2->add_statictext("animar o Helicoptero");
	glui2->add_statictext("Ordem dos Holofotes:");
	glui2->add_statictext("1 - 3 - 4 - 2");
	

	/* We register the idle callback with GLUI, not with GLUT */
	GLUI_Master.set_glutIdleFunc( myGlutIdle );
	
	inicializacao();
   
	glutMainLoop();

	return 0;
}
