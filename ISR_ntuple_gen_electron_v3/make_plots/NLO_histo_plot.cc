#include <TPaveStats.h>

void NLO_histo_plot(){

  TFile *file;
  file = TFile::Open("../histograms/NLO.root");

  ///Things to draw///

  //before fsr & after fsr
  //total dipt
  //dipt each mass region

  TH1D *hdipt = (TH1D*)file->Get("dipt");
  TH1D *hdiptfsr = (TH1D*)file->Get("diptfsr") ;
  TH1D *hdipt4060= (TH1D*)file->Get("dipt4060");
  TH1D *hdipt80100= (TH1D*)file->Get("dipt80100");
  TH1D *hdipt100200= (TH1D*)file->Get("dipt100200");
  TH1D *hdipt200350= (TH1D*)file->Get("dipt200350");
  TH1D *hdiptfsr4060= (TH1D*)file->Get("diptfsr4060");
  TH1D *hdiptfsr80100= (TH1D*)file->Get("diptfsr80100");
  TH1D *hdiptfsr100200= (TH1D*)file->Get("diptfsr100200");
  TH1D *hdiptfsr200350= (TH1D*)file->Get("diptfsr200350");
  hdipt->Sumw2();
  hdiptfsr->Sumw2();
  hdipt4060->Sumw2();
  hdipt80100->Sumw2();
  hdipt100200->Sumw2();
  hdipt200350->Sumw2();
  hdiptfsr4060->Sumw2();
  hdiptfsr80100->Sumw2();
  hdiptfsr100200->Sumw2();
  hdiptfsr200350->Sumw2();
  
  TH1D *hratio = new TH1D();
  hratio->Sumw2();
  hratio=(TH1D*)hdiptfsr->Clone();
  hratio->TH1D::Divide(hdipt);
  hratio->SetTitle("");
  hratio->SetStats(0);
  hratio->SetMarkerSize(0.5);
  hratio -> GetXaxis() -> SetLabelSize(0.13);
  hratio-> GetYaxis() -> SetLabelSize(0.13);
  hratio -> GetYaxis() -> SetTitleSize(0.15);
  hratio -> GetXaxis() -> SetTitleSize(0.15);
  hratio -> GetYaxis() -> SetTitleOffset(0.3);
  hratio -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio -> GetYaxis() -> SetTitle("FSR / no FSR");
  
  TH1D *hratio4060 = new TH1D();
  hratio4060->Sumw2();
  hratio4060=(TH1D*)hdiptfsr4060->Clone();
  hratio4060->TH1D::Divide(hdipt4060);
  hratio4060->SetTitle("");
  hratio4060->SetStats(0);
  hratio4060->SetMarkerSize(0.5);
  hratio4060 -> GetXaxis() -> SetLabelSize(0.13);
  hratio4060-> GetYaxis() -> SetLabelSize(0.13);
  hratio4060 -> GetYaxis() -> SetTitleSize(0.15);
  hratio4060 -> GetXaxis() -> SetTitleSize(0.15);
  hratio4060 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio4060 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio4060 -> GetYaxis() -> SetTitle("FSR / no FSR");
  
  TH1D *hratio80100 = new TH1D();
  hratio80100->Sumw2();
  hratio80100=(TH1D*)hdiptfsr80100->Clone();
  hratio80100->TH1D::Divide(hdipt80100);
  hratio80100->SetTitle("");
  hratio80100->SetStats(0);
  hratio80100->SetMarkerSize(0.5);
  hratio80100 -> GetXaxis() -> SetLabelSize(0.13);
  hratio80100-> GetYaxis() -> SetLabelSize(0.13);
  hratio80100 -> GetYaxis() -> SetTitleSize(0.15);
  hratio80100 -> GetXaxis() -> SetTitleSize(0.15);
  hratio80100 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio80100 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio80100 -> GetYaxis() -> SetTitle("FSR / no FSR");
 
  TH1D *hratio100200 = new TH1D();
  hratio100200->Sumw2();
  hratio100200=(TH1D*)hdiptfsr100200->Clone();
  hratio100200->TH1D::Divide(hdipt100200);
  hratio100200->SetTitle("");
  hratio100200->SetStats(0);
  hratio100200->SetMarkerSize(0.5);
  hratio100200 -> GetXaxis() -> SetLabelSize(0.13);
  hratio100200-> GetYaxis() -> SetLabelSize(0.13);
  hratio100200 -> GetYaxis() -> SetTitleSize(0.15);
  hratio100200 -> GetXaxis() -> SetTitleSize(0.15);
  hratio100200 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio100200 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio100200 -> GetYaxis() -> SetTitle("FSR / no FSR");
 
  TH1D *hratio200350 = new TH1D();
  hratio200350->Sumw2();
  hratio200350=(TH1D*)hdiptfsr200350->Clone();
  hratio200350->TH1D::Divide(hdipt200350);
  hratio200350->SetTitle("");
  hratio200350->SetStats(0);
  hratio200350->SetMarkerSize(0.5);
  hratio200350 -> GetXaxis() -> SetLabelSize(0.13);
  hratio200350-> GetYaxis() -> SetLabelSize(0.13);
  hratio200350 -> GetYaxis() -> SetTitleSize(0.15);
  hratio200350 -> GetXaxis() -> SetTitleSize(0.15);
  hratio200350 -> GetYaxis() -> SetTitleOffset(0.3);
  hratio200350 -> GetXaxis() -> SetTitleOffset(0.8);  
  hratio200350 -> GetYaxis() -> SetTitle("FSR / no FSR");

  TLine *line = new TLine(0,1,100,1);

  
  TCanvas *cdipt = new TCanvas();  
  cdipt->Divide(1,2);
  cdipt->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt = new TLegend(0.7,0.9,0.5,0.7);
  TPaveStats *st;
  TPaveStats *stfsr;
  ldipt->SetTextSize(0.05);
  ldipt->TLegend::AddEntry(hdipt,"w/o FSR mom.");
  ldipt->TLegend::AddEntry(hdiptfsr,"+ FSR mom.");
  hdipt->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipt->GetYaxis()->SetTitle("Entries"); 
  hdipt->SetTitle("P_{T}(ee) pre-FSR vs post-FSR");
  hdiptfsr->SetTitle("P_{T}(ee) pre-FSR vs post-FSR");
  hdipt->SetLineColor(kRed);
  hdiptfsr->SetLineColor(kBlue);
  hdipt->SetLineWidth(3);
  hdiptfsr->SetLineWidth(3);



  hdipt -> Draw();
  gStyle->SetOptStat("nmr");
  st = (TPaveStats*)hdipt->FindObject("stats");

  hdiptfsr->Draw();
  gStyle->SetOptStat("nmr");
  stfsr = (TPaveStats*)hdiptfsr->FindObject("stats");
  

  st->TPaveStats::SetX1NDC(0.7);
  st->TPaveStats::SetX2NDC(0.9);
  st->TPaveStats::SetY1NDC(0.8);
  st->TPaveStats::SetY2NDC(0.9);
  st->TPaveStats::SetTextSize(0.03);
  hdipt->SetName("Post-FSR");
  
  stfsr->TPaveStats::SetX1NDC(0.7);
  stfsr->TPaveStats::SetX2NDC(0.9);
  stfsr->TPaveStats::SetY1NDC(0.7);
  stfsr->TPaveStats::SetY2NDC(0.8);
  stfsr->TPaveStats::SetTextSize(0.03);
  hdiptfsr->SetName("Pre-FSR");
  
  hdipt->GetYaxis()->SetRangeUser(0,100000);

  hdipt->Draw();
  hdiptfsr->Draw("SAMES");
  ldipt->Draw();
  cdipt->cd(2);
  gPad->SetPad(0.05,0.05,0.95,0.3);
  gPad->SetBottomMargin(0.3);
  hratio->Draw("Ep");
  hratio->SetMinimum(0.4);
  hratio->SetMaximum(1.6);  
  line -> SetLineColor(kRed);
  line->SetLineWidth(2);
  line->Draw("SAME");
  
  cdipt->SaveAs("plot_files/NLOdipt_fsrcompare.png"); 
   //////////////////////////////////////////////////
  TCanvas *cdipt4060 = new TCanvas();

  cdipt4060->Divide(1,2);
  cdipt4060->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt4060 = new TLegend(0.7,0.9,0.5,0.7);
  ldipt4060->SetTextSize(0.05);
  TPaveStats *st4060;
  TPaveStats *stfsr4060;
  ldipt4060->TLegend::AddEntry(hdipt4060,"w/o FSR");
  ldipt4060->TLegend::AddEntry(hdiptfsr4060,"+FSR mom.");

  hdipt4060->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipt4060->GetYaxis()->SetTitle("Entries"); 
  hdipt4060->SetTitle("P_{T}(ee) pre-FSR vs post-FSR, 40 < M[GeV] < 60");
  hdiptfsr4060->SetTitle("P_{T}(ee) pre-FSR vs post-FSR, 40 < M[GeV] < 60");
  hdipt4060->SetLineColor(kRed);
  hdiptfsr4060->SetLineColor(kBlue);
  hdipt4060->SetLineWidth(3);
  hdiptfsr4060->SetLineWidth(3);



  hdipt4060 -> Draw();
  gStyle->SetOptStat("nmr");
  st4060 = (TPaveStats*)hdipt4060->FindObject("stats");

  hdiptfsr4060->Draw();
  gStyle->SetOptStat("nmr");
  stfsr4060 = (TPaveStats*)hdiptfsr4060->FindObject("stats");
  

  st4060->TPaveStats::SetX1NDC(0.7);
  st4060->TPaveStats::SetX2NDC(0.9);
  st4060->TPaveStats::SetY1NDC(0.8);
  st4060->TPaveStats::SetY2NDC(0.9);
  st4060->TPaveStats::SetTextSize(0.03);
  hdipt4060->SetName("Post-FSR");
  
  stfsr4060->TPaveStats::SetX1NDC(0.7);
  stfsr4060->TPaveStats::SetX2NDC(0.9);
  stfsr4060->TPaveStats::SetY1NDC(0.7);
  stfsr4060->TPaveStats::SetY2NDC(0.8);
  stfsr4060->TPaveStats::SetTextSize(0.03);
  hdiptfsr4060->SetName("Pre-FSR");
  
  hdipt4060->GetYaxis()->SetRangeUser(0,3500);

  hdiptfsr4060->Draw();
  hdipt4060->Draw("SAMES"); 
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
  
  cdipt4060->SaveAs("plot_files/NLOdipt_fsrcompare4060.png"); 
  //////////////////////////////////////////////////


  
  //////////////////////////////////////////////////
  TCanvas *cdipt80100 = new TCanvas();

  cdipt80100->Divide(1,2);
  cdipt80100->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt80100 = new TLegend(0.7,0.9,0.5,0.7);
  ldipt80100->SetTextSize(0.05);
  TPaveStats *st80100;
  TPaveStats *stfsr80100;
  
  ldipt80100->TLegend::AddEntry(hdipt80100,"w/o FSR mom.");
  ldipt80100->TLegend::AddEntry(hdiptfsr80100,"+FSR mom.");
  
  hdipt80100->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipt80100->GetYaxis()->SetTitle("Entries"); 
  hdipt80100->SetTitle("P_{T}(ee) pre-FSR vs post-FSR, 80 < M[GeV] < 100");
  hdiptfsr80100->SetTitle("P_{T}(ee) pre-FSR vs post-FSR, 80 < M[GeV] < 100");
  hdipt80100->SetLineColor(kRed);
  hdiptfsr80100->SetLineColor(kBlue);
  hdipt80100->SetLineWidth(3);
  hdiptfsr80100->SetLineWidth(3);



  hdipt80100 -> Draw();
  gStyle->SetOptStat("nmr");
  st80100 = (TPaveStats*)hdipt80100->FindObject("stats");

  hdiptfsr80100->Draw();
  gStyle->SetOptStat("nmr");
  stfsr80100 = (TPaveStats*)hdiptfsr80100->FindObject("stats");
  

  st80100->TPaveStats::SetX1NDC(0.7);
  st80100->TPaveStats::SetX2NDC(0.9);
  st80100->TPaveStats::SetY1NDC(0.8);
  st80100->TPaveStats::SetY2NDC(0.9);
  st80100->TPaveStats::SetTextSize(0.03);
  hdipt80100->SetName("Post-FSR");
  
  stfsr80100->TPaveStats::SetX1NDC(0.7);
  stfsr80100->TPaveStats::SetX2NDC(0.9);
  stfsr80100->TPaveStats::SetY1NDC(0.7);
  stfsr80100->TPaveStats::SetY2NDC(0.8);
  stfsr80100->TPaveStats::SetTextSize(0.03);
  hdiptfsr80100->SetName("Pre-FSR");
  
  hdipt80100->GetYaxis()->SetRangeUser(0,90000);

  hdiptfsr80100->Draw();
  hdipt80100->Draw("SAMES");
  
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
  
  cdipt80100->SaveAs("plot_files/NLOdipt_fsrcompare80100.png"); 
  //////////////////////////////////////////////////
  

  //////////////////////////////////////////////////
  TCanvas *cdipt100200 = new TCanvas();
  
  cdipt100200->Divide(1,2);
  cdipt100200->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt100200 = new TLegend(0.7,0.9,0.5,0.7);
  ldipt100200->SetTextSize(0.05);
  TPaveStats *st100200;
  TPaveStats *stfsr100200;
  ldipt100200->TLegend::AddEntry(hdipt100200,"w/o FSR mom.");
  ldipt100200->TLegend::AddEntry(hdiptfsr100200,"+FSR mom.");

  hdipt100200->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipt100200->GetYaxis()->SetTitle("Entries"); 
  hdipt100200->SetTitle("P_{T}(ee) pre-FSR vs post-FSR, 100 < M[GeV] < 200"); hdiptfsr100200->SetTitle("P_{T}(ee) pre-FSR vs post-FSR, 100 < M[GeV] < 200");
  hdipt100200->SetLineColor(kRed);
  hdiptfsr100200->SetLineColor(kBlue);
  hdipt100200->SetLineWidth(3);
  hdiptfsr100200->SetLineWidth(3);



  hdipt100200 -> Draw();
  gStyle->SetOptStat("nmr");
  st100200 = (TPaveStats*)hdipt100200->FindObject("stats");

  hdiptfsr100200->Draw();
  gStyle->SetOptStat("nmr");
  stfsr100200 = (TPaveStats*)hdiptfsr100200->FindObject("stats");
  

  st100200->TPaveStats::SetX1NDC(0.7);
  st100200->TPaveStats::SetX2NDC(0.9);
  st100200->TPaveStats::SetY1NDC(0.8);
  st100200->TPaveStats::SetY2NDC(0.9);
  st100200->TPaveStats::SetTextSize(0.03);
  hdipt100200->SetName("Post-FSR");
  
  stfsr100200->TPaveStats::SetX1NDC(0.7);
  stfsr100200->TPaveStats::SetX2NDC(0.9);
  stfsr100200->TPaveStats::SetY1NDC(0.7);
  stfsr100200->TPaveStats::SetY2NDC(0.8);
  stfsr100200->TPaveStats::SetTextSize(0.03);
  hdiptfsr100200->SetName("Pre-FSR");
  
  hdipt100200->GetYaxis()->SetRangeUser(0,3500);

  hdiptfsr100200->Draw();
  hdipt100200->Draw("SAMES");
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
  
  cdipt100200->SaveAs("plot_files/NLOdipt_fsrcompare100200.png"); 
  //////////////////////////////////////////////////
  

  //////////////////////////////////////////////////
  TCanvas *cdipt200350 = new TCanvas();
  cdipt200350->Divide(1,2);
  cdipt200350->cd(1);
  gPad->SetPad(0.05, 0.3, 0.95, 0.95);

  TLegend *ldipt200350 = new TLegend(0.7,0.9,0.5,0.7);
  ldipt200350->SetTextSize(0.05);
  TPaveStats *st200350;
  TPaveStats *stfsr200350;
  ldipt200350->TLegend::AddEntry(hdipt200350,"w/o FSR mom.");
  ldipt200350->TLegend::AddEntry(hdiptfsr200350,"+FSR mom.");
  
  hdipt200350->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipt200350->GetYaxis()->SetTitle("Entries"); 
  hdipt200350->SetTitle("P_{T}(ee) pre-FSR vs post-FSR, 200 < M[GeV] < 350");
  hdiptfsr200350->SetTitle("P_{T}(ee) pre-FSR vs post-FSR, 200 < M[GeV] < 350");
  hdipt200350->SetLineColor(kRed);
  hdiptfsr200350->SetLineColor(kBlue);
  hdipt200350->SetLineWidth(3);
  hdiptfsr200350->SetLineWidth(3);



  hdipt200350 -> Draw();
  gStyle->SetOptStat("nmr");
  st200350 = (TPaveStats*)hdipt200350->FindObject("stats");

  hdiptfsr200350->Draw();
  gStyle->SetOptStat("nmr");
  stfsr200350 = (TPaveStats*)hdiptfsr200350->FindObject("stats");
  

  st200350->TPaveStats::SetX1NDC(0.7);
  st200350->TPaveStats::SetX2NDC(0.9);
  st200350->TPaveStats::SetY1NDC(0.8);
  st200350->TPaveStats::SetY2NDC(0.9);
  st200350->TPaveStats::SetTextSize(0.03);
  hdipt200350->SetName("Post-FSR");
  
  stfsr200350->TPaveStats::SetX1NDC(0.7);
  stfsr200350->TPaveStats::SetX2NDC(0.9);
  stfsr200350->TPaveStats::SetY1NDC(0.7);
  stfsr200350->TPaveStats::SetY2NDC(0.8);
  stfsr200350->TPaveStats::SetTextSize(0.03);
  hdiptfsr200350->SetName("Pre-FSR");
  
  hdipt200350->GetYaxis()->SetRangeUser(0,110);

  hdiptfsr200350->Draw();
  hdipt200350->Draw("SAMES");
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
  
  cdipt200350->SaveAs("plot_files/NLOdipt_fsrcompare200350.png"); 
  //////////////////////////////////////////////////











   //////////////////////////////////////////////////
  TCanvas *cdiptm = new TCanvas();
  TLegend *ldiptm = new TLegend(0.7,0.9,0.4,0.65);
  ldiptm->SetTextSize(0.03);
  TPaveStats *st4060;
  TPaveStats *st80100;
  TPaveStats *st100200;
  TPaveStats *st200350;

  ldiptm->TLegend::AddEntry(hdipt4060,"40 < M [GeV] < 60");  
  ldiptm->TLegend::AddEntry(hdipt80100,"80 < M [GeV] < 100");  
  ldiptm->TLegend::AddEntry(hdipt100200,"100 < M [GeV] < 200");  
  ldiptm->TLegend::AddEntry(hdipt200350,"200 < M [GeV] < 350");  
  hdipt4060->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdipt4060->GetYaxis()->SetTitle("Norm. Entries"); 
  hdipt4060->GetYaxis()->SetTitleOffset(1.5); 
  
  hdipt4060->SetTitle("P_{T}(ee) At each mass region");
  hdipt4060->SetLineColor(kRed);
  hdipt80100->SetLineColor(kBlue);
  hdipt100200->SetLineColor(kGreen+2);
  hdipt200350->SetLineColor(kOrange);

  hdipt4060->SetLineWidth(3);
  hdipt80100->SetLineWidth(3);
  hdipt100200->SetLineWidth(3);
  hdipt200350->SetLineWidth(3);

  
  hdipt4060 -> Draw();
  gStyle->SetOptStat("nmr");
  st4060 = (TPaveStats*)hdipt4060->FindObject("stats");

  hdipt80100->Draw();
  gStyle->SetOptStat("nmr");
  st80100 = (TPaveStats*)hdipt80100->FindObject("stats");

  hdipt100200->Draw();
  gStyle->SetOptStat("nmr");
  st100200 = (TPaveStats*)hdipt100200->FindObject("stats");

  hdipt200350->Draw();
  gStyle->SetOptStat("nmr");
  st200350 = (TPaveStats*)hdipt200350->FindObject("stats");
  
  

  st4060->TPaveStats::SetX1NDC(0.7);
  st4060->TPaveStats::SetX2NDC(0.9);
  st4060->TPaveStats::SetY1NDC(0.8);
  st4060->TPaveStats::SetY2NDC(0.9);
  st4060->TPaveStats::SetTextSize(0.03);
  hdipt4060->SetName("40 < M [GeV] < 60");
  

  st80100->TPaveStats::SetX1NDC(0.7);
  st80100->TPaveStats::SetX2NDC(0.9);
  st80100->TPaveStats::SetY1NDC(0.7);
  st80100->TPaveStats::SetY2NDC(0.8);
  st80100->TPaveStats::SetTextSize(0.03);
  hdipt80100->SetName("80 < M [GeV] < 100");


  st100200->TPaveStats::SetX1NDC(0.7);
  st100200->TPaveStats::SetX2NDC(0.9);
  st100200->TPaveStats::SetY1NDC(0.6);
  st100200->TPaveStats::SetY2NDC(0.7);
  st100200->TPaveStats::SetTextSize(0.03);
  hdipt100200->SetName("100 < M [GeV] < 200");

  
  st200350->TPaveStats::SetX1NDC(0.7);
  st200350->TPaveStats::SetX2NDC(0.9);
  st200350->TPaveStats::SetY1NDC(0.5);
  st200350->TPaveStats::SetY2NDC(0.6);
  st200350->TPaveStats::SetTextSize(0.03);
  hdipt200350->SetName("200 < M [GeV] < 350");
  
  
  hdipt4060->GetYaxis()->SetRangeUser(0,100000);

  hdipt4060->Scale( hdipt4060->Integral()/hdipt4060->Integral() );
  hdipt80100->Scale( hdipt4060->Integral()/hdipt80100->Integral() );
  hdipt100200->Scale( hdipt4060->Integral()/hdipt100200->Integral() );
  hdipt200350->Scale( hdipt4060->Integral()/hdipt200350->Integral() );
    
  hdipt4060->Draw();
  hdipt80100->Draw("SAMES");
  hdipt100200->Draw("SAMES");
  hdipt200350->Draw("SAMES");
  ldiptm->Draw();
  cdiptm->SaveAs("plot_files/NLOdipt_massregion.png");


  //////////////////////////////////////////////////
  TCanvas *cdiptfsrm = new TCanvas();
  TLegend *ldiptfsrm = new TLegend(0.7,0.9,0.4,0.65);
  ldiptfsrm->SetTextSize(0.03);
  TPaveStats *stfsr4060;
  TPaveStats *stfsr80100;
  TPaveStats *stfsr100200;
  TPaveStats *stfsr200350;

  ldiptfsrm->TLegend::AddEntry(hdiptfsr4060,"40 < M [GeV] < 60");  
  ldiptfsrm->TLegend::AddEntry(hdiptfsr80100,"80 < M [GeV] < 100");  
  ldiptfsrm->TLegend::AddEntry(hdiptfsr100200,"100 < M [GeV] < 200");  
  ldiptfsrm->TLegend::AddEntry(hdiptfsr200350,"200 < M [GeV] < 350");  
  hdiptfsr4060->GetXaxis()->SetTitle("Transverse Momentum [GeV]");
  hdiptfsr4060->GetYaxis()->SetTitle("Norm. Entries");   
  hdiptfsr4060->GetYaxis()->SetTitleOffset(1.5);
  hdiptfsr4060->SetTitle("P_{T}(ee + QED FSR) At each mass region");
  hdiptfsr4060->SetLineColor(kRed);
  hdiptfsr80100->SetLineColor(kBlue);
  hdiptfsr100200->SetLineColor(kGreen+2);
  hdiptfsr200350->SetLineColor(kOrange);
  hdiptfsr4060->SetLineWidth(3);
  hdiptfsr80100->SetLineWidth(3);
  hdiptfsr100200->SetLineWidth(3);
  hdiptfsr200350->SetLineWidth(3);

  
  hdiptfsr4060 -> Draw();
  gStyle->SetOptStat("nmr");
  stfsr4060 = (TPaveStats*)hdiptfsr4060->FindObject("stats");

  hdiptfsr80100->Draw();
  gStyle->SetOptStat("nmr");
  stfsr80100 = (TPaveStats*)hdiptfsr80100->FindObject("stats");

  hdiptfsr100200->Draw();
  gStyle->SetOptStat("nmr");
  stfsr100200 = (TPaveStats*)hdiptfsr100200->FindObject("stats");

  hdiptfsr200350->Draw();
  gStyle->SetOptStat("nmr");
  stfsr200350 = (TPaveStats*)hdiptfsr200350->FindObject("stats");
  
  

  stfsr4060->TPaveStats::SetX1NDC(0.7);
  stfsr4060->TPaveStats::SetX2NDC(0.9);
  stfsr4060->TPaveStats::SetY1NDC(0.8);
  stfsr4060->TPaveStats::SetY2NDC(0.9);
  stfsr4060->TPaveStats::SetTextSize(0.03);
  hdiptfsr4060->SetName("40 < M [GeV] < 60");
  

  stfsr80100->TPaveStats::SetX1NDC(0.7);
  stfsr80100->TPaveStats::SetX2NDC(0.9);
  stfsr80100->TPaveStats::SetY1NDC(0.7);
  stfsr80100->TPaveStats::SetY2NDC(0.8);
  stfsr80100->TPaveStats::SetTextSize(0.03);
  hdiptfsr80100->SetName("80 < M [GeV] < 100");


  stfsr100200->TPaveStats::SetX1NDC(0.7);
  stfsr100200->TPaveStats::SetX2NDC(0.9);
  stfsr100200->TPaveStats::SetY1NDC(0.6);
  stfsr100200->TPaveStats::SetY2NDC(0.7);
  stfsr100200->TPaveStats::SetTextSize(0.03);
  hdiptfsr100200->SetName("100 < M [GeV] < 200");

  
  stfsr200350->TPaveStats::SetX1NDC(0.7);
  stfsr200350->TPaveStats::SetX2NDC(0.9);
  stfsr200350->TPaveStats::SetY1NDC(0.5);
  stfsr200350->TPaveStats::SetY2NDC(0.6);
  stfsr200350->TPaveStats::SetTextSize(0.03);
  hdiptfsr200350->SetName("200 < M [GeV] < 350");
  
  
  hdiptfsr4060->GetYaxis()->SetRangeUser(0,10000);

  hdiptfsr4060->Scale( hdiptfsr4060->Integral()/hdiptfsr4060->Integral() );
  hdiptfsr80100->Scale( hdiptfsr4060->Integral()/hdiptfsr80100->Integral() );
  hdiptfsr100200->Scale( hdiptfsr4060->Integral()/hdiptfsr100200->Integral() );
  hdiptfsr200350->Scale( hdiptfsr4060->Integral()/hdiptfsr200350->Integral() );
    
  hdiptfsr4060->Draw();
  hdiptfsr80100->Draw("SAMES");
  hdiptfsr100200->Draw("SAMES");
  hdiptfsr200350->Draw("SAMES");
  ldiptfsrm->Draw();
  cdiptfsrm->SaveAs("plot_files/NLOdiptfsr_massregion.png");

    
  

}
