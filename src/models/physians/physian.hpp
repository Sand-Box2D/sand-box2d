#pragma once

/**
 * @brief Physian is an abstract base physics object in the Sand-Box2D level.
 * It could be a box, a platform, etc.
 * 
 * You could render all the objects by calling `render()` method on all the physians.
 * Concrete objects would pick up their own render method implementations.
 * 
 * As this is an abstract class, a concrete physian has to be created as a pointer.
 */

class BasePhysian
{
public:
    virtual ~BasePhysian() {};
protected:
    /* data */
};
