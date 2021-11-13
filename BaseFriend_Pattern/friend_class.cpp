#include "friend_class.h"


Graphics::GPUDevice& GraphicsFriend::getDevice( Graphics& gph )
{
	return gph.m_device;
}