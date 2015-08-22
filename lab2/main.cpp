#include "Framework/DrawingWindow.h"
#include "Framework/Visual2D.h"
#include "Framework/Transform2D.h"
#include "Framework/Transform3D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include <iostream>
#include <windows.h>
#include <vector>

#define PI 3.14159265358979323846
#define inf 1000000
using namespace std;

Visual2D *v2d1, *v2d2;
Object3D *cube11,*cube21,*cube31,*cube12,*cube22,*cube32;

vector <Object3D*> patrate;

int liniicoloane=10;
int centru=-(liniicoloane/2.5+liniicoloane/3);
int linii=floor(sqrt(liniicoloane)), coloane= floor(sqrt(liniicoloane));;


float n=1.8;

Point3D* getPoints(Object3D *obj)
{

	Point3D *center = new Point3D(0,0,0);


	for(int i = 0; i < (int)obj->transf_vertices.size(); i++)
	{
		center->x += obj->transf_vertices[i]->x;
		center->y += obj->transf_vertices[i]->y;
		center->z += obj->transf_vertices[i]->z;
	}	
	center->x/=obj->vertices.size();
	center->y/=obj->vertices.size();
	center->z/=obj->vertices.size();
	return center;
}

void fa_patrate_mici(vector <Point3D*> &vertices,	vector <Face*> &faces){
	//varfurile de jos
	vertices.push_back(new Point3D(0,0,0));
	vertices.push_back(new Point3D(n,0,0));
	vertices.push_back(new Point3D(n,0,-n/10));
	vertices.push_back(new Point3D(0,0,-n/10));
	//varfurile de sus
	vertices.push_back(new Point3D(0,n,0));
	vertices.push_back(new Point3D(n,n,0));
	vertices.push_back(new Point3D(n,n,-n/10));
	vertices.push_back(new Point3D(0,n,-n/10));

	//cele 6 fete
	vector <int> contour;
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

}

void fa_patrate(vector <Point3D*> &vertices,	vector <Face*> &faces, int nivel ){
	//varfurile de jos
	float m=nivel*n;
	vertices.push_back(new Point3D(0+m,0+m,0+m));
	vertices.push_back(new Point3D(n+m,0+m,0+m));
	vertices.push_back(new Point3D(n+m,0+m,n+m));
	vertices.push_back(new Point3D(0+m,0+m,n+m));
	//varfurile de sus
	vertices.push_back(new Point3D(0+m,n+m,0+m));
	vertices.push_back(new Point3D(n+m,n+m,0+m));
	vertices.push_back(new Point3D(n+m,n+m,n+m));
	vertices.push_back(new Point3D(0+m,n+m,n+m));


	//cele 6 fete
	vector <int> contour;

	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

}

