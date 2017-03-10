#include "ResourceManager.h"

ResourceManager g_resourceMgr;

/// <summary>
/// Loads all required assets in game
/// </summary>
void ResourceManager::loadAssets(LevelData & levelIn)
{
	try
	{
		textureHolder.acquire("CarTexture", thor::Resources::fromFile<sf::Texture>("Resources/TestRacer.png"));
		fontHolder.acquire("GameFont", thor::Resources::fromFile<sf::Font>("Resources/arial.ttf"));
		textureHolder.acquire("CarTexture", thor::Resources::fromFile<sf::Texture>("Car.png"));
		// -> Load more assets here etc

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