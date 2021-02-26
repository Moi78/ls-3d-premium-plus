#pragma once

#ifdef _WIN32
	#ifdef RAINDROPRENDERER_EXPORTS
		#define RAINDROPRENDERER_API __declspec(dllexport)
	#else
		#define RAINDROPRENDERER_API __declspec(dllimport)
	#endif

#else

#define RAINDROPRENDERER_API

#endif //_WIN32

#ifndef RD_GUI_ELEMENT_H__
#define RD_GUI_ELEMENT_H__

#include "RaindropRenderer.h"

#include <memory>
#include <string>

class RAINDROPRENDERER_API RD_GUI_Element
{
public:
	RD_GUI_Element();
	virtual ~RD_GUI_Element();

	virtual void RenderElement() = 0;
	virtual void RebuildElement();
};

#endif //RD_GUI_ELEMENT_H__