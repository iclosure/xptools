// Copyright (c) 1997-2000  Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbruecken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $Source: /CVSROOT/CGAL/Packages/Hash_map/include/CGAL/Unique_hash_map.h,v $
// $Revision: 1.5 $ $Date: 2003/10/21 12:16:37 $
// $Name: current_submission $
//
// Author(s)     : Michael Seel <seel@mpi-sb.mpg.de>
//                 Lutz Kettner <kettner@inf.ethz.ch>

#ifndef CGAL_UNIQUE_HASH_MAP_H
#define CGAL_UNIQUE_HASH_MAP_H

#include <CGAL/basic.h>
#include <CGAL/Handle_hash_function.h>
#include <CGAL/Tools/chained_map.h>
#include <cstddef>

CGAL_BEGIN_NAMESPACE

template <class Key_, class Data_,
          class UniqueHashFunction = Handle_hash_function>
class Unique_hash_map {
public:
    typedef Key_                                     Key;
    typedef Data_                                    Data;
    typedef UniqueHashFunction                       Hash_function;

    // STL compliance
    typedef Key_                                     key_type;
    typedef Data_                                    data_type;
    typedef UniqueHashFunction                       hasher;

    typedef Unique_hash_map<Key,Data,Hash_function>  Self;

private:
    typedef CGALi::chained_map<Data>                 Map;
    typedef typename Map::item                       Item;

private:
    Hash_function  m_hash_function;
    Map            m_map;

public:

    Unique_hash_map() { m_map.xdef() = Data(); }

    Unique_hash_map( const Data& deflt, std::size_t table_size = 1)
        : m_map( table_size) { m_map.xdef() = deflt; }

    Unique_hash_map( const Data& deflt,
                     std::size_t table_size,
                     const Hash_function& fct)
        : m_hash_function(fct), m_map( table_size) { m_map.xdef() = deflt; }

    Unique_hash_map( Key first1, Key beyond1, Data first2) {
        m_map.xdef() = Data();
        insert( first1, beyond1, first2);
    }
    Unique_hash_map( Key first1, Key beyond1, Data first2,
                     const Data& deflt,
                     std::size_t table_size   = 1,
                     const Hash_function& fct = Hash_function())
    : m_hash_function(fct), m_map( table_size) {
        m_map.xdef() = deflt;
        insert( first1, beyond1, first2);
    }

    Data default_value() const { return m_map.cxdef(); }

    Hash_function  hash_function() const { return m_hash_function; }

    void clear() { m_map.clear(); }

    void clear( const Data& deflt) {
        m_map.clear();
        m_map.xdef() = deflt; }

    bool is_defined( const Key& key) const {
        return m_map.lookup( m_hash_function(key)) != 0;
    }

    const Data& operator[]( const Key& key) const {
        Item p = m_map.lookup( m_hash_function(key));
        if ( p != 0 )
            return m_map.inf(p);
        return m_map.cxdef();
    }

    Data& operator[]( const Key& key) {
        return m_map.access( m_hash_function(key));
    }

    Data insert( Key first1, Key beyond1, Data first2) {
        for ( ; first1 != beyond1; (++first1, ++first2)) {
            operator[]( first1) = first2;
        }
        return first2;
    }

    void statistics() const { m_map.statistics(); }
};

CGAL_END_NAMESPACE

#endif // CGAL_UNIQUE_HASH_MAP_H
// EOF
