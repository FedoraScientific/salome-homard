.. _tui_create_hypothese:

L'hypoth�se
###########

.. index:: single: it�ration
.. index:: single: hypoth�se
.. index:: single: zone

Les variables sont d�crites dans :ref:`gui_create_hypothese`.

M�thodes de la classe homard
****************************

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: CreateHypothesis                                  |
|                                                               |
| **CreateHypothesis(hypo_name)**                               |
|     Retourne une instance de la classe ``hypothese``          |
|                                                               |
|     - ``hypo_name`` : le nom de l'hypoth�se                   |
+---------------------------------------------------------------+
| .. module:: GetHypothesis                                     |
|                                                               |
| **GetHypothesis(hypo_name)**                                  |
|     Retourne l'instance de la classe ``hypothese`` connue par |
|     son nom                                                   |
|                                                               |
|     - ``hypo_name`` : le nom de l'hypoth�se                   |
+---------------------------------------------------------------+
| .. module:: GetAllHypothesesName                              |
|                                                               |
| **GetAllHypothesesName()**                                    |
|     Retourne la liste des noms de toutes les hypoth�ses cr��es|
+---------------------------------------------------------------+
| .. module:: GetZone                                           |
|                                                               |
| **GetZone(zone_name)**                                        |
|     Retourne l'instance de la classe ``zone`` connue par      |
|     son nom                                                   |
|                                                               |
|     - ``zone_name`` : le nom de la zone                       |
+---------------------------------------------------------------+

M�thodes de la classe hypothese
*******************************

G�n�ralit�s
===========

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Retourne le nom de l'hypoth�se                            |
+---------------------------------------------------------------+
| .. module:: GetAdapType                                       |
|                                                               |
| **GetAdapType()**                                             |
|     Retourne le type d'adaptation                             |
|                                                               |
|         * -1 : uniforme                                       |
|         * 0 : selon des zones                                 |
|         * 1 : selon un champ                                  |
+---------------------------------------------------------------+
| .. module:: GetRefinType                                      |
|                                                               |
| **GetRefinType()**                                            |
|     Retourne le type de raffinement                           |
|                                                               |
|         * 0 : inactif                                         |
|         * 1 : actif                                           |
+---------------------------------------------------------------+
| .. module:: GetUnRefType                                      |
|                                                               |
| **GetUnRefType()**                                            |
|     Retourne le type de d�raffinement                         |
|                                                               |
|         * 0 : inactif                                         |
|         * 1 : actif                                           |
+---------------------------------------------------------------+
| .. module:: Delete                                            |
|                                                               |
| **Delete()**                                                  |
|     Detruit l'hypoth�se                                       |
|                                                               |
|     Retourne un entier :                                      |
|         * 0 : destruction r�ussie                             |
|         * autre valeur : probl�me                             |
+---------------------------------------------------------------+

Adaptation uniforme
===================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetUnifRefinUnRef                                 |
|                                                               |
| **SetUnifRefinUnRef(RefinUnRef)**                             |
|     D�finit un mode d'adaptation uniforme � tout le maillage  |
|                                                               |
|     - ``RefinUnRef`` : entier pr�cisant le type d'adaptation  |
|                                                               |
|         * 1 : raffinement                                     |
|         * -1 : d�raffinement                                  |
+---------------------------------------------------------------+

Adaptation selon un champ
=========================

