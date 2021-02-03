#pragma once
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
using std::unordered_map;
using std::string;

class TextureManager
{
	static unordered_map<string, sf::Texture> textures;
	static void LoadTexture(const char* fileName);
public:
	static sf::Texture& Get(const char* textureName);
	static void ShutDown();
};

