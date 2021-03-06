#include <TPaveStats.h>
#include <fitting_histo.cc>
void FSR_histo_plot(){

  TFile *file;
  file = TFile::Open("../histograms/MG.root");

  ///Things to draw///

  //before fsr & after fsr
  //total dipt
  //dipt each mass region

  TH1D *hdiptMG = (TH1D*)file->Get("diptfsr") ;
  TH1D *hdiptMG4060= (TH1D*)file->Get("diptfsr4060");
  TH1D *hdiptMG80100= (TH1D*)file->Get("diptfsr80100");
  TH1D *hdiptMG100200= (TH1D*)file->Get("diptfsr100200");
  TH1D *hdiptMG200350= (TH1D*)file->Get("diptfsr200350");

  hdiptMG->Sumw2();
  hdiptMG4060->Sumw2();
  hdiptMG80100->Sumw2();
  hdiptMG100200->Sumw2();
  hdiptMG200350->Sumw2();
  file = TFile::Open("../histograms/NLO.root");

  TH1D *hdiptNLO = (TH1D*)file->Get("diptfsr") ;
  TH1D *hdiptNLO4060= (TH1D*)file->Get("diptfsr4060");
  TH1D *hdiptNLO80100= (TH1D*)file->Get("diptfsr80100");
  TH1D *hdiptNLO100200= (TH1D*)file->Get("diptfsr100200");
  TH1D *hdiptNLO200350= (TH1D*)file->Get("diptfsr200350");


  /*
  //Fitting range//
  float xmin = 1;
  float xmax = 5;
  
  cout<<"all mass range"<<endl;
  fitting_histo(xmin,xmax,(TH1D*)hdiptMG); //xmin,xmax,hh
  fitting_histo(xmin,xmax,(TH1D*)hdiptNLO); //xmin,xmax,hh

  cout<<"4060 mass range"<<endl;
  fitting_histo(xmin,xmax,(TH1D*)hdiptMG4060); //xmin,xmax,hh
  fitting_histo(xmin,xmax,(TH1D*)hdiptNLO4060); //xmin,xmax,hh

  cout<<"80100 mass range"<<endl;
 
  fitting_histo(xmin,xmax,(TH1D*)hdiptMG80100); //xmin,xmax,hh
  fitting_histo(xmin,xmax,(TH1D*)hdiptNLO80100); //xmin,xmax,hh

  cout<<"100200 mass range"<<endl;
 
  fitting_histo(xmin,xmax,(TH1D*)hdiptMG100200); //xmin,xmax,hh
  fitting_histo(xmin,xmax,(TH1D*)hdiptNLO100200); //xmin,xmax,hh


 cout<<"200350 mass range"<<endl;
 
  fitting_histo(xmin,xmax,(TH1D*)hdiptMG200350); //xmin,xmax,hh
  fitting_histo(xmin,xmax,(TH1D*)hdiptNLO200350); //xmin,xmax,hh
 
  
  */
  hdiptNLO->Sumw2();
  hdiptNLO4060->Sumw2();
  hdiptNLO80100->Sumw2();
  hdiptNLO100200->Sumw2();
  hdiptNLO200350->Sumw2();
  TH1D *hratio = new TH1D();
  hratio->Sumw2();
  hratio=(TH1D*)hdiptNLO->Clone();
  hratio->TH1D::Divide(hdiptMG);
  hratio->SetTitle("");
  hratio->SetStats(0);
  hratio->SetMarkerSize(0.5);
  hratio -> GetXaxis() -> SetLabelSize(0.13);
  hratio-> GetYaxis() -> SetLabelSize(0.13);
  hratio -> GetYaxis() -> SetTitleSize(0.15);
  hratio -> GetXaxis() -> SetTitleSize(0.15);
  hratio -> GetYaxis() -> SetTitleOffset(0.3);
  hratio -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio -> GetYaxis() -> SetTitle("NLO/MG");
  
  TH1D *hratio4060 = new TH1D();
  hratio4060->Sumw2();
  hratio4060=(TH1D*)hdiptNLO4060->Clone();
  hratio4060->TH1D::Divide(hdiptMG4060);
  hratio4060->SetTitle("");
  hratio4060->SetStats(0);
  hratio4060->SetMarkerSize(0.5);
  hratio4060 -> GetXaxis() -> SetLabelSize(0.13);
  hratio4060-> GetYaxis() -> SetLabelSize(0.13);
  hratio4060 -> GetYaxis() -> SetTitleSize(0.15);
  hratio4060 -> GetXaxis() -> SetTitleSize(0.15);
  hratio4060 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio4060 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio4060 -> GetYaxis() -> SetTitle("NLO/MG");
  
  TH1D *hratio80100 = new TH1D();
  
  hdiptNLO80100->Rebin(20);
  hdiptMG80100->Rebin(20);
  hratio80100->Sumw2();
  hratio80100=(TH1D*)hdiptNLO80100->Clone();
  hratio80100->TH1D::Divide(hdiptMG80100);
  hratio80100->SetTitle("");
  hratio80100->SetStats(0);
  hratio80100->SetMarkerSize(0.5);
  hratio80100 -> GetXaxis() -> SetLabelSize(0.13);
  hratio80100-> GetYaxis() -> SetLabelSize(0.13);
  hratio80100 -> GetYaxis() -> SetTitleSize(0.15);
  hratio80100 -> GetXaxis() -> SetTitleSize(0.15);
  hratio80100 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio80100 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio80100 -> GetYaxis() -> SetTitle("NLO/MG");
 
  TH1D *hratio100200 = new TH1D();
  hratio100200->Sumw2();
  hratio100200=(TH1D*)hdiptNLO100200->Clone();
  hratio100200->TH1D::Divide(hdiptMG100200);
  hratio100200->SetTitle("");
  hratio100200->SetStats(0);
  hratio100200->SetMarkerSize(0.5);
  hratio100200 -> GetXaxis() -> SetLabelSize(0.13);
  hratio100200-> GetYaxis() -> SetLabelSize(0.13);
  hratio100200 -> GetYaxis() -> SetTitleSize(0.15);
  hratio100200 -> GetXaxis() -> SetTitleSize(0.15);
  hratio100200 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio100200 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio100200 -> GetYaxis() -> SetTitle("NLO/MG");
 
  TH1D *hratio200350 = new TH1D();
  
  hdiptNLO200350->Rebin(20);
  hdiptMG200350->Rebin(20);
  hratio200350->Sumw2();
  hratio200350=(TH1D*)hdiptNLO200350->Clone();
  hratio200350->TH1D::Divide(hdiptMG200350);
  hratio200350->SetTitle("");
  hratio200350->SetStats(0);
  hratio200350->SetMarkerSize(0.5);
  hratio200350 -> GetXaxis() -> SetLabelSize(0.13);
  hratio200350-> GetYaxis() -> SetLabelSize(0.13);
  hratio200350 -> GetYaxis() -> SetTitleSize(0.15);
  hratio200350 -> GetXaxis() -> SetTitleSize(0.15);
  hratio200350 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio200350 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio200350 -> GetYaxis() -> SetTitle("NLO/MG");

  TCanvas *cdipt = new TCanvas();
  cdipt->Divide(1,2);
  cdipt->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt = new TLegend(0.7,0.9,0.5,0.7);
  TPaveStats *stMG;
  TPaveStats *stNLO;
  ldipt->TLegend::AddEntry(hdiptMG,"Madgraph");
  ldipt->TLegend::AddEntry(hdiptNLO,"aMC@NLO");
  hdiptMG->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdiptMG->GetYaxis()->SetTitle("Entries"); 
  hdiptMG->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO");
  hdiptNLO->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO");
  hdiptMG->SetLineColor(kRed);
  hdiptNLO->SetLineColor(kBlue);
  hdiptMG->SetLineWidth(3);
  hdiptNLO->SetLineWidth(3);



  hdiptMG -> Draw();
  gStyle->SetOptStat("nmr");
  stMG = (TPaveStats*)hdiptMG->FindObject("stats");

  hdiptNLO->Draw();
  gStyle->SetOptStat("nmr");
  stNLO = (TPaveStats*)hdiptNLO->FindObject("stats");
  

  stMG->TPaveStats::SetX1NDC(0.7);
  stMG->TPaveStats::SetX2NDC(0.9);
  stMG->TPaveStats::SetY1NDC(0.8);
  stMG->TPaveStats::SetY2NDC(0.9);
  stMG->TPaveStats::SetTextSize(0.03);
  hdiptMG->SetName("MG");
  
  stNLO->TPaveStats::SetX1NDC(0.7);
  stNLO->TPaveStats::SetX2NDC(0.9);
  stNLO->TPaveStats::SetY1NDC(0.7);
  stNLO->TPaveStats::SetY2NDC(0.8);
  stNLO->TPaveStats::SetTextSize(0.03);
  hdiptNLO->SetName("NLO");
  
  hdiptMG->GetYaxis()->SetRangeUser(0,100000);

  hdiptMG->Draw();
  hdiptNLO->Draw("SAMES");
  ldipt->Draw();


  TLine *line = new TLine(0,1,100,1);
  cdipt->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio->Draw("Ep");
  hratio->SetMinimum(0.4);
  hratio->SetMaximum(1.6);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt->SaveAs("plot_files/fsrcompare.png"); 
   //////////////////////////////////////////////////
  TCanvas *cdipt4060 = new TCanvas();
  cdipt4060->Divide(1,2);
  cdipt4060->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt4060 = new TLegend(0.7,0.9,0.5,0.7);
  //ldipt4060->SetTextSize(0.03);
  TPaveStats *stMG4060;
  TPaveStats *stNLO4060;
  ldipt4060->TLegend::AddEntry(hdiptMG4060,"Madgraph");
  ldipt4060->TLegend::AddEntry(hdiptNLO4060,"aMC@NLO");

  hdiptMG4060->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdiptMG4060->GetYaxis()->SetTitle("Entries"); 
  hdiptMG4060->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO, 40 < M[GeV] < 60");
  hdiptNLO4060->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO, 40 < M[GeV] < 60");
  hdiptMG4060->SetLineColor(kRed);
  hdiptNLO4060->SetLineColor(kBlue);
  hdiptMG4060->SetLineWidth(3);
  hdiptNLO4060->SetLineWidth(3);



  hdiptMG4060 -> Draw();
  gStyle->SetOptStat("nmr");
  stMG4060 = (TPaveStats*)hdiptMG4060->FindObject("stats");

  hdiptNLO4060->Draw();
  gStyle->SetOptStat("nmr");
  stNLO4060 = (TPaveStats*)hdiptNLO4060->FindObject("stats");
  

  stMG4060->TPaveStats::SetX1NDC(0.7);
  stMG4060->TPaveStats::SetX2NDC(0.9);
  stMG4060->TPaveStats::SetY1NDC(0.8);
  stMG4060->TPaveStats::SetY2NDC(0.9);
  stMG4060->TPaveStats::SetTextSize(0.03);
  hdiptMG4060->SetName("MG");
  
  stNLO4060->TPaveStats::SetX1NDC(0.7);
  stNLO4060->TPaveStats::SetX2NDC(0.9);
  stNLO4060->TPaveStats::SetY1NDC(0.7);
  stNLO4060->TPaveStats::SetY2NDC(0.8);
  stNLO4060->TPaveStats::SetTextSize(0.03);
  hdiptNLO4060->SetName("NLO");
  
  hdiptMG4060->GetYaxis()->SetRangeUser(0,4000);

  hdiptNLO4060->Draw();
  hdiptMG4060->Draw("SAMES"); 
  ldipt4060->Draw();
  cdipt4060->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio4060->Draw("Ep");
  hratio4060->SetMinimum(0.4);
  hratio4060->SetMaximum(1.6);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt4060->SaveAs("plot_files/fsrcompare4060.png"); 
  //////////////////////////////////////////////////


  
  //////////////////////////////////////////////////
  TCanvas *cdipt80100 = new TCanvas();

  cdipt80100->Divide(1,2);
  cdipt80100->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt80100 = new TLegend(0.7,0.9,0.5,0.7);
  //ldipt80100->SetTextSize(0.03);
  TPaveStats *stMG80100;
  TPaveStats *stNLO80100;
  
  ldipt80100->TLegend::AddEntry(hdiptMG80100,"Madgraph");
  ldipt80100->TLegend::AddEntry(hdiptNLO80100,"aMC@NLO");
  
  hdiptMG80100->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdiptMG80100->GetYaxis()->SetTitle("Entries"); 
  hdiptMG80100->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO, 80 < M[GeV] < 100");
  hdiptNLO80100->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO, 80 < M[GeV] < 100");
  hdiptMG80100->SetLineColor(kRed);
  hdiptNLO80100->SetLineColor(kBlue);
  hdiptMG80100->SetLineWidth(3);
  hdiptNLO80100->SetLineWidth(3);



  hdiptMG80100 -> Draw();
  gStyle->SetOptStat("nmr");
  stMG80100 = (TPaveStats*)hdiptMG80100->FindObject("stats");

  hdiptNLO80100->Draw();
  gStyle->SetOptStat("nmr");
  stNLO80100 = (TPaveStats*)hdiptNLO80100->FindObject("stats");
  

  stMG80100->TPaveStats::SetX1NDC(0.7);
  stMG80100->TPaveStats::SetX2NDC(0.9);
  stMG80100->TPaveStats::SetY1NDC(0.8);
  stMG80100->TPaveStats::SetY2NDC(0.9);
  stMG80100->TPaveStats::SetTextSize(0.03);
  hdiptMG80100->SetName("MG");
  
  stNLO80100->TPaveStats::SetX1NDC(0.7);
  stNLO80100->TPaveStats::SetX2NDC(0.9);
  stNLO80100->TPaveStats::SetY1NDC(0.7);
  stNLO80100->TPaveStats::SetY2NDC(0.8);
  stNLO80100->TPaveStats::SetTextSize(0.03);
  hdiptNLO80100->SetName("NLO");
  
  hdiptMG80100->GetYaxis()->SetRangeUser(0,98000);

  hdiptNLO80100->Draw();
  hdiptMG80100->Draw("SAMES");
  
  ldipt80100->Draw();
  cdipt80100->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio80100->Draw("Ep");
  hratio80100->SetMinimum(0.4);
  hratio80100->SetMaximum(1.6);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt80100->SaveAs("plot_files/fsrcompare80100.png"); 
  //////////////////////////////////////////////////
  

  //////////////////////////////////////////////////
  TCanvas *cdipt100200 = new TCanvas();

  cdipt100200->Divide(1,2);
  cdipt100200->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt100200 = new TLegend(0.7,0.9,0.5,0.7);
  //ldipt100200->SetTextSize(0.03);
  TPaveStats *stMG100200;
  TPaveStats *stNLO100200;
  ldipt100200->TLegend::AddEntry(hdiptMG100200,"Madgraph");
  ldipt100200->TLegend::AddEntry(hdiptNLO100200,"aMC@NLO");

  hdiptMG100200->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdiptMG100200->GetYaxis()->SetTitle("Entries"); 
  hdiptMG100200->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO, 100 < M[GeV] < 200");   hdiptNLO100200->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO, 100 < M[GeV] < 200");
  hdiptMG100200->SetLineColor(kRed);
  hdiptNLO100200->SetLineColor(kBlue);
  hdiptMG100200->SetLineWidth(3);
  hdiptNLO100200->SetLineWidth(3);



  hdiptMG100200 -> Draw();
  gStyle->SetOptStat("nmr");
  stMG100200 = (TPaveStats*)hdiptMG100200->FindObject("stats");

  hdiptNLO100200->Draw();
  gStyle->SetOptStat("nmr");
  stNLO100200 = (TPaveStats*)hdiptNLO100200->FindObject("stats");
  

  stMG100200->TPaveStats::SetX1NDC(0.7);
  stMG100200->TPaveStats::SetX2NDC(0.9);
  stMG100200->TPaveStats::SetY1NDC(0.8);
  stMG100200->TPaveStats::SetY2NDC(0.9);
  stMG100200->TPaveStats::SetTextSize(0.03);
  hdiptMG100200->SetName("MG");
  
  stNLO100200->TPaveStats::SetX1NDC(0.7);
  stNLO100200->TPaveStats::SetX2NDC(0.9);
  stNLO100200->TPaveStats::SetY1NDC(0.7);
  stNLO100200->TPaveStats::SetY2NDC(0.8);
  stNLO100200->TPaveStats::SetTextSize(0.03);
  hdiptNLO100200->SetName("NLO");
  
  hdiptMG100200->GetYaxis()->SetRangeUser(0,4000);

  hdiptNLO100200->Draw();
  hdiptMG100200->Draw("SAMES");
  ldipt100200->Draw();
  cdipt100200->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio100200->Draw("Ep");
  hratio100200->SetMinimum(0.4);
  hratio100200->SetMaximum(1.6);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt100200->SaveAs("plot_files/fsrcompare100200.png"); 
  //////////////////////////////////////////////////
  

  //////////////////////////////////////////////////
  TCanvas *cdipt200350 = new TCanvas();

  cdipt200350->Divide(1,2);
  cdipt200350->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt200350 = new TLegend(0.7,0.9,0.5,0.7);
  //ldipt200350->SetTextSize(0.03);
  TPaveStats *stMG200350;
  TPaveStats *stNLO200350;
  ldipt200350->TLegend::AddEntry(hdiptMG200350,"Madgraph");
  ldipt200350->TLegend::AddEntry(hdiptNLO200350,"aMC@NLO");
  
  hdiptMG200350->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdiptMG200350->GetYaxis()->SetTitle("Entries"); 
  hdiptMG200350->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO, 200 < M[GeV] < 350");
  hdiptNLO200350->SetTitle("P_{T}(#mu#mu + FSR) MG vs NLO, 200 < M[GeV] < 350");
  hdiptMG200350->SetLineColor(kRed);
  hdiptNLO200350->SetLineColor(kBlue);
  hdiptMG200350->SetLineWidth(3);
  hdiptNLO200350->SetLineWidth(3);



  hdiptMG200350 -> Draw();
  gStyle->SetOptStat("nmr");
  stMG200350 = (TPaveStats*)hdiptMG200350->FindObject("stats");

  hdiptNLO200350->Draw();
  gStyle->SetOptStat("nmr");
  stNLO200350 = (TPaveStats*)hdiptNLO200350->FindObject("stats");
  

  stMG200350->TPaveStats::SetX1NDC(0.7);
  stMG200350->TPaveStats::SetX2NDC(0.9);
  stMG200350->TPaveStats::SetY1NDC(0.8);
  stMG200350->TPaveStats::SetY2NDC(0.9);
  stMG200350->TPaveStats::SetTextSize(0.03);
  hdiptMG200350->SetName("MG");
  
  stNLO200350->TPaveStats::SetX1NDC(0.7);
  stNLO200350->TPaveStats::SetX2NDC(0.9);
  stNLO200350->TPaveStats::SetY1NDC(0.7);
  stNLO200350->TPaveStats::SetY2NDC(0.8);
  stNLO200350->TPaveStats::SetTextSize(0.03);
  hdiptNLO200350->SetName("NLO");
  
  hdiptMG200350->GetYaxis()->SetRangeUser(0,150);

  hdiptNLO200350->Draw();
  hdiptMG200350->Draw("SAMES");
  ldipt200350->Draw();
  cdipt200350->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio200350->Draw("Ep");
  hratio200350->SetMinimum(0.4);
  hratio200350->SetMaximum(1.6);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt200350->SaveAs("plot_files/fsrcompare200350.png"); 
  //////////////////////////////////////////////////









    
  

}
