// Copyright (c) 1997  Tel-Aviv University (Israel).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.3-branch/Arrangement_2/include/CGAL/Sweep_line_2/Arr_basic_addition_traits.h $
// $Id$
// 
//
// Author(s)     : Baruch Zukerman <baruchzu@post.tau.ac.il>

#ifndef CGAL_ARR_BASIC_ADDITION_TRAITS_H
#define CGAL_ARR_BASIC_ADDITION_TRAITS_H

#include <CGAL/Object.h> 
#include <list>
#include <iterator>

CGAL_BEGIN_NAMESPACE

template <class Traits_, class Arrangement_>
class Arr_basic_addition_traits 
{
public:

  typedef Traits_                                  Traits_2;
  typedef Arrangement_                             Arrangement_2;

  typedef typename Arrangement_2::Halfedge_handle  Halfedge_handle;
  typedef typename Arrangement_2::Vertex_handle    Vertex_handle;
  typedef typename Traits_2::X_monotone_curve_2    Base_x_monotone_curve_2;
  typedef typename Traits_2::Point_2               Base_point_2;
  typedef typename Traits_2::Construct_min_vertex_2
                                                   Base_Construct_min_vertex_2;
  typedef typename Traits_2::Construct_max_vertex_2
                                                   Base_Construct_max_vertex_2;
  typedef typename Traits_2::Compare_xy_2          Base_Compare_xy_2;
  typedef typename Traits_2::Compare_y_at_x_2      Base_Compare_y_at_x_2;
  typedef typename Traits_2::Compare_y_at_x_right_2 
                                                   Base_Compare_y_at_x_right_2;
  typedef typename Traits_2::Equal_2               Base_Equal_2;
  typedef typename Traits_2::Compare_x_2           Base_Compare_x_2;
  typedef typename Traits_2::Is_vertical_2         Base_Is_vertical_2;
  typedef typename Traits_2::Has_boundary_category Base_has_boundary_category;
  typedef Tag_true                                 Has_boundary_category;
  typedef typename Traits_2::Has_left_category     Has_left_category;

protected:

  Traits_2*    m_base_traits;

public:

  Arr_basic_addition_traits() 
  {}

  //Constructor
  Arr_basic_addition_traits (Traits_2& tr):
    m_base_traits (&tr)
  {}

  /*! \class
   * Nested extension of the x-monotone curve type.
   */
  class Ex_x_monotone_curve_2 
  {
  public:

    typedef  Base_x_monotone_curve_2 Base;
    typedef  Base_point_2            Point_2;

    Ex_x_monotone_curve_2() :
      m_base_cv(),
      m_he_handle(),
      m_overlap(false)
    {}

    Ex_x_monotone_curve_2(const Base& cv) :
      m_base_cv(cv),
      m_he_handle(),
      m_overlap(false)
    {}

    Ex_x_monotone_curve_2(const Base& cv, Halfedge_handle he) :
      m_base_cv(cv),
      m_he_handle(he),
      m_overlap(false)
    {}

    const Base& base() const
    {
      return (m_base_cv);
    }

    Base& base()
    {
      return (m_base_cv);
    }

    operator const Base& () const
    {
      return (m_base_cv);
    }

    Ex_x_monotone_curve_2& operator=(const Base& cv)
    {
      m_base_cv = cv;
      m_he_handle = Halfedge_handle();
      return (*this);
    }

    Halfedge_handle get_halfedge_handle() const
    {
      return m_he_handle;
    }

    void set_halfedge_handle(Halfedge_handle he)
    {
      m_he_handle = he;
    }

    bool is_overlapping () const
    {
      return m_overlap;
    }

    void set_overlapping ()
    {
      m_overlap = true;
    }

  protected:
    Base                m_base_cv;
    Halfedge_handle     m_he_handle;
    bool                m_overlap;

  };

  friend std::ostream& operator<< (std::ostream& os, 
                                   const Ex_x_monotone_curve_2 & cv)
  {
    os << cv.base();
    return (os);
  }

  /*! \class
   * Nested extension of the point type.
   */
  class Ex_point_2 
  {
  public:
    typedef  Base_point_2            Base;

    Ex_point_2(): m_base_pt(),
                  m_v(NULL)
    {}

    Ex_point_2(const Base& pt): m_base_pt(pt),
                                m_v(NULL)
    {}

