void DrawMNN()
{
  gROOT->LoadMacro("MakeRawProduction.C+g");
  
  RawProduction::Output output;

  const char* example1 = "kMB/pt003_hPi0M11";
  TCanvas* canv = new TCanvas(example1, example1);
  gStyle->SetOptFit(1);
  TH1* hist = output.GetHistogram(example1);
  hist->SetAxisRange(0.05, 0.3);
  hist->GetXaxis()->SetTitle("M_{#gamma#gamma}");
  hist->Draw();
  canv->SaveAs("imgs/kMB_pt003_hPi0M11.pdf");

  const char* example2 = "kMB/pt003_hPi0M12";
  TCanvas* canv = new TCanvas(example2, example2);
  gStyle->SetOptFit(1);
  TH1* hist = output.GetHistogram(example2);
  hist->SetAxisRange(0.05, 0.3);
  hist->GetXaxis()->SetTitle("M_{#gamma#gamma}");
  hist->Draw();
  canv->SaveAs(Form("imgs/kMB_pt003_hPi0M12.pdf", example2));



  const char* badM11 = "kCentral/pt003_hPi0M11";
  TCanvas* canv = new TCanvas(badM11, badM11);
  gStyle->SetOptFit(1);
  TH1* hist = output.GetHistogram(badM11);
  hist->SetAxisRange(0.05, 0.3);
  hist->GetXaxis()->SetTitle("M_{#gamma#gamma}");
  hist->Draw();
  canv->SaveAs(Form("imgs/kCentral_pt003_hPi0M11.pdf", badM11));


  const char* badM22 = "kCentral/pt003_hPi0M22";
  TCanvas* canv = new TCanvas(badM22, badM22);
  gStyle->SetOptFit(1);
  TH1* hist = output.GetHistogram(badM22);
  hist->SetAxisRange(0.05, 0.3);
  hist->GetXaxis()->SetTitle("M_{#gamma#gamma}");
  hist->Draw();
  canv->SaveAs(Form("imgs/kCentral_pt003_hPi0M22.pdf", badM22));


  const char* badM33 = "kCentral/pt003_hPi0M33";
  TCanvas* canv = new TCanvas(badM33, badM33);
  gStyle->SetOptFit(1);
  TH1* hist = output.GetHistogram(badM33);
  hist->SetAxisRange(0.05, 0.3);
  hist->GetXaxis()->SetTitle("M_{#gamma#gamma}");
  hist->Draw();
  canv->SaveAs(Form("imgs/kCentral_pt003_hPi0M33.pdf", badM33));
  
 
  
  TStringToken triggers("kMB kCentral kSemiCentral kPHOSPb", " ");
  while(triggers.NextToken()) {
    canv = new TCanvas(Form("cMean_%s", triggers.Data()), Form("cMean_%s", triggers.Data()));

    RawProduction::TriggerBin triggerBin(triggers);
    TH1* hM11 = output.GetHistogram("M_M11", triggerBin);
    TH1* hM12 = output.GetHistogram("M_M12", triggerBin);
    TH1* hM13 = output.GetHistogram("M_M13", triggerBin);
    TH1* hM22 = output.GetHistogram("M_M22", triggerBin);
    TH1* hM23 = output.GetHistogram("M_M23", triggerBin);
    TH1* hM33 = output.GetHistogram("M_M33", triggerBin);


    hM12->SetMarkerStyle(24);
    hM12->SetMarkerColor(kCyan+1);
    hM12->SetLineColor(kCyan+1);
    hM12->GetYaxis()->SetRangeUser(0.12, 0.15);
    hM12->SetTitle(Form("#pi^{0} Peak Mean, %s", triggers.Data()));
    hM12->GetYaxis()->SetTitle("Peak #mu");
    hM12->GetYaxis()->SetTitleOffset(1.3);
    hM12->GetXaxis()->SetTitle("p_{T}");
    gStyle->SetOptStat(0);
    hM12->Draw();

    hM13->SetMarkerStyle(25);
    hM13->SetMarkerColor(kMagenta);
    hM13->SetLineColor(kMagenta);
    hM13->Draw("same");

    hM23->SetMarkerStyle(26);
    hM23->SetMarkerColor(kYellow+1);
    hM23->SetLineColor(kYellow+1);
    hM23->Draw("same");
    

    hM11->SetMarkerStyle(21);
    hM11->SetMarkerColor(1);
    hM11->SetLineColor(1);
    hM11->GetYaxis()->SetRangeUser(0.12, 0.15);
    hM11->Draw("same");

    hM22->SetMarkerStyle(22);
    hM22->SetMarkerColor(kRed);
    hM22->SetLineColor(kRed);
    hM22->Draw("same");

    hM33->SetMarkerStyle(23);
    hM33->SetMarkerColor(kGreen);
    hM33->SetLineColor(kGreen);
    hM33->Draw("same");

    TLegend* leg = new TLegend(0.8,0.6,0.95,0.95);
    leg->AddEntry(hM11, "M11", "lep");
    leg->AddEntry(hM22, "M22", "lep");
    leg->AddEntry(hM33, "M33", "lep");
    leg->AddEntry(hM12, "M12", "lep");
    leg->AddEntry(hM13, "M13", "lep");
    leg->AddEntry(hM23, "M23", "lep");
    leg->Draw();
    
    canv->SaveAs(Form("imgs/MNN_Mean_%s.pdf", triggers.Data()));
    canv->SaveAs(Form("imgs/MNN_Mean_%s.png", triggers.Data()));

    
    
    canv = new TCanvas(Form("cWidth_%s", triggers.Data()), Form("cWidth_%s", triggers.Data()));

    TH1* hW11 = output.GetHistogram("W_M11", triggerBin);
    TH1* hW12 = output.GetHistogram("W_M12", triggerBin);
    TH1* hW13 = output.GetHistogram("W_M13", triggerBin);
    TH1* hW22 = output.GetHistogram("W_M22", triggerBin);
    TH1* hW23 = output.GetHistogram("W_M23", triggerBin);
    TH1* hW33 = output.GetHistogram("W_M33", triggerBin);


    hW12->SetMarkerStyle(24);
    hW12->SetMarkerColor(kCyan+1);
    hW12->SetLineColor(kCyan+1);
    hW12->GetYaxis()->SetRangeUser(0., 0.012);
    hW12->SetTitle(Form("#pi^{0} Peak Width, %s", triggers.Data()));
    hW12->GetYaxis()->SetTitle("Peak #sigma");
    hW12->GetYaxis()->SetTitleOffset(1.3);
    hW12->GetXaxis()->SetTitle("p_{T}");
    gStyle->SetOptStat(0);
    hW12->Draw();

    hW13->SetMarkerStyle(25);
    hW13->SetMarkerColor(kMagenta);
    hW13->SetLineColor(kMagenta);
    hW13->Draw("same");

    hW23->SetMarkerStyle(26);
    hW23->SetMarkerColor(kYellow+1);
    hW23->SetLineColor(kYellow+1);
    hW23->Draw("same");
    

    hW11->SetMarkerStyle(21);
    hW11->SetMarkerColor(1);
    hW11->SetLineColor(1);
    hW11->GetYaxis()->SetRangeUser(0.12, 0.15);
    hW11->Draw("same");

    hW22->SetMarkerStyle(22);
    hW22->SetMarkerColor(kRed);
    hW22->SetLineColor(kRed);
    hW22->Draw("same");

    hW33->SetMarkerStyle(23);
    hW33->SetMarkerColor(kGreen);
    hW33->SetLineColor(kGreen);
    hW33->Draw("same");

    leg = new TLegend(0.8,0.6,0.95,0.95);
    leg->AddEntry(hW11, "M11", "lep");
    leg->AddEntry(hW22, "M22", "lep");
    leg->AddEntry(hW33, "M33", "lep");
    leg->AddEntry(hW12, "M12", "lep");
    leg->AddEntry(hW13, "M13", "lep");
    leg->AddEntry(hW23, "M23", "lep");
    leg->Draw();
    
    canv->SaveAs(Form("imgs/MNN_Width_%s.pdf", triggers.Data()));
  }
}
