// Copyright (c) 1997-2001  Freie Universitaet Berlin (Germany).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.2-branch/Min_circle_2/include/CGAL/Optimisation_circle_2.C $
// $Id: Optimisation_circle_2.C 28567 2006-02-16 14:30:13Z lsaboret $
// 
//
// Author(s)     : Sven Schoenherr <sven@inf.ethz.ch>, Bernd Gaertner

// includes
#ifndef CGAL_OPTIMISATION_ASSERTIONS_H
#  include <CGAL/Optimisation/assertions.h>
#endif

CGAL_BEGIN_NAMESPACE

// Class implementation (continued)
// ================================

// I/O
// ---
template < class K_ >
std::ostream&
operator << ( std::ostream& os, const CGAL::Optimisation_circle_2<K_>& c)
{
    switch ( CGAL::get_mode( os)) {

      case CGAL::IO::PRETTY:
        os << "CGAL::Optimisation_circle_2( "
           << c.center() << ", "
           << c.squared_radius() << ')';
        break;

      case CGAL::IO::ASCII:
        os << c.center() << ' ' << c.squared_radius();
        break;

      case CGAL::IO::BINARY:
        os << c.center();
        CGAL::write( os, c.squared_radius());
        break;

      default:
        CGAL_optimisation_assertion_msg( false,
                                         "CGAL::get_mode( os) invalid!");
        break; }

    return( os);
}

template < class K_ >
std::istream&
operator >> ( std::istream& is, CGAL::Optimisation_circle_2<K_>& c)
{
    typedef  typename CGAL::Optimisation_circle_2<K_>::Point     Point;
    typedef  typename CGAL::Optimisation_circle_2<K_>::Distance  Distance;

    switch ( CGAL::get_mode( is)) {

      case CGAL::IO::PRETTY:
        std::cerr << std::endl;
        std::cerr << "Stream must be in ascii or binary mode" << std::endl;
        break;

      case CGAL::IO::ASCII: {
        Point     center;
        Distance  squared_radius;
        is >> center >> squared_radius;
        c.set( center, squared_radius); }
        break;

      case CGAL::IO::BINARY: {
        Point     center;
        Distance  squared_radius;
        is >> center;
        CGAL::read( is, squared_radius);
        c.set( center, squared_radius); }
        break;

      default:
        CGAL_optimisation_assertion_msg( false,
                                         "CGAL::get_mode( is) invalid!");
        break; }

    return( is);
}

CGAL_END_NAMESPACE

// ===== EOF ==================================================================
