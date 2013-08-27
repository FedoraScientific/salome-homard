.. _tui_create_iteration:

L'it�ration
===========

.. index:: single: it�ration
.. index:: single: hypoth�se
.. index:: single: zone

Les variables sont d�crites dans :ref:`gui_create_iteration`.

M�thodes de la classe homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetIteration                                      |
|                                                               |
| **GetIteration(iter_name)**                                   |
|     Retourne l'instance de la classe ``iteration`` connue par |
|     son nom                                                   |
|                                                               |
|     - ``iter_name`` : le nom de l'it�ration                   |
+---------------------------------------------------------------+
| .. module:: GetAllIterationsName                              |
|                                                               |
| **GetAllIterationsName()**                                    |
|     Retourne la liste des noms de toutes les it�rations cr��es|
|                                                               |
+---------------------------------------------------------------+

M�thodes communes aux classes cas et iteration
""""""""""""""""""""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: NextIteration                                     |
|                                                               |
| **NextIteration(iter_name)**                                  |
|     Retourne une instance de la classe ``iteration`` apr�s    |
|     sa cr�ation. Elle suit imm�diatement :                    |
|                                                               |
|     - pour un cas : l'it�ration initiale, correspondant au    |
|       maillage d�finissant le cas                             |
|     - pour une it�ration : l'it�ration courante               |
|                                                               |
| Par d�faut, le maillage produit a le m�me nom que l'it�ration |
|                                                               |
|     - ``iter_name`` : le nom � donner � la nouvelle it�ration |
+---------------------------------------------------------------+
| .. module:: LastIteration                                     |
|                                                               |
| **LastIteration()**                                           |
|     Retourne une instance de la classe ``iteration``. C'est   |
|     la derni�re cr��e dans la descendance de :                |
|                                                               |
|     - pour un cas : l'it�ration initiale du cas               |
|     - pour une it�ration : l'it�ration courante               |
|                                                               |
|     C'est celle qui est sans fille. Il y a erreur s'il existe |
|     plus d'une branche dans la descendance.                   |
|                                                               |
+---------------------------------------------------------------+

M�thodes de la classe iteration
"""""""""""""""""""""""""""""""

G�n�ralit�s
^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: Compute                                           |
|                                                               |
| **Compute(option1, option2)**                                 |
|     Calcule le maillage correspondant � l'it�ration           |
|                                                               |
|     - ``option1`` : un entier pr�cisant ce qui se passe quand |
|       des fichiers de r�sultats existent d�j�                 |
|                                                               |
|         * 0 : arr�t en erreur                                 |
|         * 1 : �crasement des anciens fichiers                 |
|                                                               |
|     - ``option2`` : un entier pr�cisant ce qui est fait des   |
|       r�sultats                                               |
|                                                               |
|         * 1 : aucune action particuli�re                      |
|         * 2 : publication dans le module SMESH                |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : adaptation r�ussie                              |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de l'it�ration                            |
+---------------------------------------------------------------+
| .. module:: GetNumber                                         |
|                                                               |
| **GetNumber()**                                               |
|     Retourne le num�ro de l'it�ration.                        |
|                                                               |
|     L'it�ration 0 est celle associ�e au maillage initial.     |
|     Ensuite, une it�ration de num�ro N est issue de           |
|     l'adaptation d'une it�ration de num�ro N-1.               |
+---------------------------------------------------------------+
| .. module:: GetIterParent                                     |
|                                                               |
| **GetIterParent()**                                           |
|     Retourne l'it�ration m�re                                 |
+---------------------------------------------------------------+
| .. module:: AssociateHypo                                     |
|                                                               |
| **AssociateHypo(hypo_name)**                                  |
|     Associe une hypoth�se � l'it�ration                       |
|                                                               |
|     - ``hypo_name`` : le nom de l'hypoth�se � associer        |
+---------------------------------------------------------------+
| .. module:: GetHypoName                                       |
|                                                               |
| **GetHypoName()**                                             |
|     Retourne le nom de l'hypoth�se associ�e                   |
+---------------------------------------------------------------+
| .. module:: GetCaseName                                       |
|                                                               |
| **GetCaseName()**                                             |
|     Retourne le nom du cas associ�                            |
+---------------------------------------------------------------+
| .. module:: GetState                                          |
|                                                               |
| **GetState()**                                                |
|     Retourne l'�tat de l'it�ration                            |
|                                                               |
|     - ``2`` : it�ration calcul�e correctement                 |
|     - ``1`` : it�ration non calcul�e                          |
|     - ``<=0`` : it�ration initiale � ne pas calculer, de      |
|       num�ro valant la valeur absolue de l'�tat               |
+---------------------------------------------------------------+
| .. module:: GetLogFile                                        |
|                                                               |
| **GetLogFile()**                                              |
|     Retourne le nom du fichier retra�ant le d�roulement de    |
|     l'ex�cution de HOMARD                                     |
+---------------------------------------------------------------+
| .. module:: GetFileInfo                                       |
|                                                               |
| **GetFileInfo()**                                             |
|     Retourne le nom du fichier contenant l'analyse du maillage|
+---------------------------------------------------------------+
| .. module:: GetDirName                                        |
|                                                               |
| **GetDirName()**                                              |
|     Retourne le nom du r�pertoire des r�sutats associ� �      |
|     l'it�ration                                               |
+---------------------------------------------------------------+
| .. module:: Delete                                            |
|                                                               |
| **Delete(option)**                                            |
|     Detruit l'it�ration et toutes ses filles �ventuelles.     |
|                                                               |
|     - ``option`` : un entier pr�cisant ce qui est fait des    |
|       fichiers de maillage associ�s                           |
|                                                               |
|         * 0 : les fichiers sont conserv�s                     |
|         * 1 : les fichiers sont d�truits                      |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : destruction r�ussie                             |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+

