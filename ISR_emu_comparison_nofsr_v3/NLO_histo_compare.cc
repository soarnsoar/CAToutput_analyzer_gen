#include <TPaveStats.h>

void NLO_histo_compare(){

  TFile *file;
  file = TFile::Open("../ISR_ntuple_gen_muon_v3/histograms/NLO.root");

  ///Things to draw///

  //before fsr & after fsr
  //total dipt
  //dipt each mass region

  TH1D *hdiptm = (TH1D*)file->Get("dipt");
  TH1D *hdiptm4060= (TH1D*)file->Get("dipt4060");
  TH1D *hdiptm80100= (TH1D*)file->Get("dipt80100");
  TH1D *hdiptm100200= (TH1D*)file->Get("dipt100200");
  TH1D *hdiptm200350= (TH1D*)file->Get("dipt200350");

  file = TFile::Open("../ISR_ntuple_gen_electron_v3/histograms/NLO.root");

  TH1D *hdipte = (TH1D*)file->Get("dipt");
  TH1D *hdipte4060= (TH1D*)file->Get("dipt4060");
  TH1D *hdipte80100= (TH1D*)file->Get("dipt80100");
  TH1D *hdipte100200= (TH1D*)file->Get("dipt100200");
  TH1D *hdipte200350= (TH1D*)file->Get("dipt200350");
  hdiptm->Sumw2();
  hdiptm4060->Sumw2();
  hdiptm80100->Sumw2();
  hdiptm100200->Sumw2();
  hdiptm200350->Sumw2();
  hdipte->Sumw2();
  hdipte4060->Sumw2();
  hdipte80100->Sumw2();
  hdipte100200->Sumw2();
  hdipte200350->Sumw2();
  
  TH1D *hratio = new TH1D();
  hratio->Sumw2();
  hratio=(TH1D*)hdiptm->Clone();
  hratio->TH1D::Divide(hdipte);
  hratio->SetTitle("");
  hratio->SetStats(0);
  hratio->SetMarkerSize(0.5);
  hratio -> GetXaxis() -> SetLabelSize(0.13);
  hratio-> GetYaxis() -> SetLabelSize(0.13);
  hratio -> GetYaxis() -> SetTitleSize(0.15);
  hratio -> GetXaxis() -> SetTitleSize(0.15);
  hratio -> GetYaxis() -> SetTitleOffset(0.3);
  hratio -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio -> GetYaxis() -> SetTitle("#mu#mu / ee");
  
  TH1D *hratio4060 = new TH1D();
  hratio4060->Sumw2();
  hratio4060=(TH1D*)hdiptm4060->Clone();
  hratio4060->TH1D::Divide(hdipte4060);
  hratio4060->SetTitle("");
  hratio4060->SetStats(0);
  hratio4060->SetMarkerSize(0.5);
  hratio4060 -> GetXaxis() -> SetLabelSize(0.13);
  hratio4060-> GetYaxis() -> SetLabelSize(0.13);
  hratio4060 -> GetYaxis() -> SetTitleSize(0.15);
  hratio4060 -> GetXaxis() -> SetTitleSize(0.15);
  hratio4060 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio4060 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio4060 -> GetYaxis() -> SetTitle("#mu#mu / ee");
  
  TH1D *hratio80100 = new TH1D();
  hratio80100->Sumw2();
  hratio80100=(TH1D*)hdiptm80100->Clone();
  hratio80100->TH1D::Divide(hdipte80100);
  hratio80100->SetTitle("");
  hratio80100->SetStats(0);
  hratio80100->SetMarkerSize(0.5);
  hratio80100 -> GetXaxis() -> SetLabelSize(0.13);
  hratio80100-> GetYaxis() -> SetLabelSize(0.13);
  hratio80100 -> GetYaxis() -> SetTitleSize(0.15);
  hratio80100 -> GetXaxis() -> SetTitleSize(0.15);
  hratio80100 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio80100 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio80100 -> GetYaxis() -> SetTitle("#mu#mu / ee");
 
  TH1D *hratio100200 = new TH1D();
  hratio100200->Sumw2();
  hratio100200=(TH1D*)hdiptm100200->Clone();
  hratio100200->TH1D::Divide(hdipte100200);
  hratio100200->SetTitle("");
  hratio100200->SetStats(0);
  hratio100200->SetMarkerSize(0.5);
  hratio100200 -> GetXaxis() -> SetLabelSize(0.13);
  hratio100200-> GetYaxis() -> SetLabelSize(0.13);
  hratio100200 -> GetYaxis() -> SetTitleSize(0.15);
  hratio100200 -> GetXaxis() -> SetTitleSize(0.15);
  hratio100200 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio100200 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio100200 -> GetYaxis() -> SetTitle("#mu#mu / ee");
 
  TH1D *hratio200350 = new TH1D();
  hratio200350->Sumw2();
  hratio200350=(TH1D*)hdiptm200350->Clone();
  hratio200350->TH1D::Divide(hdipte200350);
  hratio200350->SetTitle("");
  hratio200350->SetStats(0);
  hratio200350->SetMarkerSize(0.5);
  hratio200350 -> GetXaxis() -> SetLabelSize(0.13);
  hratio200350-> GetYaxis() -> SetLabelSize(0.13);
  hratio200350 -> GetYaxis() -> SetTitleSize(0.15);
  hratio200350 -> GetXaxis() -> SetTitleSize(0.15);
  hratio200350 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio200350 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio200350 -> GetYaxis() -> SetTitle("#mu#mu / ee");

  TLine *line = new TLine(0,1,100,1);

  
  TCanvas *cdipt = new TCanvas();  
  cdipt->Divide(1,2);
  cdipt->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt = new TLegend(0.7,0.9,0.5,0.7);
  TPaveStats *ste;
  TPaveStats *stm;
  ldipt->SetTextSize(0.09);
  ldipt->TLegend::AddEntry(hdipte,"ee");
  ldipt->TLegend::AddEntry(hdiptm,"#mu#mu");

  hdipte->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipte->GetYaxis()->SetTitle("Entries"); 
  hdipte->SetTitle("P_{T}(ll) #mu#mu vs ee");
  hdiptm->SetTitle("P_{T}(ll) #mu#mu vs ee");
  hdipte->SetLineColor(kRed);
  hdiptm->SetLineColor(kBlue);
  hdipte->SetLineWidth(3);
  hdiptm->SetLineWidth(3);



  hdipte -> Draw();
  gStyle->SetOptStat("nmr");
  ste = (TPaveStats*)hdipte->FindObject("stats");

  hdiptm->Draw();
  gStyle->SetOptStat("nmr");
  stm = (TPaveStats*)hdiptm->FindObject("stats");
  

  ste->TPaveStats::SetX1NDC(0.7);
  ste->TPaveStats::SetX2NDC(0.9);
  ste->TPaveStats::SetY1NDC(0.8);
  ste->TPaveStats::SetY2NDC(0.9);
  ste->TPaveStats::SetTextSize(0.05);
  hdipte->SetName("ee");
  
  stm->TPaveStats::SetX1NDC(0.7);
  stm->TPaveStats::SetX2NDC(0.9);
  stm->TPaveStats::SetY1NDC(0.7);
  stm->TPaveStats::SetY2NDC(0.8);
  stm->TPaveStats::SetTextSize(0.05);
  hdiptm->SetName("#mu#mu");
  
  hdipte->GetYaxis()->SetRangeUser(0,100000);

  hdipte->Draw();
  hdiptm->Draw("SAMES");
  ldipt->Draw();
  cdipt->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio->Draw("Ep");
  hratio->SetMinimum(0.8);
  hratio->SetMaximum(1.2);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt->SaveAs("plot_files/NLOdipt_emucompare.png"); 
   //////////////////////////////////////////////////
  TCanvas *cdipt4060 = new TCanvas();

  cdipt4060->Divide(1,2);
  cdipt4060->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt4060 = new TLegend(0.7,0.9,0.5,0.7);
  ldipt4060->SetTextSize(0.09);
  TPaveStats *ste4060;
  TPaveStats *stm4060;
  ldipt4060->TLegend::AddEntry(hdipte4060,"ee");
  ldipt4060->TLegend::AddEntry(hdiptm4060,"#mu#mu");

  hdipte4060->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipte4060->GetYaxis()->SetTitle("Entries"); 
  hdipte4060->SetTitle("P_{T}(ll) #mu#mu vs ee, 40 < M[GeV] < 60");
  hdiptm4060->SetTitle("P_{T}(ll) #mu#mu vs ee, 40 < M[GeV] < 60");
  hdipte4060->SetLineColor(kRed);
  hdiptm4060->SetLineColor(kBlue);
  hdipte4060->SetLineWidth(3);
  hdiptm4060->SetLineWidth(3);



  hdipte4060 -> Draw();
  gStyle->SetOptStat("nmr");
  ste4060 = (TPaveStats*)hdipte4060->FindObject("stats");

  hdiptm4060->Draw();
  gStyle->SetOptStat("nmr");
  stm4060 = (TPaveStats*)hdiptm4060->FindObject("stats");
  

  ste4060->TPaveStats::SetX1NDC(0.7);
  ste4060->TPaveStats::SetX2NDC(0.9);
  ste4060->TPaveStats::SetY1NDC(0.8);
  ste4060->TPaveStats::SetY2NDC(0.9);
  ste4060->TPaveStats::SetTextSize(0.05);
  hdipte4060->SetName("ee");
  
  stm4060->TPaveStats::SetX1NDC(0.7);
  stm4060->TPaveStats::SetX2NDC(0.9);
  stm4060->TPaveStats::SetY1NDC(0.7);
  stm4060->TPaveStats::SetY2NDC(0.8);
  stm4060->TPaveStats::SetTextSize(0.05);
  hdiptm4060->SetName("#mu#mu");
  
  hdipte4060->GetYaxis()->SetRangeUser(0,3500);

  hdiptm4060->Draw();
  hdipte4060->Draw("SAMES"); 
  ldipt4060->Draw();
  cdipt4060->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio4060->Draw("Ep");
  hratio4060->SetMinimum(0.8);
  hratio4060->SetMaximum(1.2);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt4060->SaveAs("plot_files/NLOdipt_emucompare4060.png"); 
  //////////////////////////////////////////////////


  
  //////////////////////////////////////////////////
  TCanvas *cdipt80100 = new TCanvas();

  cdipt80100->Divide(1,2);
  cdipt80100->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt80100 = new TLegend(0.7,0.9,0.5,0.7);
  ldipt80100->SetTextSize(0.09);
  TPaveStats *ste80100;
  TPaveStats *stm80100;
  
  ldipt80100->TLegend::AddEntry(hdipte80100,"ee.");
  ldipt80100->TLegend::AddEntry(hdiptm80100,"#mu#mu.");
  
  hdipte80100->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipte80100->GetYaxis()->SetTitle("Entries"); 
  hdipte80100->SetTitle("P_{T}(ll) #mu#mu vs ee, 80 < M[GeV] < 100");
  hdiptm80100->SetTitle("P_{T}(ll) #mu#mu vs ee, 80 < M[GeV] < 100");
  hdipte80100->SetLineColor(kRed);
  hdiptm80100->SetLineColor(kBlue);
  hdipte80100->SetLineWidth(3);
  hdiptm80100->SetLineWidth(3);



  hdipte80100 -> Draw();
  gStyle->SetOptStat("nmr");
  ste80100 = (TPaveStats*)hdipte80100->FindObject("stats");

  hdiptm80100->Draw();
  gStyle->SetOptStat("nmr");
  stm80100 = (TPaveStats*)hdiptm80100->FindObject("stats");
  

  ste80100->TPaveStats::SetX1NDC(0.7);
  ste80100->TPaveStats::SetX2NDC(0.9);
  ste80100->TPaveStats::SetY1NDC(0.8);
  ste80100->TPaveStats::SetY2NDC(0.9);
  ste80100->TPaveStats::SetTextSize(0.05);
  hdipte80100->SetName("ee");
  
  stm80100->TPaveStats::SetX1NDC(0.7);
  stm80100->TPaveStats::SetX2NDC(0.9);
  stm80100->TPaveStats::SetY1NDC(0.7);
  stm80100->TPaveStats::SetY2NDC(0.8);
  stm80100->TPaveStats::SetTextSize(0.05);
  hdiptm80100->SetName("#mu#mu");
  
  hdipte80100->GetYaxis()->SetRangeUser(0,90000);

  hdiptm80100->Draw();
  hdipte80100->Draw("SAMES");
  
  ldipt80100->Draw();
  cdipt80100->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio80100->Draw("Ep");
  hratio80100->SetMinimum(0.8);
  hratio80100->SetMaximum(1.2);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt80100->SaveAs("plot_files/NLOdipt_emucompare80100.png"); 
  //////////////////////////////////////////////////
  

  //////////////////////////////////////////////////
  TCanvas *cdipt100200 = new TCanvas();
  
  cdipt100200->Divide(1,2);
  cdipt100200->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt100200 = new TLegend(0.7,0.9,0.5,0.7);
  ldipt100200->SetTextSize(0.09);
  TPaveStats *ste100200;
  TPaveStats *stm100200;
  ldipt100200->TLegend::AddEntry(hdipte100200,"ee");
  ldipt100200->TLegend::AddEntry(hdiptm100200,"#mu#mu");

  hdipte100200->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipte100200->GetYaxis()->SetTitle("Entries"); 
  hdipte100200->SetTitle("P_{T}(ll) #mu#mu vs ee, 100 < M[GeV] < 200"); hdiptm100200->SetTitle("P_{T}(ll) #mu#mu vs ee, 100 < M[GeV] < 200");
  hdipte100200->SetLineColor(kRed);
  hdiptm100200->SetLineColor(kBlue);
  hdipte100200->SetLineWidth(3);
  hdiptm100200->SetLineWidth(3);



  hdipte100200 -> Draw();
  gStyle->SetOptStat("nmr");
  ste100200 = (TPaveStats*)hdipte100200->FindObject("stats");

  hdiptm100200->Draw();
  gStyle->SetOptStat("nmr");
  stm100200 = (TPaveStats*)hdiptm100200->FindObject("stats");
  

  ste100200->TPaveStats::SetX1NDC(0.7);
  ste100200->TPaveStats::SetX2NDC(0.9);
  ste100200->TPaveStats::SetY1NDC(0.8);
  ste100200->TPaveStats::SetY2NDC(0.9);
  ste100200->TPaveStats::SetTextSize(0.05);
  hdipte100200->SetName("ee");
  
  stm100200->TPaveStats::SetX1NDC(0.7);
  stm100200->TPaveStats::SetX2NDC(0.9);
  stm100200->TPaveStats::SetY1NDC(0.7);
  stm100200->TPaveStats::SetY2NDC(0.8);
  stm100200->TPaveStats::SetTextSize(0.05);
  hdiptm100200->SetName("#mu#mu");
  
  hdipte100200->GetYaxis()->SetRangeUser(0,3500);

  hdiptm100200->Draw();
  hdipte100200->Draw("SAMES");
  ldipt100200->Draw();
  cdipt100200->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio100200->Draw("Ep");
  hratio100200->SetMinimum(0.8);
  hratio100200->SetMaximum(1.2);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt100200->SaveAs("plot_files/NLOdipt_emucompare100200.png"); 
  //////////////////////////////////////////////////
  

  //////////////////////////////////////////////////
  TCanvas *cdipt200350 = new TCanvas();
  cdipt200350->Divide(1,2);
  cdipt200350->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt200350 = new TLegend(0.7,0.9,0.5,0.7);
  ldipt200350->SetTextSize(0.09);
  TPaveStats *ste200350;
  TPaveStats *stm200350;
  ldipt200350->TLegend::AddEntry(hdipte200350,"ee");
  ldipt200350->TLegend::AddEntry(hdiptm200350,"#mu#mu");
  
  hdipte200350->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipte200350->GetYaxis()->SetTitle("Entries"); 
  hdipte200350->SetTitle("P_{T}(ll) #mu#mu vs ee, 200 < M[GeV] < 350");
  hdiptm200350->SetTitle("P_{T}(ll) #mu#mu vs ee, 200 < M[GeV] < 350");
  hdipte200350->SetLineColor(kRed);
  hdiptm200350->SetLineColor(kBlue);
  hdipte200350->SetLineWidth(3);
  hdiptm200350->SetLineWidth(3);



  hdipte200350 -> Draw();
  gStyle->SetOptStat("nmr");
  ste200350 = (TPaveStats*)hdipte200350->FindObject("stats");

  hdiptm200350->Draw();
  gStyle->SetOptStat("nmr");
  stm200350 = (TPaveStats*)hdiptm200350->FindObject("stats");
  

  ste200350->TPaveStats::SetX1NDC(0.7);
  ste200350->TPaveStats::SetX2NDC(0.9);
  ste200350->TPaveStats::SetY1NDC(0.8);
  ste200350->TPaveStats::SetY2NDC(0.9);
  ste200350->TPaveStats::SetTextSize(0.05);
  hdipte200350->SetName("ee");
  
  stm200350->TPaveStats::SetX1NDC(0.7);
  stm200350->TPaveStats::SetX2NDC(0.9);
  stm200350->TPaveStats::SetY1NDC(0.7);
  stm200350->TPaveStats::SetY2NDC(0.8);
  stm200350->TPaveStats::SetTextSize(0.05);
  hdiptm200350->SetName("#mu#mu");
  
  hdipte200350->GetYaxis()->SetRangeUser(0,110);

  hdiptm200350->Draw();
  hdipte200350->Draw("SAMES");
  ldipt200350->Draw();
  cdipt200350->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio200350->Draw("Ep");
  hratio200350->SetMinimum(0.8);
  hratio200350->SetMaximum(1.2);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt200350->SaveAs("plot_files/NLOdipt_emucompare200350.png"); 
  //////////////////////////////////////////////////











    
  

}
