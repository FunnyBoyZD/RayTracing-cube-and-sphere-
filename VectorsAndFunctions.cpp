#include <math.h>
#include "VectorsAndFunctions.h"

/*
Constructor with one parameter
Enter:
    value - value for setting the x and y coordinates
Exit: missing
*/
Vector1::Vector1(float value)
{
    _x = value;
    _y = value;
}

/*
Constructor with two parameters
Enter:
    x - value for setting the x coordinate
    y - value for setting the y coordinate
Exit: missing
*/
Vector1::Vector1(float x, float y)
{
    _x = x;
    _y = y;
}

/*
Overloaded coordinate add operator
Enter:
    other - Vector1 object reference
Exit:
    Vector1 object with new coordinates
*/
Vector1 Vector1::operator+(const Vector1& other)
{
    return Vector1(_x + other._x, _y + other._y);
}

/*
Overloaded coordinate selection operator
Enter:
    other - Vector1 object reference
Exit:
    Vector1 object with new coordinates
*/
Vector1 Vector1::operator-(const Vector1& other)
{
    return Vector1(_x - other._x, _y - other._y);
}

/*
Overloaded coordinate multiplication operator
Enter:
    other - Vector1 object reference
Exit:
    Vector1 object with new coordinates
*/
Vector1 Vector1::operator*(const Vector1& other)
{
    return Vector1(_x * other._x, _y * other._y);
}

/*
Overloaded coordinate division operator
Enter:
    other - Vector1 object reference
Exit:
    Vector1 object with new coordinates
*/
Vector1 Vector1::operator/(const Vector1& other)
{
    return Vector1(_x / other._x, _y / other._y);
}

/*
Constructor with one parameter
Enter:
    value - value for setting the x, y and z coordinates
Exit: missing
*/
Vector2::Vector2(float value)
{
    _x = value;
    _y = value;
    _z = value;
}

/*
Constructor with two parameters
Enter:
    x - value for setting the x coordinate
    v - Vector1 object reference for setting the x and y coordinates
Exit: missing
*/
Vector2::Vector2(float x, Vector1& v)
{
    _x = x;
    _y = v._x;
    _z = v._y;
}

/*
Constructor with three parameters
Enter:
    x - value for setting the x coordinate
    y - value for setting the y coordinate
    z - value for setting the z coordinate
Exit: missing
*/
Vector2::Vector2(float x, float y, float z)
{
    _x = x;
    _y = y;
    _z = z;
}

/*
Overloaded coordinate add operator
Enter:
    other - Vector2 object reference
Exit:
    Vector2 object with new coordinates
*/
Vector2 Vector2::operator+(const Vector2& other)
{
    return Vector2(_x + other._x, _y + other._y, _z + other._z);
}

/*
Overloaded coordinate selection operator
Enter:
    other - Vector2 object reference
Exit:
    Vector2 object with new coordinates
*/
Vector2 Vector2::operator-(const Vector2& other)
{
    return Vector2(_x - other._x, _y - other._y, _z - other._z);
}

/*
Overloaded coordinate multiplication operator
Enter:
    other - Vector2 object reference
Exit:
    Vector2 object with new coordinates
*/
Vector2 Vector2::operator*(const Vector2& other)
{
    return Vector2(_x * other._x, _y * other._y, _z * other._z);
}

/*
Overloaded coordinate division operator
Enter:
    other - Vector2 object reference
Exit:
    Vector2 object with new coordinates
*/
Vector2 Vector2::operator/(const Vector2& other)
{
    return Vector2(_x / other._x, _y / other._y, _z / other._z);
}

/*
Overloaded operator of changing coordinate signs to opposite
Enter: missing
Exit:
    Vector2 object with new coordinates
*/
Vector2 Vector2::operator-()
{
    return Vector2(-_x, -_y, -_z);
}

/*
Function for determining the number of the gradient layer of the element
Enter:
    value - character`s number
    min - minimum of the gradient
    max - maximum of the gradient
Exit:
    The number of the gradient layer of the element
*/
float GradientNumCheck(float value, float min, float max)
{
    return (float)fmax((float)fmin(value, max), (float)min);
}

/*
Function for determining the current sign of value
Enter:
    a - value
Exit:
    Value with it`s current sign
*/
float Sign(float value)
{
    return (float)(static_cast<double>(0 < value) - static_cast<double>(value < 0));
}

/*
Function to get the greater value element
Enter:
    edge - previous value
    x - current value
Exit:
    Step = x - if x value is greater than edge value
    Step = edge - if edge value is greated than x value
*/
float Step(float previous, float current)
{
    return current > previous;
}

///*
//Function to get a length of the vector(for 2D)
//Enter:
//    v - Vector1 object reference
//Exit:
//    Length of the vector
//*/
//float Length2D(Vector1& vector)
//{
//    return (float)sqrt(static_cast<double>(vector._x) * static_cast<double>(vector._x) + static_cast<double>(vector._y) * static_cast<double>(vector._y));
//}

/*
Function to get a length of the vector(for 3D)
Enter:
    v - Vector1 object reference
Exit:
    Length of the vector
*/
float Length3D(Vector2& vector)
{
    return (float)sqrt(static_cast<double>(vector._x) * static_cast<double>(vector._x) + static_cast<double>(vector._y) * static_cast<double>(vector._y) + static_cast<double>(vector._z) * static_cast<double>(vector._z));
}

/*
Function to calculate how strongly the vector is rotated of the light source
Enter:
    vector - vector(Vector2 object) reference
    light - light source(Vector2 object) reference
Exit:
    How strongly the vector is rotated of the light source
*/
float AngleOfRotation(Vector2& vector, Vector2& light)
{
    return vector._x * light._x + vector._y * light._y + vector._z * light._z;
}