    Ex_point_2(const Base& pt, Vertex_handle v): m_base_pt(pt),
                                                 m_v(v)
    {}

    const Base& base() const
    {
      return (m_base_pt);
    }
    
    operator const Base& () const
    {
      return (m_base_pt);
    }

    Vertex_handle get_vertex_handle() const
    {
      return m_v;
    }

    void set_vertex_handle(Vertex_handle v)
    {
      m_v = v;
    }
    
  protected:
    Base             m_base_pt;
    Vertex_handle    m_v;

  };

  friend std::ostream& operator<< (std::ostream& os, const Ex_point_2 & p)
  {
    os << p.base();
    return (os);
  }
  
  typedef Ex_x_monotone_curve_2                     X_monotone_curve_2;
  typedef Ex_point_2                                Point_2;


  /*! \class
   * The Boundary_in_x_2 functor.
   */
  class Boundary_in_x_2
  {
  public:

    Boundary_type operator() (const X_monotone_curve_2& cv,
                              Curve_end ind) const
    {
      return _boundary_in_x_imp (cv, ind, Base_has_boundary_category());
    }

  private:

    Boundary_type _boundary_in_x_imp (const X_monotone_curve_2& cv,
                                      Curve_end ind,
                                      Tag_true) const
    {
      Traits_2                    tr;
      return (tr.boundary_in_x_2_object() (cv.base(), ind));
    }

    Boundary_type _boundary_in_x_imp (const X_monotone_curve_2& , Curve_end ,
                                      Tag_false) const
    {
      return (NO_BOUNDARY);
    }
  };

  Boundary_in_x_2 boundary_in_x_2_object () const
  {
    return Boundary_in_x_2();
  }

  /*! \class
   * The Boundary_in_y_2 functor.
   */
  class Boundary_in_y_2
  {
  public:

    Boundary_type operator() (const X_monotone_curve_2& cv,
                              Curve_end ind) const
    {
      return _boundary_in_y_imp (cv, ind, Base_has_boundary_category());
    }

  private:

    Boundary_type _boundary_in_y_imp (const X_monotone_curve_2& cv,
                                      Curve_end ind,
                                      Tag_true) const
    {
      Traits_2                    tr;
      return (tr.boundary_in_y_2_object() (cv.base(), ind));
    }

    Boundary_type _boundary_in_y_imp (const X_monotone_curve_2& , Curve_end ,
                                      Tag_false) const
    {
      return (NO_BOUNDARY);
    }
  };

  Boundary_in_y_2 boundary_in_y_2_object () const
  {
    return Boundary_in_y_2();
  }

  /*! \class
   * The Construct_min_vertex_2 functor.
   */
  class Construct_min_vertex_2
  {
  private:
    Base_Construct_min_vertex_2 m_base_min_v;
    Base_Equal_2                m_base_equal;

  public:

    Construct_min_vertex_2 (const Base_Construct_min_vertex_2& base_min_v,
                            const Base_Equal_2& base_equal):
      m_base_min_v (base_min_v),
      m_base_equal (base_equal)
    {}

    Point_2 operator() (const X_monotone_curve_2 & cv) 
    {
      // If there is not halfedge associated with the curve, just return
      // a point with invalid halfedge handle.
      const Base_point_2&  base_p = m_base_min_v(cv.base());

      if (cv.get_halfedge_handle() == Halfedge_handle())
        return (Point_2 (base_p, Vertex_handle()));

      // We probably have to associate the point with the target vertex of
      // the halfedge associated with the curve.
      Vertex_handle        vh = cv.get_halfedge_handle()->target();

      if (! cv.is_overlapping())
        return (Point_2(base_p, vh));

      // In case of an overlapping curve, make sure the curve endpoint equals
      // the point associated with the vertex. If not, we attach an invalid
      // vertex to the extended point.
      if (! vh->is_at_infinity() && m_base_equal (base_p, vh->point()))
        return (Point_2(base_p, vh));
      else
        return (Point_2 (base_p, Vertex_handle()));
    }
  };

  Construct_min_vertex_2 construct_min_vertex_2_object () const
  {
    return (Construct_min_vertex_2
                (m_base_traits->construct_min_vertex_2_object(),
                 m_base_traits->equal_2_object()));
  }

