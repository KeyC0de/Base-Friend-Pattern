#include "resource_class.h"
#include <iostream>


Graphics::Graphics( int width,
	int height )
	: m_width{width},
	m_height{height},
	m_device{0, "RTX ON"}
{
}

void Graphics::render()
{
	std::cout << "Currently rendering frame "
		<< m_device.nFrame
		<< "\n";
}

void Graphics::present()
{
	std::cout << m_device.adapterName
		<< " currently presenting\n";
}