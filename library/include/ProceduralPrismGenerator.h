/*
-----------------------------------------------------------------------------
This source file is part of ogre-procedural

For the latest info, see http://code.google.com/p/ogre-procedural/

Copyright (c) 2010-2013 Michael Broutin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef PROCEDURAL_PRISM_GENERATOR_INCLUDED
#define PROCEDURAL_PRISM_GENERATOR_INCLUDED

#include "ProceduralMeshGenerator.h"
#include "ProceduralPlatform.h"

namespace Procedural
{
/**
 * \ingroup objgengrp
 * Generates a prism mesh centered on the origin.
 * Default size is 1.0 with 1 quad per face on 3 sides.
 * \image html primitive_prism3.png
 */
class _ProceduralExport PrismGenerator : public MeshGenerator<PrismGenerator>
{
	Ogre::Real mRadius;
	Ogre::Real mHeight;
	unsigned int mNumSides;
	unsigned int mNumSegHeight;
	bool mCapped;
public:

	/// Contructor with arguments
	PrismGenerator(Ogre::Real radius=1.f, Ogre::Real height=1.f, unsigned int numSides=3, unsigned int numSegHeight=1, bool capped=true) :
		mRadius(radius), mHeight(height), mNumSides(numSides), mNumSegHeight(numSegHeight), mCapped(capped) {}

	/**
	Sets the radius of the prism (default=1)
	\exception Ogre::InvalidParametersException Radius must be larger than 0!
	*/
	inline PrismGenerator& setRadius(Ogre::Real radius)
	{
		if (radius <= 0.0f)
			OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "Radius must be larger than 0!", "Procedural::PrismGenerator::setRadius(Ogre::Real)");
		mRadius = radius;
		return *this;
	}

	/**
	Sets the height of the prism (default=1)
	\exception Ogre::InvalidParametersException Height must be larger than 0!
	*/
	inline PrismGenerator& setHeight(Ogre::Real height)
	{
		if (height <= 0.0f)
			OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "Height must be larger than 0!", "Procedural::PrismGenerator::setHeight(Ogre::Real)");
		mHeight = height;
		return *this;
	}

	/**
	Sets the number of prism sides (default=3)
	\exception Ogre::InvalidParametersException Minimum of numSides is 3
	*/
	PrismGenerator& setNumSides(unsigned int numSides)
	{
		if (numSides < 3)
			OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "There must be more than 2 sides", "Procedural::PrismGenerator::setNumSides(unsigned int)");
		mNumSides = numSides;
		return *this;
	}

	/**
	Sets the number of segments along the height of the prism (default=1)
	\exception Ogre::InvalidParametersException Minimum of numSegHeight is 1
	*/
	inline PrismGenerator& setNumSegHeight(unsigned int numSegHeight)
	{
		if (numSegHeight == 0)
			OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "There must be more than 0 segments", "Procedural::PrismGenerator::setNumSegHeight(unsigned int)");
		mNumSegHeight = numSegHeight;
		return *this;
	}

	/** Sets whether the prism has endings or not (default=true) */
	inline PrismGenerator& setCapped(bool capped)
	{
		mCapped = capped;
		return *this;
	}

	/**
	 * Builds the mesh into the given TriangleBuffer
	 * @param buffer The TriangleBuffer on where to append the mesh.
	 */
	void addToTriangleBuffer(TriangleBuffer& buffer) const;
};

}
#endif
