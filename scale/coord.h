#include <SFML/Graphics.hpp>
#include <cmath>


using namespace std;

float rotatex(float x1, float x2, float y1, float y2, float theta);
float rotatey(float x1, float x2, float y1, float y2, float theta);
float onethirdx (float x1, float x2);
float onethirdy (float y1, float y2);
float twothirdx (float x1, float x2);
float twothirdy (float y1, float y2);
float distanceformula (float x1, float x2, float y1, float y2);
const float pi=3.14159265359;
float DEG2RAD(float theta);

// rotate funcs

sf::Vector2f rotate(sf::Vector2f p1, sf::Vector2f p2, float angle)
{
    sf::Vector2f coord;
    coord.x = rotatex(p1.x, p2.x, p1.y, p2.y, angle);
    coord.y = rotatey(p1.x, p2.x, p1.y, p2.y, angle);
    return coord;
}


float rotatex(float x1, float x2, float y1, float y2, float theta) {
    float radians = DEG2RAD(theta);
    float x=(x2-x1)*(cos(radians))-((y2-y1)*sin(radians))+x1;
    return x;
}
float rotatey(float x1, float x2, float y1, float y2, float theta) {
    float radians = DEG2RAD(theta);
    float y=(x2-x1)*(sin(radians))+((y2-y1)*cos(radians))+y1;
    return y;
}

// 1/3 funcs

sf::Vector2f onethird(sf::Vector2f first, sf::Vector2f second)
{
    // calcs the point that is 1/3rd the distance between the first
    // and second
    sf::Vector2f result;
    result.x = onethirdx(first.x, second.x);
    result.y = onethirdy(first.y, second.y);
    return result;
}

float onethirdx(float x1, float x2){
    return x1+(x2-x1)/3;
}

float onethirdy(float y1, float y2){
    return y1+(y2-y1)/3;
}

// 2/3 funcs

sf::Vector2f twothirds(sf::Vector2f c1, sf::Vector2f c2)
{
    sf::Vector2f c3;
    c3.x = twothirdx(c1.x, c2.x);
    c3.y = twothirdy(c1.y, c2.y);
    return c3;
}

float twothirdx (float x1, float x2){
    return x1 + ((2.0/3.0)*(x2-x1));
}

float twothirdy (float y1, float y2){
    return y1 + ((2.0/3.0)*(y2-y1));
}

// other funcs

float dist(sf::Vector2f p1, sf::Vector2f p2) {
    float distance;
    distance=sqrt(pow((p2.x-p1.x), 2.0) + pow((p2.y-p1.y), 2.0));
    return distance;
}
float DEG2RAD(float theta){
    double angle = (theta*pi) / 180.0;
    return angle; 
}
