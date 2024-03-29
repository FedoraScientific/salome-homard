.. _tui_create_boundary:

La fronti�re
############

.. index:: single: boundary
.. index:: single: fronti�re
.. index:: single: cylindre
.. index:: single: sphere

Les variables sont d�crites dans :ref:`gui_create_boundary`.

M�thodes de la classe homard
****************************
Ces m�thodes retournent une instance de la classe boundary.

+----------------------------------------------------------------------------------------+
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryDi                                                           |
|                                                                                        |
| **CreateBoundaryDi(boundary_name, mesh_name, mesh_file)**                              |
|     Retourne une instance de la classe ``boundary`` de type discret apr�s sa cr�ation  |
|                                                                                        |
|     - ``boundary_name`` : le nom de la fronti�re discr�te                              |
|     - ``mesh_name`` : le nom du maillage de la fronti�re                               |
|     - ``mesh_file`` : le nom du fichier contenant ce maillage                          |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryCylinder                                                     |
|                                                                                        |
| **CreateBoundaryCylinder(boundary_name, Xcen, Ycen, Zcen, Xaxe, Yaxe, Zaxe, R)**       |
|     Retourne une instance de la classe ``boundary`` analytique de type cylindrique     |
|     apr�s sa cr�ation                                                                  |
|                                                                                        |
|     - ``boundary_name`` : le nom de la fronti�re analytique bas�e sur un cylindre      |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonn�es d'un point sur l'axe du cylindre      |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe`` : vecteur de l'axe                                  |
|     - ``R`` : rayon du cylindre                                                        |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundarySphere                                                       |
|                                                                                        |
| **CreateBoundarySphere(boundary_name, Xcen, Ycen, Zcen, R)**                           |
|     Retourne une instance de la classe ``boundary`` analytique de type sph�rique       |
|     apr�s sa cr�ation                                                                  |
|                                                                                        |
|     - ``boundary_name`` : le nom de la fronti�re analytique bas�e sur une sphere       |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonn�es du centre de la sph�re                |
|     - ``R`` : rayon de la sph�re                                                       |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryConeA                                                        |
|                                                                                        |
| **CreateBoundaryConeA(boundary_name, Xaxe, Yaxe, Zaxe, Angle, Xcen, Ycen, Zcen)**      |
|     Retourne une instance de la classe ``boundary`` analytique de type conique         |
|     apr�s sa cr�ation                                                                  |
|                                                                                        |
|     - ``boundary_name`` : le nom de la fronti�re analytique bas�e sur un c�ne          |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe`` : vecteur de l'axe (non n�cessairement norm�)       |
|     - ``Angle`` : angle d'ouverture du c�ne en degre (entre 0 et 90)                   |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonn�es du centre du c�ne                     |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryConeR                                                        |
|                                                                                        |
| **CreateBoundaryConeR(boundary_name, Xc1, Yc1, Zc1, R1, Xc2, Yc2, Zc2, R2)**           |
|     Retourne une instance de la classe ``boundary`` analytique de type conique         |
|     apr�s sa cr�ation                                                                  |
|                                                                                        |
|     - ``boundary_name`` : le nom de la fronti�re analytique bas�e sur un c�ne          |
|     - ``Xc1``, ``Yc1``, ``Zc1`` : coordonn�es du premier centre du c�ne                |
|     - ``R1`` : rayon du c�ne � la hauteur du premier centre                            |
|     - ``Xc2``, ``Yc2``, ``Zc2`` : coordonn�es du second centre du c�ne                 |
|     - ``R2`` : rayon du c�ne � la hauteur du second centre                             |
+----------------------------------------------------------------------------------------+
| .. module:: CreateBoundaryTorus                                                        |
|                                                                                        |
| **CreateBoundaryTorus(boundary_name, Xcen, Ycen, Zcen, Xaxe, Yaxe, Zaxe, RRev, RPri)** |
|     Retourne une instance de la classe ``boundary`` analytique de type torique         |
|     apr�s sa cr�ation                                                                  |
|                                                                                        |
|     - ``boundary_name`` : le nom de la fronti�re analytique bas�e sur un tore          |
|     - ``Xcen``, ``Ycen``, ``Zcen`` : coordonn�es du centre du tore                     |
|     - ``Xaxe``, ``Yaxe``, ``Zaxe`` : vecteur de l'axe                                  |
|     - ``RRev`` : rayon de r�volution du tore                                           |
|     - ``RPri`` : rayon primaire du tore                                                |
+----------------------------------------------------------------------------------------+

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetBoundary                                       |
|                                                               |
| **GetBoundary(boundary_name)**                                |
|     Retourne l'instance de la classe ``boundary`` connue par  |
|     son nom                                                   |
|                                                               |
|     - ``boundary_name`` : le nom de la fronti�re              |
+---------------------------------------------------------------+
| .. module:: GetAllBoundarysName                               |
|                                                               |
| **GetAllBoundarysName()**                                     |
|     Retourne la liste des noms de toutes les fronti�res       |
|     existantes                                                |
|                                                               |
+---------------------------------------------------------------+

