void make_slope_NLO(){
  //NLO nofsr eemm
  TFile *filem;
  TFile *filee;

  filem = TFile::Open("../ISR_ntuple_gen_muon_v3/histograms/NLO.root");
  filee = TFile::Open("../ISR_ntuple_gen_electron_v3/histograms/NLO.root");

  TLegend *leg = new TLegend(0.4,0.85,0.15,0.6);
  
  float pt4060, pt80100, pt100200, pt200350;
  float spt4060, spt80100, spt100200, spt200350;
  float n4060, n80100, n100200, n200350;
  float dpt4060, dpt80100, dpt100200, dpt200350;
  
  
  float m4060,m80100,m100200,m200350;
  float sm4060, sm80100, sm100200, sm200350;
  
  float dm4060,dm80100,dm100200,dm200350;
  



  pt4060 = ((TH1D*)filem->Get("dipt4060"))->GetMean();
  pt80100 = ((TH1D*)filem->Get("dipt80100"))->GetMean();
  pt100200 = ((TH1D*)filem->Get("dipt100200"))->GetMean();
  pt200350 = ((TH1D*)filem->Get("dipt200350"))->GetMean();

  spt4060 = ((TH1D*)filem->Get("dipt4060"))->GetRMS();
  spt80100 = ((TH1D*)filem->Get("dipt80100"))->GetRMS();
  spt100200 = ((TH1D*)filem->Get("dipt100200"))->GetRMS();
  spt200350 = ((TH1D*)filem->Get("dipt200350"))->GetRMS();

  n4060 = ((TH1D*)filem->Get("dipt4060"))->GetEntries();
  n80100 = ((TH1D*)filem->Get("dipt80100"))->GetEntries();
  n100200 = ((TH1D*)filem->Get("dipt100200"))->GetEntries();
  n200350 = ((TH1D*)filem->Get("dipt200350"))->GetEntries();


  /*
  dpt4060 = spt4060/sqrt(n4060);
  dpt80100 = spt80100/sqrt(n80100);
  dpt100200 = spt100200/sqrt(n100200);
  dpt200350 = spt200350/sqrt(n200350);
  */
  dpt4060 = ((TH1D*)filem->Get("dipt4060"))->GetMeanError();
  dpt80100 =((TH1D*)filem->Get("dipt80100"))->GetMeanError();
  dpt100200 = ((TH1D*)filem->Get("dipt100200"))->GetMeanError();
  dpt200350 = ((TH1D*)filem->Get("dipt200350"))->GetMeanError();
 
  

  m4060 = ((TH1D*)filem->Get("dimass4060"))->GetMean();
  m80100 = ((TH1D*)filem->Get("dimass80100"))->GetMean(); 
  m100200 = ((TH1D*)filem->Get("dimass100200"))->GetMean();
  m200350 = ((TH1D*)filem->Get("dimass200350"))->GetMean();
  
  sm4060 = ((TH1D*)filem->Get("dimass4060"))->GetRMS();
  sm80100 = ((TH1D*)filem->Get("dimass80100"))->GetRMS(); 
  sm100200 = ((TH1D*)filem->Get("dimass100200"))->GetRMS();
  sm200350 = ((TH1D*)filem->Get("dimass200350"))->GetRMS();

  dm4060 = sm4060/sqrt(n4060); 
  dm80100 = sm80100/sqrt(n80100); 
  dm100200 = sm100200/sqrt(n100200); 
  dm200350 = sm200350/sqrt(n200350); 
    
  Float_t x[4] = { pow(m4060,2), pow(m80100,2), pow(m100200,2), pow(m200350,2)};
  Float_t y[4] = { pt4060, pt80100, pt100200, pt200350};
  
  //Float_t ex[4] = {dm4060,dm80100,dm100200,dm200350};
  Float_t ex[4] = {0,0,0,0};
  
  Float_t ey[4] = {dpt4060,dpt80100,dpt100200,dpt200350};
  Float_t eey[4] = {0.0,0.0,0.0,0.0};
  
  TCanvas * c1 = new TCanvas();
  TGraphErrors *PTQQm = new TGraphErrors(4,x,y,ex,ey);
  TGraphErrors *PTQQmf = new TGraphErrors(4,x,y,ex,eey);
  cout<<"mumu"<<endl;
  PTQQm->Print();
  TF1 *ffm = new TF1("ffm", "[1] * log(x) + [0]");
  //PTQQf->Fit(ff);
  PTQQm->SetTitle("Gen-Level #mu#mu vs ee, exclude FSR  aMC@NLO 13TeV");
  PTQQm->GetXaxis()->SetTitle("<M(ll)>^{2} [ GeV^{2} ]");
  PTQQm->GetYaxis()->SetTitle("<P_{T}(ll)> [ GeV ]");
  PTQQm->SetMarkerColor(4);
  PTQQm->SetMarkerStyle(21);
  c1->SetLogx();
  c1->SetGrid();
   



  pt4060 = ((TH1D*)filee->Get("dipt4060"))->GetMean();
  pt80100 = ((TH1D*)filee->Get("dipt80100"))->GetMean();
  pt100200 = ((TH1D*)filee->Get("dipt100200"))->GetMean();
  pt200350 = ((TH1D*)filee->Get("dipt200350"))->GetMean();

  spt4060 = ((TH1D*)filee->Get("dipt4060"))->GetRMS();
  spt80100 = ((TH1D*)filee->Get("dipt80100"))->GetRMS();
  spt100200 = ((TH1D*)filee->Get("dipt100200"))->GetRMS();
  spt200350 = ((TH1D*)filee->Get("dipt200350"))->GetRMS();

  n4060 = ((TH1D*)filee->Get("dipt4060"))->GetEntries();
  n80100 = ((TH1D*)filee->Get("dipt80100"))->GetEntries();
  n100200 = ((TH1D*)filee->Get("dipt100200"))->GetEntries();
  n200350 = ((TH1D*)filee->Get("dipt200350"))->GetEntries();
  /*
  dpt4060 = spt4060/sqrt(n4060);
  dpt80100 = spt80100/sqrt(n80100);
  dpt100200 = spt100200/sqrt(n100200);
  dpt200350 = spt200350/sqrt(n200350);
  */

  dpt4060 = ((TH1D*)filee->Get("dipt4060"))->GetMeanError();
  dpt80100 = ((TH1D*)filee->Get("dipt80100"))->GetMeanError();
  dpt100200 = ((TH1D*)filee->Get("dipt100200"))->GetMeanError();
  dpt200350 = ((TH1D*)filee->Get("dipt200350"))->GetMeanError();


  
  m4060 = ((TH1D*)filee->Get("dimass4060"))->GetMean();
  m80100 = ((TH1D*)filee->Get("dimass80100"))->GetMean(); 
  m100200 = ((TH1D*)filee->Get("dimass100200"))->GetMean();
  m200350 = ((TH1D*)filee->Get("dimass200350"))->GetMean();
  
  sm4060 = ((TH1D*)filee->Get("dimass4060"))->GetRMS();
  sm80100 = ((TH1D*)filee->Get("dimass80100"))->GetRMS(); 
  sm100200 = ((TH1D*)filee->Get("dimass100200"))->GetRMS();
  sm200350 = ((TH1D*)filee->Get("dimass200350"))->GetRMS();

  dm4060 = sm4060/sqrt(n4060); 
  dm80100 = sm80100/sqrt(n80100); 
  dm100200 = sm100200/sqrt(n100200); 
  dm200350 = sm200350/sqrt(n200350); 
    
  Float_t x[4] = { pow(m4060,2), pow(m80100,2), pow(m100200,2), pow(m200350,2)};
  Float_t y[4] = { pt4060, pt80100, pt100200, pt200350};
  cout<<x[3]<<endl;
  cout<<y[3]<<endl;
  
  //Float_t ex[4] = {dm4060,dm80100,dm100200,dm200350};
  Float_t ex[4] = {0,0,0,0};
  
  Float_t ey[4] = {dpt4060,dpt80100,dpt100200,dpt200350};
  
  TGraphErrors *PTQQe = new TGraphErrors(4,x,y,ex,ey);
  TGraphErrors *PTQQef = new TGraphErrors(4,x,y,ex,eey);

  TF1 *ffe = new TF1("ffe", "[1] * log(x) + [0]");
  cout<<"ee, NLO"<<endl;
  PTQQe->Print();
  //PTQQf_fsr->Fit(ff_fsr);
  PTQQe->SetTitle("Gen-Level #mu#mu vs ee, exclude FSR aMC@NLO 13TeV");
  PTQQe->GetXaxis()->SetTitle("<M(ll)>^{2} [ GeV^{2} ]");
  PTQQe->GetYaxis()->SetTitle("<P_{T}(ll)> [ GeV ]");
 
  PTQQe->SetMarkerColor(3);
  PTQQe->SetMarkerStyle(21);

  
  
  PTQQm->SetFillColor(0);  
  PTQQe->SetFillColor(0);
  leg->TLegend::AddEntry(PTQQe,"ee");
  leg->TLegend::AddEntry(PTQQm,"#mu#mu");


  PTQQe->Draw("ALP");
  PTQQm->Draw("LP SAME");
  // PTQQf->SetLineColor(0);
  PTQQm->GetYaxis()->SetRangeUser(10,30);
  PTQQe->GetYaxis()->SetRangeUser(10,30);
  //  PTQQ->GetXaxis()->SetRangeUser(1600,80000);
  //PTQQ_fsr->GetXaxis()->SetRangeUser(1600,80000);
 
  leg->Draw();
  c1->SaveAs("plot_files/slope_NLO.png");  
}
