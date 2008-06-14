/***************************************************************************
 *   Copyright (C) 2008 by Ivan Dilchovski   *
 *   root.darkstar@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "ImageFeeder.h"

ImageFeeder::ImageFeeder(int _width, int _height)
{
	image = NULL;

	width = _width;
	height = _height;
}

ImageFeeder::~ImageFeeder()
{
	delete image;
}

void ImageFeeder::loadImage(QImage *_image)
{
	if(_image->isNull())
		throw Exception("NULL image provided.");
	else
	{
		
		image = _image;
		image = new QImage(image->scaled(QSize(320,240),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
	}
}

void ImageFeeder::loadImage(char* path)
{
	image = new QImage(path);
	if(image->isNull())
		throw Exception("Incorrect image path provided.");
	image = new QImage(image->scaled(QSize(320,240),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

QImage *ImageFeeder::scaleDown()
{
	if(image->isNull())
		throw Exception("Image not loaded.");
	
	image = new QImage(image->scaledToHeight((int)(image->height() / 1.33), Qt::SmoothTransformation));
	
	return image;
}

QImage *ImageFeeder::getImage()
{
	if(image->isNull())
		throw Exception("Image not loaded.");
	
	return image;
}

void ImageFeeder::createInputsFromImage(std::vector<std::vector<double> >& inputs)
{
	if(image->isNull())
		throw Exception("Image not loaded.");
	inputs.clear();
	for(unsigned int x = 1; x < (image->width() - width); x+=4)
		for(unsigned int y = 1; y < (image->height() - height); y+=4)
		{
			std::vector<double> singleImage;
			for(unsigned int j = 0; j < width; ++j)
				for(unsigned int k = 0; k < height; ++k)
					singleImage.push_back(qGray(image->pixel(j + x,k + y)));
			inputs.push_back(singleImage);
		}
}
