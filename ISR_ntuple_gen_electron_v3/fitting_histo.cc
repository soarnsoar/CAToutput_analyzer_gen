void fit_histo(float xmin, float xmax, TH1D &hh){
  //  TH1F *hh = TFile::Open("MG.root")->Get("dipt");
  //  hh->Draw();
  TF1 *g1 = new TF1("g1","gaus",xmin,xmax);
  hh->Fit(g1,"R");
  
}
