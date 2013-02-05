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

#ifndef _HOMARD_HYPOTHESIS_I_HXX_
#define _HOMARD_HYPOTHESIS_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Hypothesis)

#include "SALOME_Component_i.hxx"
#include "SALOME_NamingService.hxx"
#include "Utils_CorbaException.hxx"

#include <string>

class HOMARD_Hypothesis;

class HOMARD_Hypothesis_i:
  public virtual Engines_Component_i,
  public virtual POA_HOMARD::HOMARD_Hypothesis,
  public virtual PortableServer::ServantBase
{
public:
  HOMARD_Hypothesis_i( CORBA::ORB_ptr orb, HOMARD::HOMARD_Gen_var gen_i );
  HOMARD_Hypothesis_i();

  virtual ~HOMARD_Hypothesis_i();

// Generalites
  void                   SetName( const char* Name );
  char*                  GetName();

  CORBA::Long            Delete();

  char*                  GetDumpPython();

  std::string            Dump() const;
  bool                   Restore( const std::string& stream );

// Caracteristiques
  void                   SetAdapRefinUnRef( CORBA::Long TypeAdap, CORBA::Long TypeRaff, CORBA::Long TypeDera );
  HOMARD::listeTypes*    GetAdapRefinUnRef();
  CORBA::Long            GetAdapType();
  CORBA::Long            GetRefinType();
  CORBA::Long            GetUnRefType();

  void                   SetField( const char* FieldName );
  char*                  GetFieldName();
  void                   SetUseField(CORBA::Long UsField);
  HOMARD::InfosHypo*     GetField();

  void                   SetUseComp(CORBA::Long UsCmpI);
  void                   AddComp( const char* NomComposant );
  void                   SupprComp();
  HOMARD::listeComposantsHypo* GetListComp();

  void                   SetRefinThr(CORBA::Long TypeThR, CORBA::Double ThreshR);
  CORBA::Long            GetRefinThrType();
  void                   SetUnRefThr(CORBA::Long TypeThC, CORBA::Double ThreshC);
  CORBA::Long            GetUnRefThrType();

  void                   SetNivMax( CORBA::Long NivMax );
  CORBA::Long            GetNivMax();

  void                   SetDiamMin( CORBA::Double DiamMin );
  CORBA::Double          GetDiamMin();

  void                   SetAdapInit( CORBA::Long AdapInit );
  CORBA::Long            GetAdapInit();

  void                   SetLevelOutput( CORBA::Long LevelOutput );
  CORBA::Long            GetLevelOutput();

  void                   AddGroup( const char* Group);
  void                   SetGroups(const HOMARD::ListGroupType& ListGroup);
  HOMARD::ListGroupType* GetGroups();

  void                   SetTypeFieldInterp( CORBA::Long TypeFieldInterp );
  CORBA::Long            GetTypeFieldInterp();
  void                   AddFieldInterp( const char* FieldInterp );
  void                   SupprFieldInterp();
  HOMARD::listFieldInterpHypo* GetListFieldInterp();

// Liens avec les autres structures
  void                   SetCaseCreation( const char* NomCaseCreation );
  char*                  GetCaseCreation();

  void                   LinkIteration( const char* NomIteration );
  void                   UnLinkIteration( const char* NomIteration );
  HOMARD::listeIters*    GetIterations();

  void                   AddZone( const char* NomZone, CORBA::Long TypeUse );
  void                   AddZone0( const char* NomZone, CORBA::Long TypeUse );
  void                   SupprZone( const char* NomZone );
  HOMARD::listeZonesHypo* GetZones();

private:
  ::HOMARD_Hypothesis*         myHomardHypothesis;

  CORBA::ORB_ptr               _orb;
  HOMARD::HOMARD_Gen_var       _gen_i;
};

#endif