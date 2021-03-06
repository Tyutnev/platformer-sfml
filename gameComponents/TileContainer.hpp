#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <memory>
#include <string>

#include "IComponent.hpp"

using Tiles = std::map<char, std::shared_ptr<sf::Sprite>>;

class TileContainer : public IComponent
{
private:
    /**
     * Текстуры тайлов
     **/
    std::vector<std::shared_ptr<sf::Texture>> tileTexture;
    /**
     * Спрайты тайлов
     **/
    Tiles tileSprite;
public:
    static const int TILE_SIZE = 32;

    TileContainer();

    bool emptyTile(char tileIdentity);

    sf::Sprite& getTileByIdentity(char tileIdentity);
};