/*
Function to get an intersection value for the plane
Enter:
    camPosition - position of the camera
    beamDirection - beam direction from camera
    lightForPlane - light vector for plane
    weight - weight of the plane
Exit:
    Intersection value for the plane
*/
float Plane(Vector2 camPosition, Vector2 beamDirection, Vector2 lightForPlane, float weight) {
    return -(AngleOfRotation(camPosition, lightForPlane) + weight) / AngleOfRotation(beamDirection, lightForPlane);
}

/*
Funtion for normalizing the vector
Enter:
    vector - Vector2 object to normalize
Exit:
    Normalize = vector - normalized vector
*/
Vector2 Normalize(Vector2 vector)
{
    return vector / Length3D(vector);
}

/*
Function to change the coordinates to their absolute values
Enter:
    vector - vector(Vector2 object) reference
Exit:
    Abs = vector - vector with new coordinates
*/
Vector2 Abs(Vector2& vector)
{
    return Vector2((float)fabs(vector._x), (float)fabs(vector._y), (float)fabs(vector._z));
}

/*
Function to set the current coordinates of the vector with the corresponding signs
Enter:
    vector - vector(Vector2 object) reference
Exit:
    Sign = vector - vector with correct coordinates
*/
Vector2 Sign(Vector2& vector)
{
    return Vector2(Sign(vector._x), Sign(vector._y), Sign(vector._z));
}

/*
Function to set the current coordinates of the vector after the step
Enter:
    previous - vector before the step(Vector2 object) reference
    current - vector after the step(Vector2 object) reference
Exit:
    Vector with correct coordinates
*/
Vector2 Step(Vector2& previous, Vector2 current)
{
    return Vector2(Step(previous._x, current._x), Step(previous._y, current._y), Step(previous._z, current._z));
}

/*
Function to reflect the first object in the second object
Enter:
    firstObject - object that needs to be reflected
    secondObject - object that need to reflect the first object
Exit:
    Reflected object
*/
Vector2 Reflect(Vector2 firstObject, Vector2 secondObject)
{
    return firstObject - secondObject * (2 * AngleOfRotation(secondObject, firstObject));
}

///*
//Function to change the x coordinates when rotating
//Enter:
//    vector - vector to rotate
//    angle - the angle at which the vector should be rotated
//Exit:
//    RotateX = rotatedVector - vector with x coordinate after the rotation
//*/
//Vector2 RotateX(Vector2 vector, double angle)
//{
//    Vector2 rotatedVector = vector;
//    
//    rotatedVector._z = vector._z * (float)cos(angle) - vector._y * (float)sin(angle);
//    rotatedVector._y = vector._z * (float)sin(angle) + vector._y * (float)cos(angle);
//    return rotatedVector;
//}

/*
Function to change the y coordinates when rotating
Enter:
    vector - vector to rotate
    angle - the angle at which the vector should be rotated
Exit:
    RotateX = rotatedVector - vector with y coordinate after the rotation
*/
Vector2 RotateY(Vector2 vector, double angle)
{
    Vector2 rotatedVector = vector;
    rotatedVector._x = vector._x * (float)cos(angle) - vector._z * (float)sin(angle);
    rotatedVector._z = vector._x * (float)sin(angle) + vector._z * (float)cos(angle);
    return rotatedVector;
}

/*
Function to change the z coordinates when rotating
Enter:
    vector - vector to rotate
    angle - the angle at which the vector should be rotated
Exit:
    RotateX = rotatedVector - vector with z coordinate after the rotation
*/
Vector2 RotateZ(Vector2 vector, double angle)
{
    Vector2 rotatedVector = vector;
    rotatedVector._x = vector._x * (float)cos(angle) - vector._y * (float)sin(angle);
    rotatedVector._y = vector._x * (float)sin(angle) + vector._y * (float)cos(angle);
    return rotatedVector;
}

/*
Function to intersect the sphere
Enter:
    camSphereDiff - difference between the camera and sphere positions
    beamDirection - beam direction from camera
    radius - radius of the sphere
Exit:
    Vector of an intersected sphere
*/
Vector1 Sphere(Vector2 camSphereDiff, Vector2 beamDirection, float radius) {
    float b = AngleOfRotation(camSphereDiff, beamDirection);
    float c = AngleOfRotation(camSphereDiff, camSphereDiff) - radius * radius;
    float height = b * b - c;
    if (height < 0.0)
    {
        return Vector1(-1.0);
    } 
    height = (float)sqrt(height);
    return Vector1(-b - height, -b + height);
}

/*
Function to intersect the cube
Enter:
    camPosition - position of the camera
    beamDirection - beam direction from camera
    boxSize - the length of the side of the cube
    outNormal - out of normal positions vector
Exit:
    Vector of an intersected cube
*/
Vector1 Cube(Vector2 camPosition, Vector2 beamDirection, Vector2 boxSize, Vector2& outNormal) {
    Vector2 m = Vector2(1.0) / beamDirection;
    Vector2 n = m * camPosition;
    Vector2 k = Abs(m) * boxSize;
    Vector2 t1 = -n - k;
    Vector2 t2 = -n + k;
    float tN = (float)fmax(fmax(t1._x, t1._y), t1._z);
    float tF = (float)fmin(fmin(t2._x, t2._y), t2._z);
    if (tN > tF || tF < 0.0) return Vector1(-1.0);
    Vector2 yzx = Vector2(t1._y, t1._z, t1._x);
    Vector2 zxy = Vector2(t1._z, t1._x, t1._y);
    outNormal = -Sign(beamDirection) * Step(yzx, t1) * Step(zxy, t1);
    return Vector1(tN, tF);
}