void fa_drum(vector <Point3D*> &vertices,	vector <Face*> &faces, int nivel,int directie,int linii,int coloane,float centru)
{
	cout<<directie;
	if (directie % 2==0)
	{
		//varfurile de jos
		vertices.clear();
		vertices.push_back(new Point3D(0,0,0));
		vertices.push_back(new Point3D(n/7,0,0));
		vertices.push_back(new Point3D(n/7,0,+n/10.5));
		vertices.push_back(new Point3D(0,0,+n/10.5));
		//varfurile de sus
		vertices.push_back(new Point3D(0,n,0));
		vertices.push_back(new Point3D(n/7,n,0));
		vertices.push_back(new Point3D(n/7,n,+n/10.5));
		vertices.push_back(new Point3D(0,n,+n/10.5));

		//cele 6 fete
		vector <int> contour;
		//fata jos
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(3);
		faces.push_back(new Face(contour));
		//fata sus
		contour.clear();
		contour.push_back(4);
		contour.push_back(5);
		contour.push_back(6);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		//fata fata
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(5);
		contour.push_back(4);
		faces.push_back(new Face(contour));
		//fata dreapta
		contour.clear();
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(6);
		contour.push_back(5);
		faces.push_back(new Face(contour));
		//fata spate
		contour.clear();
		contour.push_back(2);
		contour.push_back(3);
		contour.push_back(7);
		contour.push_back(6);
		faces.push_back(new Face(contour));
		//fata stanga
		contour.clear();
		contour.push_back(3);
		contour.push_back(0);
		contour.push_back(4);
		contour.push_back(7);
		faces.push_back(new Face(contour));


		patrate.push_back( new Object3D(vertices,faces,Color(0.721569, 0.52549 ,0.0431373),true));
		DrawingWindow::addObject3D(patrate.back());

		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());

		//varfurile de jos
		vertices.clear();
		vertices.push_back(new Point3D(n*6/7,0,0));
		vertices.push_back(new Point3D(n,0,0));
		vertices.push_back(new Point3D(n,0,+n/10.5));
		vertices.push_back(new Point3D(n*6/7,0,+n/10.5));
		//varfurile de sus
		vertices.push_back(new Point3D(n*6/7,n,0));
		vertices.push_back(new Point3D(n,n,0));
		vertices.push_back(new Point3D(n,n,+n/10.5));
		vertices.push_back(new Point3D(n*6/7,n,+n/10.5));

		//cele 6 fete
		//vector <int> contour;
		//fata jos
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(3);
		faces.push_back(new Face(contour));
		//fata sus
		contour.clear();
		contour.push_back(4);
		contour.push_back(5);
		contour.push_back(6);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		//fata fata
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(5);
		contour.push_back(4);
		faces.push_back(new Face(contour));
		//fata dreapta
		contour.clear();
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(6);
		contour.push_back(5);
		faces.push_back(new Face(contour));
		//fata spate
		contour.clear();
		contour.push_back(2);
		contour.push_back(3);
		contour.push_back(7);
		contour.push_back(6);
		faces.push_back(new Face(contour));
		//fata stanga
		contour.clear();
		contour.push_back(3);
		contour.push_back(0);
		contour.push_back(4);
		contour.push_back(7);
		faces.push_back(new Face(contour));


		patrate.push_back( new Object3D(vertices,faces,Color(0.721569, 0.52549, 0.0431373),true));
		DrawingWindow::addObject3D(patrate.back());

		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());


		//varfurile de jos
		vertices.clear();
		vertices.push_back(new Point3D(n/7,0,0));
		vertices.push_back(new Point3D(n*6/7,0,0));
		vertices.push_back(new Point3D(n*6/7,0,+n/10));
		vertices.push_back(new Point3D(n/7,0,+n/10));
		//varfurile de sus
		vertices.push_back(new Point3D(n/7,n,0));
		vertices.push_back(new Point3D(n*6/7,n,0));
		vertices.push_back(new Point3D(n*6/7,n,+n/10));
		vertices.push_back(new Point3D(n/7,n,+n/10));

		//cele 6 fete
		//vector <int> contour;
		//fata jos
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(3);
		faces.push_back(new Face(contour));
		//fata sus
		contour.clear();
		contour.push_back(4);
		contour.push_back(5);
		contour.push_back(6);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		//fata fata
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(5);
		contour.push_back(4);
		faces.push_back(new Face(contour));
		//fata dreapta
		contour.clear();
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(6);
		contour.push_back(5);
		faces.push_back(new Face(contour));
		//fata spate
		contour.clear();
		contour.push_back(2);
		contour.push_back(3);
		contour.push_back(7);
		contour.push_back(6);
		faces.push_back(new Face(contour));
		//fata stanga
		contour.clear();
		contour.push_back(3);
		contour.push_back(0);
		contour.push_back(4);
		contour.push_back(7);
		faces.push_back(new Face(contour));

		patrate.push_back( new Object3D(vertices,faces,Color( 0.2, 0.2, 0.2),true));
		DrawingWindow::addObject3D(patrate.back());

		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());

		//varfurile de jos
		vertices.clear();
		vertices.push_back(new Point3D(n*5/11,0,0));
		vertices.push_back(new Point3D(n*6/11,0,0));
		vertices.push_back(new Point3D(n*5/11,0,+n/9.99));
		vertices.push_back(new Point3D(n*6/11,0,+n/9.99));
		//varfurile de sus
		vertices.push_back(new Point3D(n*5/11,n,0));
		vertices.push_back(new Point3D(n*6/11,n,0));
		vertices.push_back(new Point3D(n*6/11,n,+n/9.99));
		vertices.push_back(new Point3D(n*5/11,n,+n/9.99));

		//cele 6 fete
		//vector <int> contour;
		//fata jos
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(3);
		faces.push_back(new Face(contour));
		//fata sus
		contour.clear();
		contour.push_back(4);
		contour.push_back(5);
		contour.push_back(6);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		//fata fata
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(5);
		contour.push_back(4);
		faces.push_back(new Face(contour));
		//fata dreapta
		contour.clear();
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(6);
		contour.push_back(5);
		faces.push_back(new Face(contour));
		//fata spate
		contour.clear();
		contour.push_back(2);
		contour.push_back(3);
		contour.push_back(7);
		contour.push_back(6);
		faces.push_back(new Face(contour));
		//fata stanga
		contour.clear();
		contour.push_back(3);
		contour.push_back(0);
		contour.push_back(4);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		patrate.push_back( new Object3D(vertices,faces,Color( .839216 ,0.839216 ,0.839216),true));
		DrawingWindow::addObject3D(patrate.back());


		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());
	}
	else{
		//varfurile de jos
		cout<<"aici"<<endl;
		vertices.clear();
		vertices.push_back(new Point3D(n/7,0,0));//2
		vertices.push_back(new Point3D(n/7,n,0));//6
		vertices.push_back(new Point3D(n/7,n,+n/10.5));//7
		vertices.push_back(new Point3D(n/7,0,+n/10.5));//3
		vertices.push_back(new Point3D(0,0,0));//1
		vertices.push_back(new Point3D(0,n,0));//5
		vertices.push_back(new Point3D(0,n,+n/10.5));//8
		vertices.push_back(new Point3D(0,0,+n/10.5));//4
		//cele 6 fete
		vector <int> contour;
		//fata jos
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(3);
		faces.push_back(new Face(contour));
		//fata sus
		contour.clear();
		contour.push_back(4);
		contour.push_back(5);
		contour.push_back(6);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		//fata fata
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(5);
		contour.push_back(4);
		faces.push_back(new Face(contour));
		//fata dreapta
		contour.clear();
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(6);
		contour.push_back(5);
		faces.push_back(new Face(contour));
		//fata spate
		contour.clear();
		contour.push_back(2);
		contour.push_back(3);
		contour.push_back(7);
		contour.push_back(6);
		faces.push_back(new Face(contour));
		//fata stanga
		contour.clear();
		contour.push_back(3);
		contour.push_back(0);
		contour.push_back(4);
		contour.push_back(7);
		faces.push_back(new Face(contour));


		patrate.push_back( new Object3D(vertices,faces,Color(0.721569, 0.52549 ,0.0431373),true));
		DrawingWindow::addObject3D(patrate.back());


		Point3D *centru2=new Point3D(0,0,0);
		centru2=getPoints(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(0,-centru2->y,-centru2->z);
		Transform3D::rotateMatrixOz(PI/2);
		Transform3D::translateMatrix(centru2->y,0,centru2->z);
		Transform3D::applyTransform(patrate.back());
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());


		//varfurile de jos
		vertices.clear();
		vertices.push_back(new Point3D(n*6/7,0,0));
		vertices.push_back(new Point3D(n,0,0));
		vertices.push_back(new Point3D(n,0,+n/10.5));
		vertices.push_back(new Point3D(n*6/7,0,+n/10.5));
		//varfurile de sus
		vertices.push_back(new Point3D(n*6/7,n,0));
		vertices.push_back(new Point3D(n,n,0));
		vertices.push_back(new Point3D(n,n,+n/10.5));
		vertices.push_back(new Point3D(n*6/7,n,+n/10.5));

		//cele 6 fete
		//vector <int> contour;
		//fata jos
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(3);
		faces.push_back(new Face(contour));
		//fata sus
		contour.clear();
		contour.push_back(4);
		contour.push_back(5);
		contour.push_back(6);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		//fata fata
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(5);
		contour.push_back(4);
		faces.push_back(new Face(contour));
		//fata dreapta
		contour.clear();
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(6);
		contour.push_back(5);
		faces.push_back(new Face(contour));
		//fata spate
		contour.clear();
		contour.push_back(2);
		contour.push_back(3);
		contour.push_back(7);
		contour.push_back(6);
		faces.push_back(new Face(contour));
		//fata stanga
		contour.clear();
		contour.push_back(3);
		contour.push_back(0);
		contour.push_back(4);
		contour.push_back(7);
		faces.push_back(new Face(contour));


		patrate.push_back( new Object3D(vertices,faces,Color(0.721569, 0.52549, 0.0431373),true));
		DrawingWindow::addObject3D(patrate.back());
		//		Point3D *centru2=new Point3D(0,0,0);
		centru2=getPoints(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(0,-centru2->y,-centru2->z);
		Transform3D::rotateMatrixOz(PI/2);
		Transform3D::translateMatrix(centru2->y,0,centru2->z);
		Transform3D::applyTransform(patrate.back());
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());


		//varfurile de jos
		vertices.clear();
		vertices.push_back(new Point3D(n/7,0,0));
		vertices.push_back(new Point3D(n*6/7,0,0));
		vertices.push_back(new Point3D(n*6/7,0,+n/10));
		vertices.push_back(new Point3D(n/7,0,+n/10));
		//varfurile de sus
		vertices.push_back(new Point3D(n/7,n,0));
		vertices.push_back(new Point3D(n*6/7,n,0));
		vertices.push_back(new Point3D(n*6/7,n,+n/10));
		vertices.push_back(new Point3D(n/7,n,+n/10));

		//cele 6 fete
		//vector <int> contour;
		//fata jos
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(3);
		faces.push_back(new Face(contour));
		//fata sus
		contour.clear();
		contour.push_back(4);
		contour.push_back(5);
		contour.push_back(6);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		//fata fata
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(5);
		contour.push_back(4);
		faces.push_back(new Face(contour));
		//fata dreapta
		contour.clear();
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(6);
		contour.push_back(5);
		faces.push_back(new Face(contour));
		//fata spate
		contour.clear();
		contour.push_back(2);
		contour.push_back(3);
		contour.push_back(7);
		contour.push_back(6);
		faces.push_back(new Face(contour));
		//fata stanga
		contour.clear();
		contour.push_back(3);
		contour.push_back(0);
		contour.push_back(4);
		contour.push_back(7);
		faces.push_back(new Face(contour));

		patrate.push_back( new Object3D(vertices,faces,Color( 0.2, 0.2, 0.2),true));
		DrawingWindow::addObject3D(patrate.back());
		//		Point3D *centru2=new Point3D(0,0,0);
		centru2=getPoints(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(0,-centru2->y,-centru2->z);
		Transform3D::rotateMatrixOz(PI/2);
		Transform3D::translateMatrix(centru2->y,0,centru2->z);
		Transform3D::applyTransform(patrate.back());
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());

		//varfurile de jos
		vertices.clear();
		vertices.push_back(new Point3D(n*5/11,0,0));
		vertices.push_back(new Point3D(n*6/11,0,0));
		vertices.push_back(new Point3D(n*5/11,0,+n/9.99));
		vertices.push_back(new Point3D(n*6/11,0,+n/9.99));
		//varfurile de sus
		vertices.push_back(new Point3D(n*5/11,n,0));
		vertices.push_back(new Point3D(n*6/11,n,0));
		vertices.push_back(new Point3D(n*6/11,n,+n/9.99));
		vertices.push_back(new Point3D(n*5/11,n,+n/9.99));

		//cele 6 fete
		//vector <int> contour;
		//fata jos
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(3);
		faces.push_back(new Face(contour));
		//fata sus
		contour.clear();
		contour.push_back(4);
		contour.push_back(5);
		contour.push_back(6);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		//fata fata
		contour.clear();
		contour.push_back(0);
		contour.push_back(1);
		contour.push_back(5);
		contour.push_back(4);
		faces.push_back(new Face(contour));
		//fata dreapta
		contour.clear();
		contour.push_back(1);
		contour.push_back(2);
		contour.push_back(6);
		contour.push_back(5);
		faces.push_back(new Face(contour));
		//fata spate
		contour.clear();
		contour.push_back(2);
		contour.push_back(3);
		contour.push_back(7);
		contour.push_back(6);
		faces.push_back(new Face(contour));
		//fata stanga
		contour.clear();
		contour.push_back(3);
		contour.push_back(0);
		contour.push_back(4);
		contour.push_back(7);
		faces.push_back(new Face(contour));
		patrate.push_back( new Object3D(vertices,faces,Color( .839216 ,0.839216 ,0.839216),true));
		DrawingWindow::addObject3D(patrate.back());
		//		Point3D *centru2=new Point3D(0,0,0);
		centru2=getPoints(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(0,-centru2->y,-centru2->z);
		Transform3D::rotateMatrixOz(PI/2);
		Transform3D::translateMatrix(centru2->y,0,centru2->z);
		Transform3D::applyTransform(patrate.back());
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());
	}

	patrate.pop_back();
	patrate.pop_back();
	patrate.pop_back();
	patrate.pop_back();
}

