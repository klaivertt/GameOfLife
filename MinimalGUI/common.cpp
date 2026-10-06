#include "common.h"

bool CollisionRectPoint(sf::FloatRect& _rect, sf::Vector2f& _vec)
{
    return _rect.contains(_vec);
}

int Random(int _min, int _max)
{
    return _min + rand() % (_max - _min);
}
