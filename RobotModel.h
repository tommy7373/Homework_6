/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RobotModel.h
 * Author: thomas
 *
 * Created on October 19, 2016, 10:08 AM
 */

#ifndef ROBOTMODEL_H
#define ROBOTMODEL_H
#include <vector>

class RobotModel {
public:
    RobotModel();
    int torso,head,locomotor;
    std::vector<int> batteries;
    std::vector<int> arms;
};

#endif /* ROBOTMODEL_H */

