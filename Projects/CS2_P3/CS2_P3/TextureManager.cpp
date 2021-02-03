#include "TextureManager.h"

unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(const char* fileName)
{
	string filePath = "images/";
	filePath += fileName;
	filePath += ".png";

	textures[fileName].loadFromFile(filePath);
}

sf::Texture& TextureManager::Get(const char* textureName)
{
	if (textures.find(textureName) == textures.end())
		LoadTexture(textureName);

	return textures[textureName];
}

void TextureManager::ShutDown()
{
	textures.clear();
}