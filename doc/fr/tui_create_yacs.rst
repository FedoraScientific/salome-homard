.. _tui_create_yacs:

Le sch�ma YACS
##############

.. index:: single: YACS

Les variables sont d�crites dans :ref:`gui_create_yacs`.

M�thodes de la classe cas
*************************
Voir �galement dans :ref:`tui_create_case`.

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateYACSSchema                                  |
|                                                               |
| **CreateYACSSchema(yacs_name, ScriptFile, DirName, MeshFile)**|
|     Retourne une instance de la classe ``yacs`` apr�s sa      |
|     cr�ation                                                  |
|                                                               |
|     - ``yacs_name`` : le nom du sch�ma                        |
|     - ``ScriptFile`` : le fichier du script python qui permet |
|       de lancer le calcul � coupler avec l'adaptation de      |
|       maillage                                                |
|     - ``DirName`` : le r�pertoire o� a lieu le calcul         |
|     - ``MeshFile`` : le fichier MED contenant le tout premier |
|       maillage de calcul                                      |
+---------------------------------------------------------------+

M�thodes de la classe homard
****************************

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetYACS                                           |
|                                                               |
| **GetYACS(yacs_name)**                                        |
|     Retourne l'instance de la classe ``yacs`` connue par      |
|     son nom                                                   |
|                                                               |
|     - ``yacs_name`` : le nom du sch�ma                        |
+---------------------------------------------------------------+
| .. module:: GetAllYACSsName                                   |
|                                                               |
| **GetAllYACSsName()**                                         |
|     Retourne la liste des noms de tous les sch�mas existant   |
+---------------------------------------------------------------+



M�thodes de la classe YACS
**************************

G�n�ralit�s
===========

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: Write                                             |
|                                                               |
| **Write()**                                                   |
|     Ecrit le sch�ma dans le fichier li� au sch�ma             |
|     Par d�faut, c'est le fichier ``schema.xml``, dans le      |
|     r�pertoire du cas. Si ``WriteOnFile`` a �t� utilis�       |
|     auparavant, l'�criture a lieu dans le nouveau fichier.    |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : �criture r�ussie                                |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+
| .. module:: WriteOnFile                                       |
|                                                               |
| **WriteOnFile(file_xml)**                                     |
|     Ecrit le sch�ma dans un fichier d�sign�.                  |
|                                                               |
|     - ``file_xml`` : nom du fichier xml du sch�ma             |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : �criture r�ussie                                |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+
| .. module:: Delete                                            |
|                                                               |
| **Delete(option)**                                            |
|     Detruit le sch�ma.                                        |
|                                                               |
|     - ``option`` : un entier pr�cisant ce qui est fait du     |
|       fichier xml du sch�ma                                   |
|                                                               |
|         * 0 : le fichier est conserv�                         |
|         * 1 : le fichier est d�truit                          |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : destruction r�ussie                             |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+


Informations sur le sch�ma
==========================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom du sch�ma                                 |
+---------------------------------------------------------------+
| .. module:: SetType                                           |
|                                                               |
| **SetType(Type)**                                             |
|     D�finit le type de sch�ma.                                |
|                                                               |
|     - ``Type`` : le type de sch�ma                            |
|                                                               |
|         * 1 : constant                                        |
|         * 2 : variable                                        |
+---------------------------------------------------------------+
| .. module:: GetType                                           |
|                                                               |
| **GetType()**                                                 |
|     Retourne le type du sch�ma                                |
+---------------------------------------------------------------+
| .. module:: SetScriptFile                                     |
|                                                               |
| **SetScriptFile(script_file)**                                |
|     D�finit le fichier du script python de lancement du calcul|
|                                                               |
|     - ``script_file`` : le nom du fichier qui contient le     |
|       le script python                                        |
+---------------------------------------------------------------+
| .. module:: GetScriptFile                                     |
|                                                               |
| **GetScriptFile()**                                           |
|     Retourne le nom du fichier MED qui contient le script     |
|     python                                                    |
+---------------------------------------------------------------+
| .. module:: SetDirName                                        |
|                                                               |
| **SetDirName(dir_name)**                                      |
|     D�finit le nom du r�pertoire de calcul                    |
|                                                               |
|     - ``dir_name`` : le nom du r�pertoire de calcul           |
+---------------------------------------------------------------+
| .. module:: GetDirName                                        |
|                                                               |
| **GetDirName()**                                              |
|     Retourne le nom du r�pertoire de calcul                   |
+---------------------------------------------------------------+
| .. module:: SetMeshFile                                       |
|                                                               |
| **SetMeshFile(mesh_file)**                                    |
|     D�finit le fichier MED du tout premier maillage           |
|                                                               |
|     - ``mesh_file`` : le nom du fichier MED contenant le tout |
|       premier maillage de calcul                              |
+---------------------------------------------------------------+
| .. module:: GetMeshFile                                       |
|                                                               |
| **GetMeshFile()**                                             |
|     Retourne le nom du fichier MED du tout premier maillage   |
|     de calcul                                                 |
+---------------------------------------------------------------+
| .. module:: SetXMLFile                                        |
|                                                               |
| **SetXMLFile(xml_file)**                                      |
|     D�finit le fichier xml pour l'�criture                    |
|                                                               |
|     - ``xml_file`` : le nom du fichier xml                    |
+---------------------------------------------------------------+
| .. module:: GetXMLFile                                        |
|                                                               |
| **GetXMLFile()**                                              |
|     Retourne le nom du fichier xml                            |
+---------------------------------------------------------------+


Exemple
*******
La cr�ation d'un sch�ma se fait ainsi :
::

    ScriptFile = "/scratch/D68518/Salome/HOMARD_SALOME/HOMARD_SRC/doc/files/ScriptAster.py"
    DirName = "/scratch/D68518/calcul"
    MeshFile = "/scratch/D68518/calcul/maill.00.med"
    YACS_0 = Case.CreateYACSSchema("YACS_0", ScriptFile, DirName, MeshFile)

On peut ensuite l'�crire dans un fichier :
::

    YACSFile = "/scratch/D68518/calcul/yacs.xml"
    codret = YACS_0.WriteOnFile(YACSFile)

Saisie graphique correspondante
*******************************
Consulter :ref:`gui_create_yacs`