Informations sur les maillages
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetMeshName                                       |
|                                                               |
| **SetMeshName(mesh_name)**                                    |
|     D�finit le nom du maillage produit                        |
|                                                               |
|     - ``mesh_name`` : le nom du maillage produit              |
+---------------------------------------------------------------+
| .. module:: GetMeshName                                       |
|                                                               |
| **GetMeshName()**                                             |
|     Retourne le nom du maillage produit                       |
+---------------------------------------------------------------+
| .. module:: SetMeshFile                                       |
|                                                               |
| **SetMeshFile(mesh_file)**                                    |
|     D�finit le fichier MED du maillage produit                |
|                                                               |
|     - ``mesh_file`` : le nom du fichier MED qui contiendra    |
|       le maillage produit                                     |
+---------------------------------------------------------------+
| .. module:: GetMeshFile                                       |
|                                                               |
| **GetMeshFile()**                                             |
|     Retourne le nom du fichier MED du maillage produit        |
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

Informations sur le champ
^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetFieldFile                                      |
|                                                               |
| **SetFieldFile(field_file)**                                  |
|     D�finit le fichier MED des champs utiles                  |
|                                                               |
|     - ``field_file`` : le nom du fichier MED contenant le     |
|       champ                                                   |
+---------------------------------------------------------------+
| .. module:: SetTimeStepRank                                   |
|                                                               |
| **SetTimeStepRank(TimeStep, Rank)**                           |
|     D�finit les instants pour le champ                        |
|                                                               |
|     Inutile si aucun instant n'est d�fini pour le champ       |
|                                                               |
|     Si un seul instant est d�fini pour le champ, il est pris  |
|     par d�faut.                                               |
|                                                               |
|     - ``TimeStep`` : l'instant o� est pris le champ           |
|     - ``Rank`` : le num�ro d'ordre o� est pris le champ       |
+---------------------------------------------------------------+
| .. module:: SetTimeStepRankLast                               |
|                                                               |
| **SetTimeStepRankLast()**                                     |
|     Pr�cise que le dernier instant enregistr� pour le champ   |
|     est utilis�                                               |
+---------------------------------------------------------------+
| .. module:: GetFieldFileName                                  |
|                                                               |
| **GetFieldFileName()**                                        |
|     Retourne le nom du fichier MED du champ                   |
+---------------------------------------------------------------+
| .. module:: GetTimeStep                                       |
|                                                               |
| **GetTimeStep()**                                             |
|     Retourne l'instant o� est pris le champ                   |
+---------------------------------------------------------------+
| .. module:: GetRank                                           |
|                                                               |
| **GetRank()**                                                 |
|     Retourne le num�ro d'ordre o� est pris le champ           |
+---------------------------------------------------------------+

Divers
^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetInfoCompute                                    |
|                                                               |
| **SetInfoCompute(MessInfo)**                                  |
|     Pr�cise des options d'informations sur le d�roulement du  |
|     calcul de l'it�ration                                     |
|                                                               |
|     - ``MessInfo`` : entier pilotant des �critures, sous la   |
|       forme d'un entier multiple de 2, 3 et 5                 |
|                                                               |
|         * 1 : aucune �criture (d�faut)                        |
|         * 2x : temps de calcul                                |
|         * 3x : fichiers MED                                   |
|         * 5x : m�moire                                        |
+---------------------------------------------------------------+
| .. module:: GetInfoCompute                                    |
|                                                               |
| **GetInfoCompute()**                                          |
|     Retourne les options d'informations sur le d�roulement du |
|     calcul de l'it�ration                                     |
+---------------------------------------------------------------+


Exemple
"""""""
.. index:: single: maillage;initial

Pour la cr�ation de la premi�re it�ration, on part de celle qui correspond au maillage initial. C'est celle contenue dans le cas. ::

    iter_name = "Iteration_1"
    iter_1 = case_1.NextIteration(iter_name)
    iter_1.SetField(field_file)
    iter_1.SetTimeStepRank( 0, 0)
    iter_1.SetMeshName("maill_01")
    iter_1.SetMeshFile("/local00/M.01.med")
    iter_1.AssociateHypo("HypoField")
    codret = iter_1.Compute(1, 2)

Ensuite, on cr�e une it�ration suivante � l'it�ration parent de laquelle on part. ::

    iter_name = "Iteration_2"
    iter_2 = iter_1.NextIteration(iter_name)
    iter_2.SetField(field_file)
    iter_2.SetTimeStepRank( 1, 1)
    iter_2.SetMeshName("maill_02")
    iter_2.SetMeshFile("/local00/M.02.med")
    iter_2.AssociateHypo("HypoField")
    codret = iter_2.Compute(1, 2)


Saisie graphique correspondante
"""""""""""""""""""""""""""""""
Consulter :ref:`gui_create_iteration`
