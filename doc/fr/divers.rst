.. _divers:

Divers
######

R�f�rences
**********
.. index:: single: r�f�rence

Pour une r�f�rence � HOMARD, utiliser :

G. Nicolas and T. Fouquet, Adaptive Mesh Refinement for Conformal Hexahedral Meshes, "*Finite Elements in Analysis and Design*", Vol. 67, pp. 1-12, 2013, doi:10.1016/j.finel.2012.11.008

`Accessible en cliquant ici <http://dx.doi.org/10.1016/j.finel.2012.11.008>`_

D'autres r�f�rences sont disponibles sur le site de `HOMARD <http://www.code-aster.org/outils/homard/fr/divers.html>`_

Evolutions du module
********************
.. index:: single: �volution

On trouvera ici les principales �volutions de HOMARD � partir de la premi�re version livr�e dans SALOME 6.5.

SALOME VERSION 6.6 :
    - Interfa�age avec med 3.0.6
    - Valeurs par d�faut des instants
    - Acceptation des mailles de type TRIA7 et QUAD9
    - Option de sortie dans le fichier MED du niveau de raffinement atteint dans chaque maille

SALOME VERSION 7.1 :
    - Correction d'une anomalie sur le filtrage du raffinement par les groupes
    - Pilotage de l'adaptation par un seuil bas� sur la moyenne et l'�cart-type (voir :ref:`tui_create_hypothese`)
    - En TUI, choix du dernier instant comme instant de pilotage par SetTimeStepRankLast (voir :ref:`tui_create_iteration`)
    - Possibilit� de d�truire les objets (GUI et TUI)
    - Modification des fonctions TUI pour qu'elles agissent sur les objets et non plus sur les noms :
      ``homard.AssociateIterHypo(iter_name,hypo_name)`` devient ``iter.AssociateHypo(hypo_name)``, ``homard.AssociateHypoZone(hypo_name,zone_name,type_use)`` devient ``hypo.AddZone(zone_name,type_use)``, ``homard.CreateIteration(iter_name,iter_parent_name)`` devient ``case.NextIteration(iter_name)`` ou ``iter.NextIteration(iter_name)``
    - Ajout de fonctions :
      ``cas.LastIteration()`` : retourne la derni�re it�ration de la descendance du cas (voir :ref:`tui_create_iteration`)
    - Analyse de maillages (voir :ref:`gui_mesh_info`)

SALOME VERSION 7.2 :
    - Possibilit� d'utiliser un cone comme support de frontiere 2D (voir :ref:`tui_create_boundary`)
    - Choix de publier ou non le r�sultat dans SMESH (voir :ref:`tui_create_iteration`)
      ``iter.Compute(option)`` devient ``iter.Compute(option1, option2)``
    - Possibilit� de poursuivre une suite d'it�rations archiv�es dans un r�pertoire (voir :ref:`gui_create_case`)

SALOME VERSION 7.3 :
    - Documentation en anglais
    - Options pour suivre le calcul de l'it�ration (voir :ref:`tui_create_iteration`) : ``iter.SetInfoCompute(MessInfo)``
    - Creation automatique de sch�ma YACS :
      ``case.WriteYACSSchema(ScriptFile, DirName, MeshFile)`` : �crit un sch�ma YACS correspondant au cas (voir :ref:`tui_create_case`)
    - Le maillage initial n'est pas publi� dans SMESH.
    - Le raffinement de maillages 2D avec des quadrangles est am�lior� pour prendre en compte des zones 'en escalier'.
    - Les champs constants par mailles peuvent �tre interpol�s selon les deux modes : intensif ou extensif.
    - Possibilit� de choix des pas de temps pour l'interpolation des champs :
      ``SetFieldInterpTimeStep(FieldInterp, TimeStep)`` : interpole le champ au pas de temps TimeStep (voir :ref:`tui_create_iteration`)
      ``SetFieldInterpTimeStepRank(FieldInterp, TimeStep, Rank)`` : interpole le champ au pas de temps TimeStep et au num�ro d'ordre Rank (voir :ref:`tui_create_iteration`)
    - Arr�t en cas d'erreur dans les donn�es des instructions python

SALOME VERSION 7.4 :
    - Grandes fen�tres avec ascenseur.
    - Publication des maillages � la demande.
    - Suivi de fronti�re analytique torique.
    - La fonction ``SetAdapRefinUnRef(TypeAdap, TypeRaff, TypeDera)`` est supprim�e. Pour une adaptation selon un champ ou des zones, le mode raffinement/d�raffinement est automatiquement d�duit des autres param�tres de l'hypoth�se. Pour un raffinement uniforme, on utilisera ``SetUnifRefinUnRef(TypeRaffDera)`` (voir :ref:`tui_create_hypothese`).
    - En cas d'erreur dans l'adaptation, le nom du fichier de messages est affich�.
    - Passage � la version 11.1 de l'ex�cutable HOMARD ; le raffinement conforme des maillages en hexa�dres est am�lior� pour diminuer le nombre de mailles produites.



