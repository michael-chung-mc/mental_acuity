#pragma once
#ifndef FORM_H
#define FORM_H

#include "tuple.h"
#include "matrix.h"
#include "material.h"
#include "ray.h"
class Intersections;
#include <vector>

class Form {
public:
	Point mbrOrigin;
	double mbrRadius;
	std::unique_ptr<Matrix> mbrTransform;
	std::unique_ptr<Material> mbrMaterial;
	Ray mbrObjectRay;
	Form();
	Form(const Form& other);
	virtual ~Form();
	Form& operator=(const Form other);
	virtual Intersections getIntersections(Ray argRay);
	virtual bool checkEqual(Form other);
	virtual Vector getNormal(Point argPoint);
	Color getColorShaded(PointSource argLighting, Point argPosition, Vector argEye, Vector argNormal, bool argInShadow);
	Color getColorLocal(Point argPosition);
	void setTransform(const Matrix &argMatrix);
	void setMaterial(const Material &argMaterial);
};

class Sphere : public Form {
public:
	Sphere();
	Intersections getIntersections(Ray argRay);
	Vector getNormal(Point argPoint);
	bool checkEqual(Form other);
};

class Plane : public Form {
public:
	Vector getNormal(Point argPoint);
	Intersections getIntersections(Ray argRay);
};

#endif