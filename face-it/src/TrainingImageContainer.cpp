#include "TrainingImageContainer.h"

TrainingImageContainer::TrainingImageContainer()
{
}

TrainingImageContainer::~TrainingImageContainer()
{
}

void TrainingImageContainer::createInputs()
{
 	QStringList::iterator file;
	vector<double> singleImage;
	QImage image;

 	for(file = pathFaces.begin(); file < pathFaces.end(); ++file)
 	{
		singleImage.clear();
 		if((*file == ".") || (*file == ".."))
 			continue;
		
		QImage image(*file);

 		if(image.isNull())
 			continue;
		
		applyMask(image);
		for(unsigned int j = 0; j < width; ++j)
			for(unsigned int k = 0; k < height; ++k)
				singleImage.push_back(qGray(image.pixel(j ,k)));
		faces.push_back(singleImage);

 	}

 	for(file = pathNonFaces.begin(); file < pathNonFaces.end(); ++file)
 	{
		singleImage.clear();		
 		if((*file == ".") || (*file == ".."))
 			continue;

		QImage image(*file);
		
 		if(image.isNull())
 			continue;
		
		applyMask(image);
		for(unsigned int j = 0; j < width; ++j)
			for(unsigned int k = 0; k < height; ++k)
				singleImage.push_back(qGray(image.pixel(j ,k)));

		nonFaces.push_back(singleImage);

 	}
}


void TrainingImageContainer::divideUntrainedImages()
{
	unsigned int controlFaces = faces.size() / 10;
	unsigned int controlNonFaces = nonFaces.size() / 10;
	
 	for(unsigned int i = 0; i < controlFaces; i++)
 	{
 		int position = rand() % faces.size();
 		untrainedFaces.push_back(faces.at(position));
 		faces.erase(faces.begin() + position);
 	}
 	
 	for(unsigned int i = 0; i < controlNonFaces; i++)
 	{
 		int position = rand() % nonFaces.size();
 		untrainedNonFaces.push_back(nonFaces.at(position));
 		nonFaces.erase(nonFaces.begin() + position);
 	}
}

void TrainingImageContainer::setFaces(QStringList _pathFaces)
{
	pathFaces = _pathFaces;
}

void TrainingImageContainer::setNonFaces(QStringList _pathNonFaces)
{
	pathNonFaces = _pathNonFaces;
}

void TrainingImageContainer::load() throw( Exception )
{
	if(pathFaces.size() == 0)
		throw Exception("List of faces is empty.");

	if(pathNonFaces.size() == 0)
		throw Exception("List of NonFaces is empty.");

	createInputs();
	divideUntrainedImages();
}


const vector< vector < double > >& TrainingImageContainer::getFaces() const
{
	return faces;
}


const vector< vector < double > >& TrainingImageContainer::getNonFaces() const
{
	return nonFaces;
}


const vector< vector < double > >& TrainingImageContainer::getUntrainedFaces() const
{
	return untrainedFaces;
}


const vector< vector < double > >& TrainingImageContainer::getUntrainedNonFaces() const
{
	return untrainedNonFaces;
}

void TrainingImageContainer::applyMask(QImage& image)
{
	int k = 0;
	for(int i = (image.height() - MASK_SIDE); i < image.height(); ++i)
	{
		++k;
		for(int j = 0; j < k; ++j)
			image.setPixel(j,i,4278190080);
	}
	
	k = 0;
	for(int i = (image.height() - MASK_SIDE); i < image.height(); ++i)
	{
		++k;
		for(int j = image.width() - k; j < image.width(); ++j)
			image.setPixel(j,i,4278190080);
	}
}

void TrainingImageContainer::setRanges(unsigned int _width, unsigned int _height)
{
	width = _width;
	height = _height;
}
