#include <iostream>

void make_each_histo_mg(){
  TString path = "../combined_files/";

  TFile *MGfile;
  MGfile = TFile::Open(path + "MG.root");

  TFile *NLOfile;
  NLOfile = TFile::Open(path + "MCatNLO.root");
  

  //V//muon prefsr//muon postfsr
  //V PT
  //diPT
  
  //all of them with respect to mass 
  //


  TH1F *hVpt = new TH1F("Vpt","Vpt",100,0,100);
  TH1F *hdipt = new TH1F("dipt","dipt",100,0,100);
  TH1F *hdiptfsr = new TH1F("diptfsr","diptfsr",100,0,100);
 
  TH1F *hVmass = new TH1F("Vmass","Vmass",310,40,350);
  TH1F *hdimass = new TH1F("dimass","dimass",310,40,350);
  TH1F *hdimassfsr = new TH1F("dimassfsr","dimassfsr",310,40,350);

  TH1F *hVpt4060 = new TH1F("Vpt4060","Vpt4060",100,0,100);
  TH1F *hVpt80100 = new TH1F("Vpt80100","Vpt80100",100,0,100);
  TH1F *hVpt100200 = new TH1F("Vpt100200", "Vpt100200", 100,0,100);
  TH1F *hVpt200350 = new TH1F("Vpt200350", "Vpt200350", 100,0,100);
  
  TH1F *hdipt4060 = new TH1F("dipt4060","dipt4060",100,0,100);
  TH1F *hdipt80100 = new TH1F("dipt80100","dipt80100",100,0,100);
  TH1F *hdipt100200 = new TH1F("dipt100200","dipt100200",100,0,100);
  TH1F *hdipt200350 = new TH1F("dipt200350", "dipt200350",100,0,100);
  
  TH1F *hdiptfsr4060  = new TH1F("diptfsr4060","diptfsr4060",100,0,100);
  TH1F *hdiptfsr6080  = new TH1F("diptfsr6080","diptfsr6080",100,0,100);
  TH1F *hdiptfsr80100 = new TH1F("diptfsr80100","diptfsr80100",100,0,100);
  TH1F *hdiptfsr100200  = new TH1F("diptfsr100200","diptfsr100200",100,0,100);
  TH1F *hdiptfsr200350 = new TH1F("diptfsr200350","diptfsr200350",100,0,100);

  TH1F *hVmass4060 = new TH1F("Vmass4060","Vmass4060",20,40,60);
  TH1F *hVmass80100= new TH1F("Vmass80100","Vmass80100",20,80,100);
  TH1F *hVmass100200= new TH1F("Vmass100200","Vmass100200",100,100,200);
  TH1F *hVmass200350= new TH1F("Vmass200350","Vmass200350",150,200,350);

  TH1F *hdimass4060 = new TH1F("dimass4060","dimass4060",20,40,60);
  TH1F *hdimass80100= new TH1F("dimass80100","dimass80100",20,80,100);
  TH1F *hdimass100200= new TH1F("dimass100200","dimass100200",100,100,200);
  TH1F *hdimass200350= new TH1F("dimass200350","dimass200350",150,200,350);


  TH1F *hdimassfsr4060 = new TH1F("dimassfsr4060","dimassfsr4060",20,40,60);
  TH1F *hdimassfsr80100= new TH1F("dimassfsr80100","dimassfsr80100",20,80,100);
  TH1F *hdimassfsr100200= new TH1F("dimassfsr100200","dimassfsr100200",100,100,200);
  TH1F *hdimassfsr200350= new TH1F("dimassfsr200350","dimassfsr200350",150,200,350);

  TH1F *hfsrpt1 = new TH1F("FSR1 PT","FSR1 PT",10,0,10);
  TH1F *hfsrpt2 = new TH1F("FSR2 PT","FSR2 PT",10,0,10);
  TH1F *hfsrdipt = new TH1F("FSR PT sum", "FSR PT sum", 10,0,10);

  TH1F *hdR1 = new TH1F("dR1","dR1",100,0,6);
  TH1F *hdR2 = new TH1F("dR2","dR2",100,0,6);
  TH1F *hdRsum = new TH1F("dR( dilep, FSR)", "dR(dilep, FSR)", 100,0,6);
  TH1F *hdphi1 = new TH1F("dphi1","dphi1",100,-4,4);
  TH1F *hdphi2 = new TH1F("dphi2","dphi2",100,-4,4);
  TH1F *hdphisum = new TH1F("dphisum","dphisum",100,-4,4);

  TH1F *hdRll = new TH1F("dRll","dRll",100,0,6);
  TH1F *hdphill = new TH1F("dphill","dphill",100,-4,4);

  TH1F *hphifsr1 = new TH1F("phifsr1","phifsr1",100,-4,4);
  TH1F *hphifsr2 = new TH1F("phifsr2","phifsr2",100,-4,4);
  TH1F *hphifsrsum = new TH1F("phifsrsum","phifsrsum",100,-4,4);

  TH1F *hphill = new TH1F("phill","phill",100,-4,4);
 
  
  
  float pripx, pripy, pripz, prie;
  float secpx, secpy, secpz, sece;
  float vpx,vpy,vpz,ve;
  float fsr1px,fsr1py,fsr1pz,fsr1e;
  float fsr2px,fsr2py,fsr2pz,fsr2e;
  float weight;

  float mass, massfsr, dipt, diptfsr;

  TLorentzVector v1, v2, vfsr1,vfsr2, vv;
  

  TTree *prilep;
  TTree *seclep;
  TTree *V;
  TTree *fsr1;
  TTree *fsr2;
  TTree *weights;
  ////////////////MG//////////////////
  prilep = (TTree*)MGfile->Get("prilep");
  seclep = (TTree*)MGfile->Get("seclep");
  V = (TTree*)MGfile->Get("V");
  fsr1 = (TTree*)MGfile->Get("fsr1");
  fsr2 = (TTree*)MGfile->Get("fsr2");
  weights = (TTree*)MGfile->Get("weights");

  prilep->SetBranchAddress("px",&pripx);
  prilep->SetBranchAddress("py",&pripy);
  prilep->SetBranchAddress("pz",&pripz);
  prilep->SetBranchAddress("e",&prie);
  
  seclep->SetBranchAddress("px",&secpx);
  seclep->SetBranchAddress("py",&secpy);
  seclep->SetBranchAddress("pz",&secpz);
  seclep->SetBranchAddress("e",&sece);

    
  V->SetBranchAddress("px",&vpx);
  V->SetBranchAddress("py",&vpy);
  V->SetBranchAddress("pz",&vpz);
  V->SetBranchAddress("e",&ve);
 
  fsr1->SetBranchAddress("px",&fsr1px);
  fsr1->SetBranchAddress("py",&fsr1py);
  fsr1->SetBranchAddress("pz",&fsr1pz);
  fsr1->SetBranchAddress("e",&fsr1e);

  fsr2->SetBranchAddress("px",&fsr2px);
  fsr2->SetBranchAddress("py",&fsr2py);
  fsr2->SetBranchAddress("pz",&fsr2pz);
  fsr2->SetBranchAddress("e",&fsr2e);

  weights->SetBranchAddress("mcweights", &weight);


  int NN = prilep->GetEntries();
  cout<<"# of events = " << NN<<endl;
  for(int l = 0; l < NN; l++){
    //  cout<<l<<endl;
    prilep->GetEntry(l);
    v1.SetPxPyPzE( pripx, pripy, pripz, prie);

    seclep->GetEntry(l);
    v2.SetPxPyPzE( secpx, secpy, secpz, sece);

    V->GetEntry(l);
    vv.SetPxPyPzE( vpx, vpy, vpz, ve);

    fsr1->GetEntry(l);
    vfsr1.SetPxPyPzE( fsr1px, fsr1py, fsr1pz, fsr1e);

    fsr2->GetEntry(l);
    vfsr2.SetPxPyPzE( fsr2px, fsr2py, fsr2pz, fsr2e);

    weights->GetEntry(l);

    mass = (v1+v2).M();
    massfsr = (v1+v2+vfsr1+vfsr2).M();
    dipt = (v1+v2).Perp();
    diptfsr = (v1+v2+vfsr1+vfsr2).Perp();
    
    float ptlep1= v1.Perp();
    float ptlep2 = v2.Perp();
    float etalep1 = v1.Eta();
    float etalep2 = v2.Eta();
    float dR1 = v1.DeltaR(vfsr1);
    float dR2 = v2.DeltaR(vfsr2);
    float dRsum = (v1+v2).DeltaR(vfsr1+vfsr2);
    float dphi1 = v1.DeltaPhi(vfsr1);
    float dphi2 = v2.DeltaPhi(vfsr2);
    float dphisum = (v1+v2).DeltaPhi(vfsr1+vfsr2);
    float dRll = v1.DeltaR(v2);
    float dphill = v1.DeltaPhi(v2);

    float phifsr1 = vfsr1.Phi();
    float phifsr2 = vfsr2.Phi();
    float phifsrsum = (vfsr1+vfsr2).Phi(); 
    float phill = (v1+v2).Phi();
    ///////    normal condition ==> no fsr cut/////
    if(mass > 40 && mass <350 && ptlep1 > 20 && ptlep2 > 20 && fabs(etalep1)<2.4 && fabs( etalep2 ) < 2.4 && dipt < 100  ){
      hdipt->Fill(dipt,weight);
      hdimass->Fill(mass,weight);
      hdRll->Fill(dRll,weight);
      hdphill->Fill(dphill,weight);
      hphill -> Fill(phill,weight);
      if(fsr1e !=0){
	hdR1->Fill(dR1,weight); 
	hfsrpt1->Fill(vfsr1.Perp(),weight);
	hdphi1->Fill(dphi1,weight);
	hphifsr1 -> Fill(phifsr1,weight);
      }
      if(fsr2e !=0){
	hdR2->Fill(dR2,weight);
	hfsrpt2->Fill(vfsr2.Perp(),weight);
	hdphi2->Fill(dphi2,weight);
	hphifsr2 -> Fill(phifsr2,weight);
      }
      if(fsr1e !=0 || fsr2e !=0){
      hfsrdipt->Fill( (vfsr1+vfsr2).Perp());
      hdRsum -> Fill(dRsum);
      hdphisum->Fill(dphisum,weight);
      hphifsrsum -> Fill(phifsrsum,weight);
      }
      if(mass > 40 && mass < 60){
	hdipt4060->Fill(dipt,weight);
	hdimass4060->Fill(mass,weight);
	
      }
      if(mass > 80 && mass < 100){
	hdipt80100->Fill(dipt,weight);
	hdimass80100->Fill(mass,weight);
	
      }
      if(mass > 100 && mass < 200){
	hdipt100200->Fill(dipt,weight);
	hdimass100200->Fill(mass,weight);

      }
      if(mass > 200 && mass < 350){
	hdipt200350->Fill(dipt,weight);
	hdimass200350->Fill(mass,weight);	
      }
      
      
    }//end of normal condition if




    float ptfsrlep1, ptfsrlep2, etafsrlep1, etafsrlep2;
    ptfsrlep1 = (v1+vfsr1).Perp();
    ptfsrlep2 = (v2+vfsr2).Perp();
    etafsrlep1 = (v1+vfsr1).Eta();
    etafsrlep2 = (v2+vfsr2).Eta();
    if((massfsr > 40) && (massfsr < 350) && ( ptfsrlep1 > 20) && (ptfsrlep2 >20) && (fabs(etafsrlep1)<2.4) &&(  fabs(etafsrlep2) < 2.4) && diptfsr<100  ){
      
      
      hdiptfsr->Fill(diptfsr, weight);
      


      if(massfsr > 40 && massfsr < 60){
	hdiptfsr4060->Fill(diptfsr,weight);
	hdimassfsr4060->Fill(massfsr,weight);
	hVpt4060->Fill(vv.Perp(),weight);
	hVmass4060->Fill(vv.M(),weight);
      
      }
      
      if(massfsr > 80 && massfsr < 100){
	hdiptfsr80100->Fill(diptfsr,weight);
	hdimassfsr80100->Fill(massfsr,weight);
	hVpt80100->Fill(vv.Perp(),weight);
	hVmass80100->Fill(vv.M(),weight);
	
      }
      if(massfsr > 100 && massfsr < 200){
	hdiptfsr100200->Fill(diptfsr,weight);
	hdimassfsr100200->Fill(massfsr,weight);
	hVpt100200->Fill(vv.Perp(),weight);
	hVmass100200->Fill(vv.M(),weight);
	
      }
      if(massfsr > 200 && massfsr < 350){
	hdiptfsr200350->Fill(diptfsr, weight);
	hdimassfsr200350->Fill(massfsr, weight);
       	hVpt200350->Fill(vv.Perp(), weight);
	hVmass200350->Fill(vv.M(), weight);
	
      }
      

      hdimassfsr->Fill(massfsr,weight);
      hVmass->Fill(vv.M(),weight);
      hVpt->Fill(vv.Perp(),weight);
      //  if(vv.Perp() == 0) cout<<"what the hell"<<endl;
    }//end of fsr
    
    
    
    
  }//end of truth loop
  
  //hdiptfsr->Draw();
  TList *hListmg = new TList();

  TFile ftmg("../histograms/MG.root","recreate");
  //  hdiptfsr4060->Add(hdiptfsr80100);
  //hdiptfsr4060->Add(hdiptfsr100200);
  //hdiptfsr4060->Add(hdiptfsr200350);
  
  hListmg->Add(hVpt);
  hListmg->Add(hdipt);
  hListmg->Add(hdiptfsr);
  hListmg->Add(hVmass);
  hListmg->Add(hdimass);
  hListmg->Add(hdimassfsr);
  hListmg->Add(hVpt4060);
  hListmg->Add(hVpt80100);
  hListmg->Add(hVpt100200);
  hListmg->Add(hVpt200350);
  hListmg->Add(hdipt4060);
  hListmg->Add(hdipt80100);
  hListmg->Add(hdipt100200);
  hListmg->Add(hdipt200350);
  hListmg->Add(hdiptfsr4060);
  hListmg->Add(hdiptfsr6080);
  hListmg->Add(hdiptfsr80100);
  hListmg->Add(hdiptfsr100200);
  hListmg->Add(hdiptfsr200350);
  hListmg->Add(hVmass4060);
  hListmg->Add(hVmass80100);
  hListmg->Add(hVmass100200);
  hListmg->Add(hVmass200350);
  hListmg->Add(hdimass4060);
  hListmg->Add(hdimass80100);
  hListmg->Add(hdimass100200);
  hListmg->Add(hdimass200350);
  hListmg->Add(hdimassfsr4060);
  hListmg->Add(hdimassfsr80100);
  hListmg->Add(hdimassfsr100200);
  hListmg->Add(hdimassfsr200350);

  hListmg->Add(hdR1);
  hListmg->Add(hdR2);

  hListmg->Add(hfsrpt1);
  hListmg->Add(hfsrpt2);
  hListmg->Add(hfsrdipt);
  hListmg->Add(hdRsum);
  hListmg->Add(hdphi1);
  hListmg->Add(hdphi2);
  hListmg->Add(hdphisum);

  hListmg->Add(hdRll);
  hListmg->Add(hdphill);
  hListmg->Add(hphifsr1);
  hListmg->Add(hphifsr2);
  hListmg->Add(hphifsrsum);
  hListmg->Add(hphill);
  
  hListmg->Write();

  ftmg.Write();
  // exit();  
}
