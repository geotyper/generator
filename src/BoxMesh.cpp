// Copyright 2015 Markus Ilmola
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.


#include "generator/BoxMesh.hpp"


using namespace generator;

using namespace generator::detail;




BoxFace::BoxFace(
	const gml::dvec2& size, const gml::uvec2& segments, double delta
) :
	TranslateMesh{{size, segments}, {0.0, 0.0, delta}}
{ }


BoxFaces::BoxFaces(
	const gml::dvec2& size, const gml::uvec2& segments, double delta
) :
	MergeMesh{
		{size, segments, delta},
		{{{size, segments, -delta}}, true, false}
	}
{ }



BoxMesh::BoxMesh(const gml::dvec3& size, const gml::uvec3& segments) :
	MergeMesh{
		{
			{{size[1], size[2]}, {segments[1], segments[2]}, size[0]},
			Axis::Z, Axis::X, Axis::Y
		},
		{
			{
				{{size[0], size[2]}, {segments[0], segments[2]}, size[1]},
				Axis::X, Axis::Z, Axis::Y
			},
			true, false
		},
		{{size[0], size[1]}, {segments[0], segments[1]}, size[2]}
	}
{ }
