#include "ResourceManager.h"

ResourceManager g_resourceMgr;

/// <summary>
/// Loads all required assets in game
/// </summary>
void ResourceManager::loadAssets(LevelData & levelIn)
{
	try
	{
		fontHolder.acquire("GameFont", thor::Resources::fromFile<sf::Font>("Resources/arial.ttf"));
		textureHolder.acquire("CarTexture", thor::Resources::fromFile<sf::Texture>("Resources/Cars/CarGreen.png"));
		textureHolder.acquire("Trophies", thor::Resources::fromFile<sf::Texture>("Resources/Trophies.png"));

		for (int Row = 0; Row < 6; Row++)
		{
			for (int Col = 0; Col < 6; Col++)
			{
				std::stringstream ss;
				ss << "Resources/TrackTiles/Row" << Row << "/TrackFinal-" << Col << "-" << Row;
				std::string id = ss.str();
				ss << ".png";
				std::string path = ss.str();
				textureHolder.acquire(id, thor::Resources::fromFile<sf::Texture>(path));
				TileData tile;
				tile.m_rotation = 0;
				tile.m_textureString = id;
				tile.m_xIndex = Col;
				tile.m_yIndex = Row;
				levelIn.m_tileDataVector.push_back(tile);
			}
		}

		std::string s;
		for (int i = 0; i < levelIn.m_textureDataVector.size(); i++)
		{
			s = levelIn.m_textureDataVector.at(i).m_filename;
			std::cout << s << levelIn.m_textureDataVector.size() << std::endl;
			textureHolder.acquire(levelIn.m_textureDataVector.at(i).m_textureName, thor::Resources::fromFile<sf::Texture>(levelIn.m_textureDataVector.at(i).m_filename));
		}
	}
	catch (thor::ResourceLoadingException& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}