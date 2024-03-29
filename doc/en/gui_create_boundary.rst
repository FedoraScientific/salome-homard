.. _gui_create_boundary:

The boundary
############
.. index:: single: boundary
.. index:: single: fronti�re

The object boundary contains all the geometrical definitions allowing to describe a curved boundary to be followed.

There are two modes of description of a boundary:

  - Discrete: this mode is used to describe a curve 1D
  - Analytics: this mode is used to describe a surface


Discrete boundary
*****************

The follow-up of a discrete boundary will be made by selecting a boundary chosen in the list of the existing discrete boundaries.

In the starting up, the list is empty. It is necessary to create a first discrete boundary by activation of the button "*New*" :

.. image:: images/create_boundary_di_1.png
   :align: center

The window invites in the choice of a file of mesh. This mesh is the one of all the lines constituting the boundary. A name of boundary is automatically proposed: Boun_1, Boun_2, etc. This name can be modified. It must not already have been used for another boundary.

.. image:: images/create_boundary_di_2.png
   :align: center

.. note::
  The file has to contain only a single mesh.

If discrete boundaries were already defined for another case, we can select one of them. We can also create a new discrete boundary by activation of the button "*New*", as explained previously.

.. image:: images/create_boundary_di_3.png
   :align: center



Analytical boundary
*******************
In the starting up, SALOME shows a table with one only one column. This column contains the list of all the groups of the initial mesh defining the case.

.. image:: images/create_boundary_an_1.png
   :align: center

It is necessary to create a first analytical boundary by activation of the button "*New*". We shall have the choice between cylinder, sphere, cone or torus. When the boundary will be validated, its name will appear in header of the second column.

.. image:: images/create_boundary_an_2.png
   :align: center

It is now necessary to establish the link enter the mesh defining the case and this boundary described analytically. It is made by checking the groups of the faces which have to be on the boundary.

.. image:: images/create_boundary_an_3.png
   :align: center

This operation is repeated as often as we wish to place faces of meshs on a curved surface:

.. image:: images/create_boundary_an_4.png
   :align: center

.. note::

  A group can be checked very well never: it means that the elements which it defines belong to none of the described boundaries.

  A group can be checked only once. Indeed, surface elements cannot belong to more than one surface.

  Several groups can be checked for the same boundary. It occurs if the initial mesh of the zone was subdivided into several groups: all the surface elements belong to this surface but were distributed in several groups.

  Conversely, a boundary can be very well retained by no group. It occurs if it was defined for a previous case and if it is groundless for the case in the course of definition.


There are three types of analytical boundary:

  - Cylindre
  - Sphere
  - Cone, described by an axis and an angle or by two radius
  - Torus

.. note::
  The numerical values proposed by default take into account the geometry of the mesh.


Cylindre
========
.. index:: single: cylindre

The cylinder is defined by a point of the axis, its axis and its radius. The axis is defined by a vector. The standard of this vector is not inevitably equal to 1; also, its orientation has no importance. A name of boundary is automatically proposed: Boun_1, Boun_2, etc. This name can be modified. It must not already have been used for another boundary.

.. image:: images/create_boundary_an_cy.png
   :align: center

Sphere
======
.. index:: single: sphere

The sphere is defined by its center and its radius. A name of boundary is automatically proposed: Boun_1, Boun_2, etc. This name can be modified. It must not already have been used for another boundary.

.. image:: images/create_boundary_an_sp.png
   :align: center

Cone
====
.. index:: single: cone

A cone is defined by two different manners: the center, the axis and the angle of opening in degree or by two points centered on the axis and the associated radius. A name of boundary is automatically proposed: Boun_1, Boun_2, etc. This name can be modified. It must not already have been used for another boundary.

Creation by an origin, an axis and an angle of opening:

.. image:: images/create_boundary_an_co_1.png
   :align: center

Creation by two points centered on the axis and the associated radius:

.. image:: images/create_boundary_an_co_2.png
   :align: center

.. index:: single: object browser

Torus
=====
.. index:: single: torus

The torus is defined by its centre, its axis, the revolution radius and the primary radius. The axis is defined by a vector. The standard of this vector is not inevitably equal to 1; also, its orientation has no importance. A name of boundary is automatically proposed: Boun_1, Boun_2, etc. This name can be modified. It must not already have been used for another boundary.

.. image:: images/create_boundary_an_to.png
   :align: center

Object browser
**************
At the end of this creation of boundaries, the object browser was enriched. We find all the boundaries created, identified there by their name, with the possibility of editing them.

.. image:: images/create_boundary_1.png
   :align: center

Corresponding python functions
******************************
Look :ref:`tui_create_boundary`