M�thodes de la classe cas
*************************
Voir �galement dans :ref:`tui_create_case`.

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddBoundaryGroup                                  |
|                                                               |
| **AddBoundaryGroup(boundary, group)**                         |
|     Ajoute une fronti�re � la d�finition du cas               |
|                                                               |
|     - ``boundary`` : nom d'une fronti�re courbe � suivre      |
|                                                               |
|     Pour une fronti�re discr�te :                             |
|                                                               |
|     . si toutes les lignes courbes sont suivies, le second    |
|     argument est une cha�ne vide.                             |
|                                                               |
|     . si seulement certaines lignes courbes sont suivies,     |
|     ``group`` est le nom d'un groupe de segments � suivre.    |
|                                                               |
|     Pour une fronti�re analytique :                           |
|                                                               |
|     - ``group`` : nom d'un groupe de faces plac�es sur la     |
|       fronti�re                                               |
+---------------------------------------------------------------+

M�thodes de la classe boundary
******************************

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de la fronti�re                           |
+---------------------------------------------------------------+
| .. module:: GetType                                           |
|                                                               |
| **GetType()**                                                 |
|     Retourne le type de la fronti�re :                        |
|                                                               |
|         * 0 : discr�te                                        |
|         * 1 : cylindre                                        |
|         * 2 : sph�re                                          |
|         * 3 : c�ne d�fini par un axe et un angle              |
|         * 4 : c�ne d�fini par deux rayons                     |
|         * 5 : tore                                            |
+---------------------------------------------------------------+
| .. module:: GetCoords                                         |
|                                                               |
| **GetCoords()**                                               |
|     Retourne un tableau contenant les coordonn�es de la       |
|     fronti�re dans l'ordre d'entr�e dans le CreateBoundaryXXXX|
|     associ�                                                   |
+---------------------------------------------------------------+
| .. module:: Delete                                            |
|                                                               |
| **Delete()**                                                  |
|     Detruit la fronti�re.                                     |
|     Pour une fronti�re discr�te, le fichier du maillage       |
|     associ� est conserv�.                                     |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : destruction r�ussie                             |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+


Exemple
*******
Cr�ation d'une fronti�re discr�te, d'une fronti�re sph�rique, puis d'une fronti�re cylindrique : ::

    inter = homard.CreateBoundaryDi("INTERSECTION", 'PIQUAGE', dircase+'/tutorial_4.fr.med')
    fron_1 = homard.CreateBoundarySphere("FRON_1", 12.3, 3.4, .56, 6.5)
    fron_2 = homard.CreateBoundaryCylinder('CYL_1', 0.0, 25., -25., 25., 50., 75., 100.)


Saisie graphique correspondante
*******************************
Consulter :ref:`gui_create_boundary`
