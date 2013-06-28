.. _gui_create_case:

The creation of a case
######################
.. index:: single: case

The definition of a case is done with the following data:

  - A name
  - A directory
  - The file of the initial mesh
  - The type of conformity for the serie of adaptations
  - Some curved boundaries

.. image:: images/create_case_1.png
   :align: center


Name of the case
****************
A name is automatically suggested for the case: Case_1, Case_2, etc. This name can be modified. It must be a new name.

The directory
*************
The directory will countain all the files producted by the successive adaptations. By default, nothing is suggested. The choice is made either by giving a name into the text zone or by a selection through the search window. In this directory, the MED files for the adapted mesh will be stored, with name ``maill.xx.med``, where ``xx`` is a rank number automatically created. These files can be seen into the object browser.

.. image:: images/create_case_2.png
   :align: center

.. index:: single: mesh;initial
.. index:: single: MED

The initial mesh
****************
The initial mesh must be stored into a MED file. Usually, it is produced by the software that solves the physical problem. But it also can be created by the module SMESH and exported with the MED format. The name of the file is choosen either by giving a name into the text zone or by a selection through the search window.


.. image:: images/create_case_3.png
   :align: center

.. note::
  Only one mesh into the file.

.. warning::
  The initial mesh must not be itself the product of an adaptation by HOMARD. If it is, the coherence between the different levels of refinement will be lost.


.. index:: single: conformity

Type of conformity
******************
The future iterations for this case must respect the the same behaviour regarding the type of conformity.

The default option, 'conformal', implies that the meshes produced by HOMARD will be conformal, as expected in the finite element method. This is a classical choice for most of the simulation software with the finite element method.

Nevertheless, if the computation is available with non conformal meshes, 3 possibilities are available:


.. image:: images/create_case_4.png
   :align: center

* 1 node per element: an element must not have more than one hanging node with its neighbours.
* 1 node per edge: every single edge of an element ban be split once while its neighbour is not.
* free: no limit for the number of hanging node.

.. index:: single: boundary

The boundaries
**************
If the limit of the domain is curved, HOMARD can put the new nodes onto these curved limits to avoid some artificial singularities. This technique is effective for external limits as well for internal limits.

Two situations:

* 1D curve: this curve may be defined into a plane, for example for a 2D calculation. It can also be defined into the 3D space, for example to describe the intersection of two surfaces. Such a line is defined with a discrete desription.
* a surface: such a surface is defined with an analytical description.

Check the button:

.. image:: images/create_case_5.png
   :align: center

The definition of the boundaries is described in :ref:`gui_create_boundary`.

.. index:: single: pyramid

Advanced options
****************
Par d�faut, aucune option avanc�e n'est active.

N�anmoins, on peut d�finir une oprion avanc�e :

.. image:: images/create_case_7.png
   :align: center

Par d�faut, HOMARD sait traiter des maillages en 2 ou 3 dimensions et comportant les mailles suivantes :
   - mailles-points
   - segments
   - triangles
   - quadrangles
   - t�tra�dres
   - hexa�dres
   - prismes

Si le maillage initial comporte des pyramides, il y a arr�t en erreur. Toutefois, si on est certain que les raffinements ult�rieurs ne toucheront aucune des ar�tes des pyramides, on cochera la case "Pyramides autoris�es". Les adaptations se d�rouleront normalement et les pyramides seront restitu�es telles quelles dans le maillage final.


The pursuit of a case
*********************
.. index:: single: pursuit
.. index:: single: yacs

La poursuite d'un cas correspond � la situation suivante :
Une s�rie d'adaptations ont �t� conduites sur un cas puis SALOME est ferm�. On a gard� les r�pertoires de travail de ces it�rations. On souhaite ensuite reprendre ces it�rations pour les poursuivre l� o� on s'est arr�t�. Cette fonctionnalit� est particuli�rement utile dans le cas de sch�mas YACS pour lesquels on scinde en plusieurs parties une longue s�rie d'adaptations.

La condition pour reprendre une it�ration est d'avoir conserv� dans un m�me r�pertoire deux fichiers :
   - le fichier de configuration qui a servi de donn�es au module ex�cutable de HOMARD ; ce fichier se pr�sente sous la forme ``HOMARD.Configuration.(n).vers.(n+1)``
   - le fichier au format MED qui conserve l'historique des adaptations r�alis�es ; ce fichier se pr�sente sous la forme ``maill.(n).hom.med``

On peut choisir de partir d'une it�ration archiv�e d�sign�e explicitement par son r�pertoire ou d'une it�ration rep�r�e dans le r�pertoire archivant un cas.

Pour poursuivre une it�ration connue par son r�pertoire d'archive, la d�finition du cas se fait par la donn�e des informations suivantes :

  - Un nom
  - Un r�pertoire
  - Le r�pertoire qui contient les archives

.. image:: images/pursue_case_1.png
   :align: center

On peut choisir de partir d'un cas d�j� calcul� ; par d�faut, le nouveau cas sera cr�� en partant de la derni�re it�ration pr�c�demment calcul�e.

.. image:: images/pursue_case_2.png
   :align: center

Si on souhaite partir d'une it�ration qui ne soit pas la derni�re, il suffit de le pr�ciser :

.. image:: images/pursue_case_3.png
   :align: center

.. note::
  Les param�trages du cas ainsi cr�� sont ceux de l'it�ration poursuivie : mode de conformit� identique par exemple.


Object browser
**************
A l'issue de cette cr�ation de cas, l'arbre d'�tudes a �t� enrichi de ce nouveau cas. On y trouve l'it�ration initiale, identifi�e par le nom du maillage qui a �t� lu dans le fichier fourni.

.. image:: images/create_case_6.png
   :align: center



Corresponding python functions
******************************
Look :ref:`tui_create_case`

