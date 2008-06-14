#ifndef IMAGEPREPARER_H_
#define IMAGEPREPARER_H_

#include <vector>
#include <QImage>
#include <QDir>
#include <QStringList>
#include <QDebug>

#include "exception.h"

using namespace std;

class TrainingImagesWorker
{
public:
	TrainingImagesWorker(int _width, int _height);
	virtual ~TrainingImagesWorker();

	void load() throw (Exception);
	
	void setFaces(QStringList _faces);
	void setNonFaces(QStringList _nonFaces);

	const vector< vector < double > >& getFaces() const;
	const vector< vector < double > >& getNonFaces() const;
	const vector< vector < double > >& getUntrainedFaces() const;
	const vector< vector < double > >& getUntrainedNonFaces() const;
private:
	vector<vector<double> > faces;
	vector<vector<double> > nonFaces;
	vector<vector<double> > untrainedFaces;
	vector<vector<double> > untrainedNonFaces;

	QStringList pathFaces;
	QStringList pathNonFaces;

	unsigned int width;
	unsigned int height;

	void createInputs();
	void divideUntrainedImages();
};

#endif /*IMAGEPREPARER_H_*/
