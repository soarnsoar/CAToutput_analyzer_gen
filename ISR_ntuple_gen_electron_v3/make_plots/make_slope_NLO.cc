void make_slope_NLO(){

  TFile *MGfile;
  TFile *NLOfile;

  MGfile = TFile::Open("../histograms/MG.root");
  NLOfile = TFile::Open("../histograms/NLO.root");

  TLegend *leg = new TLegend(0.4,0.85,0.15,0.6);
  
  float pt4060, pt80100, pt100200, pt200350;
  float spt4060, spt80100, spt100200, spt200350;
  float n4060, n80100, n100200, n200350;
  float dpt4060, dpt80100, dpt100200, dpt200350;
  
  
  float m4060,m80100,m100200,m200350;
  float sm4060, sm80100, sm100200, sm200350;
  
  float dm4060,dm80100,dm100200,dm200350;
  



  pt4060 = ((TH1D*)NLOfile->Get("dipt4060"))->GetMean();
  pt80100 = ((TH1D*)NLOfile->Get("dipt80100"))->GetMean();
  pt100200 = ((TH1D*)NLOfile->Get("dipt100200"))->GetMean();
  pt200350 = ((TH1D*)NLOfile->Get("dipt200350"))->GetMean();

  spt4060 = ((TH1D*)NLOfile->Get("dipt4060"))->GetRMS();
  spt80100 = ((TH1D*)NLOfile->Get("dipt80100"))->GetRMS();
  spt100200 = ((TH1D*)NLOfile->Get("dipt100200"))->GetRMS();
  spt200350 = ((TH1D*)NLOfile->Get("dipt200350"))->GetRMS();

  n4060 = ((TH1D*)NLOfile->Get("dipt4060"))->GetEntries();
  n80100 = ((TH1D*)NLOfile->Get("dipt80100"))->GetEntries();
  n100200 = ((TH1D*)NLOfile->Get("dipt100200"))->GetEntries();
  n200350 = ((TH1D*)NLOfile->Get("dipt200350"))->GetEntries();
  /*
  dpt4060 = spt4060/sqrt(n4060);
  dpt80100 = spt80100/sqrt(n80100);
  dpt100200 = spt100200/sqrt(n100200);
  dpt200350 = spt200350/sqrt(n200350);
  */
  dpt4060 = ((TH1D*)NLOfile->Get("dipt4060"))->GetMeanError();
  dpt80100 = ((TH1D*)NLOfile->Get("dipt80100"))->GetMeanError();
  dpt100200 = ((TH1D*)NLOfile->Get("dipt100200"))->GetMeanError();
  dpt200350 = ((TH1D*)NLOfile->Get("dipt200350"))->GetMeanError();
 
 

  m4060 = ((TH1D*)NLOfile->Get("dimass4060"))->GetMean();
  m80100 = ((TH1D*)NLOfile->Get("dimass80100"))->GetMean(); 
  m100200 = ((TH1D*)NLOfile->Get("dimass100200"))->GetMean();
  m200350 = ((TH1D*)NLOfile->Get("dimass200350"))->GetMean();
  
  sm4060 = ((TH1D*)NLOfile->Get("dimass4060"))->GetRMS();
  sm80100 = ((TH1D*)NLOfile->Get("dimass80100"))->GetRMS(); 
  sm100200 = ((TH1D*)NLOfile->Get("dimass100200"))->GetRMS();
  sm200350 = ((TH1D*)NLOfile->Get("dimass200350"))->GetRMS();

  dm4060 = sm4060/sqrt(n4060); 
  dm80100 = sm80100/sqrt(n80100); 
  dm100200 = sm100200/sqrt(n100200); 
  dm200350 = sm200350/sqrt(n200350); 
    
  Float_t x[4] = { pow(m4060,2), pow(m80100,2), pow(m100200,2), pow(m200350,2)};
  Float_t y[4] = { pt4060, pt80100, pt100200, pt200350};
  
  //Float_t ex[4] = {dm4060,dm80100,dm100200,dm200350};
  Float_t ex[4] = {0,0,0,0};
  
  Float_t ey[4] = {dpt4060,dpt80100,dpt100200,dpt200350};
  
  TCanvas * c1 = new TCanvas();
  TGraphErrors *PTQQ = new TGraphErrors(4,x,y,ex,ey);
  cout<<"NLO exclude FSR"<<endl;
  TF1 *ff = new TF1("ff", "[1] * log(x) + [0]");
  cout<<"FSR NOT considered"<<endl; 
  PTQQ->Print();
  //PTQQ->Fit(ff);
  PTQQ->SetTitle("Gen-Level No FSR vs FSR, aMC@NLO 13TeV");
  PTQQ->GetXaxis()->SetTitle("<M(ee)>^{2} [ GeV^{2} ]");
  PTQQ->GetYaxis()->SetTitle("<P_{T}(ee)> [ GeV ]");
  PTQQ->SetMarkerColor(4);
  PTQQ->SetMarkerStyle(21);
  c1->SetLogx();
  c1->SetGrid();
   



  pt4060 = ((TH1D*)NLOfile->Get("diptfsr4060"))->GetMean();
  pt80100 = ((TH1D*)NLOfile->Get("diptfsr80100"))->GetMean();
  pt100200 = ((TH1D*)NLOfile->Get("diptfsr100200"))->GetMean();
  pt200350 = ((TH1D*)NLOfile->Get("diptfsr200350"))->GetMean();

  spt4060 = ((TH1D*)NLOfile->Get("diptfsr4060"))->GetRMS();
  spt80100 = ((TH1D*)NLOfile->Get("diptfsr80100"))->GetRMS();
  spt100200 = ((TH1D*)NLOfile->Get("diptfsr100200"))->GetRMS();
  spt200350 = ((TH1D*)NLOfile->Get("diptfsr200350"))->GetRMS();

  n4060 = ((TH1D*)NLOfile->Get("diptfsr4060"))->GetEntries();
  n80100 = ((TH1D*)NLOfile->Get("diptfsr80100"))->GetEntries();
  n100200 = ((TH1D*)NLOfile->Get("diptfsr100200"))->GetEntries();
  n200350 = ((TH1D*)NLOfile->Get("diptfsr200350"))->GetEntries();
  /*
  dpt4060 = spt4060/sqrt(n4060);
  dpt80100 = spt80100/sqrt(n80100);
  dpt100200 = spt100200/sqrt(n100200);
  dpt200350 = spt200350/sqrt(n200350);
  */

  dpt4060 = ((TH1D*)NLOfile->Get("diptfsr4060"))->GetMeanError();
  dpt80100 = ((TH1D*)NLOfile->Get("diptfsr80100"))->GetMeanError();
  dpt100200 = ((TH1D*)NLOfile->Get("diptfsr100200"))->GetMeanError();
  dpt200350 = ((TH1D*)NLOfile->Get("diptfsr200350"))->GetMeanError();
 

  
  m4060 = ((TH1D*)NLOfile->Get("dimassfsr4060"))->GetMean();
  m80100 = ((TH1D*)NLOfile->Get("dimassfsr80100"))->GetMean(); 
  m100200 = ((TH1D*)NLOfile->Get("dimassfsr100200"))->GetMean();
  m200350 = ((TH1D*)NLOfile->Get("dimassfsr200350"))->GetMean();
  
  sm4060 = ((TH1D*)NLOfile->Get("dimassfsr4060"))->GetRMS();
  sm80100 = ((TH1D*)NLOfile->Get("dimassfsr80100"))->GetRMS(); 
  sm100200 = ((TH1D*)NLOfile->Get("dimassfsr100200"))->GetRMS();
  sm200350 = ((TH1D*)NLOfile->Get("dimassfsr200350"))->GetRMS();

  dm4060 = sm4060/sqrt(n4060); 
  dm80100 = sm80100/sqrt(n80100); 
  dm100200 = sm100200/sqrt(n100200); 
  dm200350 = sm200350/sqrt(n200350); 
    
  Float_t x[4] = { pow(m4060,2), pow(m80100,2), pow(m100200,2), pow(m200350,2)};
  Float_t y[4] = { pt4060, pt80100, pt100200, pt200350};
  
  //Float_t ex[4] = {dm4060,dm80100,dm100200,dm200350};
  Float_t ex[4] = {0,0,0,0};
  
  Float_t ey[4] = {dpt4060,dpt80100,dpt100200,dpt200350};
  
  TGraphErrors *PTQQ_fsr = new TGraphErrors(4,x,y,ex,ey);
  cout<<"NLO include FSR"<<endl;
  PTQQ_fsr->Print();
  TF1 *ff_fsr = new TF1("ff_fsr", "[1] * log(x) + [0]");
  // PTQQ_fsr->Fit(ff_fsr);
  PTQQ_fsr->SetTitle("Gen-Level No FSR vs FSR, aMC@NLO 13TeV");
  PTQQ_fsr->GetXaxis()->SetTitle("<M(ee)>^{2} [ GeV^{2} ]");
  PTQQ_fsr->GetYaxis()->SetTitle("<P_{T}(ee)> [ GeV ]");
 
  PTQQ_fsr->SetMarkerColor(3);
  PTQQ_fsr->SetMarkerStyle(21);

  PTQQ->GetYaxis()->SetRangeUser(10,30);
  PTQQ_fsr->GetYaxis()->SetRangeUser(10,30);
 
  
  PTQQ->SetFillColor(0);  
  PTQQ_fsr->SetFillColor(0);
  
  leg->TLegend::AddEntry(PTQQ_fsr,"+ FSR mom.");
  leg->TLegend::AddEntry(PTQQ,"w/o FSR mom.");

  
  PTQQ_fsr->Draw("ALP");
  PTQQ->Draw("LP SAME");
  
  leg->Draw();
  c1->SaveAs("plot_files/slope_NLO.png");  
}
