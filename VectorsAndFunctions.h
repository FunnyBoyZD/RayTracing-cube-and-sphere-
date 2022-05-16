#pragma once

struct Vector1
{
public: //fields/methods/constructors to which public access is granted
	float _x, //coordinate x
		  _y; //coordinate y
	Vector1(float value); //constructor with one parameter
	Vector1(float x, float y); //constructor with two parameters
	Vector1 operator+(Vector1 const& other); //overloaded coordinate add operator
	Vector1 operator-(Vector1 const& other); //overloaded coordinate selection operator
	Vector1 operator*(Vector1 const& other); //overloaded coordinate multiplication operator
	Vector1 operator/(Vector1 const& other); //overloaded coordinate division operator
};

struct Vector2
{
public: //fields/methods/constructors to which public access is granted
	float _x, //coordinate x
		  _y, //coordinate y
		  _z; //coordinate z
	Vector2(float value); //constructor with one parameters
	Vector2(float x, Vector1& v); //constructor with two parameters
	Vector2(float x, float y, float z); //constructor with three parameters
	Vector2 operator+(const Vector2& other); //overloaded coordinate add operator 
	Vector2 operator-(const Vector2& other); //overloaded coordinate selection operator
	Vector2 operator*(const Vector2& other); //overloaded coordinate multiplication operator
	Vector2 operator/(const Vector2& other); //overloaded coordinate division operator
	Vector2 operator-(); //overloaded operator of changing coordinate signs to opposite
};

float GradientNumCheck(float value, float min, float max); //determining the number of the gradient layer of the element
float Sign(float value); //determining the current sign of value
float Step(float previous, float current); //get the greater value element
/*float Length2D(Vector1 const& vector); //length of the vector(for 2D)*/
float Length3D(Vector2 const& vector); //length of of the vector(for 3D)
float AngleOfRotation(Vector2& vector, Vector2& light); //how strongly the vector is rotated of the light source
float Plane(Vector2 camPosition, Vector2 beamDirection, Vector2 lightForPlane, float weight); //get an intersection value for the plane
Vector2 Normalize(Vector2 vector); //normalizing the vector
Vector2 Abs(Vector2& vector); //changes the coordinates to their absolute values
Vector2 Sign(Vector2 const& vector); //setting the current coordinates of the vector with the corresponding signs
Vector2 Step(Vector2& previous, Vector2 current); //setting the current coordinates of the vector after the step
Vector2 Reflect(Vector2 firstObject, Vector2 n); //reflect the first object in the second object
/*Vector2 RotateX(Vector2 vector, double angle); //change the x coordinates when rotating*/
Vector2 RotateY(Vector2 vector, double angle); //change the y coordinates when rotating
Vector2 RotateZ(Vector2 vector, double angle); //change the z coordinates when rotating
Vector1 Sphere(Vector2 camSphereDiff, Vector2 beamDirection, float radius); //intersection of the sphere
Vector1 Cube(Vector2 camPosition, Vector2 beamDirection, Vector2 boxSize, Vector2& outNormal); //intersection of the cube