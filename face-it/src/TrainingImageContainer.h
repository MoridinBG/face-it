#ifndef IMAGEPREPARER_H_
#define IMAGEPREPARER_H_

#include <vector>
#include <QImage>
#include <QDir>
#include <QStringList>

#include "exception.h"

using namespace std;

class TrainingImageContainer
{
public:
	TrainingImageContainer();
	virtual ~TrainingImageContainer();

	void load() throw (Exception);
	
	void setRanges(unsigned int _width,
		       unsigned int _height);
	void setFaces(QStringList _faces);
	void setNonFaces(QStringList _nonFaces);
	void applyMask(QImage& image);

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
	
	static const unsigned int MASK_SIDE = 6;

	void createInputs();
	void divideUntrainedImages();
};

#endif /*IMAGEPREPARER_H_*/