Le champ de pilotage de l'adaptation et les seuils
--------------------------------------------------

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetField                                          |
|                                                               |
| **SetField(FieldName)**                                       |
|     Attribue un nom de champ de pilotage � l'hypoth�se        |
|                                                               |
|     - ``FieldName`` : le nom du champ  de pilotage            |
+---------------------------------------------------------------+
| .. module:: GetFieldName                                      |
|                                                               |
| **GetFieldName()**                                            |
|     Retourne le nom du champ de pilotage                      |
+---------------------------------------------------------------+
| .. module:: SetUseField                                       |
|                                                               |
| **SetUseField(use_field)**                                    |
|     Attribue un mode d'usage du champ de pilotage             |
|                                                               |
|     - ``use_field`` : entier pr�cisant l'usage du champ       |
|                                                               |
|        * 0 : valeur par �l�ment (d�faut)                      |
|        * 1 : saut entre un �l�ment et ses voisins             |
+---------------------------------------------------------------+
| .. module:: SetRefinThr                                       |
|                                                               |
| **SetRefinThr(type_thres, threshold)**                        |
|     D�finit les seuils en raffinement                         |
|                                                               |
|     - ``type_thres`` : entier pr�cisant le type de seuil en   |
|       raffinement                                             |
|                                                               |
|        * 1 : valeur absolue                                   |
|        * 2 : valeur relative en %                             |
|        * 3 : fraction des mailles en %                        |
|        * 4 : moyenne + n fois l'�cart-type                    |
|                                                               |
|     - ``threshold`` : valeur num�rique entrant dans la        |
|                       d�finition du seuil                     |
+---------------------------------------------------------------+
| .. module:: GetRefinThrType                                   |
|                                                               |
| **GetRefinThrType()**                                         |
|     Retourne le type de seuil de raffinement                  |
+---------------------------------------------------------------+
| .. module:: SetUnRefThr                                       |
|                                                               |
| **SetUnRefThr(type_thres, threshold)**                        |
|     D�finit les seuils en d�raffinement                       |
|                                                               |
|     - ``type_thres`` : entier pr�cisant le type de seuil en   |
|       d�raffinement                                           |
|                                                               |
|        * 1 : valeur absolue                                   |
|        * 2 : valeur relative en %                             |
|        * 3 : fraction des mailles en %                        |
|        * 4 : moyenne - n fois l'�cart-type                    |
|                                                               |
|     - ``threshold`` : valeur du seuil                         |
+---------------------------------------------------------------+
| .. module:: GetUnRefThrType                                   |
|                                                               |
| **GetUnRefThrType()**                                         |
|     Retourne le type de seuil de d�raffinement                |
+---------------------------------------------------------------+


Les composantes du champ de pilotage
------------------------------------

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddComp                                           |
|                                                               |
| **AddComp(comp_name)**                                        |
|     Ajoute une composante du champ de pilotage � consid�rer   |
|                                                               |
|     - ``comp_name`` : nom d'une composante � prendre en       |
|       compte                                                  |
|                                                               |
|     Remarque : si cette m�thode n'est pas appel�e, par d�faut |
|     toutes les composantes seront retenues.                   |
+---------------------------------------------------------------+
| .. module:: SetUseComp                                        |
|                                                               |
| **SetUseComp(use_comp)**                                      |
|     D�finit l'usage des composantes                           |
|                                                               |
|     - ``use_comp`` : entier pr�cisant l'usage des composantes |
|                                                               |
|        * 0 : norme L2 (d�faut)                                |
|        * 1 : norme infinie                                    |
|        * 2 : valeur relative, si une seule composante         |
+---------------------------------------------------------------+
| .. module:: GetComps                                          |
|                                                               |
| **GetComps()**                                                |
|     Retourne la liste des composantes utilis�es               |
+---------------------------------------------------------------+
| .. module:: SupprComp                                         |
|                                                               |
| **SupprComp(comp_name)**                                      |
|     Supprime une composante du champ � consid�rer             |
|                                                               |
|     - ``comp_name`` : nom de la composante � supprimer        |
+---------------------------------------------------------------+
| .. module:: SupprComps                                        |
|                                                               |
| **SupprComps()**                                              |
|     Supprime toutes les composantes du champ � consid�rer     |
+---------------------------------------------------------------+


