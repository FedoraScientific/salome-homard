.. _tui_create_iteration:

The iteration
=============

.. index:: single: iteration
.. index:: single: hypothesis
.. index:: single: zone

The variables are described in :ref:`gui_create_iteration`.

Methods of the class homard
""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: GetIteration                                      |
|                                                               |
| **GetIteration(iter_name)**                                   |
|     Returns an instance of the class ``iteration``            |
|     known by its name                                         |
|                                                               |
|     - ``iter_name``: the name of the iteration                |
+---------------------------------------------------------------+
| .. module:: GetAllIterationsName                              |
|                                                               |
| **GetAllIterationsName()**                                    |
|     Returns the liste of the name of all the existing         |
|     iterations                                                |
|                                                               |
+---------------------------------------------------------------+

Methods of both classes cas and iteration
"""""""""""""""""""""""""""""""""""""""""

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: NextIteration                                     |
|                                                               |
| **NextIteration(iter_name)**                                  |
|     Returns an instance of the class ``iteration`` after      |
|     its creation. It is the next iteration after:             |
|                                                               |
|     - for a case: the very first one that corresponds to the  |
|       first mesh of the case                                  |
|     - for an iteration: the current iteration                 |
|                                                               |
| Default:  the produced mesh has got the same name as the      |
| iteration                                                     |
|                                                               |
|     - ``iter_name``: the name of this next iteration          |
+---------------------------------------------------------------+
| .. module:: LastIteration                                     |
|                                                               |
| **LastIteration()**                                           |
|     Returns an instance of the class ``iteration`` that is    |
|     the last iteration into the descendants of:               |
|                                                               |
|     - for a case: the very first one that corresponds to the  |
|       first mesh of the case                                  |
|     - for an iteration: the current iteration                 |
|                                                               |
|     It is the one that has got no child. There is an error if |
|     more than one branch exists into the descendants.         |
|                                                               |
+---------------------------------------------------------------+

Methods of the class iteration
""""""""""""""""""""""""""""""

General methods
^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: Compute                                           |
|                                                               |
| **Compute(option1, option2)**                                 |
|     Computes the mesh produced by the iteration               |
|                                                               |
|     - ``option1``: an integer to decide what to do with       |
|       existing files, if any                                  |
|                                                               |
|         * 0: stop with error                                  |
|         * 1: the old files are removed                        |
|                                                               |
|     - ``option2``: an integer to decide what to do with       |
|       the results                                             |
|                                                               |
|         * 1: no specific action                               |
|         * 2: publication into the module SMESH                |
|                                                               |
|     Returns an integer:                                       |
|         * 0: successful adaptation                            |
|         * other value: problem                                |
+---------------------------------------------------------------+
| .. module:: GetName                                           |
|                                                               |
| **GetName()**                                                 |
|     Returns the name of the iteration                         |
+---------------------------------------------------------------+
| .. module:: GetNumber                                         |
|                                                               |
| **GetNumber()**                                               |
|     Returns the number of the iteration.                      |
|                                                               |
|     The iteration #0 is the one associated to the initial     |
|     mesh. Then, an iteration with number #N comes from the    |
|     adaptation of an iteration with number #(N-1).            |
+---------------------------------------------------------------+
| .. module:: GetIterParent                                     |
|                                                               |
| **GetIterParent()**                                           |
|     Returns the iteration parent                              |
+---------------------------------------------------------------+
| .. module:: AssociateHypo                                     |
|                                                               |
| **AssociateHypo(hypo_name)**                                  |
|     Associate an hypothesis with the iteration                |
|                                                               |
|     - ``hypo_name``: the name of the hypothesis               |
+---------------------------------------------------------------+
| .. module:: GetHypoName                                       |
|                                                               |
| **GetHypoName()**                                             |
|     Returns the name of the associated hypothesis             |
+---------------------------------------------------------------+
| .. module:: GetCaseName                                       |
|                                                               |
| **GetCaseName()**                                             |
|     Returns the name of the associated case                   |
+---------------------------------------------------------------+
| .. module:: GetState                                          |
|                                                               |
| **GetState()**                                                |
|     Returns the state of the iteration                        |
|                                                               |
|     - ``2``: computed iteration                               |
|     - ``1``: non computed iteration                           |
|     - ``<=0``: initial iteration not to be computed, with a   |
|       number equal to the absolute valure of the state        |
+---------------------------------------------------------------+
| .. module:: GetLogFile                                        |
|                                                               |
| **GetLogFile()**                                              |
|     Returns the name of the file with the messages all along  |
|     the running of HOMARD                                     |
+---------------------------------------------------------------+
| .. module:: GetFileInfo                                       |
|                                                               |
| **GetFileInfo()**                                             |
|     Returns the name of the file with the analysis of the mesh|
+---------------------------------------------------------------+
| .. module:: GetDirName                                        |
|                                                               |
| **GetDirName()**                                              |
|     Returns the name of the directory that contains the       |
|     results of the iteration                                  |
+---------------------------------------------------------------+
| .. module:: Delete                                            |
|                                                               |
| **Delete(option)**                                            |
|     Deletes the iteration and all its children                |
|                                                               |
|     - ``option``: an integer to define what to do with the    |
|       MED file of the associated meshes                       |
|                                                               |
|         * 0: the files are kept                               |
|         * 1: the files are removed                            |
|                                                               |
|     Returns an integer:                                       |
|         * 0: the destruction is done                          |
|         * other value: problem                                |
+---------------------------------------------------------------+

Information about the meshes
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetMeshName                                       |
|                                                               |
| **SetMeshName(mesh_name)**                                    |
|     Defines the name of the produced mesh                     |
|                                                               |
|     - ``mesh_name``: the name of the produced mesh            |
+---------------------------------------------------------------+
| .. module:: GetMeshName                                       |
|                                                               |
| **GetMeshName()**                                             |
|     Returns the name of the produced mesh                     |
+---------------------------------------------------------------+
| .. module:: SetMeshFile                                       |
|                                                               |
| **SetMeshFile(mesh_file)**                                    |
|     Defines the name of the MED file of the produced mesh     |
|                                                               |
|     - ``mesh_file``: the name of the MED file of the          |
|       produced mesh                                           |
+---------------------------------------------------------------+
| .. module:: GetMeshFile                                       |
|                                                               |
| **GetMeshFile()**                                             |
|     Returns the name of the MED file of the produced mesh     |
+---------------------------------------------------------------+
| .. module:: MeshInfo                                          |
|                                                               |
| **MeshInfo(Qual, Diam, Conn, Tail, Inte)**                    |
|     Gives information about the current mesh. For every       |
|     option, the choice #0 corresponds to 'no action', while   |
|     the choice #1 launches the option.                        |
|                                                               |
|     - ``Qual``: quality of the elements                       |
|     - ``Diam``: diametre of the elements                      |
|     - ``Conn``: connexity of the domain; a single block, how  |
|       many holes, etc.                                        |
|     - ``Tail``: size of the parts of the domain, group by     |
|       group                                                   |
|     - ``Inte``: staggered elements, by dimension              |
+---------------------------------------------------------------+

Information about the field
^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------------------------------------------+
+---------------------------------------------------------------+
| .. module:: SetFieldFile                                      |
|                                                               |
| **SetFieldFile(field_file)**                                  |
|     Defines the MED file of the field                         |
|                                                               |
|     - ``field_file``: the name of the MED file of the field   |
+---------------------------------------------------------------+
| .. module:: SetTimeStepRank                                   |
|                                                               |
| **SetTimeStepRank(TimeStep, Rank)**                           |
|     Defines the time steps for the fields                     |
|                                                               |
|     Useless if no time step is defined for the field.         |
|                                                               |
|     If a single time step is defined for the filed, it is the |
|     default choice.                                           |
|                                                               |
|     - ``TimeStep``: the selected time step                    |
|     - ``Rank``: the selected rank                             |
+---------------------------------------------------------------+
| .. module:: SetTimeStepRankLast                               |
|                                                               |
| **SetTimeStepRankLast()**                                     |
|     The last time step will be used, whatever its value       |
+---------------------------------------------------------------+
| .. module:: GetFieldFileName                                  |
|                                                               |
| **GetFieldFileName()**                                        |
|     Returns the name of the MED file of the field             |
+---------------------------------------------------------------+
| .. module:: GetTimeStep                                       |
|                                                               |
| **GetTimeStep()**                                             |
|     Returns the selected time step for the field              |
+---------------------------------------------------------------+
| .. module:: GetRank                                           |
|                                                               |
| **GetRank()**                                                 |
|     Returns the selected rank for the field                   |
+---------------------------------------------------------------+

Example
"""""""
.. index:: single: mesh;initial

To create the first iteration, the starting point is the iteration associated to the initial mesh. It is the one that defines the case.
::

    iter_name = "Iteration_1"
    iter_1 = case_1.NextIteration(iter_name)
    iter_1.SetField(field_file)
    iter_1.SetTimeStepRank( 0, 0)
    iter_1.SetMeshName("maill_01")
    iter_1.SetMeshFile("/local00/M.01.med")
    iter_1.AssociateHypo("HypoField")
    codret = iter_1.Compute(1, 2)

Then, the next iteration is created from the current iteration.
::

    iter_name = "Iteration_2"
    iter_2 = iter_1.NextIteration(iter_name)
    iter_2.SetField(field_file)
    iter_2.SetTimeStepRank( 1, 1)
    iter_2.SetMeshName("maill_02")
    iter_2.SetMeshFile("/local00/M.02.med")
    iter_2.AssociateHypo("HypoField")
    codret = iter_2.Compute(1, 2)


Similar graphical input
"""""""""""""""""""""""
Look at :ref:`gui_create_iteration`