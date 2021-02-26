#pragma once

#ifndef _RD_MESH_H__
#define _RD_MESH_H__

#ifdef _WIN32
#ifdef RAINDROPRENDERER_EXPORTS
#define RAINDROPRENDERER_API __declspec(dllexport)
#else
#define RAINDROPRENDERER_API __declspec(dllimport)
#endif

#else

#define RAINDROPRENDERER_API

#endif //_WIN32

#include "RD_ShaderLoader.h"
#include "RD_Materials.h"
#include "RaindropRenderer.h"
#include "RD_Camera.h"
#include "RD_RenderingAPI.h"

#include <mat4.h>

#include <string>
#include <vector>
#include <assert.h>

#include <BD_Reader.h>
#include <BulldozerFileManager.h>

#include <vec3.h>

class RAINDROPRENDERER_API RD_Mesh
{
public:
	RD_Mesh(RaindropRenderer* rndr, RD_ShaderMaterial* shader, vec3f position, vec3f rotation, vec3f scale);
	virtual ~RD_Mesh();

	void loadMesh(std::string);

	virtual void render(RD_Camera* cam);
	virtual void renderShadows(RD_ShaderLoader* shadowShader);

	virtual void addRotation(vec3f rotation, bool update = true);
	virtual void addTranslation(vec3f translation, bool update = true);
	virtual void addScale(vec3f scale, bool update = true);

	virtual void SetRotation(vec3f nRotation, bool update = true);
	virtual void SetPosition(vec3f nPos, bool update = true);
	virtual void SetScale(vec3f nScale, bool update = true);

	void SetShadowCasting(bool value);

	virtual void UseMatrix(mat4f mdl);
	virtual void SetParentMatrix(mat4f parent);
	virtual void Update();

	virtual vec3f GetLocation();

	RD_ShaderMaterial* GetMaterial();
	void SetMaterial(RD_ShaderMaterial* mat);
	
private:
	bool m_shadowCaster;

protected:
	RaindropRenderer* m_rndr;

	mat4f m_parent;
	mat4f m_mdl;

	RD_ShaderMaterial* m_mat;

	RD_RenderingAPI_VertexElemBuffer* m_buffer;
	int m_nbr_indices;

	vec3f m_position;
	vec3f m_rotation;
	vec3f m_scale;

	void Bufferize();

	std::vector<vec3f> m_vertices;
	std::vector<unsigned int> m_indices;
	std::vector<vec3f> m_normals;
	std::vector<vec2f> m_uv;

	std::vector<float> MixVertNormUV;
};

#endif