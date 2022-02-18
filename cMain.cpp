#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "OneLoneCoder.com - wxWidgets!", wxPoint(30,30), wxSize(800,600))
{
    btn = new wxButton*[nFieldHeight * nFieldWidth];
    wxGridSizer *grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

    nField = new int[nFieldWidth * nFieldHeight];

    wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

    for( int x = 0; x < nFieldWidth; ++x){
        for(int y = 0; y < nFieldHeight; ++y){
            btn[y*nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x) );
            btn[y*nFieldWidth + x]->SetFont(font);
            grid->Add(btn[y*nFieldWidth + x], 1, wxEXPAND | wxALL);

            btn[y*nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
            nField[y*nFieldWidth + x] = 0;
        }
    }
    this->SetSizer(grid);
    grid->Layout();
}

cMain::~cMain()
{
    delete[]btn;
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
    int x = (evt.GetId() - 10000) % nFieldWidth;
    int y = (evt.GetId() - 10000) % nFieldHeight;

    if(bFirstClick){
        int mines = 30;
        while(mines){
            int rx = rand() % nFieldWidth;
            int ry = rand() % nFieldHeight;
            if(nField[ry * nFieldWidth + rx] == 0 && rx != x && ry != y){
                nField[ry* nFieldWidth + rx] = -1; // mine is there
                mines--;
            }
        }
        bFirstClick = false;
    }

    // Disable Button, preventing it being pressed again
    btn[y*nFieldWidth + x]->Enable(false);

    // check if the player hit a mine
    if( nField[y*nFieldWidth + x] == -1){
        wxMessageBox("BOOOOOM !! - Game Over :(");

        // Reset Game
        bFirstClick = true;
        for(int x = 0; x < nFieldWidth; x++){
            for(int y = 0; y < nFieldHeight; y++){
                nField[y*nFieldWidth + x] = 0;
                btn[y*nFieldWidth + x]->SetLabel("");
                btn[y*nFieldWidth + x]->Enable(true);
            }
        }
    }
    else{
        // Count neighbor mines
        int mine_count = 0;
        for(int i = -1; i < 2; i++){
            for(int j = -1; j<2; ++j){
                if(x+i >= 0 && x + i < nFieldWidth && y + j >= 0 && y+j < nFieldHeight){
                    if(nField[(y+j)*nFieldWidth+(x+i)] == -1)
                        mine_count++;
                }
            }
        }

        // update buttons label to show mine if count > 0
        if (mine_count > 0){
            btn[y*nFieldWidth + x]->SetLabel(std::to_string(mine_count));
        }

    }

    evt.Skip();
}
