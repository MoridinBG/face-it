#include "TrainingImagesWorker.h"

TrainingImagesWorker::TrainingImagesWorker(int _width, int _height)
{
	height = _height;
	width = _width;
}

TrainingImagesWorker::~TrainingImagesWorker()
{
}

void TrainingImagesWorker::createInputs()
{
 	QStringList::iterator file;
	vector<double> singleImage;

 	for(file = pathFaces.begin(); file < pathFaces.end(); ++file)
 	{
		singleImage.clear();
 		if((*file == ".") || (*file == ".."))
 			continue;
 		QImage *image = new QImage(*file);
 		if(image->isNull())
 			continue;

		for(unsigned int j = 0; j < width; ++j)
			for(unsigned int k = 0; k < height; ++k)
				singleImage.push_back(qGray(image->pixel(j ,k)));
		faces.push_back(singleImage);

 	}

 	for(file = pathNonFaces.begin(); file < pathNonFaces.end(); ++file)
 	{
		singleImage.clear();		
 		if((*file == ".") || (*file == ".."))
 			continue;
 		QImage *image = new QImage(*file);
 		if(image->isNull())
 			continue;

		for(unsigned int j = 0; j < width; ++j)
			for(unsigned int k = 0; k < height; ++k)
				singleImage.push_back(qGray(image->pixel(j ,k)));

		nonFaces.push_back(singleImage);

 	}
}


void TrainingImagesWorker::divideUntrainedImages()
{
	faces.insert(faces.begin(), untrainedFaces.begin(), untrainedFaces.end());
	nonFaces.insert(nonFaces.begin(), untrainedNonFaces.begin(), untrainedNonFaces.end());
	
 	untrainedFaces.clear();
 	untrainedNonFaces.clear();

	unsigned int controlFaces = faces.size() / 10;
	unsigned int controlNonFaces = nonFaces.size() / 10;

	if(controlFaces == 0)
		++controlFaces;
	if(controlNonFaces == 0)
		++controlNonFaces;
	
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

void TrainingImagesWorker::setFaces(QStringList _pathFaces)
{
	pathFaces = _pathFaces;
}

void TrainingImagesWorker::setNonFaces(QStringList _pathNonFaces)
{
	pathNonFaces = _pathNonFaces;
}

void TrainingImagesWorker::load() throw( Exception )
{
	if(pathFaces.size() == 0)
		throw Exception("List of faces is empty.");

	if(pathNonFaces.size() == 0)
		throw Exception("List of NonFaces is empty.");

	createInputs();
	divideUntrainedImages();
}


const vector< vector < double > >& TrainingImagesWorker::getFaces() const
{
	return faces;
}


const vector< vector < double > >& TrainingImagesWorker::getNonFaces() const
{
	return nonFaces;
}


const vector< vector < double > >& TrainingImagesWorker::getUntrainedFaces() const
{
	return untrainedFaces;
}


const vector< vector < double > >& TrainingImagesWorker::getUntrainedNonFaces() const
{
	return untrainedNonFaces;
}
