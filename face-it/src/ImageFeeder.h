#ifndef IMAGEFEEDER_H_
#define IMAGEFEEDER_H_

#include "exception.h"
#include <QImage>
#include <QDebug>

class ImageFeeder
{
public:
	~ImageFeeder();
	ImageFeeder(int _width, int _height);
	void loadImage(QImage *_image);
	void loadImage(char* path);
	
	QImage *scaleDown();
	QImage *getImage();
	void createInputsFromImage(std::vector<std::vector<double> >& inputs);
private:
	QImage *image;

	unsigned int width;
	unsigned int height;
};

#endif /*IMAGEFEEDER_H_*/
