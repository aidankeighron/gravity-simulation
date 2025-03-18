/**
 * @file MainFrame.cpp
 * @author Aidan Keighron
 */

#include "pch.h"
#include "MainFrame.h"
#include "GravityView.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Gravity", wxDefaultPosition, wxSize(1000, 800));

    auto sizer = new wxBoxSizer(wxVERTICAL);
    auto gravityView = new GravityView();
    gravityView->Initialize(this);

    sizer->Add(gravityView, 1, wxEXPAND | wxALL);
    SetSizer(sizer);
    Layout();

    auto menuBar = new wxMenuBar();
    auto fileMenu = new wxMenu();
    auto planetMenu = new wxMenu();

    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);

    planetMenu->Append(IDM_ADDPLANET, L"&New Planet", L"Add a New Planet");
    planetMenu->Append(IDM_CLEAR, L"&Clear All", L"Clears all planets");

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(planetMenu, L"&Planets");

    SetMenuBar(menuBar);
    CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}