  /*! \class
   * The Construct_max_vertex_2 functor.
   */
  class Construct_max_vertex_2
  {
  private:
    Base_Construct_max_vertex_2 m_base_max_v;
    Base_Equal_2                m_base_equal;

  public:

    Construct_max_vertex_2 (const Base_Construct_max_vertex_2& base_max_v,
                            const Base_Equal_2& base_equal):
      m_base_max_v (base_max_v),
      m_base_equal (base_equal)
    {}

    Point_2 operator() (const X_monotone_curve_2 & cv) 
    {
      // If there is not halfedge associated with the curve, just return
      // a point with invalid halfedge handle.
      const Base_point_2&  base_p = m_base_max_v(cv.base());

      if (cv.get_halfedge_handle() == Halfedge_handle())
        return (Point_2 (base_p, Vertex_handle()));

      // We probably have to associate the point with the source vertex of
      // the halfedge associated with the curve.
      Vertex_handle        vh = cv.get_halfedge_handle()->source();

      if (! cv.is_overlapping())
        return (Point_2(base_p, vh));

      // In case of an overlapping curve, make sure the curve endpoint equals
      // the point associated with the vertex. If not, we attach an invalid
      // vertex to the extended point.
      if (! vh->is_at_infinity() && m_base_equal (base_p, vh->point()))
        return (Point_2(base_p, vh));
      else
        return (Point_2 (base_p, Vertex_handle()));
    }
  };

  Construct_max_vertex_2 construct_max_vertex_2_object () const
  {
    return (Construct_max_vertex_2
                (m_base_traits->construct_max_vertex_2_object(),
                 m_base_traits->equal_2_object()));
  }

  /*! \class
   * The Comapre_xy_2 functor.
   */
  class Compare_xy_2
  {
  private:
    Base_Compare_xy_2 m_base_cmp_xy;

  public:

    Compare_xy_2(const Base_Compare_xy_2& base):
        m_base_cmp_xy(base)
    {}

    Comparison_result operator() (const Point_2& p1, const Point_2& p2) const
    {
      if(p1.get_vertex_handle() == p2.get_vertex_handle() &&
         p1.get_vertex_handle() != Vertex_handle())
        return EQUAL;

      return (m_base_cmp_xy(p1.base(), p2.base()));
    }
  };

  Compare_xy_2 compare_xy_2_object () const
  {
    return (Compare_xy_2 (m_base_traits->compare_xy_2_object()));
  }

  /*! \class
   * The Comapre_y_at_x_2 functor.
   */
  class Compare_y_at_x_2
  {
  private:
    Base_Compare_y_at_x_2 m_base_cmp_y_at_x;

  public:
    Compare_y_at_x_2(const Base_Compare_y_at_x_2& base):
        m_base_cmp_y_at_x(base)
    {}

    Comparison_result operator() (const Point_2& p,
                                  const X_monotone_curve_2& cv) const
    {
      return (m_base_cmp_y_at_x (p.base(), cv.base()));
    }

    Comparison_result operator() (const X_monotone_curve_2& cv1,
                                  const X_monotone_curve_2& cv2, 
                                  Curve_end ind) const
    {
      // The function is implemented based on the Has_infinite category.
      // If the traits class does not support unbounded curves, we just
      // return EQUAL, as this comparison will not be invoked anyway.
      return _comp_y_at_infinity_imp (cv1, cv2, ind, 
                                      Base_has_boundary_category());
    }

  private:

    Comparison_result _comp_y_at_infinity_imp (const X_monotone_curve_2& cv1,
                                               const X_monotone_curve_2& cv2, 
                                               Curve_end ind,
                                               Tag_true) const
    {
      return (m_base_cmp_y_at_x (cv1.base(), cv2.base(), ind));
    }

    Comparison_result _comp_y_at_infinity_imp (const X_monotone_curve_2& ,
                                               const X_monotone_curve_2& , 
                                               Curve_end ,
                                               Tag_false) const
    {
      return (EQUAL);
    }
  };

  Compare_y_at_x_2 compare_y_at_x_2_object () const
  {
    return (Compare_y_at_x_2 (m_base_traits->compare_y_at_x_2_object()));
  }

  /*! \class
   * The Comapre_y_at_x_right_2 functor.
   */
  class Compare_y_at_x_right_2
  {
  private:
    Base_Compare_y_at_x_right_2 m_base_cmp_y_at_x_right;

