.. _gui_create_yacs:

Le sch�ma YACS
##############
.. index:: single: YACS
.. index:: single: cas

L'objet YACS contient toutes les d�finitions permettant de cr�er un sch�ma. Ce sch�ma va piloter l'alternance d'un calcul repr�sentant une mod�lisation physique sur un maillage et l'adaptation de ce maillage de calcul. Cette alternance est pilot� par des crit�res de convergence.

.. note::
  Pour avoir une description d�taill�e de chacune des rubriques formant le sch�ma, consulter :ref:`yacs`

Proc�dure � employer
********************
La cr�ation automatique du sch�ma va se faire en trois phases :

- Au d�part, il faut avoir fait un calcul sur un tout premier maillage. Ce calcul aura produit des r�sultats dans un fichier MED.
- Ensuite, on cr�e un cas dans le module HOMARD, tel qu'il est d�crit dans :ref:`gui_create_case`. Dans ce cas, on cr�e une it�ration suivante du maillage en d�finissant une hypoth�se d'adaptation ; voir :ref:`gui_create_iteration`.
- Enfin, de ce cas, on va cr�er le sch�ma qui se basera sur l'hypoth�se d'adapation d�finie.


.. image:: images/create_yacs_01.png
   :align: center
   :alt: yacs - cr�ation
   :width: 551
   :height: 295

Nom du sch�ma
*************
Un nom de sch�ma est propos� automatiquement : YACS_1, YACS_2, etc. Ce nom peut �tre modifi�. Il ne doit pas avoir �t� d�j� utilis� pour un autre sch�ma.

Le script
*********

Le fichier contenant le script qui permet de lancer le calcul li� � la mod�lisation physique est fourni ici. C'est un script python qui doit respecter les r�gles suivantes :

- le nom de la classe qui g�re le calcul est ``Script``
- le lancement du calcul se fait par la m�thode ``Compute()``
- le r�sultat du calcul est sous la forme de trois variables : le code d'erreur, un message, un dictionnaire python.

S'ils sont n�cessaires � la cr�ation de la classe, on peut passer des arguments sous la forme :

- ``--rep_calc=rep_calc``, o� ``rep_calc`` est le r�pertoire de calcul
- ``--num=num``, o� ``num`` est le num�ro du calcul  : 0 pour le tout premier, puis 1, 2 etc.
- ``--mesh_file=meshfile``, o� ``meshfile`` est le fichier contenant le maillage sur lequel calculer.
- ``-v``, pour des messages

Les arguments de retour :

- ``erreur`` : le code d'erreur, entier : 0 si le calcul est correct, non nul sinon
- ``message`` : un �ventuel message d'information sur le calcul
- ``dico_resu`` : un dictionnaire python qui comprend a minima les deux cl�s suivantes : ``FileName`` est la cl� pour le nom du fichier MED qui contient les r�sultats du calcul, ``V_TEST`` est la cl� pour la valeur r�elle � tester.



Exemple d'usage du script :
::

    argu = ["--rep_calc=" + rep_calc)]
    argu.append("--num=%d" % numCalc)
    argu.append("--mesh_file="  + MeshFile)
    Script_A = Script(argu)
    erreur, message, dico_resu = Script_A.compute ()

.. note::

  * Pour piloter Code_Aster : :download:`ScriptAster<../files/yacs_script.py>`

Le r�pertoire
*************
Le r�pertoire est celui qui contiend les fichiers produits par le calcul. Par d�faut, rien n'est propos�. Le choix est fait, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche.

Le maillage initial
*******************
Le maillage initial doit se trouver dans un fichier au format MED. C'est celui qui est le point de d�part du tout premier calcul. Le nom du fichier peut �tre fourni, soit en tapant le nom dans la zone de texte, soit en activant la fonction de recherche.


Le type de sch�ma
*****************
Plusieurs types de sch�ma sont propos�s : constant ou variable.

L'option par d�faut, 'constant', alterne le lancement d'un calcul qui est toujours le m�me et une adaptation de maillage : d'un calcul � l'autre, la seule chose qui change est le maillage. Tout le reste est identique. Par exemple, dans le cas o� le calcul mod�liserait un transitoire, c'est toujours l'int�gralit� du transitoire qui est prise en compte.

L'option 'variable' est inactive aujourd'hui.

M�thodes python correspondantes
*******************************
Consulter :ref:`tui_create_yacs`
