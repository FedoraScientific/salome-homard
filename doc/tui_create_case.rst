.. _tui_create_case:

Le cas
======
.. index:: single: cas
.. index:: single: type de conformit�
.. index:: single: maillage;initial

Les variables sont d�crites dans :ref:`gui_create_case`.

M�thodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateCase                                        |
|                                                               |
| **CreateCase(case_name, mesh_name, mesh_file)**               |
|     Retourne une instance de la classe ``cas`` apr�s sa       |
|     cr�ation                                                  |
|                                                               |
|     - ``case_name`` : le nom du cas                           |
|     - ``mesh_name`` : le nom du maillage initial              |
|     - ``mesh_file`` : le nom du fichier contenant ce maillage |
|                                                               |
| Par d�faut :                                                  |
|                                                               |
|  * le r�pertoire des r�sultats est ``/tmp``                   |
|  * l'adaptation est conforme                                  |
+---------------------------------------------------------------+
| .. module:: GetCase                                           |
|                                                               |
| **GetCase(case_name)**                                        |
|     Retourne l'instance de la classe ``cas`` connue par       |
|     son nom                                                   |
|                                                               |
|     - ``case_name`` : le nom du cas                           |
+---------------------------------------------------------------+
| .. module:: GetAllCasesName                                   |
|                                                               |
| **GetAllCasesName()**                                         |
|     Retourne la liste des noms de tous les cas cr��s          |
|                                                               |
+---------------------------------------------------------------+


M�thodes de la classe cas
"""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom du cas                                    |
+---------------------------------------------------------------+
| .. module:: SetDirName                                        |
|                                                               |
| **SetDirName(dirname)**                                       |
|     Affecte le r�pertoire des r�sutats associ� au cas         |
|                                                               |
|     - ``dirname`` : le nom du r�pertoire des r�sutats         |
+---------------------------------------------------------------+
| .. module:: GetDirName                                        |
|                                                               |
| **GetDirName()**                                              |
|     Retourne le nom du r�pertoire des r�sutats associ� au cas |
+---------------------------------------------------------------+
| .. module:: SetConfType                                       |
|                                                               |
| **SetConfType(conf_type)**                                    |
|     D�finit le mode de conformit� associ� au cas              |
|                                                               |
|     - ``conf_type`` : entier pr�cisant le mode de conformit�  |
|                                                               |
|         * 1 : conforme                                        |
|         * 2 : non conforme avec 1 noeud par maille            |
|         * 3 : non conforme avec 1 noeud par arete de maille   |
|         * 4 : non conforme quelconque                         |
+---------------------------------------------------------------+
| .. module:: GetConfType                                       |
|                                                               |
| **GetConfType()**                                             |
|     Retourne le type de conformit�                            |
+---------------------------------------------------------------+
| .. module:: GetIter0                                          |
|                                                               |
| **GetIter0()**                                                |
|     Retourne l'it�ration 0, associ�e au maillage initial.     |
|     Cette it�ration est cr��e automatiquement par le module   |
|     HOMARD et est utilis�e pour encha�ner les adaptations.    |
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
|       argument est une cha�ne vide.                           |
|     . si seulement certaines lignes courbes sont suivies,     |
|       ``group`` est le nom d'un groupe de segments � suivre.  |
|                                                               |
|     Pour une fronti�re analytique :                           |
|                                                               |
|     - ``group`` : nom d'un groupe de faces plac�es sur la     |
|       fronti�re                                               |
+---------------------------------------------------------------+
| .. index:: single: Delete                                     |
|                                                               |
| **Delete()**                                                  |
|     Detruit le cas et toutes les it�rations associ�es ainsi   |
|     que tous les maillages produits. Le fichier du maillage   |
|     initial associ� est conserv�.                             |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : destruction r�ussie                             |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+

Les options avanc�es
^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetPyram                                          |
|                                                               |
| **SetPyram(option)**                                          |
|     D�finit le statut des pyramides pour le cas               |
|                                                               |
|     - ``option`` : entier pr�cisant le statut des pyramides   |
|       �ventuellement pr�sentes dans le maillage initial       |
|                                                               |
|         * 0 : pyramides refus�es (d�faut)                     |
|         * 1 : pyramides autoris�es                            |
+---------------------------------------------------------------+
| .. module:: GetPyram                                          |
|                                                               |
| **GetPyram()**                                                |
|     Retourne le statut accord� aux pyramides �ventuellement   |
|     pr�sentes dans le maillage initial                        |
+---------------------------------------------------------------+

Informations sur le maillage initial
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: MeshInfo                                          |
|                                                               |
| **MeshInfo(Qual, Diam, Conn, Tail, Inte)**                    |
|     Donne des informations sur le maillage. Pour chaque       |
|     option, le choix 0 correspond � ne rien faire, alors que  |
|     le choix 1 active l'option.                               |
|                                                               |
|     - ``Qual`` : qualit� des mailles                          |
|     - ``Diam`` : diam�tre des mailles                         |
|     - ``Conn`` : connexit� du domaine ; en un seul morceau,   |
|       combien de trous, etc.                                  |
|     - ``Tail`` : tailles des constituants du domaine, groupe  |
|       par groupe                                              |
|     - ``Inte`` : interp�n�tration des mailles, par dimension  |
+---------------------------------------------------------------+


Exemple
"""""""
La cr�ation de l'objet case_1 se fait ainsi : ::

    case_name = "CAS_1"
    mesh_name = "MAILL"
    mesh_file = "/local00/Salome/Adapt/m0.med"
    case_1 = homard.CreateCase(case_name, mesh_name, mesh_file)
    dirname = "/local00/Salome/Adapt/resu"
    case_1.SetDirName(dirname)
    case_1.SetConfType(1)
    case_1.AddBoundaryGroup( 'intersection', '' )
    case_1.AddBoundaryGroup( 'cyl_1', 'T1_EXT' )
    case_1.AddBoundaryGroup( 'cyl_1', 'T2_EXT' )
    case_1.AddBoundaryGroup( 'cyl_2', 'T_INT' )



Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_case`


