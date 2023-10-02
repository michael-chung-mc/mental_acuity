#pragma once
#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "sphere.h"
#include "tuple.h"
class Ray;
#include <vector>

struct IntersectionState {
public:
	double time;
	Sphere object;
	Point point;
	Vector pov;
	Vector normal;
};

class Intersection {
public:
	double time;
	Sphere object;
	Intersection();
	Intersection(double time, Sphere s);
	bool checkEqual(Intersection other);
	bool operator<(Intersection other) const;
	IntersectionState getState(Ray argRay);
};


class Intersections {
public:
	std::vector<Intersection> intersections;
	Intersections();
	Intersections(const Intersections& other);
	Intersections(double time, Sphere s);
	void intersect(double time, Sphere s);
	Intersection hit();
	Intersections& operator=(const Intersections other);
};

#endif