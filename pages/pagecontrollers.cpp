/*
    Copyright 2016 - 2017 Benjamin Vedder	benjamin@vedder.se

    This file is part of VESC Tool.

    VESC Tool is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    VESC Tool is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#include "pagecontrollers.h"
#include "ui_pagecontrollers.h"

PageControllers::PageControllers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageControllers)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageControllers::~PageControllers()
{
    delete ui;
}

VescInterface *PageControllers::vesc() const
{
    return mVesc;
}

void PageControllers::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->paramTab->addRowSeparator(tr("Speed Controller"));
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_kp");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_ki");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_kd");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_kd_filter");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_min_erpm");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_allow_braking");

        ui->paramTab->addRowSeparator(tr("Position Controller"));
        ui->paramTab->addParamRow(mVesc->mcConfig(), "p_pid_kp");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "p_pid_ki");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "p_pid_kd");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "p_pid_kd_filter");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "p_pid_ang_div");

        ui->paramTab->addRowSeparator(tr("LQR Speed Controller"));
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_A00");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_A01");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_A10");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_A11");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_B0");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_B1");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_C0");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_C1");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_K0");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_K1");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_L0");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_L1");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_Nbar");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_oversampling_factor");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_voltage_filter_freq");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_min_speed");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_max_speed");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_max_speed_per_volt");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_trunc_voltage_min");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_trunc_voltage_max");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_max_voltage_drop");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_min_duty");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_max_duty");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_max_thrust");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_lqr_max_thrust_rate");
    }
}
