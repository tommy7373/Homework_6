/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   controller.cpp
 * Author: thomas
 * 
 * Created on October 4, 2016, 8:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "controller.h"
#include "RobotParts.h"
#include "RobotModel.h"

using namespace std;

controller::controller() {
    string Name = "Test name";
    int modelNumber = 1;
    string Type = "Test type";
    double Weight = 10;
    double Cost = 123;
    string Description = "Test Description";
    int input,input2,input3;
    vector<RobotModel> robotmodels;
    vector<Head> headV;
    vector<Locomotor> locomotorV;
    vector<Torso> torsoV;
    vector<Arm> armV;
    vector<Battery> batteryV;
    while(true){
    cout << "\nMain Menu\n---------\n1) Create\n2) Browse\n3) Order\n4)Quit\n\nEnter the number of the selection you want: ";
    cin >> input;
    switch(input){ //switch for main menu
        case 1:
            cout << "\nCreate\n------\n1) Robot Part\n2) Robot Model\n\nEnter the number of the selection you want: ";
            cin >> input2;
            switch(input2){ //switch for create menu
                case 1:{
                    string name;
                    string desc;
                    double weight;
                    double cost;
                    int modnum;
                    cout << "\n1) Head\n2) Locomotor\n3) Torso\n4) Arm\n5) Battery\n\nEnter the number of the part type you wish to create: ";
                    cin >> input3;
                    switch(input3){ //switch for part selection
                        case 1:{ //add head
                            cout << "What is the head's name?\n";
                            cin.ignore();
                            getline(cin,name);
                            cout << "What is the head's weight (in kg)?\n";
                            cin >> weight;
                            cout << "What is the head's cost (in USD)?\n";
                            cin >> cost;
                            cout << "Type a brief description for the head: \n";
                            cin.ignore();
                            getline(cin,desc);
                            modnum=headV.size()+1;
                            Head head;
                            head.SetInfo(name,modnum,weight,cost,desc);
                            headV.push_back(head);
                            break;}
                        case 2:{ //add locomotor
                            double speed;
                            cout << "What is the locomotor's name?\n";
                            cin.ignore();
                            getline(cin,name);
                            cout << "What is the locomotor's weight (in kg)?\n";
                            cin >> weight;
                            cout << "What is the locomotor's cost (in USD)?\n";
                            cin >> cost;
                            cout << "What is the maximum speed of the locomotor (in MPH)?\n";
                            cin >> speed;
                            cout << "Type a brief description for the locomotor: \n";
                            cin.ignore();
                            getline(cin,desc);
                            modnum=locomotorV.size()+1;
                            Locomotor locomotor;
                            locomotor.SetInfo(name,modnum,weight,cost,desc);
                            locomotor.setLocomotorInfo(speed);
                            locomotorV.push_back(locomotor);
                            break;}
                        case 3:{ //add torso
                            int compartments;
                            cout << "What is the torso's name?\n";
                            cin.ignore();
                            getline(cin,name);
                            cout << "What is the torso's weight (in kg)?\n";
                            cin >> weight;
                            cout << "What is the torso's cost (in USD)?\n";
                            cin >> cost;
                            cout << "How many battery compartments does the torso have?\n";
                            cin >> compartments;
                            cout << "Type a brief description for the torso: \n";
                            cin.ignore();
                            getline(cin,desc);
                            modnum=torsoV.size()+1;
                            Torso torso;
                            torso.SetInfo(name,modnum,weight,cost,desc);
                            torso.setBatteryCompartments(compartments);
                            torsoV.push_back(torso);
                            break;}
                        case 4:{ //add arm
                            double powerc;
                            cout << "What is the arm's name?\n";
                            getline(cin,name);
                            cin.ignore();
                            cout << "What is the arm's weight (in kg)?\n";
                            cin >> weight;
                            cout << "What is the arm's cost (in USD)?\n";
                            cin >> cost;
                            cout << "How much energy does the arm consume (in W)?\n";
                            cin >> powerc;
                            cout << "Type a brief description for the arm: \n";
                            cin.ignore();
                            getline(cin,desc);
                            modnum=armV.size()+1;
                            Arm arm;
                            arm.SetInfo(name,modnum,weight,cost,desc);
                            arm.setPowerConsumed(powerc);
                            armV.push_back(arm);
                            break;}
                        case 5:{ //add battery
                            double energy;
                            cout << "What is the battery's name?\n";
                            cin.ignore();
                            getline(cin,name);
                            cout << "What is the battery's weight (in kg)?\n";
                            cin >> weight;
                            cout << "What is the battery's cost (in USD)?\n";
                            cin >> cost;
                            cout << "What is the battery's energy capacity (in kWh?)\n";
                            cin >> energy;
                            cout << "Type a brief description for the battery: \n";
                            cin.ignore();
                            getline(cin,desc);
                            modnum=batteryV.size()+1;
                            Battery battery;
                            battery.SetInfo(name,modnum,weight,cost,desc);
                            battery.setBatteryInfo(energy);
                            batteryV.push_back(battery);
                            break;}
                        break;}
                    break;
                }
                case 2:{
                    RobotModel newModel;
                    int torso,head,locomotor,selection;
                    vector<int> arms;
                    vector<int> batteries;
                    cout << "Robot model creation\n--------------------\n";
                    cout << "Which of the following torsos would you like?:\n";
                    cout << "Torso\tModel#\tName\tWeight\tCost\tOther info\n";
                    for(int i=0;i<torsoV.size();i++){
                        torsoV[i].PrintInfo();
                        cout << '\n';
                    }
                    cout << "Enter the model number of the torso you would like: ";
                    cin >> selection;
                    newModel.torso=selection-1;
                    cout << "This torso contains " << torsoV[newModel.torso].batteryCompartments << " battery compartments.\n";
                    for (int i=0;i<torsoV[newModel.torso].batteryCompartments;i++){
                        cout << "Choose battery #" << i+1 << ":";
                        for (int j=0;j<batteryV.size();j++){
                            batteryV[j].PrintInfo();
                            cout << '\n';
                        }
                        cout << "Selection: ";
                        cin >> selection;
                        newModel.batteries.push_back(selection-1);
                    }
                    cout << "Which of the following heads would you like?:\n";
                    cout << "Head\tModel#\tName\tWeight\tCost\tOther info\n";
                    for(int i=0;i<headV.size();i++){
                        headV[i].PrintInfo();
                        cout << '\n';
                    }
                    cout << "Enter the model number of the head you would like: ";
                    cin >> selection;
                    newModel.head=selection-1;
                    cout << "Which of the following locomotors would you like?:\n";
                    cout << "Locomotor\tModel#\tName\tWeight\tCost\tOther info\n";
                    for(int i=0;i<headV.size();i++){
                        locomotorV[i].PrintInfo();
                        cout << '\n';
                    }
                    cout << "Enter the model number of the locomotor you would like: ";
                    cin >> selection;
                    newModel.locomotor=selection-1;                   
                    break;
                    cout << "How many arms can this robot have?\n";
                    cin >> selection;
                    for(int i=0;i<selection;i++){
                        cout << "Choose arm # " << i+1 << ":";
                        for (int j=0;j<armV.size();j++){
                        armV[j].PrintInfo();
                        cout << "\n";
                        }
                    cout << "Selection: ";
                    cin >> selection;
                    newModel.batteries.push_back(selection-1);
                    }
                }
            }
            break;
        case 2:
            cout << "\nBrowse menu\n-----------\n1) View models\n";
            cin >> input2;
            switch(input2){
                case 1:{ //print current models
                    for(int i=0;i<robotmodels.size();i++){ //for all models
                        cout << "Model " << i+1 << ",\n";
                        headV[robotmodels[i].head].PrintInfo();  
                        torsoV[robotmodels[i].torso].PrintInfo();
                        for(int j=0;j<robotmodels[i].batteries.size();j++){
                            batteryV[robotmodels[i].batteries[j]].PrintInfo();
                        }
                        for(int j=0;j<robotmodels[i].arms.size();j++){
                            armV[robotmodels[i].batteries[j]].PrintInfo();
                        }
                        locomotorV[robotmodels[i].locomotor].PrintInfo();
                    }
                    break;
                }
            }
            break;
        case 3:{
            int selection;
            int modelcount;
            string exitanswer;
            double cost,localcost;
            bool adding=1;
            cout << "Order creation\n--------------\nHere is a list of our current models: \n\n";
            while(adding){
                for(int i=0;i<robotmodels.size();i++){ //list for all models
                    localcost=0;
                    cout << "Model " << i+1 << ",\n";
                    headV[robotmodels[i].head].PrintInfo();  
                    torsoV[robotmodels[i].torso].PrintInfo();
                    for(int j=0;j<robotmodels[i].batteries.size();j++){
                        batteryV[robotmodels[i].batteries[j]].PrintInfo();
                    }
                    for(int j=0;j<robotmodels[i].arms.size();j++){
                        armV[robotmodels[i].batteries[j]].PrintInfo();
                    }
                    locomotorV[robotmodels[i].locomotor].PrintInfo();
                    localcost = localcost+torsoV[robotmodels[i].torso].Cost;
                    localcost = localcost+headV[robotmodels[i].head].Cost;
                    localcost = localcost+locomotorV[robotmodels[i].locomotor].Cost;
                    for(int j=0;j<robotmodels[i].arms.size();j++){
                        localcost = localcost+armV[robotmodels[i].arms[j]].Cost;
                    }
                    for(int j=0;j<robotmodels[i].batteries.size();j++){
                        localcost = localcost+batteryV[robotmodels[i].batteries[j]].Cost;
                    }
                    cout << "\n This model costs $" << localcost << "\n";
                }
            cout << "Choose a model to add to your order: ";
            cin >> selection;
            selection--;
            cost = cost+torsoV[robotmodels[selection].torso].Cost;
            cost = cost+headV[robotmodels[selection].head].Cost;
            cost = cost+locomotorV[robotmodels[selection].locomotor].Cost;
            for(int i=0;i<robotmodels[selection].arms.size();i++){
                cost = cost+armV[robotmodels[selection].arms[i]].Cost;
            }
            for(int i=0;i<robotmodels[selection].batteries.size();i++){
                cost = cost+batteryV[robotmodels[selection].batteries[i]].Cost;
            }
            modelcount++;
            cout << "\nWould you like to keep adding models to your order? y/n";
            cin >> exitanswer;
            if(exitanswer=="y"){
                adding=0;
            }else if(exitanswer=="n"){
                adding=1;
            }
            cout << "Your order of " << modelcount << " models ";
            cout << "comes to $" << cost << " in total.\n";
            }
            break;
        }
        case 4:
            exit(0);
    }
}
}


