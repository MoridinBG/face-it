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
	
	static const unsigned int BASE_WIDTH = 320;
	static const unsigned int BASE_HEIGHT = 240;
	static const double SCALE_FACTOR = 1.33;
	static const unsigned int STEP = 4;
};

#endif /*IMAGEFEEDER_H_*/
