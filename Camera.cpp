#include "Camera.h"


Camera::Camera()
{
	camera = new ofEasyCam();
	camera->setDistance(100);
}


Camera::~Camera()
{
	delete camera;
}

void Camera::Zoom()
{
	
}

void Camera::draw()
{
	//this->camera:beginCame
}
