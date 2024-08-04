#pragma once

/**
 * @brief Physian is an abstract base physics object in the Sand-Box2D level.
 * It could be a box, a platform, etc.
 * 
 * You could render all the objects by calling `render()` method on all the Physians.
 * Concrete objects would pick up their own render method implementations.
 */

class BasePhysian
{
public:
    BasePhysian();
    ~BasePhysian();
private:
    /* data */
};
