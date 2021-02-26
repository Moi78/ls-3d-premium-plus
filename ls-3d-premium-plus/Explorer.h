#pragma once

#include <EXP_Game.h>
#include <EXP_Level.h>
#include <EXP_MapLoader.h>

#include <EXP_Camera.h>
#include <EXP_InstanciatedMesh.h>
#include <EXP_TextSurface.h>

#include <filesystem>
#include <random>

#include "Character.h"

class Explorer : public EXP_Level
{
public:
	Explorer(EXP_Game* game, EXP_MapLoader* map);
	~Explorer();

	virtual void OnStart() override;
	virtual void OnTick() override;

private:
	EXP_Game* m_game;
	EXP_MapLoader* m_map;

	EXP_InstanciatedMesh* m_elems;
	EXP_InstanciatedMesh* m_folders;

	std::vector<EXP_TextSurface*> m_txt;
	std::vector<EXP_PointLight*> m_lights;

	Character* m_character;
};

EXPGE_LEVEL_HEADER(Explorer);