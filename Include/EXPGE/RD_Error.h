#pragma once

#ifndef _RD_ERROR_H__
#define _RD_ERROR_H__

#ifdef _WIN32

#ifdef RAINDROPRENDERER_EXPORTS
#define RAINDROPRENDERER_API __declspec(dllexport)
#else
#define RAINDROPRENDERER_API __declspec(dllimport)
#endif //RAINDROPRENDERER_EXPORTS

#include <Windows.h>
#include <iostream>
#include <string>

//Error displayer
extern "C" void RAINDROPRENDERER_API dispErrorMessageBox(std::wstring Message);
RAINDROPRENDERER_API std::wstring StrToWStr(std::string str);

#else

#include <iostream>

void dispErrorMessageBox(std::wstring message);
std::wstring StrToWStr(std::string str);

#endif //_WIN32

#endif
