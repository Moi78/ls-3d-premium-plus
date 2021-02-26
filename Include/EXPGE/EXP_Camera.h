#pragma once

#ifndef _EXP_CAMERA_H__
#define _EXP_CAMERA_H__

#ifdef _WIN32

#ifdef EXPANSIONGAMEENGINECORE_EXPORTS
#define EXPGE_API __declspec(dllexport)
#else
#define EXPGE_API __declspec(dllimport)
#endif

#else

#define EXPGE_API

#endif //_WIN32

#include "EXP_Component.h"
#include "EXP_Game.h"

#include <RD_Camera.h>

#include <vec3.h>
#include <mat4.h>

class EXPGE_API EXP_Camera : public EXP_Component, public RD_Camera
{
public:
	EXP_Camera(EXP_Game* gameinstance, vec3f pos, vec3f rot, vec3f scale, vec3f YawPitchRoll, float FOV, float Near = 0.1f, float Far = 100.0f, bool inheritParentRot = false);
	~EXP_Camera();

	void Translate(vec3f translation, bool changeSubject = false);
	void Use();

	//EXP_Component virtual methods override
	virtual vec3f GetPosition() override;
	virtual vec3f GetRotation() override;
	virtual vec3f GetScale() override;

	virtual void SetPosition(vec3f nPos) override;
	virtual void SetRotation(vec3f YawPitchRoll) override;

	virtual void UseParentMatrix(mat4f mat) override;

	//RD_Camera virtual methods override (RD_Camera Wrapping)
	virtual void TranslateCamera(vec3f trans, bool changeSub = false) override;
	virtual void RotateCamera(vec3f rotation) override;

	virtual void AddPitch(float pitch) override;
	virtual void AddYaw(float yaw) override;
	virtual void AddRoll(float roll) override;

	virtual void SetYPR(vec3f YPR) override;

private:
	void ComputeCamRealCoord();

	EXP_Game* m_gameinstance;
	bool m_inheritParentRot;
};

#endif //_EXP_CAMERA_H__