  public:
    Compare_y_at_x_right_2(const Base_Compare_y_at_x_right_2& base):
        m_base_cmp_y_at_x_right(base)
    {}

    Comparison_result operator() (const X_monotone_curve_2& cv1,
                                  const X_monotone_curve_2& cv2,
                                  const Point_2& p) const
    {
      return (m_base_cmp_y_at_x_right(cv1.base(),
                                      cv2.base(),
                                      p.base()));
    }
  };

  Compare_y_at_x_right_2 compare_y_at_x_right_2_object () const
  {
    return (Compare_y_at_x_right_2
	    (m_base_traits->compare_y_at_x_right_2_object()));
  }

  /*! \class
   * The Equal_2 functor.
   */
  class Equal_2
  {
  private:
    Base_Equal_2 m_base_eq;

  public:
    
    Equal_2(const Base_Equal_2& base):
        m_base_eq(base)
    {}

    /*! Check if two curves are the same. */
    bool operator() (const X_monotone_curve_2& cv1,
		     const X_monotone_curve_2& cv2) const
    {
      return (m_base_eq(cv1.base(), cv2.base()));
    }

    /*! Check if the two points are the same. */
    bool operator() (const Point_2& p1, const Point_2& p2) const
    {
      return (m_base_eq(p1.base(), p2.base()));
    }
  };

  Equal_2 equal_2_object () const
  {
    return (Equal_2 (m_base_traits->equal_2_object()));
  }

  /*! \class
   * The Comapre_x_2 functor.
   */
  class Compare_x_2
  {
  private:
    Base_Compare_x_2 m_base_cmp_x;

  public:
    Compare_x_2(const Base_Compare_x_2& base):
        m_base_cmp_x(base)
    {}

    Comparison_result operator() (const Point_2& p1, const Point_2& p2) const
    {
      return (m_base_cmp_x(p1.base(), p2.base()));
    }

    Comparison_result operator() (const Point_2& p,
                                  const X_monotone_curve_2& cv,
                                  Curve_end ind) const
    {
      return (_compare_point_curve_imp (p, cv, ind,
                                        Base_has_boundary_category()));
    }

    Comparison_result operator() (const X_monotone_curve_2& cv1,
                                  Curve_end ind1,
                                  const X_monotone_curve_2& cv2,
                                  Curve_end ind2) const
    {
      return (_compare_curves_imp (cv1, ind1, cv2, ind2,
                                   Base_has_boundary_category()));
    }

  private:

    Comparison_result _compare_point_curve_imp (const Point_2& p,
                                                const X_monotone_curve_2& cv,
                                                Curve_end ind,
                                                Tag_true) const
    {
      return (m_base_cmp_x (p.base(), cv.base(), ind));
    }

    Comparison_result _compare_point_curve_imp (const Point_2& ,
                                                const X_monotone_curve_2& ,
                                                Curve_end ,
                                                Tag_false) const
    {
      return (EQUAL);
    }

    Comparison_result _compare_curves_imp (const X_monotone_curve_2& cv1, 
                                           Curve_end ind1,
                                           const X_monotone_curve_2& cv2,
                                           Curve_end ind2,
                                           Tag_true) const
    {
      return (m_base_cmp_x (cv1.base(), ind1, cv2.base(), ind2));
    }

    Comparison_result _compare_curves_imp (const X_monotone_curve_2& ,
                                           Curve_end,
                                           const X_monotone_curve_2& , 
                                           Curve_end,
                                           Tag_false) const
    {
      return (EQUAL);
    }

  };

  Compare_x_2 compare_x_2_object () const
  {
    return (Compare_x_2 (m_base_traits->compare_x_2_object()));
  }

  /*! \class
   * The Is_vertical_2 functor.
   */
  class Is_vertical_2
  {
  private:
    Base_Is_vertical_2 m_base_is_vert;

  public:
    Is_vertical_2(const Base_Is_vertical_2& base):
        m_base_is_vert(base)
    {}

     bool operator() (const X_monotone_curve_2& cv) const
    {
      return (m_base_is_vert(cv.base()));
    }
  };

  Is_vertical_2 is_vertical_2_object() const
  {
    return (Is_vertical_2(m_base_traits->is_vertical_2_object()));
  }
};


CGAL_END_NAMESPACE

#endif