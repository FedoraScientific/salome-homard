.. _tui_create_case:

Le cas
======
.. index:: single: cas
.. index:: single: type de conformité
.. index:: single: maillage;initial

Les variables sont décrites dans :ref:`gui_create_case`.

Méthodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+===============================================================+
| .. module:: CreateCase                                        |
|                                                               |
| **CreateCase(case_name, mesh_name, mesh_file)**               |
|     Retourne une instance de la classe cas                    |
|                                                               |
|     - ``case_name`` : le nom du cas                           |
|     - ``mesh_name`` : le nom du maillage initial              |
|     - ``mesh_file`` : le nom du fichier contenant ce maillage |
|                                                               |
| Par défaut :                                                  |
|                                                               |
|  * le répertoire des résultats est ``/tmp``                   |
|  * l'adaptation est conforme                                  |
+---------------------------------------------------------------+


Méthodes de la classe cas
"""""""""""""""""""""""""

+---------------------------------------------------------------+
+===============================================================+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom du cas                                    |
+---------------------------------------------------------------+
| .. module:: SetDirName                                        |
|                                                               |
| **SetDirName(dirname)**                                       |
|                                                               |
|     - ``dirname`` : le nom du répertoire des résutats         |
+---------------------------------------------------------------+
| .. module:: GetDirName                                        |
|                                                               |
| **GetDirName()**                                              |
|     Retourne le nom du répertoire des résutats associé au cas |
+---------------------------------------------------------------+
| .. module:: SetConfType                                       |
|                                                               |
| **SetConfType(conf_type)**                                    |
|                                                               |
|     - ``conf_type`` :  entier précisant le mode de conformité |
|                                                               |
|         1. conforme                                           |
|         2. non conforme avec 1 noeud par maille               |
|         3. non conforme avec 1 noeud par arete de maille      |
|         4. non conforme quelconque                            |
+---------------------------------------------------------------+
| .. module:: GetConfType                                       |
|                                                               |
| **GetConfType()**                                             |
|     Retourne le type de conformité                            |
+---------------------------------------------------------------+
| .. module:: GetIter0Name                                      |
|                                                               |
| **GetIter0Name()**                                            |
|     Retourne le nom de l'itération 0, associée au maillage    |
|     initial. Ce nom est mis automatiquement par le module     |
|     HOMARD et doit être utilisé pour enchaîner les adaptations|
+---------------------------------------------------------------+


Exemple
"""""""
La création de l'objet case_1 se fait ainsi : ::

    case_name = "CAS_1"
    mesh_name = "MAILL"
    mesh_file = "/local00/Salome/Adapt/m0.med"
    case_1 = homard.CreateCase(case_name, mesh_name, mesh_file)
    dirname = "/local00/Salome/Adapt/resu"
    case_1.SetDirName(dirname)
    case_1.SetConfType(1)