Adaptation selon des zones
==========================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddZone                                           |
|                                                               |
| **AddZone(zone_name, type_use)**                              |
|                                                               |
|     - ``zone_name`` : le nom de la zone � ajouter             |
|     - ``type_use``  : entier pr�cisant l'usage de la zone     |
|                                                               |
|         * 1 : raffinement                                     |
|         * -1 : d�raffinement                                  |
+---------------------------------------------------------------+
| .. module:: GetZones                                          |
|                                                               |
| **GetZones()**                                                |
|     Retourne la liste des zones utilis�es avec leur usage.    |
|                                                               |
|     Attention : l'usage est stock� sous forme de cha�ne de    |
|     caract�res et non pas d'entier dans la liste.             |
|                                                               |
|     Exemple : ['Zone_A', '1', 'Zone_B', '1', 'Zone_C', '1']   |
+---------------------------------------------------------------+
| .. module:: SupprZone                                         |
|                                                               |
| **SupprZone(zone_name)**                                      |
|     Supprime une zone de l'hypoth�se                          |
|                                                               |
|     - ``zone_name`` : nom de la zone � supprimer              |
+---------------------------------------------------------------+
| .. module:: SupprZones                                        |
|                                                               |
| **SupprZones()**                                              |
|     Supprime toutes les zones de l'hypoth�se                  |
+---------------------------------------------------------------+


Le filtrage par les groupes
===========================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: AddGroup                                          |
|                                                               |
| **AddGroup(group_name)**                                      |
|     Ajoute un groupe au filtrage                              |
|                                                               |
|     - ``group_name`` : nom du groupe � prendre en compte      |
+---------------------------------------------------------------+
| .. module:: GetGroups                                         |
|                                                               |
| **GetGroups()**                                               |
|     Retourne la liste des groupes utilis�s pour le filtrage   |
+---------------------------------------------------------------+


Les champs � interpoler
=======================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetTypeFieldInterp                                |
|                                                               |
| **SetTypeFieldInterp(typefieldinterp)**                       |
|                                                               |
|     - ``typefieldinterp`` : entier pr�cisant si des champs    |
|       sont a interpoler                                       |
|                                                               |
|         * 0 : aucun champ n'est � interpoler (d�faut)         |
|         * 1 : tous les champs sont interpol�s                 |
|         * 2 : certains champs sont interpol�s ; implicitement |
|           affect� apr�s usage de AddFieldInterp ou            |
|           AddFieldInterpType                                  |
+---------------------------------------------------------------+
| .. module:: GetTypeFieldInterp                                |
|                                                               |
| **GetTypeFieldInterp()**                                      |
|     Retourne l'entier pr�cisant si des champs sont �          |
|     interpoler                                                |
+---------------------------------------------------------------+
| .. module:: AddFieldInterp                                    |
|                                                               |
| **AddFieldInterp(FieldName)**                                 |
|                                                               |
|     - ``FieldName`` : le nom du champ � interpoler            |
|                                                               |
|     Le mode d'interpolation sera choisi automatiquement par   |
|     HOMARD ; cela correspond au mode 0 de AddFieldInterpType  |
+---------------------------------------------------------------+
| .. module:: AddFieldInterpType                                |
|                                                               |
| **AddFieldInterpType(FieldName, type_interp)**                |
|                                                               |
|     - ``FieldName`` : le nom du champ � interpoler            |
|     - ``type_interp`` : entier pr�cisant le type              |
|       d'interpolation du champ                                |
|                                                               |
|     Pour un champ aux noeuds :                                |
|                                                               |
|         * 0 : le champ sera interpol� en degr� 1 ou 2 selon   |
|           son support.                                        |
|         * 1 : interpolation en degr� 1                        |
|         * 2 : interpolation en degr� 2                        |
|         * 3 : interpolation iso-P2                            |
|                                                               |
|     Pour un champ aux �l�ments :                              |
|                                                               |
|         * 0 : le champ sera interpol� en le consid�rant comme |
|           une variable intensive.                             |
|         * 1 : le champ sera interpol� en le consid�rant comme |
|           une variable extensive.                             |
+---------------------------------------------------------------+
| .. module:: GetFieldInterps                                   |
|                                                               |
| **GetFieldInterps()**                                         |
|     Retourne la liste des champs � interoler avec leur usage. |
|                                                               |
|     Attention : l'usage est stock� sous forme de cha�ne de    |
|     caract�res et non pas d'entier dans la liste.             |
|                                                               |
|     Exemple : ['DEPL', '0', 'Masse', '1', 'Densite', '0']     |
+---------------------------------------------------------------+
| .. module:: SupprFieldInterp                                  |
|                                                               |
| **SupprFieldInterp(FieldName)**                               |
|     Supprime un champ � interpoler de l'hypoth�se             |
|                                                               |
|     - ``FieldName`` : nom du champ � supprimer                |
+---------------------------------------------------------------+
| .. module:: SupprFieldInterps                                 |
|                                                               |
| **SupprFieldInterps()**                                       |
|     Supprime tous les champs � interpoler de l'hypoth�se      |
+---------------------------------------------------------------+