void fa_apa(vector <Point3D*> &vertices,	vector <Face*> &faces, int nivel,int linii,int coloane,float centru)
{
	//varfurile de jos
	vertices.push_back(new Point3D(0,0,0));
	vertices.push_back(new Point3D(n,0,0));
	vertices.push_back(new Point3D(n,0,n/12));
	vertices.push_back(new Point3D(0,0,n/12));
	//varfurile de sus
	vertices.push_back(new Point3D(0,n,0));
	vertices.push_back(new Point3D(n,n,0));
	vertices.push_back(new Point3D(n,n,n/12));
	vertices.push_back(new Point3D(0,n,n/12));

	//cele 6 fete
	vector <int> contour;
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color(0, 0, 0.545098),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.push_back( new Object3D(vertices,faces,Color(0.133333, 0.1, 0.133333),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

}

void fa_iarba(vector <Point3D*> &vertices,	vector <Face*> &faces, int nivel,int linii,int coloane,float centru)
{
	//varfurile de jos
	vertices.push_back(new Point3D(0,0,0));
	vertices.push_back(new Point3D(n,0,0));
	vertices.push_back(new Point3D(n,0,n/8));
	vertices.push_back(new Point3D(0,0,n/8));
	//varfurile de sus
	vertices.push_back(new Point3D(0,n,0));
	vertices.push_back(new Point3D(n,n,0));
	vertices.push_back(new Point3D(n,n,n/8));
	vertices.push_back(new Point3D(0,n,n/8));

	//cele 6 fete
	vector <int> contour;
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color(0.133333, 0.545098, 0.133333),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());

	patrate.push_back( new Object3D(vertices,faces,Color(0.133333, 0.1, 0.133333),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();
}

void fa_piata(vector <Point3D*> &vertices,	vector <Face*> &faces, int nivel,int linii,int coloane,float centru)
{
	//varfurile de jos
	vertices.push_back(new Point3D(0,0,0));
	vertices.push_back(new Point3D(n,0,0));
	vertices.push_back(new Point3D(n,0,n/8));
	vertices.push_back(new Point3D(0,0,n/8));
	//varfurile de sus
	vertices.push_back(new Point3D(0,n,0));
	vertices.push_back(new Point3D(n,n,0));
	vertices.push_back(new Point3D(n,n,n/8));
	vertices.push_back(new Point3D(0,n,n/8));

	//cele 6 fete
	vector <int> contour;
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color(0.839216, 0.839216, 0.839216),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	//______________________________________________________________________________________
	vertices.clear();
	vertices.push_back(new Point3D(n/5,n/5,0));
	vertices.push_back(new Point3D(4*n/5,n/5,0));
	vertices.push_back(new Point3D(4*n/5,n/5,n*3));
	vertices.push_back(new Point3D(n/5,n/5,n*3));
	//varfurile de sus
	vertices.push_back(new Point3D(n/5,4*n/5,0));
	vertices.push_back(new Point3D(4*n/5,4*n/5,0));
	vertices.push_back(new Point3D(4*n/5,4*n/5,n*3));
	vertices.push_back(new Point3D(n/5,4*n/5,n*3));

	//cele 6 fete

	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	//Stalp totemic
	patrate.push_back( new Object3D(vertices,faces,Color(0.6941176 ,0.895 ,1),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());

	patrate.push_back( new Object3D(vertices,faces,Color(0.1176 ,0.1 ,0.1),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());



	vertices.clear();
	vertices.push_back(new Point3D(0,0,0));
	vertices.push_back(new Point3D(n,0,0));
	vertices.push_back(new Point3D(n,0,n/7));
	vertices.push_back(new Point3D(0,0,n/7));
	//varfurile de sus
	vertices.push_back(new Point3D(0,n,0));
	vertices.push_back(new Point3D(n,n,0));
	vertices.push_back(new Point3D(n,n,n/7));
	vertices.push_back(new Point3D(0,n,n/7));

	//cele 6 fete
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	//Drumuri spre stalp
	//__________________________________________________________________________________________
	patrate.push_back( new Object3D(vertices,faces,Color(0.772549 ,0.756863, 0.666667),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+1+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	//_____________________________________________________________________________________________
	patrate.push_back( new Object3D(vertices,faces,Color(0.772549 ,0.756863, 0.666667),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+2+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	//_____________________________________________________________________________________________
	patrate.push_back( new Object3D(vertices,faces,Color(0.772549 ,0.756863, 0.666667),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii-1+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	//_______________________________________________________________________________________________
	patrate.push_back( new Object3D(vertices,faces,Color(0.772549 ,0.756863, 0.666667),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii-2+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());

	//__________________________________________________________________________________________
	patrate.push_back( new Object3D(vertices,faces,Color(0.772549 ,0.756863, 0.666667),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+1+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	//_____________________________________________________________________________________________
	patrate.push_back( new Object3D(vertices,faces,Color(0.772549 ,0.756863, 0.666667),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+2+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	//_____________________________________________________________________________________________
	patrate.push_back( new Object3D(vertices,faces,Color(0.772549 ,0.756863, 0.666667),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane-1+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	//_______________________________________________________________________________________________
	patrate.push_back( new Object3D(vertices,faces,Color(0.772549 ,0.756863, 0.666667),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane-2+centru)*n,0);
	Transform3D::applyTransform(patrate.back());


	////APA

	vector <Point3D*> verticesapa;
	vector <Face*> facesapa;
	fa_apa(verticesapa,facesapa,0,linii-1,coloane-1,centru);
	fa_apa(verticesapa,facesapa,0,linii-1,coloane+1,centru);
	fa_apa(verticesapa,facesapa,0,linii+1,coloane-1,centru);
	fa_apa(verticesapa,facesapa,0,linii+1,coloane+1,centru);

	//Fan
	vector <Point3D*> verticesiarba;
	vector <Face*> facesiarba;
	fa_iarba(verticesiarba,facesiarba,0,linii-2,coloane-2,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii-2,coloane-1,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii-2,coloane+1,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii-2,coloane+2,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii-1,coloane-2,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii-1,coloane+2,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii+1,coloane-2,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii+1,coloane+2,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii+2,coloane-2,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii+2,coloane-1,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii+2,coloane+1,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii+2,coloane+2,centru);



}

void fa_iarba_copac(vector <Point3D*> &vertices,	vector <Face*> &faces, int nivel,int linii,int coloane,float centru)
{

	vector <Point3D*> verticesiarba;
	vector <Face*> facesiarba;
	fa_iarba(verticesiarba,facesiarba,0,linii,coloane,centru);

	vertices.clear();
	vertices.push_back(new Point3D(n/3,n/3,0));
	vertices.push_back(new Point3D(2*n/3,n/3,0));
	vertices.push_back(new Point3D(2*n/3,n/3,n));
	vertices.push_back(new Point3D(n/3,n/3,n));
	//varfurile de sus
	vertices.push_back(new Point3D(n/3,2*n/3,0));
	vertices.push_back(new Point3D(2*n/3,2*n/3,0));
	vertices.push_back(new Point3D(2*n/3,2*n/3,n));
	vertices.push_back(new Point3D(n/3,2*n/3,n));

	//cele 6 fete
	vector <int> contour;
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color(0.545098 ,0.270588, 0.0745098),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.push_back( new Object3D(vertices,faces,Color(0.137, 0.1 ,0.17),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());


	vertices.clear();
	vertices.push_back(new Point3D(n/5,n/5,n));
	vertices.push_back(new Point3D(4*n/5,n/5,n));
	vertices.push_back(new Point3D(4*n/5,n/5,n*2));
	vertices.push_back(new Point3D(n/5,n/5,n*2));
	//varfurile de sus
	vertices.push_back(new Point3D(n/5,4*n/5,n));
	vertices.push_back(new Point3D(4*n/5,4*n/5,n));
	vertices.push_back(new Point3D(4*n/5,4*n/5,n*2));
	vertices.push_back(new Point3D(n/5,4*n/5,n*2));

	//cele 6 fete
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color(0.180392 ,0.545098, 0.341176),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());


	patrate.push_back( new Object3D(vertices,faces,Color(0,0,0),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());


}

void fa_casa(vector <Point3D*> &vertices,	vector <Face*> &faces, int nivel,int directie,int linii,int coloane,float centru)

{
	//CASA

	//varfurile de jos
	vertices.push_back(new Point3D(0,0,0));
	vertices.push_back(new Point3D(n,0,0));
	vertices.push_back(new Point3D(n,0,n*1.174));
	vertices.push_back(new Point3D(0,0,n*1.174));
	//varfurile de sus
	vertices.push_back(new Point3D(0,n/1.01,0));
	vertices.push_back(new Point3D(n,n/1.01,0));
	vertices.push_back(new Point3D(n,n/1.01,n));
	vertices.push_back(new Point3D(0,n/1.01,n));

	//cele 6 fete
	vector <int> contour;
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color( 0.823529, 0.705882 ,0.54902),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	patrate.push_back( new Object3D(vertices,faces,Color( 0.803922, 0.360784 ,0.360784),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();




	//USA
	//________________________________________________________________________________________________
	//varfurile de jos
	vertices.clear();
	vertices.push_back(new Point3D(n*5/6,n/2,0));
	vertices.push_back(new Point3D(n/1.01,n/2,0));
	vertices.push_back(new Point3D(n/1.01,n/2,n/3));
	vertices.push_back(new Point3D(n*5/6,n/2,n/3));
	//varfurile de sus
	vertices.push_back(new Point3D(n*5/6,n,0));
	vertices.push_back(new Point3D(n/1.01,n,0));
	vertices.push_back(new Point3D(n/1.01,n,n/3));
	vertices.push_back(new Point3D(n*5/6,n,n/3));

	//cele 6 fete
	//	vector <int> contour;
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color( 0.647059, 0.164706, 0.164706),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	patrate.push_back( new Object3D(vertices,faces,Color( 0.803922, 0.60784 ,0.60784),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();


	//GEAMURI 
	//_______________________________________________________________________________________________
	//varfurile de jos
	vertices.clear();
	vertices.push_back(new Point3D(n*2/6,n/2,n/3));
	vertices.push_back(new Point3D(n*3/6,n/2,n/3));
	vertices.push_back(new Point3D(n*3/6,n/2,n*2/3));
	vertices.push_back(new Point3D(n*2/6,n/2,n*2/3));
	//varfurile de sus
	vertices.push_back(new Point3D(n*2/6,n,n/3));
	vertices.push_back(new Point3D(n*3/6,n,n/3));
	vertices.push_back(new Point3D(n*3/6,n,n*2/3));
	vertices.push_back(new Point3D(n*2/6,n,n*2/3));

	//cele 6 fete
	//vector <int> contour;
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color( 0, 0.2 ,0.9),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	patrate.push_back( new Object3D(vertices,faces,Color( 0, 0,0.60784),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	//varfurile de jos
	vertices.clear();
	vertices.push_back(new Point3D(n*4/7,n/2,n/3));
	vertices.push_back(new Point3D(n*5/7,n/2,n/3));
	vertices.push_back(new Point3D(n*4/7,n/2,n*2/3));
	vertices.push_back(new Point3D(n*3/7,n/2,n*2/3));
	//varfurile de sus
	vertices.push_back(new Point3D(n*4/7,n,n/3));
	vertices.push_back(new Point3D(n*5/7,n,n/3));
	vertices.push_back(new Point3D(n*5/7,n,n*2/3));
	vertices.push_back(new Point3D(n*4/7,n,n*2/3));

	//cele 6 fete
	//vector <int> contour;
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color( 0, 0.2 ,0.9),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	patrate.push_back( new Object3D(vertices,faces,Color( 0, 0,0.60784),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	//2 parcele in fata casei
	vector <Point3D*> verticesiarba;
	vector <Face*> facesiarba;
	fa_iarba(verticesiarba,facesiarba,0,linii+2,coloane+1,centru);
	fa_iarba(verticesiarba,facesiarba,0,linii,coloane+1,centru);

	patrate.pop_back();
	patrate.pop_back();

	vertices.clear();
	//varfurile de jos
	vertices.push_back(new Point3D(0,0,0));
	vertices.push_back(new Point3D(n,0,0));
	vertices.push_back(new Point3D(n,0,n/8));
	vertices.push_back(new Point3D(0,0,n/8));
	//varfurile de sus
	vertices.push_back(new Point3D(0,n,0));
	vertices.push_back(new Point3D(n,n,0));
	vertices.push_back(new Point3D(n,n,n/8));
	vertices.push_back(new Point3D(0,n,n/8));

	//cele 6 fete
	//fata jos

	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color(0.439216 ,0.501961, 0.564706),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru+2)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();


	patrate.push_back( new Object3D(vertices,faces,Color(0, 0.5 ,0.9839216),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru+2)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	vertices.clear();
	vertices.push_back(new Point3D(n/5,n/5,0));
	vertices.push_back(new Point3D(4*n/5,n/5,0));
	vertices.push_back(new Point3D(4*n/5,n/5,n/7.9));
	vertices.push_back(new Point3D(n/5,n/5,n/7.9));
	//varfurile de sus
	vertices.push_back(new Point3D(n/5,4*n/5,0));
	vertices.push_back(new Point3D(4*n/5,4*n/5,0));
	vertices.push_back(new Point3D(4*n/5,4*n/5,n/7.9));
	vertices.push_back(new Point3D(n/5,4*n/5,n/7.9));



	vertices.clear();
	vertices.push_back(new Point3D(n/5,n/5,0));
	vertices.push_back(new Point3D(4*n/5,n/5,0));
	vertices.push_back(new Point3D(4*n/5,n/5,n/7.9));
	vertices.push_back(new Point3D(n/5,n/5,n/7.9));
	//varfurile de sus
	vertices.push_back(new Point3D(n/5,4*n/5,0));
	vertices.push_back(new Point3D(4*n/5,4*n/5,0));
	vertices.push_back(new Point3D(4*n/5,4*n/5,n/7.9));
	vertices.push_back(new Point3D(n/5,4*n/5,n/7.9));

	//cele 6 fete

	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	//interior piscina
	patrate.push_back( new Object3D(vertices,faces,Color(0.6941176 ,0.895 ,1),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru+2)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());

	patrate.push_back( new Object3D(vertices,faces,Color(0.1176 ,0.1 ,0.1),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru+2)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());

	patrate.pop_back();
	patrate.pop_back();

	//BANCA

	//

	//varfurile de jos
	vertices.clear();
	vertices.push_back(new Point3D(n/3,n/5,0));
	vertices.push_back(new Point3D(2*n/3,n/5,0));
	vertices.push_back(new Point3D(2*n/3,n/5,n/2));
	vertices.push_back(new Point3D(n/3,n/5,n/2.5));
	//varfurile de sus
	vertices.push_back(new Point3D(n/3,4*n/5,0));
	vertices.push_back(new Point3D(2*n/3,4*n/5,0));
	vertices.push_back(new Point3D(2*n/3,4*n/5,n/2));
	vertices.push_back(new Point3D(n/3,4*n/5,n/2.5));


	//cele 6 fete
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color( 0.823529 ,0.411765, 0.117647),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru+2)*n,(1+coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	patrate.push_back( new Object3D(vertices,faces,Color( 0.545098, 0.270588, 0.0745098),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((2+linii+centru)*n,(1+coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();




	///GARAJ
	//varfurile de jos
	vertices.clear();
	vertices.push_back(new Point3D(0,0,0));
	vertices.push_back(new Point3D(n,0,0));
	vertices.push_back(new Point3D(n,0,2*n/3));
	vertices.push_back(new Point3D(0,0,2*n/3));
	//varfurile de sus
	vertices.push_back(new Point3D(0,n/1.01,0));
	vertices.push_back(new Point3D(n,n/1.01,0));
	vertices.push_back(new Point3D(n,n/1.01,2*n/3));
	vertices.push_back(new Point3D(0,n/1.01,2*n/3));

	//cele 6 fete

	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	patrate.push_back( new Object3D(vertices,faces,Color( 0.803922, 0.521569, 0.247059),true));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru+1)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();

	patrate.push_back( new Object3D(vertices,faces,Color( 0.803922, 0.360784 ,0.360784),false));
	DrawingWindow::addObject3D(patrate.back());

	Transform3D::loadIdentityModelMatrix();
	Transform3D::translateMatrix((linii+centru+1)*n,(coloane+centru)*n,0);
	Transform3D::applyTransform(patrate.back());
	patrate.pop_back();


	//DRUM IN FATA CASA

	vector <Point3D*> verticesdrum;
	vector <Face*> facesdrum;

	fa_drum(verticesdrum,facesdrum,0,directie,linii+1,coloane+1,centru);

}

//functia care permite adaugarea de obiecte
void DrawingWindow::init()
{

	static float w1=-2*DrawingWindow::width,
		w2=3 * DrawingWindow::width,
		h1=-2*DrawingWindow::height,
		h2=3 * DrawingWindow::height;
	v2d1=new Visual2D(-50, -50, 50, 50, w1, h1, w2, h2);


	v2d1->tipTran(true);

	addVisual2D(v2d1);

	//se deseneaza un cub
	vector <Point3D*> vertices;
	vector <Face*> faces;

	fa_patrate_mici(vertices,faces);


	//	Creare grid
	for (int i=0;i<liniicoloane;i++){
		for (int j=0;j<liniicoloane;j++){


			patrate.push_back( new Object3D(vertices,faces,Color(0,0.2,1),false));
			addObject3D(patrate.back());

			Transform3D::loadIdentityModelMatrix();

			Transform3D::translateMatrix((i+centru)*n,(j+centru)*n,0);

			Transform3D::applyTransform(patrate.back());
		}
	}

	//Creare cub cursor
	{
		vector <Point3D*> vertices1;
		vector <Face*> faces1;
		//CubulPlin
		fa_patrate(vertices1,faces1,1);
		patrate.push_back( new Object3D(vertices1,faces1,Color(0.1,0.6,0.6),true));
		addObject3D(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());
		//Contur
		patrate.push_back( new Object3D(vertices1,faces1,Color(1,0,0),false));
		addObject3D(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());

	}

}
static int rotareste=0,nivel=1;

bool keyup=false,keydown=false,keyleft=false,keyright=false;
bool ssus=false,sjos=false,sdreapta=false,sstanga=false;
bool space=false, roteste1=false,roteste2=false, swaptip=false;

void Perspectiva(float x1, float y1, float z1,float &x ,float &y)
{
	float aux[3];
	aux[0]=(1 / sqrt (6)) * ((sqrt(3)* x1) - (sqrt (3) *z1));
	aux[1]=(1 / sqrt (6)) * ((1*x1) + (2*y1) + (1 * z1));
	aux[2]=(1 / sqrt (6)) * ((sqrt(2)* x1) - (sqrt (2) *y1 ) + (sqrt (2) *z1));

	x=aux[0];
	y=aux[1];
}

static int ipud=0, iplr=0; 
static int swapt=0;
//functia care permite animatia
void DrawingWindow::onIdle()
{
	if(swaptip==true)
	{
		if (swapt==6)
			swapt=0;
		else
			swapt++;
		cout<<swapt<<endl;
		swaptip=false;
	}

	if(roteste1==true)
	{
		rotareste++;
		roteste1=false;
	}
	if(roteste2==true)
	{
		rotareste--;
		roteste2=false;
	}

	//SCROLL HARTA
	//___________________________________________________________________________________________________________________________________________________________________	
	//	v2d1->cadruPoarta(Color(0.741176 ,0.717647, 0.419608));
	if (keyup==true){
		if(iplr<550)
			iplr+=16;
		v2d1->fereastra((-DrawingWindow::width+ipud)/15.8,(-DrawingWindow::height+iplr)/15.8, (DrawingWindow::width+ipud)/15.8,((DrawingWindow::height+iplr)/15.8));
		keyup=false;
	}
	if (keydown==true){
		if(iplr>-100)
			iplr-=16;
		v2d1->fereastra((-DrawingWindow::width+ipud)/15.8,(-DrawingWindow::height+iplr)/15.8,(DrawingWindow::width+ipud)/15.8,((DrawingWindow::height+iplr)/15.8));
		keydown=false;
	}
	if (keyleft==true){
		if(ipud>-550)
			ipud-=16;
		v2d1->fereastra((-DrawingWindow::height+ipud)/15.8,(-DrawingWindow::width+iplr)/15.8 ,((DrawingWindow::height+ipud)/15.8),(DrawingWindow::width+iplr)/15.8);
		keyleft=false;
	}
	if (keyright==true){
		if(ipud<550)
			ipud+=16;
		v2d1->fereastra((-DrawingWindow::height+ipud)/15.8,(-DrawingWindow::width+iplr)/15.8 ,((DrawingWindow::height+ipud)/15.8),(DrawingWindow::width+iplr)/15.8);
		keyright=false;
	}
	//______________________________________________________________________________________________________________________________________________________________________

	vector <Point3D*> vertices1;
	vector <Face*> faces1;
	fa_patrate(vertices1,faces1,1);


	if(sstanga==true)
	{
		if(linii<liniicoloane-1)
			linii++;
		//Stergem obiectele anterioare
		removeObject3D(patrate.back());
		patrate.pop_back();
		removeObject3D(patrate.back());
		patrate.pop_back();

		//Cream obiectul nou
		patrate.push_back( new Object3D(vertices1,faces1,Color(0.1,0.6,0.6),true));
		addObject3D(patrate.back());

		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());

		//Cream conturul
		patrate.push_back( new Object3D(vertices1,faces1,Color(1,0,0),false));
		addObject3D(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());


		//cout<<linii<<endl;
		sstanga=false;
	}
	if(sdreapta==true)
	{
		if(linii>0)
			linii--;
		//Stergem obiectele anterioare
		removeObject3D(patrate.back());
		patrate.pop_back();
		removeObject3D(patrate.back());
		patrate.pop_back();

		//Cream obiectul nou
		patrate.push_back( new Object3D(vertices1,faces1,Color(0.1,0.6,0.6),true));
		addObject3D(patrate.back());

		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());

		//Cream conturul
		patrate.push_back( new Object3D(vertices1,faces1,Color(1,0,0),false));
		addObject3D(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());

		//cout<<linii<<endl;
		sdreapta=false;
	}
	if(ssus==true)
	{
		if(coloane>0)
			coloane--;
		//Stergem obiectele anterioare
		removeObject3D(patrate.back());
		patrate.pop_back();
		removeObject3D(patrate.back());
		patrate.pop_back();

		//Cream obiectul nou
		patrate.push_back( new Object3D(vertices1,faces1,Color(0.1,0.6,0.6),true));
		addObject3D(patrate.back());

		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());

		//Cream conturul
		patrate.push_back( new Object3D(vertices1,faces1,Color(1,0,0),false));
		addObject3D(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());
		//cout<<coloane<<endl;
		ssus=false;
	}
	if(sjos==true)
	{
		if(coloane<liniicoloane-1)
			coloane++;
		//Stergem obiectele anterioare
		removeObject3D(patrate.back());
		patrate.pop_back();
		removeObject3D(patrate.back());
		patrate.pop_back();

		//Cream obiectul nou
		patrate.push_back( new Object3D(vertices1,faces1,Color(0.1,0.6,0.6),true));
		addObject3D(patrate.back());

		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());

		//Cream conturul
		patrate.push_back( new Object3D(vertices1,faces1,Color(1,0,0),false));
		addObject3D(patrate.back());
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix((linii+centru)*n,(coloane+centru)*n,0);
		Transform3D::applyTransform(patrate.back());
		//cout<<coloane<<endl;
		sjos=false;
	}

	if (space==true)
	{
		//swap 0 -drum
		if (swapt==0)
		{

			vector <Point3D*> verticesdrum;
			vector <Face*> facesdrum;
			//cout<<rotareste;
			fa_drum(verticesdrum,facesdrum,0,rotareste,linii,coloane,centru);

			space=false;
		}
		//swap 1 -iarba
		if (swapt==1)
		{
			//swap 1 -iarba
			vector <Point3D*> verticesiarba;
			vector <Face*> facesiarba;
			fa_iarba(verticesiarba,facesiarba,0,linii,coloane,centru);
			patrate.pop_back();
			space=false;
		}
		//swap 2 -apa
		if (swapt==2)
		{
			vector <Point3D*> verticesapa;
			vector <Face*> facesapa;
			fa_apa(verticesapa,facesapa,0,linii,coloane,centru);
			patrate.pop_back();
			space=false;
		}
		//swap 3 iarba-copac
		if (swapt==3)
		{
			vector <Point3D*> verticescopac;
			vector <Face*> facescopac;
			fa_iarba_copac(verticescopac,facescopac,0,linii,coloane,centru);
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();


			space=false;

		}
		//swap 4 piata
		if (swapt==4)
		{
			vector <Point3D*> verticespiatza;
			vector <Face*> facesapiatza;
			fa_piata(verticespiatza,facesapiatza,0,linii,coloane,centru);
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();
			patrate.pop_back();




			space=false;

		}

		if (swapt==5) 
		{
			vector <Point3D*> verticesapa;
			vector <Face*> facesapa;
			fa_casa(verticesapa,facesapa,0,0,linii,coloane,centru);
			space=false;
		}

	}



}

//functia care se apeleaza la redimensionarea ferestrei
void DrawingWindow::onReshape(int width,int height)
{

}

//functia care defineste ce se intampla cand se apasa pe tastatura
void DrawingWindow::onKey(unsigned char key)
{
	switch(key)
	{
	case 27 : exit(0);
		//w
	case 119: keyup=true;  break;
		//a
	case 97:  keyleft=true; break;
		//s
	case 115: keydown=true;	break;
		//d
	case 100: keyright=true; break;
		//space
	case 32: space=true;break;
		//dreapta, schimbi tipul
	case KEY_RIGHT: swaptip=true;break;
		//num4
	case 52: sstanga=true;break;
		//num8
	case 56: ssus=true;break;
		//num6
	case 54: sdreapta=true;break;
		//num5
	case 53: sjos=true;break;
		//num2
	case 50: sjos=true;break; 
		//Schimb rotatia
	case KEY_UP: roteste1=true;break;
	case KEY_DOWN:roteste2=true;break;
	}
}

//functia care defineste ce se intampla cand se da click pe mouse
void DrawingWindow::onMouse(int button,int state,int x, int y)
{

}


int main(int argc, char** argv)
{
	//creare fereastra
	DrawingWindow dw(argc, argv, 800, 800, 20, 20, "Tema2");
	//se apeleaza functia init() - in care s-au adaugat obiecte
	dw.init();
	//se intra in bucla principala de desenare - care face posibila desenarea, animatia si procesarea evenimentelor
	dw.run();
	return 0;

}