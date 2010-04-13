#ifndef ALIANALYSISTASKSEIMPPARRES_H
#define ALIANALYSISTASKSEIMPPARRES_H

/* Copyright(c) 1998-2010, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

//*************************************************************************
// Class AliAnalysisTaskSEImpParRes
// AliAnalysisTaskSE for the study of the track impact parameter resolution
//
// Authors: xianbao.yuan@pd.infn.it, andrea.dainese@pd.infn.it
// 
//*************************************************************************

class TList;
class TH1F;

#include "AliAnalysisTaskSE.h"

class AliAnalysisTaskSEImpParRes : public AliAnalysisTaskSE {

 public:
  
  AliAnalysisTaskSEImpParRes();
  AliAnalysisTaskSEImpParRes(const char *name);
  virtual ~AliAnalysisTaskSEImpParRes();
  
  
  // Implementation of interface methods
  virtual void UserCreateOutputObjects();
  virtual void UserExec(Option_t *option);
  virtual void Terminate(Option_t *option);
  void SetReadMC(Bool_t readMC) { fReadMC=readMC; return; }
  void SetSelectedPdg(Int_t pdg) { fSelectedPdg=pdg; return; }

 private:
  
  AliAnalysisTaskSEImpParRes(const AliAnalysisTaskSEImpParRes &source);
  AliAnalysisTaskSEImpParRes& operator=(const AliAnalysisTaskSEImpParRes& source);  
  
  Int_t PtBin(Double_t pt) const;

  Bool_t fReadMC;       // flag used to switch on/off MC reading
  Int_t  fSelectedPdg;  // only for a given particle species (-1 takes all tracks)
  TList *fOutputitspureSARec;  //! ITS StandAlone: with track in vtx 
  TList *fOutputitspureSASkip; //! ITS StandAlone: w/o track in vtx
  TList *fOutputallPointRec;   //! ITS+TPC: 6 ITScls, with track in vtx      
  TList *fOutputallPointSkip;  //! ITS+TPC: 6 ITScls, w/o track in vtx      
  TList *fOutputpartPointRec;   //! ITS+TPC: >=1 SPD, with track in vtx
  TList *fOutputpartPointSkip;  //! ITS+TPC: >=1 SPD, w/o track in vtx
  TList *fOutputonepointSPDRec; //! At least one point on SPD, with track in vtx
  TList *fOutputonepointSPDSkip;//! At least one point on SPD w/o track in vtx
  TList *fOutputpostvTracRec;   //! ITS+TPC: >=1 SPD, positives, with track in vtx
  TList *fOutputpostvTracSkip;  //! ITS+TPC: >=1 SPD, positives, w/o track in vtx
  TList *fOutputnegtvTracRec;   //! ITS+TPC: >=1 SPD, negatives, with track in vtx
  TList *fOutputnegtvTracSkip;  //! ITS+TPC: >=1 SPD, negatives, w/o track in vtx
  TList *fOutputpullAllpointRec; //! pull ITS+TPC: 6 ITScls, with track in vtx
  TList *fOutputpullAllpointSkip;//! pull ITS+TPC: 6 ITScls, w/o track in vtx
  TList *fOutputOnlyRefitRec;   //! ITS+TPC: any ITScls, with track in vtx
  TList *fOutputOnlyRefitSkip; //! ITS+TPC: any ITScls, w/o track in vtx
  TList *fOutputPt;     //!           
  TH1F  *fNentries;   //! histogram of number of events
  TH1F  *fEstimVtx;   //! vertex resolution

  ClassDef(AliAnalysisTaskSEImpParRes,1); // AliAnalysisTaskSE for the study of the impact parameter resolution
};

#endif
