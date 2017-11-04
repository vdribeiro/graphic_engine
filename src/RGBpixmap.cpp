
#include <GL\glui.h>
#include "RGBpixmap.h"
#include <fstream>

FILE *inf;



void RGBpixmap::setTexture(GLuint textureName)
{
	glBindTexture(GL_TEXTURE_2D, textureName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, nCols, nRows, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel);
}

unsigned short getShort()
{
	char ic;
	unsigned short ip;

	ic = getc(inf); ip = ic;
	ic = getc(inf); ip |= ((unsigned short)ic << 8);
	
	return ip;
}

unsigned long getLong()
{
	unsigned long ip=0;
	char ic=0;
	unsigned char uc = ic;

	ic = getc(inf);	uc = ic;	ip = uc;
	ic = getc(inf);	uc = ic;	ip |= ((unsigned long)uc << 8);
	ic = getc(inf);	uc = ic;	ip |= ((unsigned long)uc << 16);
	ic = getc(inf);	uc = ic;	ip |= ((unsigned long)uc << 24);

	return ip;
}


int RGBpixmap::readBMPFile(char * fname)
{
	int k, row, col, numPadBytes, nBytesInRow, count;
	char c1, c2, dum, r, g, b;
	unsigned long fileSize, offBits, headerSize, numCols, numRows, compression, imageSize;
	unsigned long xPels, yPels, numLUTentries, impColors;
	unsigned short reserved, planes, bitsPerPixel;

	inf = fopen(fname, "r+b");
	if (inf == NULL)
		return 0;
	
	// le header "BMP"
	c1 = getc(inf);	c2 = getc(inf);
	printf("Cabecalho:%c%c\n",c1,c2);

	fileSize = getLong();
	reserved = getShort();	// sempre 0
	reserved = getShort();	// sempre 0
	offBits = getLong();	// offset ate a imagem
	headerSize = getLong(); // sempre 40
	numCols = getLong();
	numRows = getLong();
	printf("headersize:%d  rows=%d  cols=%d\n",headerSize, numRows, numCols);
	
	planes = getShort();	// sempre 1
	bitsPerPixel = getShort();	// 8 ou 24
	compression = getLong();
	imageSize = getLong();
	xPels = getLong();
	yPels = getLong();
	numLUTentries = getLong();
	impColors = getLong();

	if (bitsPerPixel != 24)
	{	printf("A image nao e de 24 bits por pixel!\n");
		fclose(inf);
		return 0;
	}

	nBytesInRow = ((3*numCols+3)/4)*4;
	numPadBytes = nBytesInRow - 3 * numCols;
	nRows = numRows;
	nCols = numCols;

	pixel = new RGBmap[3 * nRows * nCols];
	if (!pixel)
	{	printf("Erro a reservar memoria!");
		return 0;
	}
	count = 0;

	for(row=0; row<nRows; row++)
	{
		for(col=0; col<nCols; col++)
		{
			b = getc(inf);	g = getc(inf);	r = getc(inf);
            pixel[count].r = r;
			pixel[count].g = g;
			pixel[count++].b = b;
		}
		for(k=0; k<numPadBytes; k++)
			dum = fgetc(inf);
	}

	fclose(inf);

	return 1;	
}