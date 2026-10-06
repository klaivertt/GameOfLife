#ifndef COMMON__H
#define COMMON__H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define SCREEN_S sf::Vector2i(1920, 1080)

constexpr const float M_PI = 3.141592654f;

using Pixel = unsigned int;

class GameData;

bool CollisionRectPoint(sf::FloatRect& _rect, sf::Vector2f& _vec);

#endif