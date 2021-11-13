#pragma once

#include "resource_class.h"


class GraphicsFriend
{
protected:
	static Graphics::GPUDevice& getDevice( Graphics& gph );
};