.. note::
  Le fichier et les instants o� sont pris les champs sont d�finis dans l'it�ration ; voir :ref:`tui_create_iteration`.

Les options avanc�es
====================

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetNivMax                                         |
|                                                               |
| **SetNivMax(nivmax)**                                         |
|     D�finit le niveau maximal de raffinement                  |
|                                                               |
|     - ``nivmax`` : niveau de raffinement � ne pas d�passer    |
+---------------------------------------------------------------+
| .. module:: GetNivMax                                         |
|                                                               |
| **GetNivMax()**                                               |
|     Retourne le niveau maximal de raffinement                 |
+---------------------------------------------------------------+
| .. module:: SetDiamMin                                        |
|                                                               |
| **SetDiamMin(diammin)**                                       |
|     D�finit le diam�tre minimal des futures mailles           |
|                                                               |
|     - ``diammin`` : diam�tre minimal voulu pour une maille    |
+---------------------------------------------------------------+
| .. module:: GetDiamMin                                        |
|                                                               |
| **GetDiamMin()**                                              |
|     Retourne le diam�tre minimal voulu                        |
+---------------------------------------------------------------+
| .. module:: SetAdapInit                                       |
|                                                               |
| **SetAdapInit(option)**                                       |
|     D�finit le traitement � appliquer aux mailles o�          |
|     le champ de pilotage de l'adaptation n'est pas d�fini     |
|                                                               |
|     - ``option`` : entier pr�cisant le choix retenu           |
|                                                               |
|         *  0 : aucun effet (d�faut)                           |
|         *  1 : les mailles sans indicateurs sont raffin�es    |
|         * -1 : les mailles sans indicateurs sont d�raffin�es  |
+---------------------------------------------------------------+
| .. module:: GetAdapInit                                       |
|                                                               |
| **GetAdapInit()**                                             |
|     Retourne le type de traitement � appliquer aux mailles o� |
|     le champ de pilotage de l'adaptation n'est pas d�fini     |
+---------------------------------------------------------------+
| .. module:: SetExtraOutput                                    |
|                                                               |
| **SetExtraOutput(option)**                                    |
|     Pr�cise quelles sorties suppl�mentaires sur les mailles on|
|     veut r�cup�rer dans le fichier MED de sortie. C'est un    |
|     entier multiple ou non de 2, 3, 5.                        |
|                                                               |
|     - ``option`` : entier pr�cisant le choix retenu           |
|                                                               |
|         *  1 : aucun effet (d�faut)                           |
|         *  2x : le niveau de raffinement de chaque maille     |
|         *  3x : la qualit� de chaque maille                   |
|         *  5x : le diam�tre de chaque maille                  |
+---------------------------------------------------------------+
| .. module:: GetExtraOutput                                    |
|                                                               |
| **GetExtraOutput()**                                          |
|     Retourne le choix retenu pour la r�cup�ration des sorties |
|     suppl�mentaires                                           |
+---------------------------------------------------------------+


Exemple
*******
La cr�ation de l'objet hypo_1 se fait ainsi : ::

    hypo_1 = homard.CreateHypothesis("HypoField")
    hypo_1.SetField("INDICATEUR")
    hypo_1.AddComp("INDX")
    hypo_1.AddComp("INDZ")
    hypo_1.SetRefinThr(1, 80.)
    hypo_1.AddFieldInterp("DEPL")
    hypo_1.AddFieldInterpType("MASSE", 1)


Saisie graphique correspondante
*******************************
Consulter :ref:`gui_create_hypothese`

.. warning::
  En mode graphique, si on �dite une hypoth�se et que l'on modifie une de ses caract�ristiques, par exemple le seuil de raffinement, toutes les it�rations qui ont �t� calcul�es pr�c�demment avec cette hypoth�se sont invalid�es. En mode python, cela n'est plus vrai : les it�rations restent telles quelles.
