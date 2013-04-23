// Copyright (C) 2011-2013  CEA/DEN, EDF R&D
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

#ifndef _HOMARD_GEN_I_HXX_
#define _HOMARD_GEN_I_HXX_

#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(HOMARD_Gen)
#include CORBA_SERVER_HEADER(HOMARD_Cas)
#include CORBA_SERVER_HEADER(HOMARD_Hypothesis)
#include CORBA_SERVER_HEADER(HOMARD_Iteration)
#include CORBA_SERVER_HEADER(HOMARD_Zone)
#include CORBA_SERVER_HEADER(HOMARD_Boundary)
#include CORBA_CLIENT_HEADER(SALOMEDS)
#include CORBA_CLIENT_HEADER(SALOMEDS_Attributes)

#include "HOMARD_Gen.hxx"
#include "HomardDriver.hxx"
#include "SALOME_Component_i.hxx"
#include "SALOME_NamingService.hxx"
#include "Utils_CorbaException.hxx"


#include <string>
#include <map>

class HOMARD_Gen_i:
  public virtual Engines_Component_i,
  public virtual POA_HOMARD::HOMARD_Gen
{
public:
  HOMARD_Gen_i( CORBA::ORB_ptr orb,
                PortableServer::POA_ptr poa,
                PortableServer::ObjectId* contId,
                const char* instanceName,
                const char* interfaceName );
  virtual ~HOMARD_Gen_i();


// Generalites

// Les creations
  HOMARD::HOMARD_Boundary_ptr     CreateBoundary (const char* nomBoundary, CORBA::Long typeBoundary);
  HOMARD::HOMARD_Boundary_ptr     CreateBoundaryDi (const char* nomBoundary,
                                                    const char* MeshName, const char* FileName);
  HOMARD::HOMARD_Boundary_ptr     CreateBoundaryCylinder (const char* nomBoundary,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre,
                                      CORBA::Double Xaxis, CORBA::Double Yaxis, CORBA::Double Zaxis,
                                      CORBA::Double Rayon);
  HOMARD::HOMARD_Boundary_ptr     CreateBoundarySphere (const char* nomBoundary,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre,
                                      CORBA::Double Rayon);
  HOMARD::HOMARD_Boundary_ptr     CreateBoundaryConeR (const char* nomBoundary,
                                      CORBA::Double Xcentre1, CORBA::Double Ycentre1, CORBA::Double Zcentre1, CORBA::Double Rayon1,
                                      CORBA::Double Xcentre2, CORBA::Double Ycentre2, CORBA::Double Zcentre2, CORBA::Double Rayon2);
  HOMARD::HOMARD_Boundary_ptr     CreateBoundaryConeA (const char* nomBoundary,
                                      CORBA::Double Xaxis, CORBA::Double Yaxis, CORBA::Double Zaxis, CORBA::Double Angle,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre);

  HOMARD::HOMARD_Cas_ptr          CreateCase (const char* nomCas, const char* MeshName, const char* FileName);
  HOMARD::HOMARD_Cas_ptr          CreateCaseFromIteration (const char* nomCas, const char* DirNameStart);
  HOMARD::HOMARD_Cas_ptr          CreateCaseFromCaseLastIteration (const char* nomCas, const char* DirNameStart);
  HOMARD::HOMARD_Cas_ptr          CreateCaseFromCaseIteration (const char* nomCas, const char* DirNameStart, CORBA::Long Number);
  HOMARD::HOMARD_Cas_ptr          CreateCase0 (const char* nomCas, const char* MeshName, const char* FileName, CORBA::Long MeshOption, CORBA::Long NumeIter, CORBA::Long Option);
  std::string                     CreateCase1 (const char* DirNameStart, CORBA::Long Number);

  HOMARD::HOMARD_Hypothesis_ptr   CreateHypothesis(const char* nomHypothesis);

  HOMARD::HOMARD_Iteration_ptr    CreateIteration (const char* nomIter, const char* nomIterParent);

  HOMARD::HOMARD_Zone_ptr         CreateZone (const char* nomZone, CORBA::Long typeZone);
  HOMARD::HOMARD_Zone_ptr         CreateZoneBox (const char* nomZone,
                                      CORBA::Double Xmini, CORBA::Double Xmaxi,
                                      CORBA::Double Ymini, CORBA::Double Ymaxi,
                                      CORBA::Double Zmini, CORBA::Double Zmaxi);
  HOMARD::HOMARD_Zone_ptr         CreateZoneBox2D (const char* nomZone,
                                      CORBA::Double Umini, CORBA::Double Umaxi,
                                      CORBA::Double Vmini, CORBA::Double Vmaxi,
                                      CORBA::Long Orient);
  HOMARD::HOMARD_Zone_ptr         CreateZoneCylinder (const char* nomZone,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre,
                                      CORBA::Double Xaxe, CORBA::Double Yaxe, CORBA::Double Zaxe,
                                      CORBA::Double Rayon, CORBA::Double Haut);
  HOMARD::HOMARD_Zone_ptr         CreateZoneDisk (const char* nomZone,
                                      CORBA::Double Ucentre, CORBA::Double Vcentre,
                                      CORBA::Double Rayon,
                                      CORBA::Long Orient);
  HOMARD::HOMARD_Zone_ptr         CreateZoneDiskWithHole (const char* nomZone,
                                      CORBA::Double Ucentre, CORBA::Double Vcentre,
                                      CORBA::Double Rayon, CORBA::Double Rayonint,
                                      CORBA::Long Orient);
  HOMARD::HOMARD_Zone_ptr         CreateZonePipe (const char* nomZone,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre,
                                      CORBA::Double Xaxe, CORBA::Double Yaxe, CORBA::Double Zaxe,
                                      CORBA::Double Rayon, CORBA::Double Haut, CORBA::Double Rayonint);
  HOMARD::HOMARD_Zone_ptr         CreateZoneSphere (const char* nomZone,
                                      CORBA::Double Xcentre, CORBA::Double Ycentre, CORBA::Double Zcentre, CORBA::Double Rayon);

// Les informations
  HOMARD::HOMARD_Boundary_ptr     GetBoundary   (const char* nomBoundary);
  HOMARD::HOMARD_Cas_ptr          GetCase       (const char* nomCas);
  HOMARD::HOMARD_Hypothesis_ptr   GetHypothesis (const char* nomHypothesis);
  HOMARD::HOMARD_Iteration_ptr    GetIteration  (const char* nomIteration);
  HOMARD::HOMARD_Zone_ptr         GetZone       (const char* nomZone);

  HOMARD::listeBoundarys*         GetAllBoundarysName();
  HOMARD::listeCases*             GetAllCasesName();
  HOMARD::listeHypotheses*        GetAllHypothesesName();
  HOMARD::listeIterations*        GetAllIterationsName();
  HOMARD::listeZones*             GetAllZonesName();

  void                            MeshInfo      (const char* nomCas,
                                                 const char* MeshName, const char* FileName, const char* DirName,
                                                 CORBA::Long Qual, CORBA::Long Diam, CORBA::Long Conn, CORBA::Long Tail, CORBA::Long Inte);

  HOMARD::HOMARD_Iteration_ptr    LastIteration  (const char* nomCas);

// L'etude
  SALOMEDS::Study_ptr             GetCurrentStudy();
  void                            SetCurrentStudy(SALOMEDS::Study_ptr theStudy);
  CORBA::Long                     GetCurrentStudyID();

// Liens entre structures
  void                            InvalideBoundary(const char* nomBoundary);
  void                            InvalideHypo(const char* nomHypo);
  void                            InvalideIter(const char* nomIter);
  void                            InvalideIterOption(const char* nomIter, CORBA::Long Option);
  void                            InvalideIterInfo(const char* nomIter);
  void                            InvalideZone(const char* nomZone);

  CORBA::Long                     DeleteBoundary(const char* nomBoundary);
  CORBA::Long                     DeleteCase(const char* nomCas, CORBA::Long Option);
  CORBA::Long                     DeleteHypo(const char* nomHypothesis);
  CORBA::Long                     DeleteIteration(const char* nomIter, CORBA::Long Option);
  CORBA::Long                     DeleteIterationOption(const char* nomIter, CORBA::Long Option1, CORBA::Long Option2);
  CORBA::Long                     DeleteZone(const char* nomZone);

  void                            AssociateIterHypo(const char* nomIter, const char* nomHypothesis);

  void                            AssociateHypoZone(const char* nomHypothesis, const char* nomZone, CORBA::Long TypeUse);
  void                            DissociateHypoZone(const char* nomHypothesis, const char* nomZone);

  void                            AssociateCaseIter(const char* nomCas, const char* nomIter,
                                                    const char* labelIter);

// Actions
  void                            SetEtatIter(const char* nomIter,const CORBA::Long Etat);
  char*                           CreateDirNameIter(const char* nomrep, CORBA::Long num );

  CORBA::Long                     Compute(const char* nomIteration, CORBA::Long etatMenage, CORBA::Long modeHOMARD, CORBA::Long Option1, CORBA::Long Option2);
  CORBA::Long                     ComputeAdap(HOMARD::HOMARD_Cas_var myCase, HOMARD::HOMARD_Iteration_var myIteration, CORBA::Long etatMenage, HomardDriver* myDriver, CORBA::Long Option1, CORBA::Long Option2);
  char*                           ComputeDirManagement(HOMARD::HOMARD_Cas_var myCase, HOMARD::HOMARD_Iteration_var myIteration, CORBA::Long etatMenage);
  char*                           ComputeDirPaManagement(HOMARD::HOMARD_Cas_var myCase, HOMARD::HOMARD_Iteration_var myIteration);
  void                            DriverTexteZone(HOMARD::HOMARD_Hypothesis_var myHypo, HomardDriver* myDriver);
  void                            DriverTexteField(HOMARD::HOMARD_Iteration_var myIteration, HOMARD::HOMARD_Hypothesis_var myHypo, HomardDriver* myDriver);
  void                            DriverTexteBoundary(HOMARD::HOMARD_Cas_var myCase, HomardDriver* myDriver);
  void                            DriverTexteFieldInterp(HOMARD::HOMARD_Iteration_var myIteration, HOMARD::HOMARD_Hypothesis_var myHypo, HomardDriver* myDriver);

  CORBA::Boolean                  VerifieDir(const char* nomDir);

  void                            PublishResultInSmesh(const char* NomFich, CORBA::Long Option);
  void                            DeleteResultInSmesh(const char* NomFich, const char* MeshName);
  void                            PublishFileUnderIteration(const char* NomIter, const char* NomFich,
                                                            const char* Commentaire);
  void                            PublishBoundaryUnderCase(const char* CaseName, const char* BoundaryName);

  void                            IsValidStudy();

  // ---------------------------------------------------------------
  // next functions are inherited from SALOMEDS::Driver interface
  // ---------------------------------------------------------------

  // --> Persistence
  virtual SALOMEDS::TMPFile*      Save(SALOMEDS::SComponent_ptr theComponent,
					const char* theURL,
					CORBA::Boolean isMultiFile);

  virtual SALOMEDS::TMPFile*      SaveASCII(SALOMEDS::SComponent_ptr theComponent,
					     const char* theURL,
					     CORBA::Boolean isMultiFile);

  virtual CORBA::Boolean          Load(SALOMEDS::SComponent_ptr theComponent,
					const SALOMEDS::TMPFile& theStream,
					const char* theURL,
					CORBA::Boolean isMultiFile);

  virtual CORBA::Boolean          LoadASCII(SALOMEDS::SComponent_ptr theComponent,
					     const SALOMEDS::TMPFile& theStream,
					     const char* theURL,
					     CORBA::Boolean isMultiFile);

  virtual void                    Close(SALOMEDS::SComponent_ptr IORSComponent);

  virtual char*                   ComponentDataType();

  virtual char*                   IORToLocalPersistentID(SALOMEDS::SObject_ptr theSObject,
							  const char* IORString,
							  CORBA::Boolean isMultiFile,
							  CORBA::Boolean isASCII);

  virtual char*                   LocalPersistentIDToIOR(SALOMEDS::SObject_ptr theSObject,
							  const char* aLocalPersistentID,
							  CORBA::Boolean isMultiFile,
							  CORBA::Boolean isASCII);

  // --> Data publishing
  virtual CORBA::Boolean          CanPublishInStudy(CORBA::Object_ptr theIOR);

  virtual SALOMEDS::SObject_ptr   PublishInStudy(SALOMEDS::Study_ptr theStudy,
                                                 SALOMEDS::SObject_ptr theSObject,
                                                 CORBA::Object_ptr theObject,
                                                 const char* theName);

  // --> Copy/Paste
  virtual CORBA::Boolean          CanCopy(SALOMEDS::SObject_ptr theObject);

  virtual SALOMEDS::TMPFile*      CopyFrom(SALOMEDS::SObject_ptr theObject,
					    CORBA::Long& theObjectID);

  virtual CORBA::Boolean          CanPaste(const char* theComponentName, CORBA::Long theObjectID);

  virtual SALOMEDS::SObject_ptr   PasteInto(const SALOMEDS::TMPFile& theStream,
					     CORBA::Long theObjectID,
					     SALOMEDS::SObject_ptr theObject);

//   virtual void SALOMEException( std::string message );

private:
  void                            addInStudy(SALOMEDS::Study_ptr theStudy);
  SALOMEDS::SObject_ptr           PublishCaseInStudy(SALOMEDS::Study_ptr theStudy, SALOMEDS::StudyBuilder_var aStudyBuilder,
                                                     HOMARD::HOMARD_Cas_ptr theObject, const char* theName);

  SALOMEDS::SObject_ptr           PublishHypotheseInStudy(SALOMEDS::Study_ptr theStudy, SALOMEDS::StudyBuilder_var aStudyBuilder,
                                                     HOMARD::HOMARD_Hypothesis_ptr theObject, const char* theName);

  SALOMEDS::SObject_ptr           PublishZoneInStudy(SALOMEDS::Study_ptr theStudy, SALOMEDS::StudyBuilder_var aStudyBuilder,
                                                     HOMARD::HOMARD_Zone_ptr theObject, const char* theName);
  SALOMEDS::SObject_ptr           PublishBoundaryInStudy(SALOMEDS::Study_ptr theStudy, SALOMEDS::StudyBuilder_var aStudyBuilder,
                                                     HOMARD::HOMARD_Boundary_ptr theObject, const char* theName);
  virtual void                    PublishInStudyAttr(SALOMEDS::StudyBuilder_var aStudyBuilder,
                                                     SALOMEDS::SObject_var aResultSO,
                                                     const char* theName, const char* value, const char* icone, const char* ior);

PortableServer::ServantBase_var GetServant(CORBA::Object_ptr theObject);

  HOMARD::HOMARD_Cas_ptr          newCase();
  HOMARD::HOMARD_Hypothesis_ptr   newHypothesis();
  HOMARD::HOMARD_Iteration_ptr    newIteration();
  HOMARD::HOMARD_Zone_ptr         newZone();
  HOMARD::HOMARD_Boundary_ptr     newBoundary();


  virtual Engines::TMPFile*       DumpPython(CORBA::Object_ptr theStudy,
					     CORBA::Boolean isPublished,
					     CORBA::Boolean isMultiFile,
					     CORBA::Boolean& isValidScript);

  virtual char*                   getVersion();

private:
  struct StudyContext
  {
    std::map<std::string, HOMARD::HOMARD_Cas_var>        _mesCas;
    std::map<std::string, HOMARD::HOMARD_Hypothesis_var> _mesHypotheses;
    std::map<std::string, HOMARD::HOMARD_Iteration_var>  _mesIterations;
    std::map<std::string, HOMARD::HOMARD_Zone_var>       _mesZones;
    std::map<std::string, HOMARD::HOMARD_Boundary_var>   _mesBoundarys;
    std::map<int, PortableServer::ServantBase*>          _idmap;
  };
  typedef std::map<int, StudyContext> ContextMap;

  ::HOMARD_Gen*                 myHomard;
  SALOMEDS::Study_var           myCurrentStudy;
  ContextMap                    myContextMap;
  SALOME_NamingService*         _NS;

};

#endif
