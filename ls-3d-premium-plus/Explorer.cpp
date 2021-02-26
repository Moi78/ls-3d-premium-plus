#include "pch.h"
#include "Explorer.h"

EXPGE_LEVEL_CODE(Explorer);

//														OnStart enabled, OnTick disabled
Explorer::Explorer(EXP_Game* game, EXP_MapLoader* map) : EXP_Level(true, false) {
	m_game = game;
	m_map = map;

	m_elems = new EXP_InstanciatedMesh(game, game->GetShaderByFileRef("/mat/files.exmtl"), "/meshes/file");
	m_folders = new EXP_InstanciatedMesh(game, game->GetShaderByFileRef("/mat/folder.exmtl"), "/meshes/folder");

	m_character = new Character(game);

	game->GetRenderer()->DisableFeature(RendererFeature::Bloom);
	game->GetRenderer()->DisableFeature(RendererFeature::SSAO);
}

Explorer::~Explorer() {

}

void Explorer::OnStart() {
	int i = 0;
	int nbrEntry = 0;

	vec3f cur_pos(0.0f, 0.0f, 0.5f);
	vec3f text_pos(0.1f, -0.4f, 0.5f);
	for (auto& entry : std::filesystem::directory_iterator("./")) {
		RD_MeshInstance mi{};
		mi.pos = cur_pos;
		mi.rotation = vec3f(0.0f, 0.0f, 90.0f);
		mi.scale = vec3f(0.2f, 0.2f, 0.2f);

		std::string ent = entry.path().generic_string();
		std::string name;
		for (int i = ent.size() - 1; i >= 0; i--) {
			if ((ent[i] == '\\') || (ent[i] == '/')) {
				break;
			}

			name = ent[i] + name;
		}

		EXP_TextSurface* txt = new EXP_TextSurface(
			m_game, name, 120, "/font.ttf",
			text_pos, vec3f(0.0f, -90.0f, -90.0f), vec3f(0.1f, 0.1f, 0.1f),
			vec3f(1.0f, 1.0f, 1.0f)
		);

		m_txt.push_back(txt);

		if (entry.is_directory()) {
			mi.scale = vec3f(0.15f, 0.15f, 0.15f);
			m_folders->AppendInstance(mi);
		}
		else {
			m_elems->AppendInstance(mi);
		}

		cur_pos += vec3f(0.5f, -0.04f, 0.0f);
		text_pos += vec3f(0.5f, 0.0f, 0.0f);

		if (nbrEntry % 3 == 0) {
			srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());

			vec3f lpos = cur_pos + vec3f(0.0f, 0.0f, 1.0f);
			m_lights.push_back(new EXP_PointLight(
				m_game, lpos,
				vec3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX),
				5.0f, 10.0f)
			);
		}
		nbrEntry += 1;
	}
}

void Explorer::OnTick() {

}
