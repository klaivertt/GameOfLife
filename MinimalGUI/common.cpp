#include "common.h"

bool CollisionRectPoint(sf::FloatRect& _rect, sf::Vector2f& _vec)
{
    return _rect.contains(_vec);
}
