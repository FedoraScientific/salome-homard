// Copyright (C) 2011-2012  CEA/DEN, EDF R&D
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//
// Remarques :
// L'ordre de description des fonctions est le meme dans tous les fichiers
// HOMARD_aaaa.idl, HOMARD_aaaa.hxx, HOMARD_aaaa.cxx, HOMARD_aaaa_i.hxx, HOMARD_aaaa_i.cxx :
// 1. Les generalites : Name, Delete, DumpPython, Dump, Restore
// 2. Les caracteristiques
// 3. Le lien avec les autres structures
//
// Quand les 2 fonctions Setxxx et Getxxx sont presentes, Setxxx est decrit en premier
//

#ifndef _HOMARD_ITERATION_I_HXX_
#define _HOMARD_ITERATION_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Iteration)

#include "SALOME_Component_i.hxx"
#include "SALOME_NamingService.hxx"
#include "Utils_CorbaException.hxx"

#include <string>

class HOMARD_Iteration;

class HOMARD_Iteration_i:
  public virtual Engines_Component_i,
  public virtual POA_HOMARD::HOMARD_Iteration,
  public virtual PortableServer::ServantBase
{
public:
  HOMARD_Iteration_i( CORBA::ORB_ptr orb,
                      HOMARD::HOMARD_Gen_var gen_i );
  HOMARD_Iteration_i();

  virtual ~HOMARD_Iteration_i();

// Generalites
  void                   SetName( const char* Name );
  char*                  GetName();

  CORBA::Long            Delete();

  char*                  GetDumpPython();

  std::string            Dump() const;
  bool                   Restore( const std::string& stream );

// Caracteristiques
  void                   SetDirName( const char* NomDir );
  char*                  GetDirName();

  void                   SetNumber( CORBA::Long NumIter );
  CORBA::Long            GetNumber();

  void                   SetEtat( CORBA::Boolean etat );
  CORBA::Boolean         GetEtat();

  void                   SetMeshName( const char* NomMesh );
  char*                  GetMeshName();

  void                   SetMeshFile( const char* MeshFile );
  char*                  GetMeshFile();

  void                   SetFieldFile( const char* FieldFile );
  char*                  GetFieldFile();
  void                   SetTimeStepRank( CORBA::Long TimeStep, CORBA::Long Rank );
  CORBA::Long            GetTimeStep();
  CORBA::Long            GetRank();

  void                   SetMessFile( const char* MessFile );
  char*                  GetMessFile();

  CORBA::Long            Compute(CORBA::Long etatMenage);

// Liens avec les autres iterations
  HOMARD::HOMARD_Iteration_ptr NextIteration( const char* Name) ;

  void                   LinkNextIteration( const char* NomIteration );
  void                   UnLinkNextIteration( const char* NomIteration );
  HOMARD::listeIterFilles* GetIterations();

  void                   SetIterParentName( const char* NomIterParent );
  char*                  GetIterParentName();
  HOMARD::HOMARD_Iteration_ptr GetIterParent() ;

// Liens avec les autres structures
  void                   SetCaseName( const char* NomCas );
  char*                  GetCaseName();

  void                   AssociateHypo( const char* NomHypo);
  void                   SetHypoName( const char* NomHypo );
  char*                  GetHypoName();

private:
  ::HOMARD_Iteration*    myHomardIteration;

  CORBA::ORB_ptr         _orb;
  HOMARD::HOMARD_Gen_var _gen_i;
};

#endif