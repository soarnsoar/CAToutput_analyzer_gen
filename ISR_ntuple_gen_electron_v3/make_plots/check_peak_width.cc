void check_peak_width(){


  TFile *file;
    file = TFile::Open("../histograms/MG.root");
  TH1D *hdiptMG = (TH1D*)file->Get("dipt") ;
  TH1D *hdiptMG4060= (TH1D*)file->Get("dipt4060");
  TH1D *hdiptMG80100= (TH1D*)file->Get("dipt80100");
  TH1D *hdiptMG100200= (TH1D*)file->Get("dipt100200");
  TH1D *hdiptMG200350= (TH1D*)file->Get("dipt200350");

    file = TFile::Open("../histograms/NLO.root");

  TH1D *hdiptNLO = (TH1D*)file->Get("dipt") ;
  TH1D *hdiptNLO4060= (TH1D*)file->Get("dipt4060");
  TH1D *hdiptNLO80100= (TH1D*)file->Get("dipt80100");
  TH1D *hdiptNLO100200= (TH1D*)file->Get("dipt100200");
  TH1D *hdiptNLO200350= (TH1D*)file->Get("dipt200350");

  float xmin = 1;
  float xmax = 5;

  TF1 *g1 = new TF1("g1","gaus",xmin,xmax);

  /*
  hdiptMG->Fit(g1,"R");
  TF1 *f1 = hdiptMG->GetFunction("g1");
  float xall = f1->GetParameter(1);
  float eall = f1->GetParError(1);
  //  cout<<x4060<<endl;
  hdiptMG4060->Fit(g1,"R");
  TF1 *f1 = hdiptMG->GetFunction("g1");
  float x4060 = f1->GetParameter(1);
  float e4060 = f1->GetParError(1);
  */
  float xall, x4060, x80100,x100200,x200350;
  float eall, e4060, e80100,e100200,e200350;
  
  fitpara(g1, hdiptMG, xall, eall);
  fitpara(g1, hdiptMG4060, x4060, e4060);
  fitpara(g1, hdiptMG80100, x80100, e80100);
  fitpara(g1, hdiptMG100200, x100200, e100200);
  fitpara(g1, hdiptMG200350, x200350, e200350);

  float mgx[5] = {xall, x4060, x80100, x100200, x200350};
  float mge[5] = {eall, e4060, e80100, e100200, e200350};
  
  fitpara(g1, hdiptNLO, xall, eall);
  fitpara(g1, hdiptNLO4060, x4060, e4060);
  fitpara(g1, hdiptNLO80100, x80100, e80100);
  fitpara(g1, hdiptNLO100200, x100200, e100200);
  fitpara(g1, hdiptNLO200350, x200350, e200350);

  
  float nlox[5] = {xall, x4060, x80100, x100200, x200350};
  float nloe[5] = {eall, e4060, e80100, e100200, e200350};
  TString region[5] = {"40~350 GeV","40~60 GeV","80~100 GeV","100~200 GeV","200~350 GeV"};
  TH1F *mgpeak = new TH1F("Peak width[GeV], ee, MG, w/o FSR mom.","Peak width[GeV], ee, w/o FSR mom.",5,0,5 );
  mgpeak->SetBinContent(1,mgx[0]);
  mgpeak->SetBinError(1,mge[0]);
  mgpeak->GetXaxis()->SetBinLabel(1,region[0]);

  mgpeak->SetBinContent(2,mgx[1]);
  mgpeak->SetBinError(2,mge[1]);
  mgpeak->GetXaxis()->SetBinLabel(2,region[1]);

  mgpeak->SetBinContent(3,mgx[2]);
  mgpeak->SetBinError(3,mge[2]);
  mgpeak->GetXaxis()->SetBinLabel(3,region[2]);

  mgpeak->SetBinContent(4,mgx[3]);
  mgpeak->SetBinError(4,mge[3]);
  mgpeak->GetXaxis()->SetBinLabel(4,region[3]);
 
  mgpeak->SetBinContent(5,mgx[4]);
  mgpeak->SetBinError(5,mge[4]);
  mgpeak->GetXaxis()->SetBinLabel(5,region[4]);
  mgpeak->SetStats(0);
  mgpeak->GetYaxis()->SetTitle("Peak Width [GeV]");
  mgpeak->GetYaxis()->SetRangeUser(1,4);
  //mgpeak->Draw();

  mgpeak->GetXaxis()->SetLabelSize(0.05);
  TH1F *nlopeak = new TH1F("Peak width[GeV], aMC@NLO, w/o FSR mom.","Peak width[GeV], aMC@NLO, w/o FSR mom.",5,0,5 );
  nlopeak->SetBinContent(1,nlox[0]);
  nlopeak->SetBinError(1,nloe[0]);
  nlopeak->GetXaxis()->SetBinLabel(1,region[0]);

  nlopeak->SetBinContent(2,nlox[1]);
  nlopeak->SetBinError(2,nloe[1]);
  nlopeak->GetXaxis()->SetBinLabel(2,region[1]);

  nlopeak->SetBinContent(3,nlox[2]);
  nlopeak->SetBinError(3,nloe[2]);
  nlopeak->GetXaxis()->SetBinLabel(3,region[2]);

  nlopeak->SetBinContent(4,nlox[3]);
  nlopeak->SetBinError(4,nloe[3]);
  nlopeak->GetXaxis()->SetBinLabel(4,region[3]);
 
  nlopeak->SetBinContent(5,nlox[4]);
  nlopeak->SetBinError(5,nloe[4]);
  nlopeak->GetXaxis()->SetBinLabel(5,region[4]);
  nlopeak->SetStats(0);
  
  nlopeak->GetYaxis()->SetRangeUser(1,4);
  //nlopeak->Draw();
  TCanvas *c1 = new TCanvas();
  TLegend * leg = new TLegend(0.7,0.85,0.15,0.6);
  leg->TLegend::AddEntry(mgpeak, "MG, w/o FSR mom.");
  leg->TLegend::AddEntry(nlopeak, "aMC@NLO, w/o FSR mom.");
  leg->SetTextSize(0.05);
  mgpeak->SetMarkerColor(4);
  nlopeak->SetMarkerColor(2);

  mgpeak->SetMarkerStyle(1);
  nlopeak->SetMarkerStyle(1);
 
  mgpeak->SetLineColor(4);
  nlopeak->SetLineColor(2);
  mgpeak->SetLineWidth(4);
  nlopeak->SetLineWidth(4);
  
  mgpeak->SetFillStyle(3018);
  nlopeak->SetFillStyle(3018);
  mgpeak->SetFillColor(4);
  nlopeak->SetFillColor(2);
 

  mgpeak->Draw("E2");
  mgpeak->Draw("Y0 SAME");
  nlopeak->Draw("E2 SAME");
  nlopeak->Draw("Y0 SAME");
  leg->Draw();
  c1->SaveAs("plot_files/peak_width.png");
  
}
void fitpara(TF1 *g1, TH1D *hh, float &x, float &e){
  hh->Fit(g1,"R");
  TF1 *f1 = hh->GetFunction("g1");
  x = f1->GetParameter(2);
  e = f1->GetParError(2);
  
  
}
